// 백준 온라인 저지 4963번 https://www.acmicpc.net/problem/4963
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

	int w, h;

	int nowY, nowX, nextY, nextX;
	int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
	int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

	typedef pair<int, int> p;
	queue<p> q;

	int landOrSea;
	int numOfLand;
	cin >> w >> h;
	while (!(w == 0 && h == 0))
	{
		numOfLand = 0;

		vector<vector <int>> territory(50, vector<int>(50, 0));
		vector<vector <int>> visitedArea(50, vector<int>(50, 0));

		// 땅(1), 바다(0) 입력
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				cin >> landOrSea;

				territory[y][x] = landOrSea;
			}
		}

		for (int x = 0; x < w; x++)
		{
			for (int y = 0; y < h; y++)
			{
				// 땅이고, 아직 방문하지 않았다면,
				if (territory[y][x] == 1 && !visitedArea[y][x])
				{
					visitedArea[y][x] = 1;
					q.push(make_pair(y, x));
					
					while (!q.empty())
					{
						nowY = q.front().first;
						nowX = q.front().second;
						q.pop();

						for (int i = 0; i < 8; i++)
						{
							nextY = nowY + dy[i];
							nextX = nowX + dx[i];

							if ((0 <= nextX && nextX < w) && // w 범위 안에 있는지 확인
								(0 <= nextY && nextY < h) && // h 범위 안에 있는지 확인
								territory[nextY][nextX] == 1 && // 인접한 곳이 땅이고,
								!visitedArea[nextY][nextX] // 아직 방문하지 않았다면,
								)
							{
								visitedArea[nextY][nextX] = 1;
								q.push(make_pair(nextY, nextX));
							}
						}
					}
					numOfLand++;
				}
			}
		}

		cout << numOfLand << '\n';
		
		// 너비 w, 높이 h 입력
		cin >> w >> h;
	}
}
