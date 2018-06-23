#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>  
#include<stdlib.h>  
#include<assert.h>  
void rank(int arr[], int len)
{
	assert(arr);
	assert(len);
	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
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
/*
冒泡排序法：一趟一趟的将两个相邻的数进行交换如果有10个数则需要排9躺，如果是从大到小输出则需要每次将后一个数和前一个数进行比较将较大的数赋值给钱一个数，将较小的数赋值给后一个数，其实就是两个数交换，那么第一趟交换完毕后，最小的数便出现在了数组的最后面，然后进行第二趟的比较时则要对余下的前9个数进行比较，9趟比较完成后则数组也已经排好序。

选择排序法：10个数则是需要排9次，若按降序排列，第一次比较：则是将数组的第一个元素与数组中从第二个元素开始到最后的元素进行比较找到最大的数记录下来然后将值赋值给数组的第一个元素，然后进行第二次比较：则是将数组的第二个元素与数组中从第三个元素开始到最后的元素进行比较，找最大的数记录下来将值赋值给数组的第二个元素。。。依次循环找完
	
*/