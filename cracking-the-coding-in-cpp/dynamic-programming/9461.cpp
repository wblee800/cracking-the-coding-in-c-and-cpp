// 백준 온라인 저지 9461번 https://www.acmicpc.net/problem/9461
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long P[101] = { 0, 1, 1, 1, 2, 2 };

	int testCase;
	cin >> testCase;

	for (int i = 6; i <= 100; i++)
	{
		P[i] = P[i - 1] + P[i - 5];
	}

	int N;
	for (int i = 0; i < testCase; i++)
	{
		cin >> N;
		cout << P[N] << '\n';
	}
}
