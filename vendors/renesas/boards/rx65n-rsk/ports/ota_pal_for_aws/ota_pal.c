/*
 * FreeRTOS OTA PAL for Renesas RX65N-RSK V2.0.0
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/* C Runtime includes. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FreeRTOS include. */
#include "FreeRTOS.h"

/* OTA PAL Port include. */
#include "ota_pal.h"

/* Renesas RX Driver Package include */
#include "platform.h"
#include "r_fwup_if.h"

/**
 * @brief Verify the signature of the specified file.
 *
 * This function should be implemented if signature verification is not offloaded to non-volatile
 * memory io functions.
 *
 * This function is expected to be called from otaPal_CloseFile().
 *
 * @param[in] pFileContext OTA file context information.
 *
 * @return The OtaPalStatus_t error code combined with the MCU specific error code. See
 *         ota_platform_interface.h for OTA major error codes and your specific PAL implementation
 *         for the sub error code.
 *
 * Major error codes returned are:
 *   OtaPalSuccess: if the signature verification passes.
 *   OtaPalSignatureCheckFailed: if the signature verification fails.
 *   OtaPalBadSignerCert: if the signature verification certificate cannot be read.
 */
static OtaPalStatus_t otaPal_CheckFileSignature( OtaFileContext_t * const pFileContext );

/**
 * @brief Read the specified signer certificate from the filesystem into a local buffer.
 *
 * The allocated memory returned becomes the property of the caller who is responsible for freeing it.
 *
 * This function is called from otaPAL_CheckFileSignature(). It should be implemented if signature
 * verification is not offloaded to non-volatile memory io function.
 *
 * @param[in] pucCertName The file path of the certificate file.
 * @param[out] ulSignerCertSize The size of the certificate file read.
 *
 * @return A pointer to the signer certificate in the file system. NULL if the certificate cannot be read.
 * This returned pointer is the responsibility of the caller; if the memory is allocated the caller must free it.
 */
static uint8_t * otaPal_ReadAndAssumeCertificate( const uint8_t * const pucCertName,
                                                  uint32_t * const ulSignerCertSize );

/*-----------------------------------------------------------*/

OtaPalStatus_t otaPal_CreateFileForRx( OtaFileContext_t * const pFileContext )
{
	OtaPalStatus_t eResult;

    eResult = R_FWUP_CreateFileForRx( pFileContext );
    return eResult;
}
/*-----------------------------------------------------------*/

OtaPalStatus_t otaPal_Abort( OtaFileContext_t * const pFileContext )
{
	OtaPalStatus_t eResult;

    eResult = R_FWUP_Abort( pFileContext );
    return eResult;
}
/*-----------------------------------------------------------*/

/* Write a block of data to the specified file. */
int16_t otaPal_WriteBlock( OtaFileContext_t * const pFileContext,
                           uint32_t ulOffset,
                           uint8_t * const pData,
                           uint32_t ulBlockSize )
{
    int16_t sNumBytesWritten;

    sNumBytesWritten = R_FWUP_WriteBlock( pFileContext, ulOffset, pData, ulBlockSize );
    return sNumBytesWritten;
}
/*-----------------------------------------------------------*/

OtaPalStatus_t otaPal_CloseFile( OtaFileContext_t * const pFileContext )
{
    OtaPalMainStatus_t eResult;

    vTaskDelay(500);

    eResult = R_FWUP_CloseFile( pFileContext );
    return eResult;
}
/*-----------------------------------------------------------*/

static OtaPalStatus_t otaPal_CheckFileSignature( OtaFileContext_t * const pFileContext )
{
	OtaPalStatus_t eResult;

    eResult = R_FWUP_CheckFileSignature( pFileContext );
    return eResult;
}
/*-----------------------------------------------------------*/

static uint8_t * otaPal_ReadAndAssumeCertificate( const uint8_t * const pucCertName,
                                                  uint32_t * const ulSignerCertSize )
{
    uint8_t * pucSignerCert;

    pucSignerCert = R_FWUP_ReadAndAssumeCertificate( pucCertName, ulSignerCertSize );
    return pucSignerCert;
}
/*-----------------------------------------------------------*/

OtaPalStatus_t otaPal_ResetDevice( OtaFileContext_t * const pFileContext )
{
	OtaPalStatus_t ret;

	ret = R_FWUP_ResetDevice( pFileContext );
	return ret;
}
/*-----------------------------------------------------------*/

OtaPalStatus_t otaPal_ActivateNewImage( OtaFileContext_t * const pFileContext )
{
	OtaPalStatus_t ret;

	ret = R_FWUP_ActivateNewImage( pFileContext );
	return ret;
}
/*-----------------------------------------------------------*/

OtaPalStatus_t otaPal_SetPlatformImageState( OtaFileContext_t * const pFileContext,
                                             OtaImageState_t eState )
{
	OtaPalStatus_t eResult;

    eResult = R_FWUP_SetPlatformImageState( pFileContext, eState );
    return eResult;
}
/*-----------------------------------------------------------*/

OtaPalImageState_t otaPal_GetPlatformImageState( OtaFileContext_t * const pFileContext )
{
    OtaPalImageState_t ePalState;

    ePalState = R_FWUP_GetPlatformImageState( pFileContext );
    return ePalState;
}

/* Provide access to private members for testing. */
#ifdef FREERTOS_ENABLE_UNIT_TESTS
    #include "aws_ota_pal_test_access_define.h"
#endif
