// 백준 온라인 저지 1966번 https://www.acmicpc.net/problem/1966
// 제한 시간 : 2초
// 실행 시간 : 0ms

// 핵심 : 1. 중요도가 같은 경우도 고려해야 한다 2. queue에 몇 번째에 놓인 특정 정수를 기억해야 한다.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase; // 테스트 케이스의 수
	int N; // 문서의 개수
	int M; // 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue에 몇 번째에 놓였는지를 나타내는 정수

	queue<int> queue;

	// M과 중요도를 pair로 관리
	pair<int, int> p;

	int importance;
	vector<int> importanceArr;
	vector<int>::reverse_iterator rItr;

	int maxImportance;
	int printedOrder;
	cin >> testCase;
	// 테스트 케이스 수만큼 반복
	for (int i = 0; i < testCase; i++)
	{
		maxImportance = 0;
		printedOrder = 1;

		cin >> N >> M;
		p.first = M;

		// 문서의 개수 N개만큼 반복
		for (int i = 0; i < N; i++)
		{
			cin >> importance;
			queue.push(importance);
			importanceArr.push_back(importance);

			// M 번째의 값을 찾으면,
			if (i == M)
			{
				// pair 두 번째값에 M 번째 값의 중요도 할당
				p.second = importance;
			}

			if (importance > maxImportance)
			{
				maxImportance = importance;
			}
		}

		sort(importanceArr.begin(), importanceArr.end());

		// 문서가 몇 번째로 인쇄되는지 찾을 때까지 반복
		while (true)
		{
			// queue 맨 앞의 값이 중요도가 가장 높으면,
			if (queue.front() == maxImportance)
			{
				// M이 0이고, 중요도가 가장 높다면,
				if (p.first == 0 && p.second == maxImportance)
				{
					// 프린트 순서 출력
					cout << printedOrder << "\n";
					queue.pop();
					importanceArr.pop_back();
					break;
				}
				else
				{
					// queue에서 제거 후, 인쇄 순서 1 증가
					queue.pop();
					printedOrder++;
					p.first -= 1;

					importanceArr.pop_back();
					rItr = importanceArr.rbegin();
					maxImportance = *rItr;
				}
			}
			else
			{
				// queue 맨 앞의 값을 맨 뒤로 보내기
				if (p.first == 0)
				{
					p.first = queue.size() - 1;
				}
				else
				{
					p.first -= 1;
				}
				queue.push(queue.front());
				queue.pop();
			}
		}

		while (!queue.empty())
		{
			queue.pop();
		}

		while (!importanceArr.empty())
		{
			importanceArr.pop_back();
		}
	}
}
