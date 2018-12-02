#include <stdio.h>
#include <stdlib.h>
#include <string.h>















//参数，src 字符串源，sub想要替换的字符串，dst用来替换的字符串
char*replace(char*src, char*sub, char*dst)
{
    //记录当前指针位置
    int pos =0;
    //记录偏移
    int offset =0;
    //字符串长度
    int srcLen, subLen, dstLen;
    //返回内容
    char*pRet = NULL;
    //求得各字符串长度
    srcLen = strlen(src);
    subLen = strlen(sub);
    dstLen = strlen(dst);
    //申请替换后的字符串缓冲区。用dst替换sub，所以应该是srclen-sublen+dstlen，+1流出'\0'位置
    pRet = (char*)malloc(srcLen + dstLen - subLen +1);//(外部是否该空间)if (NULL != pRet)
    {
        //strstr查找sub字符串出现的指针。该指针减去src地址。得到相对位置
        pos = strstr(src, sub) - src;
        //拷贝src字符串，从首地址开始，pos个字符。
        memcpy(pRet, src, pos);
        //增加偏移位置到pos
        offset += pos;
        //拷贝dst到返回内容中。
        memcpy(pRet + offset, dst, dstLen);
        //重新定位偏移
        offset += dstLen;
        //拷贝src中，sub字符串后面的字符串到pRet中
        memcpy(pRet + offset, src + pos + subLen, srcLen - pos - subLen);
        //重新定位偏移
        offset += srcLen - pos - subLen;
        //最后添加字符串结尾标记'\0'
        *(pRet + offset) ='\0';
    }
    //返回新构造的字符串
    return pRet;
}


void replacestring()
{
    char string[1024] = "port is $1, porttype is $2";
    char tosave[128] = "nihaomaaaaaaaaaaaaaa bbbbbbbbbbbbbbbbbbbbbbbbb";
    printf("string is :%s\n", string);
    char buf[128];
    int num = 1;
    snprintf(buf, sizeof(buf), "$%d", num);
    char *result = replace(string, buf, tosave);
    printf("result is :%s\n", result);

    //save string and free mem
    snprintf(string, sizeof(string), "%s",result);
    free(result);

    num = 2;
    snprintf(buf, sizeof(buf), "$%d", num);
    result = replace(string, buf, tosave);
    printf("result is :%s\n", result);
    free(result);

}

int main(void)
{
    printf("Hello World!\n");
    replacestring();

    return 0;
}

