#pragma warning(disable: 4996)

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int main()
{
	int n;
	std::vector<std::vector<int>> v;
	std::cin >> n;
	while (n != 0)
	{
		char *arr = (char*)malloc(sizeof(char) * 26);
		gets_s(arr,26);
		char* str = strtok(arr, " ");
		std::vector<int> tmp;
		while (str != NULL)
		{
			tmp.push_back(atoi(str));
			str = strtok(NULL, " ");
		}
		v.push_back(tmp);
		std::cin >> n;
	}
	for(auto count=v.begin();count<v.end();count++)
	{
		std::vector<int> input((*count));
		// 0��1�� ���� �� ���� ����
		std::vector<int> ind;
		// k=6, 6���� �����ϱ�
		int k = 6;

		// k���� 1 �߰�
		for (int i = 0; i < k; i++) {
			ind.push_back(1);
		}

		// ������ 0
		for (int i = 0; i < input.size() - k; i++) {
			ind.push_back(0);
		}

		//sort(ind.begin(), ind.end(),std::greater<int>());

		//����
		do {
			// ���
			for (int i = 0; i < ind.size(); i++) {
				if (ind[i] == 1) {
					printf("%d ", input[i]);
				}
			}
			printf("\n");
		} while (prev_permutation(ind.begin(), ind.end()));
		printf("\n");
	}

	return 0;
}