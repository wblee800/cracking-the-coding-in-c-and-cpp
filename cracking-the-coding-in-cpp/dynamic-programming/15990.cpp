// 백준 온라인 저지 15990번 https://www.acmicpc.net/problem/15990
// 제한 시간 : 1초 (추가 시간 없음)
// 실행 시간 : 0ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> oneAtTheEnd(100001, 0);
	vector<int> twoAtTheEnd(100001, 0);
	vector<int> threeAtTheEnd(100001, 0);

	oneAtTheEnd[1] = 1;
	twoAtTheEnd[2] = 1;
	oneAtTheEnd[3] = 1;
	twoAtTheEnd[3] = 1;
	threeAtTheEnd[3] = 1;

	for (size_t i = 4; i < 100001; i++)
	{
		// 1로 끝나는 경우
		oneAtTheEnd[i] = (twoAtTheEnd[i - 1] + threeAtTheEnd[i - 1]) % 1000000009;

		// 2로 끝나는 경우
		twoAtTheEnd[i] = (oneAtTheEnd[i - 2] + threeAtTheEnd[i - 2]) % 1000000009;

		// 3으로 끝나는 경우
		threeAtTheEnd[i] = (oneAtTheEnd[i - 3] + twoAtTheEnd[i - 3]) % 1000000009;
	}

	int T;
	cin >> T;

	int n;
	for (size_t i = 1; i <= T; i++)
	{
		cin >> n;

		cout << (((oneAtTheEnd[n] + twoAtTheEnd[n]) % 1000000009)+ threeAtTheEnd[n]) % 1000000009 << '\n';
	}
}