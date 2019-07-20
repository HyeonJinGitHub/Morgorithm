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
 * ------------------------------------------------------------------------------------------------ */
 
#include <stdio.h>
#include <malloc.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int getDistance(int src, int dst) {
	int res = dst - src;
	return res < 0 ? -res : res;
}

int main(void)
{
	int n;
	int w;
	scanf("%d %d", &n, &w);

	int **distance_map = (int **)calloc(n + 1, sizeof(int *));
	distance_map[0] = (int *)calloc(n + 1, sizeof(int));
	
	for (int i = 1; i <= n; i++) {
		distance_map[i] = (int *)calloc(n + 1, sizeof(int));
		for (int j = 1; j <= n; j++) {
			distance_map[i][j] = max(distance_map[i][j - 1], distance_map[i - 1][j]) + 1;
		}
	}

	int *record = (int *)malloc(w * sizeof(int));

	int x, y;
	int dis1, dis2;
	int x1 = 1, y1 = 1;
	int x2 = n, y2 = n;
	int total_move = 0;
	for (int i = 0; i < w; i++) {
		scanf("%d %d", &x, &y);
		dis1 = getDistance(distance_map[y][x], distance_map[y1][x1]);
		dis2 = getDistance(distance_map[y][x], distance_map[y2][x2]);
		if (dis1 < dis2) {
			y1 = y;
			x1 = x;
			total_move += dis1;
			record[i] = 1;
		}
		else {
			y2 = y;
			x2 = x;
			total_move += dis2;
			record[i] = 2;
		}
	}
	printf("%d\n", total_move);
	for (int i = 0; i < w; i++) {
		printf("%d\n", record[i]);
	}

	return 0;
}