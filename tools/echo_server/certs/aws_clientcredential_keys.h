#ifndef AWS_CLIENT_CREDENTIAL_KEYS_H
#define AWS_CLIENT_CREDENTIAL_KEYS_H

#include <stdint.h>

/*
 * PEM-encoded client certificate.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyCLIENT_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDmTCCAoECFEHojE5TBdnhQNUMdfNziIiiP6rqMA0GCSqGSIb3DQEBCwUAMIGI\n"\
"MQswCQYDVQQGEwJVUzELMAkGA1UECAwCV0ExDjAMBgNVBAcMBVBsYWNlMRAwDgYD\n"\
"VQQKDAdHbm9tb25zMQswCQYDVQQLDAJJVDEYMBYGA1UEAwwPd3d3Lmdub21vbnMu\n"\
"Y29tMSMwIQYJKoZIhvcNAQkBFhR2aW5oLmxvaUBnbm9tb25zLmNvbTAeFw0yMjA5\n"\
"MDQwNTMzNTBaFw0yMzA5MDQwNTMzNTBaMIGIMQswCQYDVQQGEwJVUzELMAkGA1UE\n"\
"CAwCV0ExDjAMBgNVBAcMBVBsYWNlMRAwDgYDVQQKDAdHbm9tb25zMQswCQYDVQQL\n"\
"DAJJVDEYMBYGA1UEAwwPd3d3Lmdub21vbnMuY29tMSMwIQYJKoZIhvcNAQkBFhR2\n"\
"aW5oLmxvaUBnbm9tb25zLmNvbTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoC\n"\
"ggEBALLXxJ8TgasBn7jX6iO53GgOHm7QZLRO08uvWQwMJs4bufhNsoVkGNCqd2o7\n"\
"J/dVXCPOAUcayxITmAkGvFaHj11fpWSD55yLwGNFErfQXPrXY1kch5MWrl+aIryd\n"\
"Zt+49zVka8XHvHeDoOf0i6Sf8NXvPngXc+j0mBjX4Ds2kCwM+9wqr3rahqp26MkL\n"\
"xxqeb6pd6xBn3qU9kzu9YSUywqKCjxXRpr39cW3MyPYVjP7DYOcjncVuM8cbcxbz\n"\
"mevlyy3kdwdgKWH3w2KdqIdUpwmSJeoZ+FRR3FjXpwxhnldjhtjP2pRsesKre9GJ\n"\
"1YRc8wn5xsl8S0xopFta0V2QUaMCAwEAATANBgkqhkiG9w0BAQsFAAOCAQEAAcqY\n"\
"rJNsMDPSgTh39x71S2QwQ3uCB3taqVA/YDi3blWXD34SV+//K+DNk4cq8bwovx4+\n"\
"2RNzEGKil+fjKHlNvRnLN4Q+Qqt1Kff3doAJoAUYrhNfSpyHuLjm6wIfcsNgpeI/\n"\
"HFTtED64V22d56F02FnkKHlA81br4YvELUEPqN89i2MNHFUtI3PefHvAO4tgoFMf\n"\
"G20gVP1qVGKfQ70arC80J+bL9xVZvLSERf5Lp+9R8p6mPNvTjtr8vy4DUvK5fLLm\n"\
"+YLB1TedpWVhmmhFM7iUFKW7lIaJR5TetHjUvh7rwTxjprgZmw1m8hrxL29SuMn6\n"\
"gxLhd6AMIYwzA0GBGw==\n"\
"-----END CERTIFICATE-----"

/*
 * PEM-encoded client private key.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN RSA PRIVATE KEY-----\n"\
 * "...base64 data...\n"\
 * "-----END RSA PRIVATE KEY-----"
 */
