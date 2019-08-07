/* ================================================================================================
 * Baekjoon Online Judge
 *		11657 - Ÿ�Ӹӽ�
 *
 * time limit per test : 1 seconds
 * memory limit per test : 256 megabytes
 * standard input/standard output
 *
 * N���� ���ð� �ִ�. 
 * �׸��� �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� ������ M�� �ִ�. 
 * �� ������ A, B, C�� ��Ÿ�� �� �ִµ�, 
 * A�� ���۵���, B�� ��������, C�� ������ Ÿ�� �̵��ϴµ� �ɸ��� �ð��̴�. 
 * �ð� C�� ����� �ƴ� ��찡 �ִ�. C = 0�� ���� ���� �̵��� �ϴ� ���, 
 * C < 0�� ���� Ÿ�Ӹӽ����� �ð��� �ǵ��ư��� ����̴�.
 *
 * 1�� ���ÿ��� ����ؼ� ������ ���÷� ���� ���� ���� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
 *
 * ------------------------------------------------------------------------------------------------
 *
 * Bellman-Ford��s algorithm
 *		optimal substructure
 *			�ִ� ����� �κ� ��� ���� �ִܰ��
 *		time complexity : O(VE)
 *
 * ------------------------------------------------------------------------------------------------ */

#include <stdio.h>

#define INFINITY 1073741824

typedef struct {
	int source;
	int destination;
	int weight;
} Edge;

int bellman_ford(const Edge *e, int *distance, const int n, const int m) {
	int i, j;
	for (i = 1; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (distance[e[j].source] != INFINITY) {
				if (distance[e[j].destination] > distance[e[j].source] + e[j].weight) {
					distance[e[j].destination] = distance[e[j].source] + e[j].weight;
				}	
			}
		}
	}
	// Check negative cycle
	for (j = 0; j < m; j++) {
		if (distance[e[j].source] != INFINITY) {
			if (distance[e[j].destination] > distance[e[j].source] + e[j].weight) {
				return 0;
			}
		}
	}
	return 1;
}

int main(void) {
	int n, m;
	int i, j;
	int a, b, c;
	Edge e[6000];
	int distance[501];
	scanf("%d %d", &n, &m);

	for (i = 2; i <= n; i++) {
		distance[i] = INFINITY;
	}
	distance[1] = 0;

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &e[i].source, &e[i].destination, &e[i].weight);
	}

	if (bellman_ford(e, distance, n, m)) {
		for (i = 2; i < n + 1; i++) {
			printf("%d\n", distance[i] == INFINITY ? -1 : distance[i]);
		}
	}
	else {
		printf("%d", -1);
	}
}