/* ================================================================================================
 * Programmers
 *		42860 - ���̽�ƽ
 *
 * time limit per test : ?? seconds
 * memory limit per test : ?? megabytes
 * solution function's arguments/return value
 *
 * ���̽�ƽ���� ���ĺ� �̸��� �ϼ��ϼ���. �� ó���� A�θ� �̷���� �ֽ��ϴ�.
 * 
 * ���̽�ƽ�� �� �������� �����̸� �Ʒ��� �����ϴ�.
 * �� - ���� ���ĺ�
 * �� - ���� ���ĺ� (A���� �Ʒ������� �̵��ϸ� Z��)
 * �� - Ŀ���� �������� �̵� (ù ��° ��ġ���� �������� �̵��ϸ� ������ ���ڿ� Ŀ��)
 * �� - Ŀ���� ���������� �̵�
 * ������� �ϴ� �̸� name�� �Ű������� �־��� ��, 
 * �̸��� ���� ���̽�ƽ ���� Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� ���弼��.
 *
 * ------------------------------------------------------------------------------------------------
 * 
 * ���ĺ��� ���� �� ���� �̵� Ƚ���� �Ʒ��� �̵� Ƚ�� �� �� ���� ���� ���ؼ� �̵�
 * ���� ������� �ڸ��� ���ʰ� ������ �� �� ª�� �������� �̵��ϸ� ���� ������?
 *
 * ���� ���
 *	A�� �ƴ� ������ �� ���� : count
 *	for()
 *		���� �ڸ��� ���ĺ� ���� (A~Z) : count--
 *		if (��� �ڸ��� ���ĺ� ������ ��������) : count == 0
 *		������ ������ ��ġ Ž�� (���ʰ� ������ �� ª�� ��)
 *		�̵�
 *
 * �׽�Ʈ���̽��� ��� ����Ͽ�����...
 * ���� "FFFFFAAAAAAABA"���?
 * ���� �ּ��� ��ġ�� �̵��ϴ� ���� ���������� �ּ��� ������ �ƴ� ���� �ִ�
 * 
 * ...?
 * �׸����ΰ� ���� ���ǵ�...
 * 
 * ���� ������ �ذ� ����� ��ͷ� ��� ���̽��� ���� Ž���ϴ� ��.
 * �������� �̵����� �� �̵�Ƚ���� ���������� �̵����� �� �̵�Ƚ���� �� �� �� ���� ���� ����
 * ��� ���ο��� �湮�� �ڸ��� ���� ���ĺ� ���� �� �湮 ǥ���Ͽ� ��湮�� ����
 * �׸��� ����Ǵ� �κ��� ���ĺ� ����
 *
 * �ٵ�, ������ �̵��� �ʿ䰡 �ֳ�?
 * �� �̵�Ƚ�� = ���ĺ� ���� Ƚ���� �� + �̵� Ƚ���� ��
 * ���ĺ� ���� Ƚ���� ������ ������� �Һ�.
 * ��, �̵� Ƚ���� ����ȭ�ϸ� ��
 * 
 * �̵��� �ʿ䰡 ���ٸ�, ���ȣ���� �ʿ䵵 ����.
 * ������ Ǫ�µ� �ʿ��Ѱ� �� �ڸ����� ����, ������ �� �� ����� ��ġ������ �Ÿ�
 * ���������� ����� �ؼ� ������
 *
 * �ȵ� ��
 * �������� ���ÿ� ����ؼ�
 * left�� ���� �� �Ÿ�, right�� ���� �� �Ÿ��� �����Ͽ�
 * �� �� �� ª�� ������ �����ϸ�? min(left, right)*2+max(left, right)
 *
 * length/2���� ���ÿ� ��ȸ -> �� �� �� ª�� ������ ����
 * ������
 * ������
 * �� �� ���� ���� ��...
 * 
 * �̰� �׸��� �³�?
 *
 * ------------------------------------------------------------------------------------------------
 * 
 * ��¥ ��¥ ����ī�� Ǯ�̰��� ������
 * �׸���� ������ �ƴѵ�.. �³�? ��ư.
 * ���� ������ -> ������ �߾��� �������� �¿��� �̵��Ÿ��� �����߱⿡ ������ �߾Ӽ��� �Ѿ�� ����� ������ �ȵ�
 * �ΰ��� vector�� �̿��ؼ� �� ���������� �������� �̵��Ÿ�, �������� �̵��Ÿ��� ����
 * right ���Ϳ��� �� �տ� 0�� ����(�������θ� �����̴� ���)
 *  left ���Ϳ��� �� �ڿ� 0�� ����(�������θ� �����̴� ���)
 * ��� ���̽��� ���� (r�� �������� �̵��� ������ ��ġ, l�� �������� �̵��� ������ ��ġ) 2*min(l, r) + max(l, r)�� ����
 * ���� ���� ���� ������
 * 
 *	e.g.
 *	ZAAZAAZA
 *	01234567 (�� ���������� �������� �̵��Ÿ�)
 *	87654321 (�� ���������� �������� �̵��Ÿ�)
 *	vector r = {0} + {0, 3, 6}
 *	vector l =       {8, 5, 2} + {0}
 *	r = {0,0,3,6}
 *	l = {8,5,2,0}
 *	d = {8,5,7,6}
 * 
 * ------------------------------------------------------------------------------------------------ */


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
	int vertical[26] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int v_move = 0;
	int length = name.length();
	vector<int> right;
	vector<int> left;
	right.push_back(0);
	for (auto i = 0; i < length; i++) {
		cout << vertical[name[i] - 'A'] << " ";
		v_move += vertical[name[i] - 'A'];
		if (name[i] != 'A') {
			right.push_back(i);
			left.push_back(length - i);
		}
	}
	left.push_back(0);

	for (auto i : right) {
		cout << i << " ";
	}
	
	int min = right[0] * 2 + left[0];
	int dis;
	for (auto i = 1; i < right.size(); i++) {
		dis = right[i] < left[i] ? right[i] * 2 + left[i] : right[i] + left[i] * 2;
		if (dis < min) {
			min = dis;
		}
	}

	return min + v_move;
}

