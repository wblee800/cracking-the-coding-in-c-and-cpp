// 백준 온라인 저지 2615번 https://www.acmicpc.net/problem/2615
// 제한 시간 : 1초
// 실행 시간 : ms

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

void FindOmok(vector<vector<int>>& board)
{
	typedef pair<int, int> p;

	// 이전 바둑돌
	int prev_baduk_stone = 0;
	// 흑돌 카운트 = {바둑돌 색 판단, 연속된 흑돌 카운트}
	p cnt_baduk_stone_1 = { 1, 1 };
	// 백돌 카운트 = {바둑돌 색 판단, 연속된 백돌 카운트}
	p cnt_baduk_stone_2 = { 2, 1 };

	// 가로 오목 유무 판단
	for (size_t y = 1; y < 20; y++)
	{
		for (size_t x = 1; x < 20; x++)
		{
			// 현재 탐색한 돌이 흑돌이고,
			if (board[y][x] == 1)
			{
				// 이전 탐색한 돌도 흑돌이라면,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// 이전 탐색한 돌이 백돌이라면,
				else if (prev_baduk_stone == 2)
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// 현재 탐색한 돌이 백돌이고,
			else if (board[y][x] == 2)
			{
				// 이전 탐색한 돌도 백돌이라면,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// 이전 탐색한 돌이 흑돌이라면,
				else if (prev_baduk_stone == 1)
				{
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[y][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y << ' ' << x - 5;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[y][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y << ' ' << x - 5;

					return;
				}
			}
			// 현재 탐색한 돌이 없다면,
			else
			{
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[y][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y << ' ' << x - 5;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[y][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y << ' ' << x - 5;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// 현재 탐색한 돌이 가로의 끝에 있다면,
			if (x == 19)
			{
				// 5개가 연속된 바둑돌이 있고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y << ' ' << x - 4;

					return;
				}
				// 5개가 연속된 바둑돌이 있고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y << ' ' << x - 4;

					return;
				}
			}
		}

		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	// 세로 오목 유무 판단
	prev_baduk_stone = 0;
	for (size_t x = 1; x < 20; x++)
	{
		for (size_t y = 1; y < 20; y++)
		{
			// 현재 탐색한 돌이 흑돌이고,
			if (board[y][x] == 1)
			{
				// 이전 탐색한 돌도 흑돌이라면,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// 이전 탐색한 돌이 백돌이라면,
				else if (prev_baduk_stone == 2)
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// 현재 탐색한 돌이 백돌이고,
			else if (board[y][x] == 2)
			{
				// 이전 탐색한 돌도 백돌이라면,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// 이전 탐색한 돌이 흑돌이라면,
				else if (prev_baduk_stone == 1)
				{
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[y][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 5 << ' ' << x;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[y][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 5 << ' ' << x;

					return;
				}
			}
			// 현재 탐색한 돌이 없다면,
			else
			{
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[y][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 5 << ' ' << x;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[y][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 5 << ' ' << x;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// 현재 탐색한 돌이 세로의 끝에 있다면,
			if (y == 19)
			{
				// 5개가 연속된 바둑돌이 있고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 4 << ' ' << x;

					return;
				}
				// 5개가 연속된 바둑돌이 있고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 4 << ' ' << x;

					return;
				}
			}
		}

		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	// 대각선 위 오목 유무 판단
	prev_baduk_stone = 0;
	for (size_t x = 1; x < 20; x++)
	{
		size_t nowX = x;
		size_t y = 1;

		// 바둑돌이 바둑판 범위 안에 존재하면,
		while ((1 <= y && y <= 19) && (1 <= nowX && nowX <= 19))
		{
			// 현재 탐색한 돌이 흑돌이고,
			if (board[y][nowX] == 1)
			{
				// 이전 탐색한 돌도 흑돌이라면,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// 이전 탐색한 돌이 백돌이라면,
				else if (prev_baduk_stone == 2)
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// 현재 탐색한 돌이 백돌이고,
			else if (board[y][nowX] == 2)
			{
				// 이전 탐색한 돌도 백돌이라면,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// 이전 탐색한 돌이 흑돌이라면,
				else if (prev_baduk_stone == 1)
				{
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[y][nowX] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 1 << ' ' << nowX + 1;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[y][nowX] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 1 << ' ' << nowX + 1;

					return;
				}
			}
			// 현재 탐색한 돌이 없다면,
			else
			{
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[y][nowX] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 1 << ' ' << nowX + 1;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[y][nowX] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 1 << ' ' << nowX + 1;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// 현재 탐색한 돌이 대각선의 끝에 있다면,
			if (nowX == 1)
			{
				// 5개가 연속된 바둑돌이 있고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y << ' ' << nowX;

					return;
				}
				// 5개가 연속된 바둑돌이 있고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y << ' ' << nowX;

					return;
				}
			}

			// 대각선으로 이동
			y++;
			nowX--;
		}
		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	// 대각선 아래 오목 유무 판단
	prev_baduk_stone = 0;
	for (size_t y = 1; y < 16; y++)
	{
		size_t x = 19;
		size_t nowY = y;

		// 바둑돌이 바둑판 범위 안에 존재하면,
		while ((1 <= nowY && nowY <= 19) && (1 <= x && x <= 19))
		{
			// 현재 탐색한 돌이 흑돌이고,
			if (board[nowY][x] == 1)
			{
				// 이전 탐색한 돌도 흑돌이라면,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// 이전 탐색한 돌이 백돌이라면,
				else if (prev_baduk_stone == 2)
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// 현재 탐색한 돌이 백돌이고,
			else if (board[nowY][x] == 2)
			{
				// 이전 탐색한 돌도 백돌이라면,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// 이전 탐색한 돌이 흑돌이라면,
				else if (prev_baduk_stone == 1)
				{
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[nowY][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY - 1 << ' ' << x + 1;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[nowY][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY - 1 << ' ' << x + 1;

					return;
				}
			}
			// 현재 탐색한 돌이 없다면,
			else
			{
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[nowY][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY - 1 << ' ' << x + 1;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[nowY][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY - 1 << ' ' << x + 1;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// 현재 탐색한 돌이 대각선의 끝에 있다면,
			if (x == 1)
			{
				// 5개가 연속된 바둑돌이 있고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY << ' ' << x;

					return;
				}
				// 5개가 연속된 바둑돌이 있고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY << ' ' << x;

					return;
				}
			}

			// 대각선으로 이동
			nowY++;
			x--;
		}
		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	// 역 대각선 위 오목 유무 판단
	prev_baduk_stone = 0;
	for (size_t x = 1; x < 16; x++)
	{
		size_t y = 1;
		size_t nowX = x;

		// 바둑돌이 바둑판 범위 안에 존재하면,
		while ((1 <= y && y <= 19) && (1 <= nowX && nowX <= 19))
		{
			// 현재 탐색한 돌이 흑돌이고,
			if (board[y][nowX] == 1)
			{
				// 이전 탐색한 돌도 흑돌이라면,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// 이전 탐색한 돌이 백돌이라면,
				else if (prev_baduk_stone == 2)
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// 현재 탐색한 돌이 백돌이고,
			else if (board[y][nowX] == 2)
			{
				// 이전 탐색한 돌도 백돌이라면,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// 이전 탐색한 돌이 흑돌이라면,
				else if (prev_baduk_stone == 1)
				{
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[y][nowX] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 5 << ' ' << nowX - 5;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[y][nowX] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 5 << ' ' << nowX - 5;

					return;
				}
			}
			// 현재 탐색한 돌이 없다면,
			else
			{
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[y][nowX] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 5 << ' ' << nowX - 5;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[y][nowX] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 5 << ' ' << nowX - 5;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// 현재 탐색한 돌이 역 대각선의 끝에 있다면,
			if (nowX == 19)
			{
				// 5개가 연속된 바둑돌이 있고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << y - 4 << ' ' << nowX - 4;

					return;
				}
				// 5개가 연속된 바둑돌이 있고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << y - 4 << ' ' << nowX - 4;

					return;
				}
			}

			// 대각선으로 이동
			y++;
			nowX++;
		}
		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	// 역 대각선 아래 오목 유무 판단
	prev_baduk_stone = 0;
	for (size_t y = 1; y < 16; y++)
	{
		size_t x = 1;
		size_t nowY = y;

		// 바둑돌이 바둑판 범위 안에 존재하면,
		while ((1 <= nowY && nowY <= 19) && (1 <= x && x <= 19))
		{
			// 현재 탐색한 돌이 흑돌이고,
			if (board[nowY][x] == 1)
			{
				// 이전 탐색한 돌도 흑돌이라면,
				if (prev_baduk_stone == 1)
				{
					cnt_baduk_stone_1.second++;
				}
				// 이전 탐색한 돌이 백돌이라면,
				else if (prev_baduk_stone == 2)
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					// 현재 흑돌이므로 1
					cnt_baduk_stone_1.second = 1;
					cnt_baduk_stone_2.second = 0;
				}

				prev_baduk_stone = 1;
			}
			// 현재 탐색한 돌이 백돌이고,
			else if (board[nowY][x] == 2)
			{
				// 이전 탐색한 돌도 백돌이라면,
				if (prev_baduk_stone == 2)
				{
					cnt_baduk_stone_2.second++;
				}
				// 이전 탐색한 돌이 흑돌이라면,
				else if (prev_baduk_stone == 1)
				{
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}
				// 이전 탐색한 돌이 없다면,
				else
				{
					cnt_baduk_stone_1.second = 0;
					// 현재 백돌이므로 1
					cnt_baduk_stone_2.second = 1;
				}

				prev_baduk_stone = 2;

				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[nowY][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY - 5 << ' ' << x - 5;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[nowY][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY - 5 << ' ' << x - 5;

					return;
				}
			}
			// 현재 탐색한 돌이 없다면,
			else
			{
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5 && board[nowY][x] != 1)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY - 5 << ' ' << x - 5;

					return;
				}
				// 바로 앞에 탐색한 돌이 5개가 연속된 바둑돌이고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5 && board[nowY][x] != 2)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY - 5 << ' ' << x - 5;

					return;
				}

				cnt_baduk_stone_1.second = 0;
				cnt_baduk_stone_2.second = 0;

				prev_baduk_stone = 0;
			}

			// 현재 탐색한 돌이 역 대각선의 끝에 있다면,
			if (x == 19)
			{
				// 5개가 연속된 바둑돌이 있고, 그것이 흑돌이라면,
				if (cnt_baduk_stone_1.second == 5)
				{
					cout << cnt_baduk_stone_1.first << '\n';
					cout << nowY - 4 << ' ' << x - 4;

					return;
				}
				// 5개가 연속된 바둑돌이 있고, 그것이 백돌이라면,
				else if (cnt_baduk_stone_2.second == 5)
				{
					cout << cnt_baduk_stone_2.first << '\n';
					cout << nowY - 4 << ' ' << x - 4;

					return;
				}
			}

			// 대각선으로 이동
			nowY++;
			x++;
		}
		cnt_baduk_stone_1.second = 0;
		cnt_baduk_stone_2.second = 0;
	}

	cout << 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> board(20, vector<int>(20, 0));
	for (size_t y = 1; y < 20; y++)
	{
		for (size_t x = 1; x < 20; x++)
		{
			cin >> board[y][x];
		}
	}

	// 가로, 세로, /, \ 오목 유무 판단
	FindOmok(board);
}