/* ================================================================================================
 * Baekjoon Online Judge
 *		2618 - ������
 * � ������ �߽ɰ��� N���� �������� ���ο� N���� ���Ϲ��� ���η� �����Ǿ� �ִ�.
 * �� ���ÿ��� �� ���� �������� ������ �� ���� ������1�� ������2�� �θ���.
 * ó������ �׻� ������1�� (1, 1)�� ��ġ�� �ְ� ������2�� (N, N)�� ��ġ�� �ִ�.
 * ���� ���ο����� ó���� ����� ������ �� ����� �߻��� ��ġ�� �� ���� ������ �� �ϳ��� �˷� �ְ�,
 * ���� ���� �������� �� ��ġ�� ���� ���� ���� ���� �̵��Ͽ� ����� ó���Ѵ�.
 * (�ϳ��� ����� �� ���� �������� ó���Ѵ�.)
 * ó���ؾ� �� ��ǵ��� ������� �־��� ��,
 * �� ���� �������� �̵��ϴ� �Ÿ��� ���� �ּ�ȭ �ϵ��� ��ǵ��� �ñ�� ���α׷��� �ۼ��Ͻÿ�
 * ------------------------------------------------------------------------------------------------
 * �� ���������� �Ÿ��� �����س��� ������ ������.
 * �����ߴµ� Ʋ���� ��
 * �׸��� �� �������� ������ �� �־, ��ü������ ������ ���� �ִ�.
 * ���� ���ø����� ������
 *
 * �׷� ���� ��ʹ�
 * ���� �� ������ ����� ����� ���� ����
 * (�� �� ��� �̵��ߴ� �����ϰ�, ���� ������ �׽�Ʈ���̽����� �Ųٷ� �Ž����ö��)
 * �ٵ� �ð��ʰ��� �޸������̼��� ��� �ؾ����� �𸣰ڴ�
 * Ʈ���̵̽�...
 * �޸������̼� �ϱ� ���� ȣ�� ���� Ȯ��.
 * �ߺ�����ϴ� �κп� �޸������̼��� �����ϱ����� ���� ��ǥ�� ���ڷ� �ѱ�� ��Ŀ���
 * ��ǥ�迭(cases)�� �ε����� �Ѱ���
 * dp[a][b]�� ���� �������� a, b�� ���� �� ���� ����� �ذ��ϱ����� ���
 * ------------------------------------------------------------------------------------------------ */

#include <stdio.h>
#include <malloc.h>

inline int mini(int a, int b) {
	return a & ((a - b) >> 31) | b & (~(a - b) >> 31);
}
inline int maxi(int a, int b) {
	return b & ((a - b) >> 31) | a & (~(a - b) >> 31);
}

inline int absi(int x) {
	return (x ^ (x >> 31)) - (x >> 31);
}

int getDistance(int ax, int ay, int bx, int by) {
	return absi(ax - bx) + absi(ay - by);
}

int resolve(int w, int **dp, int **cases, int **record, int a, int b) {
	int level = maxi(a, b) + 1;

	if (level == w)
		return 0;

	else if (dp[a][b] != -1) {
		return dp[a][b];
	}

	int cx = cases[level][0];
	int cy = cases[level][1];
	int dis1 = resolve(w, dp, cases, record, level, b) + getDistance(cases[a][0], cases[a][1], cx, cy);
	int dis2 = resolve(w, dp, cases, record, a, level) + getDistance(cases[b][0], cases[b][1], cx, cy);

	dp[a][b] = mini(dis1, dis2);
	if (mini(dis1, dis2) ^ dis1) {
		record[a][b] = 2;
	}
	else {
		record[a][b] = 1;
	}

	return dp[a][b];
}

int main(void)
{
	int n;
	int w;
	int x, y;
	scanf("%d %d", &n, &w);

	int **dp = (int **)malloc((w + 1) * sizeof(int *));
	dp[0] = (int *)calloc(w + 1, sizeof(int));
	dp[1] = (int *)calloc(w + 1, sizeof(int));
	for (int j = 0; j < w + 2; j++) {
		dp[0][j] = -1;
		dp[1][j] = -1;
	}

	int **cases = (int **)malloc((n + 2) * sizeof(int *));
	cases[0] = (int *)malloc(2 * sizeof(int));
	cases[1] = (int *)malloc(2 * sizeof(int));
	cases[0][0] = 1;
	cases[0][1] = 1;
	cases[1][0] = n;
	cases[1][1] = n;
	for (int i = 2; i < w + 2; i++) {
		scanf("%d %d", &x, &y);
		cases[i] = (int *)malloc(2 * sizeof(int));
		cases[i][0] = x;
		cases[i][1] = y;
		dp[i] = (int *)malloc((w + 1) * sizeof(int));
		for (int j = 0; j < w + 1; j++) {
			dp[i][j] = -1;
		}
	}
	int **record = (int **)malloc((w+1) * sizeof(int *));
	for (int i = 0; i < w+2; i++) {
		record[i] = (int *)calloc(w+1, sizeof(int));
	}
	int total_move = resolve(w + 2, dp, cases, record, 0, 1);

	printf("%d\n", total_move);

	for (int x = 0, y = 1; maxi(x, y) + 1 < w + 2; ) {
		printf("%d\n", record[x][y]);
		if (record[x][y] == 2)
			y = maxi(x, y) + 1;
		else
			x = maxi(x, y) + 1;
	}

	return 0;
}