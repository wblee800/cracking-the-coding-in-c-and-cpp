// 백준 온라인 저지 16926번 https://www.acmicpc.net/problem/16926
// 제한 시간 : 1초
// 실행 시간 : 276ms

#include <iostream>
#include <vector>
using namespace std;

int N, M, R;
void RotateCube(vector<vector<int>>& cube, vector<vector<int>>& cube_after_rotation, int j)
{
	// j행 1+j열 ~ j행 (M-1)-j열
	for (size_t x = 1 + j; x < M - j; x++)
	{
		cube_after_rotation[j][x - 1] = cube[j][x];
	}

	// j행 j열 ~ (N-1)-1-j행 j열
	for (size_t y = j; y < N - 1 - j; y++)
	{
		cube_after_rotation[y + 1][j] = cube[y][j];
	}

	// (N-1)-j행 j열 ~ (N-1)-j행 (M-1)-1-j열
	for (size_t x = j; x < M - 1 - j; x++)
	{
		cube_after_rotation[N - 1 - j][x + 1] = cube[N - 1 - j][x];
	}

	// (N-1)-j행 (M-1)-j열 ~ 1+(2*j)행 (M-1)-j열
	for (size_t y = (N - 1) - j; y >= 1 + j; y--)
	{
		cube_after_rotation[y - 1][(M - 1) - j] = cube[y][(M - 1) - j];
	}
}

int main()
{
	// 2 ≤ N, M ≤ 300
	// 1 ≤ R ≤ 1,000
	cin >> N >> M >> R;

	vector<vector<int>> cube(N, vector<int>(M, 0));
	vector<vector<int>> cube_after_rotatation(N, vector<int>(M, 0));

	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			cin >> cube[y][x];
		}
	}

	// 회전 수 만큼 반복
	int the_num_of_border = min(N, M) / 2;
	for (size_t i = 0; i < R; i++)
	{
		// M, N 중 최소값의 /2만큼 반복 ∵ 한 테두리씩 회전하기 위해서
		for (size_t j = 0; j < the_num_of_border; j++)
		{
			RotateCube(cube, cube_after_rotatation, j);
		}

		for (size_t y = 0; y < N; y++)
		{
			for (size_t x = 0; x < M; x++)
			{
				cube[y][x] = cube_after_rotatation[y][x];
			}
		}

	}

	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			cout << cube[y][x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}