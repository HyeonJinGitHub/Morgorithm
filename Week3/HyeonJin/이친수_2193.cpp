#include <stdio.h>
//�Ǻ���ġ �Լ��� ������ ����
int main()
{
	int N;
	long long result[91] = { 0 };//N�� �ִ밪�� 90�̱� ������ 90��°�� �Ǻ���ġ �Լ��� ����ϱ� ���ؼ� long longŸ�� ����

	result[1] = 1;
	result[2] = 1;
	result[3] = 2;
	//1,2,3 �ε��� �ʱⰪ ����
	scanf("%d", &N);
	for (int i = 4; i <= N; i++)
	{
		//��Ģ �߰�
		result[i] = result[i - 1] + result[i - 2];
	}
	printf("%lld\n", result[N]);//���

	return 0;
}