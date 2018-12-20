#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define ABS(x) (((x) > 0) ? (x):(-x))
#define MULNUM (10000)



int ftoi(float *para)
{
    unsigned int data0=0,data1=0,exponent=0;
    unsigned int i=0;
    char mimus=0;

    memcpy(&data0,para,4);

    if (data0&0x80000000)//�ж��Ƿ�Ϊ����
        mimus = 1;

    exponent = (data0&0x7f800000)>>23;//���ָ��λ

    if ((exponent!=0) && (exponent!=0xff) && (exponent>=127)){ //�ж��Ƿ�Ϊ��������С��
        exponent -= 127;//ָ��ȥ��ƫ��ֵ
        data1 = ((data0&0x007fffff)+0x00800000) >> (23-exponent);//���ԭʼ����
    }else if (0 == exponent){//����������
        data1 = 0;
    }else if ((0xff == exponent) || (0x7e == exponent)){//����С���ĸ������������и�bug
        data1 = data0&0x007fffff;
    }

    if (mimus)
        data1 = 0-data1;

    return data1;
}


struct FloatNode
{
    unsigned int mantissa : 23;	//β�����֣������˸�λ��С�������Ч����
    unsigned int exponent : 8;	//���룬Ҳ��ָ��λ�����ڴ洢��ѧ�������е�ָ�����ݣ����Ҳ�������洢
    unsigned int sign : 1;	        //����λ��0��������1����
};

int
Float_To_Int(float ft)
{
    FloatNode* fN = (FloatNode *)&ft;
    if (fN->exponent >= 127)
    {
        int sign = 1;	//��ʼ�ٶ��ø�����Ϊ��
        int mov = 23 - (fN->exponent - 127);
        int ret = (fN->mantissa | (1 << 23)) >> mov;
        if (fN->sign == 1)	//�������λΪ1
            sign = -1;
        ret *= sign;
        return ret;
    }
    else
        return 0;
}


int main()
{
    float f=-5.75;
    printf("f=%d,f=%f\n",(int)f,f);
    printf("f=%u,f=%f\n",(unsigned int)f,f);
    printf("f=%d,f=%f\n",ftoi(&f),f);
    printf("f=%d,f=%f\n",Float_To_Int(f),f);

    printf("mf=%d,mf=%f\n",(int)ABS(f) * MULNUM ,ABS(f) * MULNUM);
    printf("mf=%u,mf=%f\n",(unsigned int)ABS(f) * MULNUM,ABS(f) * MULNUM);


    cout << "Hello World!" << endl;
    return 0;
}

