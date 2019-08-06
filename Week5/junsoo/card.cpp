#include <iostream>
#include <algorithm>
#include <cstring> 

const int MAX = 2000;
int N;
int leftCard[MAX], rightCard[MAX];
int cache[MAX][MAX];

int maxScore(int leftIdx, int rightIdx)
{
	//���� ���: �� ������ ī�� �� �ϳ��� ���� ī�尡 ���ٸ�
	if (leftIdx >= N || rightIdx >= N)
		return 0;

	int& result = cache[leftIdx][rightIdx];

	if (result != -1)
		return result;

	result = 0;

	//���� ���� �ִ� ī�尡 �����ʿ� �ִ� ī�庸�� Ŭ ��� ������� 3����
	if (leftCard[leftIdx] > rightCard[rightIdx])
		result += std::max(rightCard[rightIdx] + maxScore(leftIdx, rightIdx + 1), 
			std::max(maxScore(leftIdx + 1, rightIdx), maxScore(leftIdx + 1, rightIdx + 1)));

	//�� �ܿ��� ������� 2����

	else
		result += std::max(maxScore(leftIdx + 1, rightIdx), maxScore(leftIdx + 1, rightIdx + 1));

	return result;
}

int main(void)
{
	std::cin >> N;

	for (int i = 0; i < N; i++)
		std::cin >> leftCard[i];

	for (int i = 0; i < N; i++)
		std::cin >> rightCard[i];

	memset(cache, -1, sizeof(cache));
	std::cout << maxScore(0, 0) << std::endl;

	return 0;
}