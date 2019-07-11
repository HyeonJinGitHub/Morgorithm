/* ================================================================================================
 * Baekjoon Online Judge
 *		6603 - �ζ�
 *
 * time limit per test : 1 seconds
 * memory limit per test : 128 megabytes
 * standard input/standard output
 *
 * ���� �ζǴ� {1, 2, ..., 49}���� �� 6���� ����.
 * �ζ� ��ȣ�� �����ϴµ� ���Ǵ� ���� ������ ������ 
 * 49���� �� �� k(k>6)���� ���� ��� ���� S�� ���� ���� �� ���� ������ ��ȣ�� �����ϴ� ���̴�.
 * ���� ���, k=8, S={1,2,3,5,8,13,21,34}�� ��� �� ���� S���� ���� �� �� �ִ� ����� ���� �� 28�����̴�. 
 * ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])
 * 
 * ���� S�� k�� �־����� ��, ���� ���� ��� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
 * 2019.07.11 00:17 ~ 00:22, 04:10 ~ 04:30
 * ------------------------------------------------------------------------------------------------ */

#include <iostream>
#include <vector>

void makeSet(std::vector<int> set, std::vector<bool> visit, int k, std::vector<int> res, int q) {
	//std::cout << "i : " << q << std::endl;
	if (k == 0) {
		for (int i = 0; i < 6; i++) {
			std::cout << res[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		for (int i = q; i < set.size(); i++) {
			if (visit[i] == true)
				continue;
			std::vector<int> res_copy = res;
			//std::cout << "add " << set[i] << std::endl;
			res_copy.push_back(set[i]);
			visit[i] = true;
			makeSet(set, visit, k - 1, res_copy, i+1);
		}
	}
	
}

int main() {
	int k;
	while (true) {
		std::vector<int> set;
		std::vector<int> res;
		std::cin >> k;
		if (k == 0)
			break;
		else {
			for (int i = 0; i < k; i++) {
				int t;
				std::cin >> t;
				set.push_back(t);
			}
		}
		std::vector<bool> visit(k, false);
		makeSet(set, visit, 6, res, 0);

		std::cout << std::endl;
	}

	return 0;
}
/*

7 1 2 3 4 5 6 7
0

*/