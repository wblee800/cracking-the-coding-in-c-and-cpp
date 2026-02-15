// 백준 온라인 저지 10434번 https://www.acmicpc.net/problem/10434
// 제한 시간 : 1초
// 실행 시간 : 160ms

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 테스트 케이스의 수 (1 ≤ P ≤ 1000)
	int P;
	cin >> P;

	// 테스트 케이스 번호
	int testCase;
	// 행복한 소수인지 판정할 정수 (1 ≤ m ≤ 10000)
	int M;
	for (size_t i = 0; i < P; i++)
	{
		cin >> testCase >> M;

		if (M <= 1)
		{
			cout << testCase << ' ' << M << ' ' << "NO\n";
			continue;
		}

		// 1. 소수인지 판별(소수가 아니라면, 바로 "NO" 출력)
		vector<bool> eratos(M + 1, true);
		for (size_t i = 2; i * i <= M; i++)
		{
			if (eratos[i])
			{
				for (size_t j = i * i; j <= M; j += i)
				{
					eratos[j] = false;
				}
			}
		}

		// M이 소수가 아니라면,
		if (!eratos[M])
		{
			cout << testCase << ' ' << M << ' ' << "NO\n";
			continue;
		}

		// 2. 소수 => 자리수의 제곱의 합을 구하는 연산을 반복했을 때, 값이 1이 되는 수인지 판별
		int happyNum = M;
		vector<int> checkHappyNum(10000, 0);
		bool isHappyNum = true;
		for (size_t i = 0; M != 1; i++)
		{	
			if (!isHappyNum)
			{
				cout << testCase << ' ' << happyNum << ' ' << "NO\n";

				break;
			}
			else
			{
				isHappyNum = true;
			}

			checkHappyNum[i] += (M / 1000) * (M / 1000);
			checkHappyNum[i] += ((M % 1000) / 100) * ((M % 1000) / 100);
			checkHappyNum[i] += ((M % 100) / 10) * ((M % 100) / 10);
			checkHappyNum[i] += (M % 10) * (M % 10);

			M = checkHappyNum[i];

			if (M == 1)
			{
				cout << testCase << ' ' << happyNum << ' ' << "YES\n";

				break;
			}
			else
			{
				// 자리수의 제곱의 합이 전에 구했던 값과 같으면,
				
				for (int j = 0; j < i; j++)
				{
					if (checkHappyNum[i] == checkHappyNum[j])
					{
						isHappyNum = false;

						break;
					}
				}
			}
		}
	}
}