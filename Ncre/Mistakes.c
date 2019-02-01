#include<stdio.h>

//不能将s所指字符串正确复制到t所指存储空间
void Add_Self(void) //自增自减运算符
{	
	do	
	{
		*t ++ = *s ++;
	}
	while (*s);  
	// 当*s = '\0' 时，while(*s)跳出循环，这样导致字符串结束标志'\0'没有复制给*t，造成*t不完整
}

void Some_if(void) //if语句的几种形式
{
	int a = 0, b = 0, c = 0, d = 0;
	if(a = 1)
		b = 1;
	c = 2;
	else
		d = 3;
	printf("%d, %d, %d, %d\n", a, b, c, d);
	//if与else之间多了语句c = 2; ，所以会出现else语句位置错误的编译失败提示
}



