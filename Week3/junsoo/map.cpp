#include<iostream>
#include<vector>
#include<map>
#include<string>

int main()
{
	int x, y;
	std::map<int, std::string> Map;//����
	int idx = 0;
	std::cin >> x >> y;//����ũ��
	int len;
	std::cin >> len;//�Է°� ����

	int** v = (int**)calloc(len, sizeof(int*));

	for (int i = 0; i < len; i++)
		v[i] = (int*)calloc(3, sizeof(int));//���� ���� �迭

	while (idx<x)
	{
		std::cin.ignore();
		std::string arr;
		std::cin >> arr;
		Map[idx] = arr;//���������Է�
		idx++;
	}
	idx = 0;
	while (idx<len)
	{
		int x_top, y_top, x_bot, y_bot;
		std::cin >> x_top >> y_top >> x_bot >> y_bot;//Ž������ �Է�
		int ice=0, jungle=0, ocecn=0;
		for (int i = x_top - 1; i < x_bot; i++)
		{
			for (int j = y_top - 1; j < y_bot; j++)
			{//������ ����
				if (Map[i][j] == 'J')
				{
					jungle++;
				}
				else if (Map[i][j] == 'O')
				{
					ocecn++;
				}
				else
				{
					ice++;
				}
			}
		}
		//�׸� �Է�
		v[idx][0] = jungle;
		v[idx][1] = ocecn;
		v[idx][2] = ice;
		idx++;
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << v[i][j] << " ";//���
		}
		std::cout << "\n";
	}

	return 0;
}