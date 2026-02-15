// 백준 온라인 저지 1303번 https://www.acmicpc.net/problem/1303
// 제한 시간 : 2초
// 실행 시간 : 0ms

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<string>> battleField(M, vector<string>(N));
	vector<vector<int>> visitedArea(M, vector<int>(N, 0));

	string s;
	for (int y = 0; y < M; y++)
	{
		cin >> s;
		for (int x = 0; x < N; x++)
		{
			battleField[y][x] = s[x];
		}
	}

	typedef pair<int, int> p;
	queue<p> q;

	int dy[4] = { 1, 0, -1, 0 };
	int dx[4] = { 0, -1, 0, 1 };
	
	int countW = 0;
	int countB = 0;
	pair<int, int> countWAndB;

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (battleField[y][x] == "W" && !visitedArea[y][x])
			{
				countW = 1;

				visitedArea[y][x] = 1;
				q.push(make_pair(y, x));

				while (!q.empty())
				{
					int nowY = q.front().first;
					int nowX = q.front().second;

					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int nextY = nowY + dy[i];
						int nextX = nowX + dx[i];

						if ((0 <= nextY && nextY < M)
							&& (0 <= nextX && nextX < N)
							&& battleField[nextY][nextX] == "W"
							&& !visitedArea[nextY][nextX])
						{
							visitedArea[nextY][nextX] = 1;
							q.push(make_pair(nextY, nextX));

							countW++;
						}
					}
				}
				countWAndB.first += countW * countW;
			}
			else if (battleField[y][x] == "B" && !visitedArea[y][x])
			{
				countB = 1;

				visitedArea[y][x] = 1;
				q.push(make_pair(y, x));

				while (!q.empty())
				{
					int nowY = q.front().first;
					int nowX = q.front().second;

					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int nextY = nowY + dy[i];
						int nextX = nowX + dx[i];

						if ((0 <= nextY && nextY < M)
							&& (0 <= nextX && nextX < N)
							&& battleField[nextY][nextX] == "B"
							&& !visitedArea[nextY][nextX])
						{
							visitedArea[nextY][nextX] = 1;
							q.push(make_pair(nextY, nextX));

							countB++;
						}
					}
				}
				countWAndB.second += countB * countB;
			}
		}
	}

	cout << countWAndB.first << ' ' << countWAndB.second;
}
