// 백준 온라인 저지 1929번 https://www.acmicpc.net/problem/1929
// 제한 시간 : 2초
// 실행 시간 : 12ms

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	(M == 1) ? ++M : M;

	bool* primeNumber = new bool[N + 1];
	for (int i = 2; i <= N; i++)
	{
		primeNumber[i] = true;
	}

	for (int i = 2; i * i <= N; i++)
	{
		if (primeNumber[i])
		{
			for (int j = i * i; j <= N; j += i)
			{
				primeNumber[j] = false;
			}
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (primeNumber[i])
		{
			cout << i << "\n";
		}
	}
	
	delete[] primeNumber;
}
