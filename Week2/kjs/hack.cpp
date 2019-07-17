#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> get_max(int* arr,int len);

int main()
{
	int nodes, len;
	std::cin >> nodes >> len;
	std::vector<std::vector<int>>v(nodes,std::vector<int>());//������ �� ����� �ŷ�id���� ����
	while (len > 0)
	{
		//input
		int idx, trust;
		std::cin >> idx >> trust;
		v.at(idx - 1).push_back(trust);
		len--;
	}
	int *trust_count=(int*)calloc(nodes,sizeof(int));
	int cnt = 0;
	
	for (auto i = v.begin(); i < v.end(); i++)
	{
		for (cnt = 0; cnt < nodes; cnt++)
		{
			if (std::find((*i).begin(), (*i).end(), cnt + 1) != (*i).end())//id�� �ŷڹ޴� ��
			{
				trust_count[cnt]++;
				if (v.at(cnt).size() != 0)
				{
					trust_count[cnt]--;
					for (auto j = v.at(cnt).begin(); j < v.at(cnt).end(); j++)
					{
						trust_count[(*j)-1]++;
					}
				}
			}
		}
	}

	std::vector<int> max_idx = get_max(trust_count, nodes);//���� ���� �ŷڹ޴� index(��)ã��

	for (auto x = max_idx.begin(); x < max_idx.end(); x++)
	{
		if ((*x) != 0)
		{
			if (v.at((*x) - 1).size() == 0)//�ش�id�� �ŷ��ϴ� id�������, �״�� ���
			{
				std::cout << *x << " ";
			}
			else
			{
				for (auto i = v.at((*x) - 1).begin(); i < v.at((*x) - 1).end(); i++)//�ش� id�� �ŷ��ϴ� id���
					std::cout << *i << " ";
			}
		}
	}

	return 0;
}

std::vector<int> get_max(int *arr,int len)
{
	int idx = 0;
	std::vector<int> res;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > arr[idx])
		{
			idx = i;
		}
	}

	res.push_back(idx+1);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == arr[idx]&&i!=idx)
		{
			res.push_back(i+1);
		}
	}

	return res;
}