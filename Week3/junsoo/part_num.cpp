#include<iostream>
#include<vector>
#include<string>

int main()
{
	int len;
	std::cin >> len;
	std::vector<int> v;
	std::vector<int> part;

	char* str = (char*)malloc(sizeof(char) * (len * len));
	std::cin.ignore();
	std::cin.getline(str, len*len);//�Է¹���
	
	str = strtok(str, " ");//����������� �߶�
	while (str != NULL)
	{
		v.push_back(atoi(str));//���� �Է�
		str = strtok(NULL, " ");
	}
	for (auto i = v.begin(); i < v.end(); i++)
	{
		if (part.size() == 0)//�κм���0�϶�
		{
			part.push_back(*i);
		}
		else//�׿�
		{
			if (*i > part[part.size()-1])//�κм��� ���� ��, ũ�� ����
			{
				part.push_back(*i);
			}
		}
	}

	std::cout << part.size();//������ ���

	return 0;
}