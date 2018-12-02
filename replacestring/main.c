#include <stdio.h>
#include <stdlib.h>
#include <string.h>















//������src �ַ���Դ��sub��Ҫ�滻���ַ�����dst�����滻���ַ���
char*replace(char*src, char*sub, char*dst)
{
    //��¼��ǰָ��λ��
    int pos =0;
    //��¼ƫ��
    int offset =0;
    //�ַ�������
    int srcLen, subLen, dstLen;
    //��������
    char*pRet = NULL;
    //��ø��ַ�������
    srcLen = strlen(src);
    subLen = strlen(sub);
    dstLen = strlen(dst);
    //�����滻����ַ�������������dst�滻sub������Ӧ����srclen-sublen+dstlen��+1����'\0'λ��
    pRet = (char*)malloc(srcLen + dstLen - subLen +1);//(�ⲿ�Ƿ�ÿռ�)if (NULL != pRet)
    {
        //strstr����sub�ַ������ֵ�ָ�롣��ָ���ȥsrc��ַ���õ����λ��
        pos = strstr(src, sub) - src;
        //����src�ַ��������׵�ַ��ʼ��pos���ַ���
        memcpy(pRet, src, pos);
        //����ƫ��λ�õ�pos
        offset += pos;
        //����dst�����������С�
        memcpy(pRet + offset, dst, dstLen);
        //���¶�λƫ��
        offset += dstLen;
        //����src�У�sub�ַ���������ַ�����pRet��
        memcpy(pRet + offset, src + pos + subLen, srcLen - pos - subLen);
        //���¶�λƫ��
        offset += srcLen - pos - subLen;
        //�������ַ�����β���'\0'
        *(pRet + offset) ='\0';
    }
    //�����¹�����ַ���
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

