// 백준 온라인 저지 1012번 https://www.acmicpc.net/problem/1012
// 제한 시간 : 1초
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

	int testCase;
	int M, N, K;
	
	typedef pair<int, int> p;
	queue<p> q;
	int x, y, nowX, nowY;

	// 상하좌우를 나타내는 배열
	int dy[4] = { 0, 0, -1, 1 };
	int dx[4] = { 1, -1, 0, 0 };
	int nextY, nextX;

	int minOfEarthworm;

	// test case만큼 반복
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		minOfEarthworm = 0;

		vector<vector<int>> aFieldOfCabbage(50, vector<int>(50, 0));
		vector<vector<int>> visitedSection(50, vector<int>(50, 0));

		cin >> M >> N >> K;

		// 배추밭에 있는 배추를 1로 표시, 없다면 0
		for (int j = 0; j < K; j++)
		{
			cin >> x >> y;
			aFieldOfCabbage[y][x] = 1;
		}

		for (int x = 0; x < M; x++)
		{
			for (int y = 0; y < N; y++)
			{
				// 배추가 있고, 방문한 적이 없다면,
				if (aFieldOfCabbage[y][x] == 1 && !visitedSection[y][x])
				{
					q.push(make_pair(y, x));
					visitedSection[y][x] = 1;

					// queue가 비어있을 때까지 반복
					while (!q.empty())
					{
						nowY = q.front().first;
						nowX = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++)
						{
							nextY = nowY + dy[k];
							nextX = nowX + dx[k];

							if ((0 <= nextX && nextX < M) // x 범위 검사
								&& (0 <= nextY && nextY < N) // y 범위 검사
								&& (aFieldOfCabbage[nextY][nextX] == 1) // 다음 지점이 1이고,
								&& !visitedSection[nextY][nextX]) // 방문한 적이 없다면,
							{
								visitedSection[nextY][nextX] = 1;
								q.push(make_pair(nextY, nextX));
							}
						}
					}
					minOfEarthworm++;
				}
			}
		}

		cout << minOfEarthworm << '\n';
	}
}
