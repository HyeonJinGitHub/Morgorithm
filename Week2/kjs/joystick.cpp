#include<iostream>
#include<string>

int solution(std::string name);

int main()
{
	std::string name="";
	std::cin >> name;

	int res = solution(name);

	std::cout << res;

	return 0;
}

int solution(std::string name)
{
	int len = name.length();
	int count = 0;
	int pos = 0;
	int getAll = 0;

	if (len == 0)
	{
		return count;//���̰� 0�ΰ��
	}
	int* arr = (int*)calloc(len, sizeof(int));//�ٲ���ϴ°��� �ε��� Ȯ��

	for (int i = 0; i < len; i++)
	{
		if (name[i] != 'A')
		{
			if (name[i] <= 'N')
			{
				count = count + (int)(name[i] - 'A');//���� �����̴� ���
				arr[i]++;
			}
			else
			{
				count = count + (int)('Z' - name[i] + 1);//�Ʒ��� �����̴� ���
				arr[i]++;
			}
		}
	}
	do
	{
		if (arr[getAll] != 0)//�ٲ���ϴ� ���ĺ� ��ġ
		{
			if (pos == 0)
			{
				if (getAll == pos)
				{
					getAll++;
				}
				else
				{
					if (getAll-pos<len/2)//������ġ���� �������
					{
						pos = pos+getAll - pos;
						getAll++;
					}
					else//������ġ���� �ְ��
					{
						pos = pos + (len - 1 - getAll + 1);
						getAll++;
					}
				}
			}
			else
			{
				if (getAll - pos < len / 2)//�̵��� ���̵��� �Ÿ�Ȯ��. �������
				{
					pos = pos + getAll - pos;
					getAll++;
				}
				else//�ְ��
				{
					pos = pos + (len - getAll);
					getAll++;
				}
			}
		}
		else
		{
			getAll++;
		}
	} while (getAll < len);

	count = count + pos;
	return count;
}