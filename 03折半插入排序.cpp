/*
算法基本思想：
（1）在一个有序序列v哈如一个数据
（2）设置三个下标 low hight mid.设置low = 1；hight = n-1，mid = (low+hight)/2
（2）然后将待插入的数据与mid比较，小于mid的值还是大于mid的值，重新设定low或者hight
1.什么是折半插入排序？

折半插入排序（binary insertion sort）是对插入排序算法的一种改进，所谓排序算法过程，就是不断的依次将元素插入前面已排好序的序列中。

换句话说，就是假设数组长度为8，那么我就插7次数据(第一个数据随便插入，所以就认为它就是一个有序数列，不执行插入操作)。每次插的时候，原有的数列已经是有序的了。当插完第八个数据时，排序也就结束了。
2.折半插入排序的思想

折半插入排序本质上就是二分法的应用。例如有一串有序数列，我将插入值与数列中间值比较。倘若大于中间值，说明数据应插入到中间值到最后一个值之间。倘若小于，说明数据应插入到第一个值和中间值之间。然后再对相应区间进行同样的二分操作。这种思想的应用主要是用于：排序、数据查找。
(1)应用于排序

此处我用了上界与下界来圈定插入数据的范围。上界与下界其实就是数列中最右侧与最左侧元素的下标。通过上界与下界的不断逼近来寻找插入的位置，当上界位于下界左侧时，循环结束。

举个栗子：
我现在要将6插入3、5、7、8中。
此时，下界在3这个位置，即下界为0；上界在8这个位置，即上界为3。中界即为（上界＋下界）／2，即为1.5 约等于 1，中界在5的位置。然后将6与中界位置的数值比较，发现6>5，说明6应该插入5的右侧，此时就将下界移动到7的位置，即下界为2。然后新的中界为2.5约等于2，即在7的位置，因为6<7,所以6应该插入到7的左侧，所以将上界移动到5这个位置。此时发现，上界在下界右侧，则说明位置已经找到了，所以只需将下界所对应的数值即7之后的数值向后移一位，然后在空出的位置插入6。这样就又构成了一个新的有序序列。
(2)应用于查找

此处我用的是递归的思想来构建查找的函数。首先你将所要查找的数字与数组中间的数值比较，倘若大于中间的数值，说明插入的数据位于中间的数值与最大的数值之间；倘若小于中间的数值，说明插入的数据位于最小的数值与中间的数值之间。倘若相等，就直接输出。然后在得到的对应区间执行相同的操作，如果该数据在数列中，则直到找到这个数据为止；如果不在该序列中，则输出不存在该值。

注意：查找也需要上界、下界。
因为只有设置上界与下界，才能知道数组查找完成。否则，倘若这个数不在数列中时，递归便无法停止，最终导致爆栈。
	
*/
#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>
void Insert_sort(int *pArr, int len);  // 声明二分法插入排序
void InsertSort_find2(int X, int *pArr, int low, int up);
int main(void) {
	int *pArr, len, X;  // pArr指数组首地址，len表长度， X表查找的数据
	printf("Please enter the number of elements:");
	scanf("%d", &len);
	pArr = (int*)malloc(len * sizeof(len));
	for (int i = 0; i < len; i++) {
		scanf("%d", &pArr[i]);
	}
	printf("Before sort: ");   // 输出排序前的数组
	for (int i = 0; i < len; i++)
		printf("%d ", pArr[i]);
	printf("\n");
	Insert_sort(pArr, len);  // 调用插入排序函数
	printf("After sort: ");   // 输出排序后的数组
	for (int i = 0; i < len; i++)
		printf("%d ", pArr[i]);
	printf("\n");
	printf("Enter the number you want to find:");
	scanf("%d", &X);
	InsertSort_find2(X, pArr, 0, len - 1);
	free(pArr);
	pArr = NULL;
	return 0;
}
void Insert_sort(int *pArr, int len) {  // 定义二分法插入排序的函数
	int temp, low, up;    // temp用于存放插入值， low表示下界， up表示上界
	for (int i = 1; i < len; i++) {
		temp = pArr[i];    // 保存插入值
		low = 0;   // 下界肯定为0
		up = i - 1;   // 上界就是除去插入值剩余元素的最大下标
		while (low <= up) {  // 当up移动到low左侧时，结束循环。注意，此处一定要带有等号，否则排序会失败，可以举例说明
			if (temp > pArr[(low + up) / 2])
				low = (low + up) / 2 + 1;  // 当插入值大于中间值，将下界移动到中界＋1的位置
			else
				up = (low + up) / 2 - 1; // 当插入值小于中间值，将上界移动到下界－1的位置
		} // 对low和up处理使得在决定好插入位置后up在low之前以跳出循环
		for (int j = i - 1; j >= low; j--)   //  该循环起到将元素后移的作用
			pArr[j + 1] = pArr[j];
		pArr[low] = temp;   // 将插入值插入
	}
	return;
}
void InsertSort_find2(int X, int *pArr, int low, int up) {
	if (up < low){
		printf("Can't find X\n");
		return;
	}
	int mid = (up + low) / 2;
	if (X == pArr[mid]) {
		printf("The index is %d\n", mid);
		return;
	}
	else if (X < pArr[mid]) {
		InsertSort_find2(X, pArr, low, mid - 1);
	}
	else {
		InsertSort_find2(X, pArr, mid + 1, up);
	}
}