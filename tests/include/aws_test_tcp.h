/*
 * FreeRTOS V202203.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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

#ifndef AWS_TEST_TCP_H
#define AWS_TEST_TCP_H

/* Non-Encrypted Echo Server.
 * Update tcptestECHO_SERVER_ADDR# and
 * tcptestECHO_PORT with IP address
 * and port of unencrypted TCP echo server. */
#define tcptestECHO_SERVER_ADDR0         192
#define tcptestECHO_SERVER_ADDR1         168
#define tcptestECHO_SERVER_ADDR2         0
#define tcptestECHO_SERVER_ADDR3         159
#define tcptestECHO_PORT                 ( 8883 )

/* Encrypted Echo Server.
 * If tcptestSECURE_SERVER is set to 1, the following must be updated:
 * 1. aws_clientcredential.h to use a valid AWS endpoint.
 * 2. aws_clientcredential_keys.h with corresponding AWS keys.
 * 3. tcptestECHO_SERVER_TLS_ADDR0-3 with the IP address of an
 * echo server using TLS.
 * 4. tcptestECHO_PORT_TLS, with the port number of the echo server
 * using TLS.
 * 5. tcptestECHO_HOST_ROOT_CA with the trusted root certificate of the
 * echo server using TLS. */
#define tcptestSECURE_SERVER             1

#define tcptestECHO_SERVER_TLS_ADDR0     192
#define tcptestECHO_SERVER_TLS_ADDR1     168
#define tcptestECHO_SERVER_TLS_ADDR2     0
#define tcptestECHO_SERVER_TLS_ADDR3     159
#define tcptestECHO_PORT_TLS             ( 8884 )

/* Number of times to retry a connection if it fails. */
#define tcptestRETRY_CONNECTION_TIMES    6

/* The root certificate used for the encrypted echo server.
 * This certificate is self-signed, and not in the trusted catalog. */
static const char tcptestECHO_HOST_ROOT_CA[] = "-----BEGIN CERTIFICATE-----\n"\
"MIID8zCCAtugAwIBAgIUFVPOFCKgO/2JIR9sO9IfxDA/3FswDQYJKoZIhvcNAQEL\n"\
"BQAwgYgxCzAJBgNVBAYTAlVTMQswCQYDVQQIDAJXQTEOMAwGA1UEBwwFUGxhY2Ux\n"\
"EDAOBgNVBAoMB0dub21vbnMxCzAJBgNVBAsMAklUMRgwFgYDVQQDDA93d3cuZ25v\n"\
"bW9ucy5jb20xIzAhBgkqhkiG9w0BCQEWFHZpbmgubG9pQGdub21vbnMuY29tMB4X\n"\
"DTIyMDkwNDA1MzMzMVoXDTIzMDkwNDA1MzMzMVowgYgxCzAJBgNVBAYTAlVTMQsw\n"\
"CQYDVQQIDAJXQTEOMAwGA1UEBwwFUGxhY2UxEDAOBgNVBAoMB0dub21vbnMxCzAJ\n"\
"BgNVBAsMAklUMRgwFgYDVQQDDA93d3cuZ25vbW9ucy5jb20xIzAhBgkqhkiG9w0B\n"\
"CQEWFHZpbmgubG9pQGdub21vbnMuY29tMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8A\n"\
"MIIBCgKCAQEA2ubf1Hjq1NwnSgBSLgs5lWEbQns9U2SP3GBiviGgJqDFL4aQSf53\n"\
"SudNPQPXCH1V776taVSqISM8+bH70GvCVlWYN2FrF0DA0SUjPHNZW9PODv4h67y7\n"\
"Mp0a51LtXPUBaj4hrPZtY6Qygjs91Sz4A+cPQ5k+5GQ9GfhW7tUXOymAS8izpYm5\n"\
"5QYAAknFQXt60tZbnO4QzF+Twdw7jUQeaZW9I1WL38vBLECEBIzFJj0yXgIra1c7\n"\
"LVZuwN9eGPMtqi6ZSKyEIpAtMBeUmsXjxR9/KFTReX1fzqIYLAak84ab7JPkVMox\n"\
"d9HqJSx1zbTCdziRQ17JfGQncaI61PMEVQIDAQABo1MwUTAdBgNVHQ4EFgQU/j/s\n"\
"J2cXUDp0lunJcOXCiGJKKEYwHwYDVR0jBBgwFoAU/j/sJ2cXUDp0lunJcOXCiGJK\n"\
"KEYwDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOCAQEAsgxvsvPw0lBW\n"\
"sMVKhv7hQ1TXqAKnqYMMhZvsJm+rKqhNbFUPhKWOcQyIXXSxHCZewcKhLnFJEGU0\n"\
"I+7OvoPdkrPIhI4QM7Mel7F/E3S2dHciaRL0FFtlBZcCmmnr/OcO3tDP/oO+IyCl\n"\
"RDFtPVXcvFKE4F3te6at+adGuzoGGljuglYI0a37WdihgA0h4A3Oy00e5vGmr4/Y\n"\
"ZuMCeHTXvMZwDyDC7qsO+ekYkDtfZap1x7aHQmNXhi4lkz7COlqcz4aOaU0T/0rZ\n"\
"zHmRnbizLchM2ZKRsQYTQEsknfyemQjCNpt+bUSjB9DrLW8asK5zLWUP3Vs51tBJ\n"\
"42MTm3Ng/A==\n"\
"-----END CERTIFICATE-----";

#endif /* ifndef AWS_TEST_TCP_H */
