/* ================================================================================================
 * Programmers
 *		42579 - ����Ʈ�ٹ�
 *
 * time limit per test : ?? seconds
 * memory limit per test : ?? megabytes
 * solution function's arguments/return value
 *
 * ��Ʈ���� ����Ʈ���� �帣 ���� ���� ���� ����� �뷡�� �� ���� ��� ����Ʈ �ٹ��� ����Ϸ� �մϴ�. 
 * �뷡�� ���� ��ȣ�� �����ϸ�, �뷡�� �����ϴ� ������ ������ �����ϴ�.
 * 
 *		1. ���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
 *		2. �帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
 *		3. �帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.
 *
 * �뷡�� �帣�� ��Ÿ���� ���ڿ� �迭 genres�� �뷡�� ��� Ƚ���� ��Ÿ���� ���� �迭 plays�� �־��� ��, 
 * ����Ʈ �ٹ��� �� �뷡�� ���� ��ȣ�� ������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.
 *
 * ------------------------------------------------------------------------------------------------
 *
 * map �����̳� ���
 * �帣�� ���� ��ü ���Ƚ���� �����ϴ� map1
 * �� �뷡�� �ε��� �� ���Ƚ���� �����ϴ� map2
 * �̶� map2�� key�� �帣, value�� �ٸ� �����̳ʸ� �̿��Ͽ� �ش� �帣�� ���� ����� ��� ����
 * 
 * �Է°� ��θ� map1, map2�� ����
 * �̶� map2�� ���ĵ� ���·� ������ �� �ִ� �켱����ť ���
 * map1�� ������ ���� �� ����
 * 
 * map1�� ��ȸ�ϸ� map2�� �ִ� ��Ҹ� 1~2���� ������
 *
 * Hash�� ����?
 * map2�� ����
 *
 * Genres1 : song1 -> song2 -> song3 -> song4
 * Genres2 : song4 -> song5
 * Genres3 : song6 -> song7 -> song8
 * Genres4 : song9
 *
 * ���� �ƴұ�?
 *
 * ------------------------------------------------------------------------------------------------ */

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

template<template <typename> class P = std::less >
struct compare_pair_second {
	template<class T1, class T2> bool operator()(const std::pair<T1, T2>&left, const std::pair<T1, T2>&right) {
		return P<T2>()(left.second, right.second);
	}
};


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> total;
	map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, compare_pair_second<>>> songs;

	for (unsigned int i = 0; i < genres.size(); i++) {
		total[genres[i]] += plays[i];
		songs[genres[i]].push(pair<int, int>(i, plays[i]));
	}

	vector<pair<string, int>> v_total(total.begin(), total.end());
	sort(v_total.begin(), v_total.end(), compare_pair_second<std::greater>());

	for (vector<pair<string, int>>::iterator i = v_total.begin(); i != v_total.end(); i++) {
		unsigned int sz = songs[i->first].size();
		for (unsigned int j = 0; j < sz && j < 2; j++) {
			answer.push_back(songs[i->first].top().first);
			songs[i->first].pop();
		}
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
	int i = 0;
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
	std::vector<std::tuple<vector<string>, vector<int>, std::vector<int>>> testcase;

	/* �׽�Ʈ���̽��� �����ϴ� �κ� */
	testcase.push_back({ {"classic", "pop", "classic", "classic", "pop" }, {500, 600, 150, 800, 2500 }, {4, 1, 3, 0} });
	testcase.push_back({ {"t1", "t2", "t1", "t1", "t2", "t1", "t3", "t4" }, {50, 600, 150, 800, 2500, 6000, 400, 20000 }, {7, 5, 3, 4, 1, 6} });


	for (unsigned int i = 0; i < testcase.size(); i++) {
		std::cout << "> Test No." << i + 1 << " ----------------------------------------" << std::endl;
		std::vector<std::string> tc_arg1;
		std::vector<int> tc_arg2;
		std::vector<int> answer;
		std::vector<int> result;
		std::tie(tc_arg1, tc_arg2, answer) = testcase[i];


		std::promise<std::tuple<std::vector<int>, std::chrono::duration<double>>> p;
		auto f = p.get_future();
		//std::thread thr(get_solution, &p, tc_genres, tc_plays);
		std::thread thr([&p, tc_arg1, tc_arg2]() {get_solution(&p, tc_arg1, tc_arg2); });
		std::future_status status = f.wait_for(std::chrono::milliseconds(2100));

		if (status == std::future_status::timeout) {
			thr.detach();

			std::cout << "> Time Limit Exceed" << std::endl;
		}
		else if (status == std::future_status::ready) {
			thr.join();

			std::chrono::duration<double> ex_time;

			std::tie(result, ex_time) = f.get();

			if (result != answer) {
				std::cout << "  Check   : Wrong Answer" << std::endl;
			}
			else {
				std::cout << "  Check   : Right Answer" << std::endl;
				right_ans_count++;
			}

			std::cout << "  Ex_time : " << fixed << ex_time.count() << " seconds" << std::endl;

			std::cout << "  Input   : ";
			print_vector(tc_arg1);
			print_vector(tc_arg2);
			std::cout << std::endl;

			std::cout << "  Output  : ";
			print_vector(result);
			std::cout << std::endl;

			std::cout << "  Answer  : ";
			print_vector(answer);
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

	std::cout << "> Correct " << right_ans_count << " of " << testcase.size() << std::endl;

	return 0;
}