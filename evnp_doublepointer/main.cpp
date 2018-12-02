#include <iostream>

using namespace std;

int test(int argc, char **argv, char **envp)
{
    printf("first envp:%s, %p\n", *envp, envp);
    printf("second envp:%s,%s, %s, %p\n", *envp++, *envp++, *envp, envp);
    printf("third envp:%s, %p\n", *envp, envp);
    /**
     * 指针先算偏移++，再取值，++优先级*比高, *envp++ <==> *(envp++)
     */
    while(*envp++ != NULL)
    {
        printf("envp:%s, %p\n", *envp, envp);
    }
    printf("last envp:%s,%p\n", *envp, envp);


//    简单总结：

//    printf函数参数执行的问题：

//    VC6.0：                     从右到左

//    linux，dev-c++：       从左到右



//    当printf函数混合自增自减的时候

//    对于VC6.0而言：将printf函数当作后续运算符（对前置后置而言）

//    linux，dev-c++：请无视后续运算符（对前置后置而言），就当作是没有
//    ---------------------
//    作者：L未若
//    来源：CSDN
//    原文：https://blog.csdn.net/msdnwolaile/article/details/50846977
//    版权声明：本文为博主原创文章，转载请附上博文链接！

    //    Ｃ语言的printf函数处理的参数顺序是从右向左的
    int a = 1, b = 2, c = 3;

    printf("(a + b + c)的值是%d, b的值是%d, c的值是%d\n", a+b+c, (b = b + 1), (c = c + 2));


    int i = 3;
    printf("%d   ,   %d     ,%d\n",i++, ++i, i);
    printf("i is %d\n", i);

}

int main()
{
    char *env[] =  {
        "str1","str2","str3","\0",NULL,
    };
    cout << "Hello World!" << endl;
    test(0, NULL, env);
    return 0;
}
