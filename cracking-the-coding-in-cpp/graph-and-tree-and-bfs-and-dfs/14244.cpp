// 백준 온라인 저지 14244번 https://www.acmicpc.net/problem/14244
// 제한 시간 : 2초
// 실행 시간 : 0ms

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m - 1; ++i)
	{
		cout << i << ' ' << m - 1 << '\n';
	}
		
	for (int i = m - 1; i < n - 1; ++i)
	{
		cout << i << ' ' << i + 1 << '\n';
	}
}