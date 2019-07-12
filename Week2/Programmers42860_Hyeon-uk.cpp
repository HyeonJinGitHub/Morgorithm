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
 * length/2���� ���ÿ� ��ȸ
 * + ������, ������
 * �� �� ���� ���� ��...
 * 
 * �̰� �׸��� �³�?
 * ------------------------------------------------------------------------------------------------ */


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
	int name_length = name.size();

	int vertical_up = 0;
	int vertical_down = 0;

	int total_move = 0;

	int count = 0;
	for (int i = 0; i < name_length; i++) {
		if (name[i] != 'A')
			count++;
	}

	for (int i = 0; i < name_length; i++){
		//std::cout << name[i] << std::endl;
		if (name[i] != 'A') {
			vertical_up = name[i] - 'A';
			vertical_down = (26 - vertical_up) % 26;
			total_move += vertical_up < vertical_down ? vertical_up : vertical_down;
		}

		//if (i >= name_length - 1 || count == 0)
		//	break;

		//for (horizontal_pos_right = i + 1; name[horizontal_pos_right % name_length] == 'A'; horizontal_pos_right++);
		//for (horizontal_pos_left = i - 1; name[(horizontal_pos_left + name_length) % name_length] == 'A'; horizontal_pos_left--);
		//horizontal_pos_right = horizontal_pos_right % name_length;
		//horizontal_pos_left = (horizontal_pos_left + name_length) % name_length;

		//int right_dis = (horizontal_pos_right - i + name_length) % name_length;
		//int left_dis = (i - horizontal_pos_left + name_length) % name_length;

		//int distance;
		//int direction = 0;
		//if (right_dis <= left_dis) {
		//	distance = right_dis;
		//	direction = 1;
		//}
		//else {
		//	distance = left_dis;
		//	direction = 0;
		//}

		//if (name[i] != 'A' || (name[i] != 'A' && i==0 )) {
		//	if (direction == 1) {
		//		std::cout << "Add_r " << distance << std::endl;
		//		total_move_r += distance;
		//	}
		//	else {
		//		std::cout << "Add_l " << distance << std::endl;
		//		total_move_l += distance;
		//	} // A AABBBBB ABAAAAA
		//	name[i] = 'A';
		//	std::cout << "count--" << std::endl;
		//	count--;
		//}
		//i += 1;
	}

	int right_only_move = 0;
	int right_only_count = count;

	int left_only_move = 0;
	int left_only_count = count;

	int turn_move = 0;
	int turn_left_move = 0;
	int turn_right_move = 0;

	for (int i = 0; (right_only_count | left_only_count); i++) {
		if (name[i] != 'A') {
			right_only_count--;
		}
		if (right_only_count) {
			right_only_move++;
		}

		if (left_only_count) {
			left_only_move++;
		}
		if (name[name_length - i - 1] != 'A') {
			left_only_count--;
		}

		if (i < name_length/2) {
			if (i != 0) {
				if (name[i] != 'A') {
					turn_right_move = i;
				}
			}
			if (name[name_length - i - 1] != 'A') {
				turn_left_move = i + 1;
			}
		}
	}
	//std::cout << turn_left_move << std::endl;
	//std::cout << turn_right_move << std::endl;
	turn_move = turn_left_move < turn_right_move ? turn_left_move * 2 + turn_right_move : turn_left_move + turn_right_move * 2;

	std::cout << turn_move << std::endl;
	std::cout << left_only_move << std::endl;
	std::cout << right_only_move << std::endl;
	return total_move + std::min({turn_move, left_only_move, right_only_move});
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
	testcase.push_back({ "JAN", 23 });
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