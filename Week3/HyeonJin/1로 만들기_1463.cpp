#include <stdio.h>

int result[1000002] = { 0 };

int main()
{
	int N;
	
	result[1] = 0;
	result[2] = 1;
	result[3] = 1;
	//�迭 �ε��� 1 2 3 �ʱⰪ ����
	scanf("%d", &N);//�Է�
	for (int i = 4; i <= N; i++)//4 �̻��� ���
	{
		int temp1 = 500001, temp2 = 500001, temp3 = 500001;//������� ���� �� ���� ū �� �ӽ÷� ����
		int max = 500000;//������� ���� �� ������ temp ���ٴ� ���� �� ����
		if (i % 3 == 0)
		{
			//3���� ������ ��� temp1�� result[i/3] ��°���� 1 ū �� ����
			temp1 = result[i / 3] + 1;
		}
		if (i % 2 == 0 )
		{
			//2���� ������ ��� temp2�� result[i/2] ��°���� 1 ū �� ����
			temp2 = result[i / 2] + 1;
			
		}
		//temp3�� result[i-1] ��°���� ū �� ������ ����
		temp3 = result[i - 1] + 1;
		//��
		if (max > temp1) //temp1 ��, temp1�� ���� �ٲ� ��� �� i % 2 == 0 �� ���
			max = temp1;
		if (max > temp2) // temp2 ��, temp2�� ���� �ٲ� ���, �� i%3 == 0 �� ���
			max = temp2;
		if (max > temp3) // temp3 ��, temp3�� ������ ����� 
			max = temp3;

		//���� �񱳸� ���ؼ� ���� ���� �� ����
		result[i] = max;
	
	} 
	printf("%d\n", result[N]);//���

	return 0;
}