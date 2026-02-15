// 백준 온라인 저지 11726번 https://www.acmicpc.net/problem/11726
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
using namespace std;

int arr[1001] = { 0, 1, 2 };

int MakeATile(int n)
{
	switch (n)
	{
	case 1:
		return arr[1];
	case 2:
		return arr[2];
	}

	for (int i = 3; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 10007;
	}

	return arr[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << MakeATile(n);
}
