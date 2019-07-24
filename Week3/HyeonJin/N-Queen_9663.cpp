#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int count = 0;
int chess[226] = { -1, };

void search(int currentRow,int N);
int isPossible(int currentRow);

int main()
{
	int N;

	scanf("%d", &N);
	search(0, N);//0����� ����
	
	printf("%d\n", count);

	return 0;
}
//���� �ϳ��� �������鼭 ���� ��ġ�� �� �ִ� �� ã��
void search(int currentRow,int N)
{
	if (currentRow == N)//������� ���������� ������ ���� ��� ��ġ�Ͽ����Ƿ� count����
		count++;
	else {
		//ù����� ������ ����� ������ �ڸ� �˻�
		for (int i = 0; i < N; i++)
		{
			chess[currentRow] = i;//���� ���� ��� ���� �� �־
			if (isPossible(currentRow) == TRUE)//���� ���� �����ϴٸ� 
				search(currentRow + 1, N); //���������� �Ѿ
		}
	}
}
int isPossible(int currentRow)
{
	//�˻��Ϸ��� ���� ��� ������ ���� ��ġ��Ű��, �ش� ��ġ���� �� �Ʒ� �� �밢������ �� �����ϴ��� Ȯ��
	for (int i = 0; i < currentRow; i++) {
		//���� ���� ���� �����ϴ��� �˻�
		if (chess[i] == chess[currentRow])
			return FALSE;
		//���� �밢���� �����ϴ��� �˻�
		if (abs(chess[i] - chess[currentRow]) == abs(i - currentRow))
			return FALSE;
	}
	return TRUE;
}