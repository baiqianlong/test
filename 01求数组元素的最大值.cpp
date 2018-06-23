#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
using namespace std;

int main(void)
{

	int a[10];
	int i;
	int tem;//定义临时变量，用来存储最大值
	cout << "请输入10个整形数字：" << endl;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	tem = a[0];
	for (i = 0; i < 10; i++)
	{
		if (tem < a[i])
		{
			tem = a[i];
		}
	}
	printf("最大的数字是：%d", tem);
	system("pause");
	return 0;
}
/*
请输入10个整形数字：
2 1 2 5 4 5 6 5 22 5
最大的数字是：22请按任意键继续. . .

程序目的：现在有十个数据，求出其中的最大值

一般思路：设置一个临时变量，将第一个元素赋值给它，然后分别与后面的数据进行比较
，当比后面的数据小，就把后面的数据赋值给它，最后，临时变量t里面存放着最大的数据。
Sunrise于东北电力大学第二教学楼1121实验室
	
*/