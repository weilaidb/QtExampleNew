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

    if (data0&0x80000000)//判断是否为负数
        mimus = 1;

    exponent = (data0&0x7f800000)>>23;//获得指数位

    if ((exponent!=0) && (exponent!=0xff) && (exponent>=127)){ //判断是否为带整数的小数
        exponent -= 127;//指数去除偏移值
        data1 = ((data0&0x007fffff)+0x00800000) >> (23-exponent);//获得原始数据
    }else if (0 == exponent){//正负无穷数
        data1 = 0;
    }else if ((0xff == exponent) || (0x7e == exponent)){//不带小数的浮点数，这里有个bug
        data1 = data0&0x007fffff;
    }

    if (mimus)
        data1 = 0-data1;

    return data1;
}


struct FloatNode
{
    unsigned int mantissa : 23;	//尾数部分，隐藏了个位和小数点的有效数字
    unsigned int exponent : 8;	//阶码，也称指数位，用于存储科学计数法中的指数数据，并且采用移码存储
    unsigned int sign : 1;	        //符号位，0代表正，1代表负
};

int
Float_To_Int(float ft)
{
    FloatNode* fN = (FloatNode *)&ft;
    if (fN->exponent >= 127)
    {
        int sign = 1;	//初始假定该浮点数为正
        int mov = 23 - (fN->exponent - 127);
        int ret = (fN->mantissa | (1 << 23)) >> mov;
        if (fN->sign == 1)	//如果符号位为1
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

