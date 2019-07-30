/* ================================================================================================
 * Programmers
 *		42898 - ���
 *
 * time limit per test : ?? seconds
 * memory limit per test : ?? megabytes
 * solution function's arguments/return value
 *
 * ������ �б����� ���� ���� m x n ũ���� ���ڸ������ ��Ÿ�� �� �ֽ��ϴ�.
 * ���� ���� ��, �� ���� �ִ� ���� ��ǥ�� (1, 1)�� ��Ÿ����
 * ���� ������ �Ʒ�, �� �б��� �ִ� ���� ��ǥ�� (m, n)���� ��Ÿ���ϴ�.
 * ������ ũ�� m, n�� ���� ��� ������ ��ǥ�� ���� 2���� �迭 puddles�� �Ű������� �־��� ��,
 * �б����� ������ �� �� �ִ� �ִܰ���� ������
 * 1,000,000,007�� ���� �������� return �ϵ��� solution �Լ��� �ۼ����ּ���.
 *
 * ------------------------------------------------------------------------------------------------
 * 
 * 1 <= M, N <= 100 -> O((NM)^2) is possible
 * m x n ���ڿ��� �̵��� �� �ִ� ����� �� : (m+n)!/m!n!
 * P�� ��ġ�� �ʰ� �� �� �ִ� ����� ��?
 * P�� ���� 4ĭ�� ���ľ��� -> P�� ���� ������, P�� ���ʰ� �Ʒ�
 *
 * Using DP
 * puddle�� ���� ��, map[0][0]���� map[i][j]���� ������ �� �ִ� ����� ��
 *     -> map[i-1][j], map[i][j-1] ���� ������ �� �ִ� ����� ��
 * map[i][j]���� ������ �� �ִ� ����� ���� �޸������̼� ����
 *     -> map[i][j] = map[i][j-1] + map[i-1][j];
 *
 * puddle�� ���� ���� ���� �����ϴ� ��� = 0 ���� �����ϸ� (puddle�� �����ϴ� ����� ������ 0)
 * puddle�� �����ϴ� ��ΰ� ������
 *
 * ------------------------------------------------------------------------------------------------ */

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	vector<vector<int>> map(m + 1, vector<int>(n + 1, 0));
	for (unsigned int i = 0; i < puddles.size(); i++) {
		map[puddles[i][0]][puddles[i][1]] = -1;
	}
	map[0][1] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != -1)
				map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
			else
				map[i][j] = 0;
		}
	}
	return map[m][n];
}

#include <iostream>
#include <thread>
#include <tuple>
#include <future>
#include <chrono>

void get_solution(int m, int n, vector<vector<int>> puddles, std::promise<std::tuple<int, std::chrono::duration<double>>>* p)
{
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	int result = solution(m, n, puddles);
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	
	p->set_value({ result, time });
}

int main()
{
	/* �׽�Ʈ���̽��� �����ϴ� �κ� */
	std::vector<std::tuple<int, int, std::vector<std::vector<int>>, int>> testcase;

	testcase.push_back({ 4, 3, { {2, 2} }, 4 });
	testcase.push_back({ 6, 5, {  }, 30 });
	testcase.push_back({ 1, 1, {  }, 1 });

	for (unsigned int i = 0; i < testcase.size(); i++) {
		std::cout << "> Test No." << i + 1 << std::endl;

		int tc_m;
		int tc_n;
		std::vector<std::vector<int>> tc_puddles;
		int tc_ans;
		std::tie(tc_m, tc_n, tc_puddles, tc_ans) = testcase[i];


		std::promise<std::tuple<int, std::chrono::duration<double>>> p;
		auto f = p.get_future();

		std::thread thr(get_solution, tc_m, tc_n, tc_puddles, &p);
		std::future_status status = f.wait_for(std::chrono::milliseconds(2100));

		if (status == std::future_status::timeout) {
			thr.detach();

			std::cout << "> Time Limit Exceed" << std::endl;
		}
		else if (status == std::future_status::ready) {
			thr.join();

			int answer = tc_ans;
			std::chrono::duration<double> ex_time;
			int result;
			std::tie(result, ex_time) = f.get();

			if (result != answer) {
				std::cout << "  Check   : Wrong Answer" << std::endl;
			}
			else {
				std::cout << "  Check   : Right Answer" << std::endl;
			}

			std::cout << "  Ex_time : " << fixed << ex_time.count() << " seconds" << std::endl;

			std::cout << "  Input   : " << tc_m << ", " << tc_n << ", ";
			std::cout << "[";
			for (unsigned int i = 0; i < tc_puddles.size(); i++) {
				std::cout << "[" << tc_puddles[i][0] << ", " << tc_puddles[i][1] << "]";
				if (i != tc_puddles.size() - 1)
					std::cout << ", ";
			}
			std::cout << "]" << std::endl;

			std::cout << "  Output  : " << result << std::endl;
			std::cout << "  Answer  : " << answer << std::endl;
		}

		std::cout << std::endl;
	}

	return 0;
}
