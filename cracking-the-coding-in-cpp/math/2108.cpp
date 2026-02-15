// 백준 온라인 저지 2108번 https://www.acmicpc.net/problem/2108
// 제한 시간 : 2초
// 실행 시간 : 196ms

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void FindTheArithmeticMean(vector<int>& numbers, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += numbers[i];
	}
	double arithmetic_mean = (double)sum / (double)n;
	if (round(arithmetic_mean) == -0)
	{
		cout << abs(round(arithmetic_mean)) << '\n';
	}
	else
	{
		cout << round(arithmetic_mean) << '\n';
	}
}

void FindTheSecondMinOfMode(vector<int>& numbers, int n)
{
	int prev_num = numbers[0];
	int most_frequency = -1;
	int cnt_frequency = 0;
	// 최빈값 찾기
	for (size_t i = 0; i < n; i++)
	{
		if (numbers[i] == prev_num)
		{
			cnt_frequency++;

			if (most_frequency < cnt_frequency)
			{
				most_frequency = cnt_frequency;
			}
		}
		else
		{
			prev_num = numbers[i];
			cnt_frequency = 1;
		}
	}

	vector<int> frequent_nums;
	prev_num = numbers[0];
	cnt_frequency = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (numbers[i] == prev_num)
		{
			cnt_frequency++;
		}
		else
		{
			prev_num = numbers[i];
			cnt_frequency = 1;
		}

		if (most_frequency == cnt_frequency)
		{
			frequent_nums.push_back(numbers[i]);
		}
	}

	if (frequent_nums.empty())
	{
		cout << numbers[0] << '\n';
	}
	else if (frequent_nums.size() == 1)
	{
		cout << frequent_nums[0] << '\n';
	}
	else
	{
		cout << frequent_nums[1] << '\n';
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> numbers(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	// 산술평균 : N개의 수들의 합을 N으로 나눈 값
	FindTheArithmeticMean(numbers, n);

	// 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	sort(numbers.begin(), numbers.end());
	cout << numbers[numbers.size() / 2] << '\n';

	// 최빈값 : N개의 수들 중 가장 많이 나타나는 값
	FindTheSecondMinOfMode(numbers, n);

	// 범위 : N개의 수들 중 최댓값과 최솟값의 차이
	cout << numbers[n - 1] - numbers[0];

	return 0;
}