#define keyCLIENT_PRIVATE_KEY_PEM \
"-----BEGIN PRIVATE KEY-----\n"\
"MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQCy18SfE4GrAZ+4\n"\
"1+ojudxoDh5u0GS0TtPLr1kMDCbOG7n4TbKFZBjQqndqOyf3VVwjzgFHGssSE5gJ\n"\
"BrxWh49dX6Vkg+eci8BjRRK30Fz612NZHIeTFq5fmiK8nWbfuPc1ZGvFx7x3g6Dn\n"\
"9Iukn/DV7z54F3Po9JgY1+A7NpAsDPvcKq962oaqdujJC8canm+qXesQZ96lPZM7\n"\
"vWElMsKigo8V0aa9/XFtzMj2FYz+w2DnI53FbjPHG3MW85nr5cst5HcHYClh98Ni\n"\
"naiHVKcJkiXqGfhUUdxY16cMYZ5XY4bYz9qUbHrCq3vRidWEXPMJ+cbJfEtMaKRb\n"\
"WtFdkFGjAgMBAAECggEAAWu9Ye0Hgkl+V4O3dN2Cp3HDtN8caTAj64pJNJYO/4/l\n"\
"vkdBUGw0cgFZDSMILgPuv7VKhVnm52yUNcuKJMdTU2npRXTLmufbKJcXqEKtSWPD\n"\
"xXMlE3er/Umgv++F2nixkySbFGrE2DlzVyO70vrDoCHtTzyNKMhn0sSeNhKRtPbU\n"\
"kKOjnY/ljigcPPTxxNUmZWCPDXI/ZaAWJWql620rITmZQBY7ZSjP8/YXYebeNpIY\n"\
"nIIuA22K7Ej2+Thu3RTs5+iJiIR1DPAaCHLvArA+RsSlrruMnKatTk3i2Zs6u2Xl\n"\
"zICEYk/t0MTwud0+8KxLaYijeGTBXlBzlQydWxN0iQKBgQDTq5O66zUJdsjplPQB\n"\
"veV6GLADYPHeK1Q6Ih9kbTpDCt2pgl4RqAduQwxDNZenx4aLEEvA7Nqi+S973Fm7\n"\
"aTt/PxpBkb4/+P5fyUq5g+fGYDpVDkdMEFij9pv17V2/+rajK4bD/L6VL632x5rO\n"\
"uiO3Mh5qEi0q05r16/UcUnEa6wKBgQDYTDGhqJDmFUkjerJgOELeB8Q/F+Z1K+TH\n"\
"YeMP2LAGMQIBciTnDkUop+ytuvBa9U8Acg6pmGALra/gTqfk12aBb4Ha5rB1G1KA\n"\
"qwehvV2hthxOIigjwrFyY4HDu8az+RHXbzjwxme08LWe2fTJoKXD+H71TMBhq2Ul\n"\
"OgSz0RSGKQKBgGP3CRri0DZ7AeHGtgJIk6K5HA9Mbo31Op8F1HuSVkypSgwvBIwk\n"\
"JfY99gGbwta7FWCBvrULZypGstU1OK+YwD+VJqpG0WnXBxNntkGs+P4oHgRjbOqQ\n"\
"Ybx10CwyAO+U0UJ4YPoYWE2OqgL9O7BcGlf/dHu1v90U+H8iA61vhfknAoGBAIBx\n"\
"zs9XEKTxYvtks2ScRGkhZ5KoGLzgEf2szW/tl6o1lCFTrUJgoQUho1UPvAfnwMBc\n"\
"+wQPbonA3L5xNxaYK1EV7KEXeRYx4W5zIhcUIvQS9wAXHIsP5Nwu5zJa4gaiE8xB\n"\
"SikBSTiT8OaiO9E4SvfzK0F0EJJve6L9rykxMeTxAoGASoReUbzjthPQsNyo+VtD\n"\
"v25n8qDqd1Fnuf7RL5sjtfHuzPwxk7CaPUi6ntVJi8gLi+CfIBHl1kB3qcYZfAD9\n"\
"FyOzL7Zced2SrGDRDZZxXdIT1L66w1qSgZ6T2MJjVDpcSJ6aH0HPv1i4b8Jv7i7k\n"\
"UZ2wGRRckzSSHbRsYWoQehs=\n"\
"-----END PRIVATE KEY-----"

/*
 * PEM-encoded Just-in-Time Registration (JITR) certificate (optional).
 *
 * If used, must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM  ""


#endif /* AWS_CLIENT_CREDENTIAL_KEYS_H */
