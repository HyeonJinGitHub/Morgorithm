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
 *
 * ------------------------------------------------------------------------------------------------
 * 
 * ���������� Ǯ����� �ݹ� Ǭ ����
 * �Է¹ް� ���� S���� ���ð����� ���ڸ� �Ѱ��� �����ϸ鼭 ��� ȣ��
 * ����� ���� = ������ ������ ����
 * 
 * ���� ���� �� �� �������� �ʱ� ���ؼ� �� ��͸��� �湮���θ� �Ǻ��ϴ� bool ���͸� �����Ͽ� �Ѱ��ش�
 * �̹� �湮(���)�� ���� continue
 *
 * ------------------------------------------------------------------------------------------------ */

#include <iostream>
#include <vector>

void makeSet(std::vector<int> &set, std::vector<bool> visit_copy, int k, std::vector<int> res_copy, int q) {
	if (k == 0) {
		//for (int i = 0; i < 6; i++) {
		for (std::vector<int>::iterator i = res_copy.begin(); i != res_copy.end(); i++){
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
	else {
		for (int i = q; i < set.size(); i++) {
			if (visit_copy[i] == true)
				continue;
			//std::vector<int> res_copy = res;
			res_copy.push_back(set[i]);
			visit_copy[i] = true;
			makeSet(set, visit_copy, k - 1, res_copy, i+1);
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