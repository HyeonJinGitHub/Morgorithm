#include <stdio.h>
//�Ǻ���ġ �Լ� f(x) = f(x-1) + f(x-2)
int main()
{
	int T;
	int N;
	scanf("%d", &T); 

	for (int i = 0; i < T; i++)
	{
		int tmp, current = 1, last = 0; //tmp �� current���� ������ �ӽú���
		//current �� ���� ��ġ�� �Ǻ���ġ ��, last�� ���� �Ǻ���ġ ��
		scanf("%d", &N);
		if (N == 0)//0�� ��� 
		{
			printf("%d %d\n", current, last); // 0: 1 1: 0
		}
		else if (N == 1)//1�� ���
		{
			printf("%d %d\n", last, current); // 0: 0 1: 1
		}
		else//2 �̻��� ���
		{
			for (int j = 2; j <= N; j++)
			{
				tmp = current;//tmp�� current�� �ӽ� ����
				current += last; // f(x) = f(x-1) + f(x-2)
				last = tmp; // last�� current�� �ٲ���
			}
			printf("%d %d\n", last, current); //f(N)���� 0�� ������ f(N-1) 1�� ������ f(N)
		}
	}
	return 0;
}