#include <iostream>
#include <thread>
#include <tuple>
#include <future>
#include <chrono>
#include <string>

void get_solution(std::string name, std::promise<std::tuple<int, std::chrono::duration<double>>>* p)
{
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	int result = solution(name);
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	p->set_value({ result, time });
}

int main()
{
	int right_ans_count = 0;
	std::vector<std::tuple<std::string, int>> testcase;

	/* �׽�Ʈ���̽��� �����ϴ� �κ� */
	testcase.push_back({ "JEROEN", 56 });
	testcase.push_back({ "BAC", 23 });
	testcase.push_back({ "ABAAAAAAAAABB", 7 });
	testcase.push_back({ "AZAAAZ", 5 });
	testcase.push_back({ "ABABAAAAAAAAAAAABA", 10 });
	testcase.push_back({ "CANAAAAANAN", 48 });
	testcase.push_back({ "BBABAAAAAAAAAAAABA", 11 });
	testcase.push_back({ "BAAAAABA", 4 });
	testcase.push_back({ "AAA", 0 });
	testcase.push_back({ "", 0 });
	testcase.push_back({ "AAAAAAAAAAAAAAAAAAAA", 0 });
	testcase.push_back({ "ZZZZZZZZZZZZZZZZZZZZ", 39 });
	testcase.push_back({ "Z", 1 });
	testcase.push_back({ "AZAAAAAAAAZAZA", 9 });
	testcase.push_back({ "ZZAAAAAAAAZAZA", 10 });
	testcase.push_back({ "ZZAAAAAAAAZAZZ", 11 });
	testcase.push_back({ "AZZZAAAAAAAZZZ", 15 });
	testcase.push_back({ "ZZZZAAAAAAAZZZ", 16 });
	testcase.push_back({ "AAAAZAAZAAA", 9 });
	testcase.push_back({ "AAAZAAZA", 7 });
	testcase.push_back({ "AZAAAZ", 5 });
	testcase.push_back({ "ABAAABBBBBBB", 17 });

	for (unsigned int i = 0; i < testcase.size(); i++) {
		std::cout << "> Test No." << i + 1 << " ----------------------------------------" << std::endl;

		std::string tc_name;
		int tc_ans;
		std::tie(tc_name, tc_ans) = testcase[i];


		std::promise<std::tuple<int, std::chrono::duration<double>>> p;
		auto f = p.get_future();

		std::thread thr(get_solution, tc_name, &p);
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
				right_ans_count++;
			}

			std::cout << "  Ex_time : " << fixed << ex_time.count() << " seconds" << std::endl;

			std::cout << "  Input   : " << tc_name << std::endl;

			std::cout << "  Output  : " << result << std::endl;
			std::cout << "  Answer  : " << answer << std::endl;
		}

		std::cout << std::endl;
	}

	std::cout << "> Correct " << right_ans_count << " of " << testcase.size() << std::endl;

	return 0;
}