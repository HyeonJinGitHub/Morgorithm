/* ================================================================================================
 * Baekjoon Online Judge
 *		1915 - ���� ū ���簢��
 *
 * time limit per test : 2 seconds
 * memory limit per test : 128 megabytes
 * standard input/standard output
 *
 * n��m�� 0, 1�� �� �迭�� �ִ�. �� �迭���� 1�� �� ���� ū ���簢���� ũ�⸦ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
 * 
 *		0	1	0	0
 *		0	1	1	1
 *		1	1	1	0
 *		0	0	1	0
 * ���� ���� ���������� ����� 2��2 �迭�� ���� ū ���簢���̴�.
 * ------------------------------------------------------------------------------------------------ */

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n, m;

	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n + 1, std::vector<int>(m + 1, 0));

	int c;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &c);

			if (c) {
				v[i][j] = 1 + std::min({ v[i - 1][j - 1], v[i][j - 1], v[i - 1][j] });
				max = std::max(max, v[i][j]);
			}
		}
	}

	std::cout << max * max;

	return 0;
}