// 백준 온라인 저지 11727번 https://www.acmicpc.net/problem/11727
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	int arr[1001] = { 0, 1, 3};

	for (int i = 3; i < 1001; i++)
	{
		arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % 10007;
	}

	cout << arr[n];
}
