#include<iostream>
#include<vector>
#include<algorithm>

int get_sum(std::vector<int> v, int len);

int main()
{
	int n;
	std::cin >> n;//�ο���
	std::vector<int> v(n);

	for (auto i = v.begin(); i < v.end(); i++)
		std::cin >> *i;//�ο��� �ʿ�ð�

	sort(v.begin(), v.end());//�ּ� �ð������� ����
	int *arr = (int*)calloc(v.size(), sizeof(int));//���ð� ���� �� �ʿ�ð� ������ �迭
	int res = 0;

	for (int i=0;i<v.size();i++)
	{
		if (i == 0)
		{
			arr[i] = v[i];
		}
		else
		{
			arr[i] = get_sum(v, i);//�� �ʿ�ð� ����
		}
	}
	for (int i = 0; i < n; i++)
		res = res + arr[i];//�ջ�

	std::cout << res;

	return 0;
}

int get_sum(std::vector<int> v, int len)
{
	int count = 0;
	int res = 0;
	for (; count < len+1; count++)
	{
		res = res + v[count];//�ش� �ο������� �ҿ�ð�+���� ���ð�
	}

	return res;//��ȯ
}