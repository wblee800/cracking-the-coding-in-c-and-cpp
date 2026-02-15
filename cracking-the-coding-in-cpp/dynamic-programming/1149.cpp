// 백준 온라인 저지 1149번 https://www.acmicpc.net/problem/1149
// 제한 시간 : 0.5초 (추가 시간 없음)
// 실행 시간 : 0ms

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 집의 수 N(2 ≤ N ≤ 1,000)
	int N;
	cin >> N;

	vector<vector<int>> houses(N, vector<int>(3, 0));
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			cin >> houses[y][x];
		}
	}

	vector<int> min_cost = { 0, 0, 0 };
	vector<int> prev_min_cost = { houses[0][0], houses[0][1], houses[0][2] };
	for (size_t y = 1; y < N; y++)
	{
		min_cost[0] = houses[y][0] + min(prev_min_cost[1], prev_min_cost[2]);
		min_cost[1] = houses[y][1] + min(prev_min_cost[0], prev_min_cost[2]);
		min_cost[2] = houses[y][2] + min(prev_min_cost[0], prev_min_cost[1]);

		prev_min_cost[0] = min_cost[0];
		prev_min_cost[1] = min_cost[1];
		prev_min_cost[2] = min_cost[2];
	}

	cout << min(min(min_cost[0], min_cost[1]), min_cost[2]);

	return 0;
}