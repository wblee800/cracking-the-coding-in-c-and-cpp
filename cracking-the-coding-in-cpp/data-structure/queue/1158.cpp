// 백준 온라인 저지 1158번 https://www.acmicpc.net/problem/1158
// 제한 시간 : 2초
// 실행 시간 : 96ms

// 핵심 : 시작과 끝이 연결되어있다.

// 문제점 1 : iterator를 이용해 배열의 원소를 erase한 후, *iterator를 사용하면 Error가 발생 
// 해결 1 :  반복 시마다 itr_begin = queue.begin();으로 iterator가 가리키는 주소를 명확히 함으로써 문제를 해결했다.

// 문제점 2 : 시간 초과
// 해결 2 : 제거된 사람을 -1로 변경 후 배열의 맨 뒤로 이동시키는 불필요한 연산을 제거했다.

// 문제점 3 : 97%에서 결과가 "틀렸습니다"
// 해결 3 : 결과를 queue에 모두 저장한 후, 한 번에 출력해 해결

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 사람 수
	int K; // 제거할 사람이 앉은 곳의 순서
	queue<int> josephus;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		josephus.push(i + 1); // 각 사람에게 1번부터 N번까지 번호 부여
	}

	int countOrder = 1; // K 순서의 사람을 제거하기 위해 몇 번째 사람인지 카운트
	queue<int> answer;
	
	// 사람이 모두 제거될 때까지(queue가 비어있을 때까지) 반복
	while (!josephus.empty())
	{
		// K 번째의 사람이면,
		if ((countOrder) == K)
		{
			answer.push(josephus.front()); // K 번째 사람의 순번 저장

			josephus.pop(); // queue의 맨 앞에 남아있는 순번의 값은 제거

			countOrder = 1; // K 순번의 사람을 처음부터 다시 찾기 위해 countOrder 초기화
		}
		// K 번째의 사람이 아니면,
		else if ((countOrder) != K)
		{
			josephus.push(josephus.front()); // queue의 맨 뒤로 이동
			josephus.pop(); // queue의 맨 앞에 남아있는 이동된 값 제거

			countOrder++; // countOrder 1 증가
		}

		// 제거된 사람의 수가 모든 사람의 수보다 1명 적다면,
		if (josephus.size() == 1)
		{
			answer.push(josephus.front());
			josephus.pop();
		}
	}

	cout << "<";
	for (int i = 0; i < N - 1; i++)
	{
		cout << answer.front() << ", ";
		answer.pop();
	}
	cout << answer.front() << ">"s;
}
