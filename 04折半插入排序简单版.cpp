#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
using namespace std;

void Sort(int num[], int n);
int main(void)
{
	int n=5, i;
	int num[50] = {12,26,55,669,88};
	
		Sort(num, n);                          
		for (i = 1; i <= n; i++)
		{
			printf("%d", num[i]);
			printf("\n");
		}
	
	system("pause");
	return 0;
}

void Sort(int num[], int n)
{
	int low, hight, mid, i, j, m;
	for (i = 2; i <= n; i++)
	{
		num[0] = num[i];//��num[i]��ֵ��ʱ�����num[0]
		low = 1;
		hight = n - 1;
		while (low <= hight)
		{
			mid = (hight + low) / 2;
			if (num[0] < num[mid])//�������
			{
				hight = mid - 1;//������ڵͰ���
			}
			else
			{
				low = mid + 1;//������ڸ߰���
			}
		}
		for (j = i - 1; j > hight + 1; j--)
		{
			num[j + 1] = num[i];//���ݣ���¼������
		}
		num[hight + 1] = num[0];
	}
}
