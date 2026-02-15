// 백준 온라인 저지 1697번 https://www.acmicpc.net/problem/1697
// 제한 시간 : 2초
// 실행 시간 : 0ms	

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 수빈이의 현재 위치 N(0 ≤ N ≤ 100,000), 동생의 현재 위치 K(0 ≤ K ≤ 100,000)
	int N, K;
	cin >> N >> K;

	typedef pair<int, int> p;
	queue<p> q;
	// 첫 번째 값 : 이동한 시간
	// 두 번째 값 : 수빈이의 위치
	q.push(make_pair(0, N));

	// 방문 처리
	vector<int> visited(100001, 0);
	visited[N] = 1;

	while (!q.empty())
	{
		// 수빈이의 위치와 동생의 위치가 같다면,
		if (q.front().second == K)
		{
			cout << q.front().first;

			return 0;
		}

		int front = q.front().second - 1;
		int back = q.front().second + 1;
		int jump = q.front().second * 2;

		// 앞으로 이동했을 경우
		if (0 <= front && visited[front] == 0)
		{
			visited[front] = 1;
			q.push(make_pair(q.front().first + 1, front));
		}

		// 뒤로 이동했을 경우
		if (back < 100001 && visited[back] == 0)
		{
			visited[back] = 1;
			q.push(make_pair(q.front().first + 1, back));
		}

		// 앞으로 2배 이동했을 경우
		if (jump < 100001 && visited[jump] == 0)
		{
			visited[jump] = 1;
			q.push(make_pair(q.front().first + 1, jump));
		}

		q.pop();
	}

	return 0;
}