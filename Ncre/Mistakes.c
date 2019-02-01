#include<stdio.h>

//不能在定义结构体的同时又用结构体类型名定义变量

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

void Switch_m1(void) //switch语句
{
	int i, n;
	for(i = 0; i < 8; i ++)
	{
		n = rand() % 5;
		switch(n)
		{
			case 1:
			case 3:	printf("%d \n", n); break;
			case 2:
			case 4:	printf("%d \n", n); continue;
			case 0: exit(0);
		}
		printf("%d \n", n);
	}
	//case常量表达式只是起语句标号作用，并不是该处进行条件判断。在执行switch语句时
	//根据switch的表达式，找到与之匹配的case语句，就从此case子句执行下去。不在执行判断
	//直到碰到break或函数结束为止
}

void Switch_m2(void)
{
	//defult在switch语句中可以省略
	//switch并非每个case后都需要break语句
}

void Point_m(void) //指针(不能将一个整数直接赋值给指针变量做地址)
{
	int *a, *b, *c, *d;
	a = b = c = (int *)malloc(sizeof(int));
	*a = 1;
	*b = 2;
	*c = 3;
	a = b;
	printf("%d, %d, %d \n", *a, *b, *c);
	//输出为3, 3, 3
	//malloc 函数动态非配一个整型的内存空间，然后把函数返回的地址用(int *)
	//强制类型转换为整型指针，再把它赋给a，b，c
	//即让指针变量a，b，c都指向刚申请的内存空间
	//所以只有最后一个赋值语句*c = 3的值保留在了该空间内
	//因为a，b，c三个指针变量均指向该空间，所以打印该空间内的数值为3
}

void Point_run(void) //函数调用与返回值
{
	int add(int a, int b)
	{
		return (a+b);
	}
	int main()
	{
		int k, (*f)(), a = 5, b = 10;
		f = add;
		//k = f(a, b);  k = add(a, b);  k = (*f)(a, b);
		//k = *f(a, b)表示调用后返回一个指向整型数据的地址指针
		//即该函数的返回值为指针类型，所以不能将其赋给整型变量k
	}
}

void Mult_Array(void) // 多维数组
{
	char str[][20] = {"One*World!","One*Dream!"}, *p = str[1];
	printf("%d, ", strlen(p));
	printf("%s\n", p);
	//Output: 10, One*Dream!
	//p是指向二维数组第二行One*Daeam!的数组指针，所以长度为10
	//打印输出的也是该字符
}



