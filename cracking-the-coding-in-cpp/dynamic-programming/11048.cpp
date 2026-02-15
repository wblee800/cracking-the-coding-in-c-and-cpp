// 백준 온라인 저지 11048번 https://www.acmicpc.net/problem/11048
// 제한 시간 : 1초
// 실행 시간 : ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 미로의 크기 (1 ≤ N, M ≤ 1,000) 
	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> ground(N, vector<int>(M));
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			cin >> ground[y][x];
		}
	}

	for (size_t x = 0; x < M - 1; x++)
	{
		ground[0][x + 1] = ground[0][x] + ground[0][x + 1];
	}

	for (size_t y = 0; y < N - 1; y++)
	{
		ground[y + 1][0] = ground[y][0] + ground[y + 1][0];
	}

	for (size_t y = 1; y < N; y++)
	{
		for (size_t x = 1; x < M; x++)
		{
			ground[y][x] = max(ground[y - 1][x], ground[y][x - 1]) + ground[y][x];
		}
	}

	cout << ground[N - 1][M - 1];
}