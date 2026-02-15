// 백준 온라인 저지 1463번 https://www.acmicpc.net/problem/1463
// 제한 시간 : 0.15초
// 실행 시간 : 8ms

#include <iostream>
using namespace std;

int minimum[1000001] = { 1000000 };
int compare[3];

int MakeItOne(int N)
{
	for (int i = 4; i <= N; i++)
	{
		// 3으로 나누어 떨어지면,
		if (i % 3 == 0)
		{
			// 첫 번째 비교 원소에 저장
			compare[0] = i / 3;
		}
		// 아니면,
		else
		{
			// minimum의 첫 번째 원소값인 1,000,000을 가리킨다.
			compare[0] = 0;
		}

		// 2로 나누어 떨어지면,
		if (i % 2 == 0)
		{
			// 두 번째 비교 원소에 저장
			compare[1] = i / 2;
		}
		// 아니면,
		else
		{
			// minimum의 첫 번째 원소값인 1,000,000을 가리킨다.
			compare[1] = 0;
		}
		
		// 1을 뺀 값 세 번째 비교 원소에 저장
		compare[2] = i - 1;

		if (minimum[compare[0]] <= minimum[compare[1]])
		{
			if (minimum[compare[0]] <= minimum[compare[2]])
			{
				minimum[i] = minimum[compare[0]] + 1;
			}
			else
			{
				minimum[i] = minimum[compare[2]] + 1;
			}
		}
		else if (minimum[compare[1]] <= minimum[compare[2]])
		{
			minimum[i] = minimum[compare[1]] + 1;
		}
		else
		{
			minimum[i] = minimum[compare[2]] + 1;
		}
	}

	return minimum[N];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	minimum[1] = 0;
	minimum[2] = 1;
	minimum[3] = 1;

	int N;
	cin >> N;

	switch (N)
	{
	case 1:
		cout << minimum[N];
		return 0;
	case 2:
		cout << minimum[N];
		return 0;
	case 3:
		cout << minimum[N];
		return 0;
	}

	cout << MakeItOne(N);
}
