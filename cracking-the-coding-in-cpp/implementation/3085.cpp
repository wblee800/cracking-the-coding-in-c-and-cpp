// 백준 온라인 저지 3085번 https://www.acmicpc.net/problem/3085
// 제한 시간 : 1초
// 실행 시간 : 76ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int CheckTheColorOfTheCandy(vector<vector<char>>& candy_case)
{
	// 카운팅 변수
	int cnt_continuous_color = 1;
	// max 변수
	int max_continuous_color = -1;
	// 이전에 방문한 색을 저장하는 변수
	char prev_color = '\0';

	// 행 탐색
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < N; x++)
		{
			if (candy_case[y][x] == 'C')
			{
				if (prev_color == 'C')
					cnt_continuous_color++;
				else
					cnt_continuous_color = 1;
			}
			else if (candy_case[y][x] == 'P')
			{
				if (prev_color == 'P')
					cnt_continuous_color++;
				else
					cnt_continuous_color = 1;
			}
			else if (candy_case[y][x] == 'Z')
			{
				if (prev_color == 'Z')
					cnt_continuous_color++;
				else
					cnt_continuous_color = 1;
			}
			else if (candy_case[y][x] == 'Y')
			{
				if (prev_color == 'Y')
					cnt_continuous_color++;
				else
					cnt_continuous_color = 1;
			}

			prev_color = candy_case[y][x];

			if (max_continuous_color < cnt_continuous_color)
			{
				max_continuous_color = cnt_continuous_color;
			}
		}
		cnt_continuous_color = 0;
	}

	prev_color = '\0';

	// 열 탐색
	for (size_t x = 0; x < N; x++)
	{
		for (size_t y = 0; y < N; y++)
		{
			if (candy_case[y][x] == 'C')
			{
				if (prev_color == 'C')
					cnt_continuous_color++;
				else
					cnt_continuous_color = 1;
			}
			else if (candy_case[y][x] == 'P')
			{
				if (prev_color == 'P')
					cnt_continuous_color++;
				else
					cnt_continuous_color = 1;
			}
			else if (candy_case[y][x] == 'Z')
			{
				if (prev_color == 'Z')
					cnt_continuous_color++;
				else
					cnt_continuous_color = 1;
			}
			else if (candy_case[y][x] == 'Y')
			{
				if (prev_color == 'Y')
					cnt_continuous_color++;
				else
					cnt_continuous_color = 1;
			}

			prev_color = candy_case[y][x];

			if (max_continuous_color < cnt_continuous_color)
			{
				max_continuous_color = cnt_continuous_color;
			}
		}
		cnt_continuous_color = 0;
	}

	return max_continuous_color;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	vector<vector<char>> candy_case(N);
	string input;
	for (size_t i = 0; i < N; i++)
	{
		cin >> input;
		for (size_t j = 0; j < input.size(); j++)
		{
			candy_case[i].push_back(input[j]);
		}

		input.resize(0);
	}

	char temp = '\0';
	int max_continuous_color = -1;
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < N; x++)
		{
			if (y == N - 1 && x == N - 1)
			{
				continue;
			}
			// 열의 끝이면,
			else if (x == N - 1)
			{
				swap(candy_case[y][x], candy_case[y + 1][x]);

				if (max_continuous_color < CheckTheColorOfTheCandy(candy_case))
					max_continuous_color = CheckTheColorOfTheCandy(candy_case);

				swap(candy_case[y][x], candy_case[y + 1][x]);
			}
			// 행의 끝이면,
			else if (y == N - 1)
			{
				swap(candy_case[y][x], candy_case[y][x + 1]);

				if (max_continuous_color < CheckTheColorOfTheCandy(candy_case))
					max_continuous_color = CheckTheColorOfTheCandy(candy_case);

				swap(candy_case[y][x], candy_case[y][x + 1]);
			}
			// 행과 열 모두 끝이 아니면,
			else
			{
				swap(candy_case[y][x], candy_case[y][x + 1]);

				if (max_continuous_color < CheckTheColorOfTheCandy(candy_case))
					max_continuous_color = CheckTheColorOfTheCandy(candy_case);

				swap(candy_case[y][x], candy_case[y][x + 1]);

				// ___________________________________________________________________________

				swap(candy_case[y][x], candy_case[y + 1][x]);

				if (max_continuous_color < CheckTheColorOfTheCandy(candy_case))
					max_continuous_color = CheckTheColorOfTheCandy(candy_case);

				swap(candy_case[y][x], candy_case[y + 1][x]);
			}
		}
	}

	cout << max_continuous_color;

	return 0;
}