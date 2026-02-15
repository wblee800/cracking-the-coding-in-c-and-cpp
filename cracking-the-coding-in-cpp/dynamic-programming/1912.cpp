// 백준 온라인 저지 1912번 https://www.acmicpc.net/problem/1912
// 제한 시간 : 1초
// 실행 시간 : 8ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> sequence(n, 0);
	for (size_t i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	for (size_t i = 1; i < n; i++)
	{
		int temp = sequence[i - 1] + sequence[i];

		if (sequence[i] < temp)
		{
			sequence[i] = temp;
		}
	}

	int maxSum = -1001;
	for (size_t i = 0; i < n; i++)
	{
		maxSum = max(maxSum, sequence[i]);
	}

	cout << maxSum;

	return 0;
}