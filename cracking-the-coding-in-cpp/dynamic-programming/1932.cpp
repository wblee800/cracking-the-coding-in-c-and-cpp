// 백준 온라인 저지 1932번 https://www.acmicpc.net/problem/1932
// 제한 시간 : 2초
// 실행 시간 : 40ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 삼각형의 크기 n(1 ≤ n ≤ 500)
	int n;
	cin >> n;

	// 2차원 배열로 정수(범위는 0 이상 9999 이하) 삼각형 구현
	vector<vector<int>> triangle(n, vector<int>(n, -1));
	for (size_t y = 0; y < n; y++)
	{
		for (size_t x = 0; x <= y; x++)
		{
			cin >> triangle[y][x];
		}
	}

	if (n == 1)
	{
		cout << triangle[0][0];

		return 0;
	}

	if (n == 2)
	{
		cout << triangle[0][0] + max(triangle[1][0], triangle[1][1]);

		return 0;
	}

	// 1행까지의 최적해 구해두기
	triangle[1][0] += triangle[0][0];
	triangle[1][1] += triangle[0][0];

	// 2행부터 n행까지 최적해 구하기
	for (size_t y = 2; y < n; y++)
	{
		for (size_t x = 0; x <= y; x++)
		{
			if (x == 0)
			{
				triangle[y][x] += triangle[y - 1][x];
			}
			else if (x == y)
			{
				triangle[y][x] += triangle[y - 1][x - 1];
			}
			else
			{
				triangle[y][x] += max(triangle[y - 1][x - 1], triangle[y - 1][x]);
			}
		}
	}

	int maxSum = -1;
	for (size_t x = 1; x < n; x++)
	{
		if (maxSum < max(triangle[n - 1][x - 1], triangle[n - 1][x]))
		{
			maxSum = max(triangle[n - 1][x - 1], triangle[n - 1][x]);
		}
	}

	cout << maxSum;

	return 0;
}