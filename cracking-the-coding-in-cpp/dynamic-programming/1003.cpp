// 백준 온라인 저지 1003번 https://www.acmicpc.net/problem/1003
// 제한 시간 : 0.25 초 (추가 시간 없음)
// 실행 시간 : 0ms

// 문제점 1 : 메모리 제한 128mb 초과
// 해결 1 : 각 테스트 케이스마다 vector를 초기화하면, 계산된 결과가 메모리에 계속 쌓이므로 한 번만 초기화

#include <iostream>
using namespace std;

int fibonacciArr[41] = { 0 , };

int fibonacci(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fibonacciArr[1] = 1;

	int testCase;
	cin >> testCase;

	int fiboNum;
	for (int i = 0; i < testCase; i++)
	{
		cin >> fiboNum;

		if (fiboNum == 0)
		{
			cout << "1 0\n";
		}
		else
		{
			cout << fibonacci(fiboNum - 1) << ' ' << fibonacci(fiboNum) << '\n';
		}
	}
}

int fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (fibonacciArr[n] != 0)
	{
		return fibonacciArr[n];
	}
	else
	{
		fibonacciArr[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return fibonacciArr[n];
	}
}
