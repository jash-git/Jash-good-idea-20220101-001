#include <stdio.h>
#include <stdlib.h>

#include "Arduino_Base64_C_lib.h"

int main()
{
    //驗證URL: https://www.base64encode.org/
    char inputbuf []="123456789";
    int output_len;
    char *outputbuf='\0';
    int output_len01;
    char *outputbuf01='\0';
    output_len = b64_encode (inputbuf, (sizeof(inputbuf)-1));// (sizeof(inputbuf)-1) 不要計算字串結束符號
    outputbuf = (char *) malloc(sizeof(char) * output_len);
    get_encode(outputbuf);
    printf("base64_en(\"123456789\") => %s\n",outputbuf);

    //驗證URL: https://www.base64decode.org/
    output_len01 = b64_decode (outputbuf, strlen(outputbuf));//strlen(outputbuf) 才能計算指標字串長度
    outputbuf01 = (char *) malloc(sizeof(char) * output_len01);
    get_decode(outputbuf01);
    printf("base64_dn(\"%s\") => %s\n",outputbuf,outputbuf01);

    free(outputbuf);
    free(outputbuf01);
    return 0;
}
