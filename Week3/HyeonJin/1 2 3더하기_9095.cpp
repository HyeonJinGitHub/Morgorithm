#include <stdio.h>

int main()
{
	int T;
	int n;
	int result[11] = { 0 };//n �ִ밪 10
	scanf("%d", &T);

	result[1] = 1;
	result[2] = 2;
	result[3] = 4;
	//�迭 �ε��� 1 2 3 �ʱⰪ ����
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);//�Է�
		for (int j = 4; j <= n; j++)//�Է°� 4 �̻��� ���
		{
			//��Ģ �߰�
			result[j] = result[j - 1] + result[j - 2] + result[j - 3];
		}
		printf("%d\n", result[n]);//���
	}
	return 0;
}