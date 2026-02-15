// 백준 온라인 저지 17478번 https://www.acmicpc.net/problem/17478
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <string>
using namespace std;

string dash;
int recursive_function_2(int N)
{
	if (N <= 0)
	{
		cout << "라고 답변하였지.\n";
		return 0;
	}

	cout << dash << "라고 답변하였지.\n";
	dash.erase(0, 4);

	return recursive_function_2(N - 1);
}

int dashNum = 0;
int recursive_function_1(int N)
{
	if (N <= 0)
	{
		dash.append("_");
		dash.append("_");
		dash.append("_");
		dash.append("_");
		cout << dash << "\"재귀함수가 뭔가요?\"\n";
		cout << dash << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";

		return recursive_function_2(dashNum + 1);
	}

	dash.append("_");
	dash.append("_");
	dash.append("_");
	dash.append("_");
	cout << dash << "\"재귀함수가 뭔가요?\"\n";
	cout << dash << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	cout << dash << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	cout << dash << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	
	dashNum++;

	return recursive_function_1(N - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	cout << dash << "\"재귀함수가 뭔가요?\"\n";
	cout << dash << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	cout << dash << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	cout << dash << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	recursive_function_1(N - 1);
}
