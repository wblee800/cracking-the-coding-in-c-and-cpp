// 백준 온라인 저지 11650번 https://www.acmicpc.net/problem/11650
// 제한 시간 : 1초
// 실행 시간 : 48ms
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool SortAxis(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
	{
		return a.first < b.first;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	vector<pair<int, int>> axis(N);
	for (int i = 0; i < N; i++)
	{
		cin >> axis[i].first >> axis[i].second;
	}
	
	sort(axis.begin(), axis.end(), SortAxis);

	for (int i = 0; i < N; i++)
	{
		cout << axis[i].first << ' ' << axis[i].second << '\n';
	}
}