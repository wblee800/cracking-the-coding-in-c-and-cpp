// 백준 온라인 저지 2667번 https://www.acmicpc.net/problem/2667
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	typedef pair<int, int> p;
	queue<p> q;

	vector<vector<int>> apartmentComplex(25, vector<int>(25, 0));
	vector<vector<int>> visitedSection(25, vector<int>(25, 0));
	vector<int> numOfHouse(625, 0);
	int orderOfComplex = 0;

	int dy[4] = {0, 0, -1, 1};
	int dx[4] = {1, -1, 0, 0};

	string s;

	cin >> N;
	for (int y = 0; y < N; y++)
	{
		cin >> s;
		for (int x = 0; x < N; x++)
		{
			switch (s[x])
			{
			case '0':
				apartmentComplex[y][x] = (int)s[x] - 48;
				break;
			case '1':
				apartmentComplex[y][x] = (int)s[x] - 48;
				break;
			default:
				break;
			}
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (apartmentComplex[y][x] == 1 && !visitedSection[y][x])
			{
				visitedSection[y][x] = 1;
				q.push(make_pair(y, x));

				// 단지내 집의 수 카운트
				numOfHouse[orderOfComplex]++;

				while (!q.empty())
				{
					int nowY = q.front().first;
					int nowX = q.front().second;

					q.pop();
					
					for (int i = 0; i < 4; i++)
					{
						int nextY = nowY + dy[i];
						int nextX = nowX + dx[i];

						if ((0 <= nextX && nextX < N) 
							&& (0 <= nextY && nextY < N) 
							&& apartmentComplex[nextY][nextX] == 1 
							&& !visitedSection[nextY][nextX]
							)
						{
							visitedSection[nextY][nextX] = 1;
							q.push(make_pair(nextY, nextX));

							// 단지내 집의 수 카운트
							numOfHouse[orderOfComplex]++;
						}
					}
				}
				orderOfComplex++;
			}
		}
	}

	sort(numOfHouse.begin(), numOfHouse.begin() + orderOfComplex);

	cout << orderOfComplex << '\n';
	for (int i = 0; i < orderOfComplex; i++)
	{
		cout << numOfHouse[i] << '\n';
	}
}
