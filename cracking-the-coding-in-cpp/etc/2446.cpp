// 백준 온라인 저지 2446번 https://www.acmicpc.net/problem/2446
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << ' ';
		}

		for (int k = 0; k < (2 * N) - (2 * i + 1); k++)
		{
			cout << '*';
		}

		cout << "\n";
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i; j < N - 2; j++)
		{
			cout << ' ';
		}

		for (int k = 0; k < 3 + (2 * i); k++)
		{
			cout << '*';
		}

		cout << "\n";
	}
}
