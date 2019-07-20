/* ================================================================================================
 * Programmers
 *		42889 - ������
 * �������� ������ ���� �����Ѵ�.
 *	���������� ���������� ���� Ŭ�������� ���� �÷��̾��� �� / ���������� ������ �÷��̾� ��
 * ��ü ���������� ���� N, 
 * ������ �̿��ϴ� ����ڰ� ���� �����ִ� ���������� ��ȣ�� ��� �迭 stages�� �Ű������� �־��� ��, 
 * �������� ���� ������������ ������������ ���������� ��ȣ�� ����ִ� �迭�� return �ϵ��� solution �Լ��� �ϼ��϶�.
 * ------------------------------------------------------------------------------------------------
 * 17:20 ~ 17:55
 * ���ڸ��� ������ Ǯ��
 * �������� �� N(500), ���� �� M(200000)
 * ���������� ����, ���� ���� ��� -> O(NM)
 * ���������� �������� ����� -> O(N)
 * ���� -> O(NlogN)
 * �� ���� -> O(N)
 * ���� �ð� ���⵵ : O(NM)
 * ------------------------------------------------------------------------------------------------ */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

bool compare_pair_second(std::pair<int, double> p1, std::pair<int, double> p2) {
	return p1.second > p2.second;
}

std::vector<int> solution(int N, std::vector<int> stages) {
	std::vector<int> arrive_users(N + 2, 0);
	std::vector<int> fail_user_number(N + 2, 0);
	std::vector<std::pair<int, double>> failure_rate(N + 1, { 0, 0 }); // <stage_number, failure_rate>
	
	for (unsigned int i = 0; i < stages.size(); i++) {
		int j;
		for (j = 1; j <= stages[i]; j++) {
			arrive_users[j]++;
		}
		fail_user_number[j-1]++;
	}

	for (int i = 1; i <= N; i++) {
		failure_rate[i].first = i;
		failure_rate[i].second = fail_user_number[i] / (double)arrive_users[i];
	}

	std::stable_sort(failure_rate.begin()+1, failure_rate.end(), compare_pair_second);

	std::vector<int> answer(N);
	for (int i = 1; i <= N; i++) {
		answer[i - 1] = failure_rate[i].first;
	}

	return answer;
}

#include <iostream>
#include <thread>
#include <tuple>
#include <future>
#include <chrono>
#include <string>

template <class P, class... Args>
void get_solution(P *p, Args... args)
{
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	auto result = solution(args...);
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	p->set_value({ result, time });
}

template <typename Tv>
void print_vector(Tv v) {
	std::cout << "{";
	unsigned int i = 0;
	for (auto x : v) {
		std::cout << x;
		if (v.size() != ++i)
			std::cout << " ";
	}
	std::cout << "}";
}

int main()
{
	int right_ans_count = 0;
	std::vector<std::tuple<int, std::vector<int>, std::vector<int>>> testcase;

	/* �׽�Ʈ���̽��� �����ϴ� �κ� */
	testcase.push_back({ 5, {2,1,2,6,2,4,3,3}, {3,4,2,1,5} });
	testcase.push_back({ 4, {4,4,4,4,4}, {4,1,2,3} });

	for (unsigned int i = 0; i < testcase.size(); i++) {
		std::cout << "> Test No." << i + 1 << " ----------------------------------------" << std::endl;

		int tc_N;
		std::vector<int> tc_stages;
		std::vector<int> tc_ans;
		std::tie(tc_N, tc_stages, tc_ans) = testcase[i];


		std::promise<std::tuple<std::vector<int>, std::chrono::duration<double>>> p;
		auto f = p.get_future();

		std::thread thr([&p, tc_N, tc_stages]() {get_solution(&p, tc_N, tc_stages); });
		std::future_status status = f.wait_for(std::chrono::milliseconds(2100));

		if (status == std::future_status::timeout) {
			thr.detach();

			std::cout << "> Time Limit Exceed" << std::endl;
		}
		else if (status == std::future_status::ready) {
			thr.join();

			std::vector<int> answer = tc_ans;
			std::chrono::duration<double> ex_time;
			std::vector<int> result;
			std::tie(result, ex_time) = f.get();

			if (result != answer) {
				std::cout << "  Check   : Wrong Answer" << std::endl;
			}
			else {
				std::cout << "  Check   : Right Answer" << std::endl;
				right_ans_count++;
			}

			std::cout << "  Ex_time : " << std::fixed << ex_time.count() << " seconds" << std::endl;

			std::cout << "  Input   : " << tc_N << ", ";
			print_vector(tc_stages);
			std::cout << std::endl;

			std::cout << "  Output  : ";
			print_vector(result);
			std::cout << std::endl;

			std::cout << "  Answer  : ";
			print_vector(tc_ans);
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

	std::cout << "> Correct " << right_ans_count << " of " << testcase.size() << std::endl;

	return 0;
}