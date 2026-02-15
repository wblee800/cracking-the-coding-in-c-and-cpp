// 백준 온라인 저지 11399번 https://www.acmicpc.net/problem/11399
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int time;
	vector<int> queue;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> time;
		queue.push_back(time);
	}

	sort(queue.begin(), queue.end());
	
	int sum = 0;
	vector<int> sumTime;
	for (int i : queue)
	{
		sum += i;
		sumTime.push_back(sum);
	}

	sum = 0;
	for (int i : sumTime)
	{
		sum += i;
	}
	cout << sum;
}
