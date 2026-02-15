// 백준 온라인 저지 3085번 https://www.acmicpc.net/problem/3085
// 제한 시간 : 1초
// 실행 시간 : ms

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 보드의 크기 N (3 ≤ N ≤ 50)
	int N;
	cin >> N;

	// 사탕을 담을 보드
	vector<vector<char>> board(N, vector<char> (N));
	// 사탕 색깔(빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y)
	string str;
	for (size_t y = 0; y < N; y++)
	{
		cin >> str;
		istringstream ss(str);
		while (getline(ss, str, ' '))
		{
			for (size_t x = 0; x < str.size(); x++)
			{
				board[y][x] = str[x];
			}
		}
	}
	
	// C, P, Z, Y 각각의 색이 가질 수 있는 사탕의 최대 개수를 구하고 비교해 그 중 최대값 구하기.
	
}