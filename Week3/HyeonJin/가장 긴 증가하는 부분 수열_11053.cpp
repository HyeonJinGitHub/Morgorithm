#include <stdio.h>

int main()
{
	int N;
	int num[1001] = { 0, };
	int result[1001] = { 0, };
	int count = 0;
	scanf("%d", &N);//�迭 ���� �Է�

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);//�迭 �� �Է�
	}
	//result �迭�� 1�� �ε��� �� ����
	result[1] = num[1];
	//2�� �ε������� ����
	for (int i = 2; i <= N; i++)//i�� �ε��� 2������ N���� ������������ num �迭 Ž��
	{
		for (int j = i - 1; j >= 1; j--)//j�� �ε��� i-1��°���� 1������ ������������ result�迭 Ž��
		{
			if (result[j] == 0)//result �迭�� 0���� �ʱ�ȭ �߱� ������ �ε��� ���� 0�� ��� �Ѿ
				continue;
			if (num[i] > result[j])//i��° ���� j��° ������ Ŭ ���
			{
				result[j + 1] = num[i];//j+1��° result ���� i��° num������ ����
				break;
			}
			else if (j == 1) //������ �����Ͽ��� ��� 1�� �ε����� result �迭 ���� num[i]������ �ٲ���
				result[j] = num[i];	
		}
	}
	for (int i = 1; i <= N; i++)
	{
		
		//result �迭�� 0�� �ƴ� ���� ���� ����
		if (result[i] != 0)
			count++;
	}

	printf("%d", count);//���

	return 0;
}
