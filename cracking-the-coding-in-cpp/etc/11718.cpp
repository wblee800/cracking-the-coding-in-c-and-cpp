// 백준 온라인 저지 11718번 https://www.acmicpc.net/problem/11718
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	for (int i = 0; i < 100; i++)
	{
		getline(cin, input);
		if (input != "\0")
		{
			cout << input << '\n';
			input = "\0";
		}
	}
}
