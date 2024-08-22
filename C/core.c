#include <stdio.h>

void f(int *p)  //！！！！！！！！！！"*p"在刚被定义的时候代表着指针，但之后*p代表着指针所指向的变量。
/*
void f(int *p)是一个参数为“指向整型数据的指针 int *p” 函数的定义。
*/
{
	printf("p=%p\n",p);
	//在这里打印出指针p的值，也就是变量i的“地址”。
	printf("*p=%d\n",*p);
	//在这里打印出指针p所指向的值，也就是指针p指向的那个变量i的值。
	
	*p=26;
	//对*p进行重新赋值
} 


void g(int k)
//以一个整数k作为变量的函数 %d是十进制
{
	printf("k=%d\n",k);
} 


int main(void){
	int i=6;
	printf("&i=%p\n",&i); //输出的是i的地址，和函数没有关系
	
	f(&i);//调用函数f，打印i的地址（或者是指针p的值）	
	g(i); 
	return 0;
}