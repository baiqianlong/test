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
	int tem;//������ʱ�����������洢���ֵ
	cout << "������10���������֣�" << endl;
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
	printf("���������ǣ�%d", tem);
	system("pause");
	return 0;
}
/*
������10���������֣�
2 1 2 5 4 5 6 5 22 5
���������ǣ�22�밴���������. . .

����Ŀ�ģ�������ʮ�����ݣ�������е����ֵ

һ��˼·������һ����ʱ����������һ��Ԫ�ظ�ֵ������Ȼ��ֱ����������ݽ��бȽ�
�����Ⱥ��������С���ͰѺ�������ݸ�ֵ�����������ʱ����t���������������ݡ�
Sunrise�ڶ���������ѧ�ڶ���ѧ¥1121ʵ����
	
*/