// 백준 온라인 저지 2178번 https://www.acmicpc.net/problem/2178
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

	// (2 ≤ N, M ≤ 100)
	int N, M;
	cin >> N >> M;

	string input;
	vector<vector<int>> maze(N, vector<int>(M, 0));
	for (size_t y = 0; y < N; y++)
	{
		cin >> input;
		for (size_t x = 0; x < input.size(); x++)
		{
			maze[y][x] = input[x] - 48;
		}
	}

	// first : y, second : x
	typedef pair<int, int> p;

	queue<p> axis;
	axis.push(make_pair(0, 0));

	queue<int> cnt_blocks;
	cnt_blocks.push(1);

	int dy[4] = {0, 0, 1, -1};
	int dx[4] = {1, -1, 0, 0};

	vector<vector<int>> visited(N, vector<int>(M, 0));
	visited[0][0] = 1;

	bool isEnd = false;
	while (!axis.empty())
	{
		for (size_t i = 0; i < 4; i++)
		{
			int nowY = axis.front().first + dy[i];
			int nowX = axis.front().second + dx[i];

			if ((0 <= nowY && nowY <= N - 1) &&
				(0 <= nowX && nowX <= M - 1) &&
				maze[nowY][nowX] == 1 &&
				visited[nowY][nowX] == 0)
			{
				visited[nowY][nowX] = 1;

				axis.push(make_pair(nowY, nowX));
				cnt_blocks.push(cnt_blocks.front() + 1);

				if (nowY == N - 1 && nowX == M - 1)
				{
					isEnd = true;

					break;
				}
			}
		}
		axis.pop();
		cnt_blocks.pop();

		if (isEnd)
		{
			cout << cnt_blocks.back();

			return 0;
		}
	}

	cout << cnt_blocks.back();

	return 0;
}