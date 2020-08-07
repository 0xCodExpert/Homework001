/*
 *  int arr[3][3] = {{1,15,4}, {8,10,16},{2,7,20}}����
 *  �ִ밪�� ã�� �Լ� �����
 *  
 *  1. Key : ���� for�� ���, �迭 ������ ��� 
 *  2. ����: �ִ밪 ���� ���� 0���� �ʱ�ȭ, for�� ���� count ���� x2
 *           count max�� define���� ����
 *  3. �ִ밪 ���ϴ� ���� �Լ��� �����(�Ű����� const ����) 
*/

#include <stdio.h>

#define CNT_MAX 3

int Value_Max(const int(*)[3]);

int main(void)
{
	const int arr[3][3] = {
		{1, 15, 4}, 
		{8, 10, 16}, 
		{2, 7, 20}
	};

	printf("MAX VALUE: %d\r\n", Value_Max(arr));	
	
	return 0;
}

int Value_Max(const int(*pArr)[3])
{
	int i, j;
	int max = 0; //���� �� ����

	for(i = 0; i < CNT_MAX; i++)
	{
		for(j = 0; j < CNT_MAX; j++)
		{
			if(max < pArr[i][j])	
			{
				max = pArr[i][j];
			}
		}
	}

	return max;
}