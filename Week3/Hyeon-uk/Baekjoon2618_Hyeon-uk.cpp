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
 * ------------------------------------------------------------------------------------------------ */
 
#include <stdio.h>
#include <malloc.h>

inline int mini(int a, int b) {
	return a & ((a - b) >> 31) | b & (~(a - b) >> 31);
}

int absi(int x) {
	return (x ^ (x >> 31)) - (x >> 31);
}

inline int abs(int x) {
	return x < 0 ? -x : x;
}

int getDistance(int ax, int ay, int bx, int by) {
	return abs(ax - bx) + abs(ay - by);
}

int resolve(int level, int w, int **cases, int *record, int x1, int y1, int x2, int y2) {
	if (level == w)
		return 0; 
	for (int i = 0; i < level; i = -~i) {
		printf("\t");
	}
	printf("Current case : %d (%d, %d)\n", level, cases[level][0], cases[level][1]);
	printf("police1 pos : (%d, %d)\n", x1, y1);
	printf("police1 pos : (%d, %d)\n", x2, y2);
	int cx = cases[level][0];
	int cy = cases[level][1];
	int dis1 = resolve(level + 1, w, cases, record, cx, cy, x2, y2) + getDistance(x1, y1, cx, cy);
	int dis2 = resolve(level + 1, w, cases, record, x1, y1, cx, cy) + getDistance(x2, y2, cx, cy);

	int ret = mini(dis1, dis2);
	for (int i = 0; i < level; i++) {
		printf("\t");
	}
	printf("%d : %d\n", 1, getDistance(x1, y1, cx, cy));
	for (int i = 0; i < level; i++) {
		printf("\t");
	}
	printf("%d : %d\n", 2, getDistance(x2, y2, cx, cy));
	for (int i = 0; i < level; i++) {
		printf("\t");
	}
	printf("ret : %d\n", ret);
	return ret;
}

int main(void)
{
	int n;
	int w;
	int x, y;
	scanf("%d %d", &n, &w);

	int **cases = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < w; i++) {
		scanf("%d %d", &x, &y);
		cases[i] = (int *)malloc(2 * sizeof(int));
		cases[i][0] = x;
		cases[i][1] = y;
	}
	int *record = (int *)calloc(w, sizeof(int));

	int total_move = resolve(0, w, cases, record, 1, 1, n, n);

	printf("%d\n", total_move);

	for (int i = 0; i < w; i++) {
		printf("%d\n", record[i]);
	}

	return 0;
}