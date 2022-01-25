#include <stdio.h>
#include <stdlib.h>
#include "base64.h"
#include "aes.h"

int main()
{
    printf("Hello world!\n");
    uint8_t AES_KEY[]="1234567891234567";
    char *data = "example";

    char *OutPut01 = AES_128_ECB_PKCS5Padding_Encrypt(data, AES_KEY);
    printf("%s,%d\n",OutPut01,strlen(OutPut01));

    char *data01 = "IDcqXMG9R6tp5Vqi1RO92A==";
    char *OutPut02 = AES_128_ECB_PKCS5Padding_Decrypt(data01,AES_KEY);
    printf("%d,%s\n",strlen(OutPut02),OutPut02);
    return 0;
}
