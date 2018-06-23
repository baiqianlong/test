#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>  
#include<stdlib.h>  
#include<assert.h>  
void rank(int arr[], int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int array[9] = { 9, 8, 7, 4, 16, 5, 6, 3, 1 };
	int len = sizeof(array) / sizeof(array[0]);
	int i = 0;
	rank(array, len);
	for (i = 0; i < len; i++)
	{
		printf("%d", array[i]);
		printf(" ");
	}
	system("pause");
	return 0;
}