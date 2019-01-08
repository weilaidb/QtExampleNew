#hello.s sample program to print hello world information
.section .data    #数据段声明
msg:
    .ascii "hello world!\n"    #要输出的字符串
    len=.-msg                        #字符串长度
	
# AREA Strcopy, CODE, READONLY
# EXPORT strcopy       ;声明strcopy为导出符号
# strcopy  
       # LDRB R2, [R1], #1    ;R1的值为源数据首地址
       # STRB R2, [R0], #1    ;R0的值为目标数据块首地址
	   # CMP R2, #0
       # BNE strcopy
       # MOV PC, LR       ;复制完毕，返回
	   # END
	   
.section .text    #代码段声明
# .global main
# main:
.global main     #指定入口函数


.section .text    #代码段声明
printmsg:
	movl $len, %edx               #第三个参数： 字符串长度
	movl $msg, %ecx               #第二个参数： hello world!字符串
	movl $1, %ebx                  #第一个参数： 输出文件描述符
	movl $4, %eax                  #系统调用号sys_write
	int $0x80                            #调用内核功能

main: 
	# b printmsg                                #函数在屏幕上输出hello world!
movl $len, %edx               #第三个参数： 字符串长度
movl $msg, %ecx               #第二个参数： hello world!字符串
movl $1, %ebx                  #第一个参数： 输出文件描述符
movl $4, %eax                  #系统调用号sys_write,4为x86的函数sys_write
int $0x80                            #调用内核功能

movl $len, %edx               #第三个参数： 字符串长度
movl $msg, %ecx               #第二个参数： hello world!字符串
movl $1, %ebx                  #第一个参数： 输出文件描述符
movl $4, %eax                  #系统调用号sys_write
int $0x80                            #调用内核功能



# b test_asm


#下面为退出程序代码
movl $0, %ebx                #第一个参数： 退出返回码
movl $1, %eax                #系统调用sys_exit
int $0x80                        #调用内核功能

