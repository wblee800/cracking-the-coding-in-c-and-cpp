// 백준 온라인 저지 10845번 https://www.acmicpc.net/problem/10845
// 제한 시간 : 0.5초
// 실행 시간 : 4ms

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int X;
	string queueOperator;

	cin >> N;
	int* queue = new int[N];
	int queueFrontPtr = 0;
	int queueBackPtr = -1;

	for (int i = 0; i < N; i++)
	{
		cin >> queueOperator;
		if (queueOperator == "push")
		{
			cin >> X;
			queueBackPtr++;
			queue[queueBackPtr] = X;
		}
		else if (queueOperator == "pop")
		{
			if (queueBackPtr == -1)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << queue[queueFrontPtr] << "\n";

				// 한 칸씩 앞으로 옮기기
				for (int i = queueFrontPtr; i < queueBackPtr; i++)
				{
					queue[i] = queue[i + 1];
				}
				queueBackPtr--;
			}
		}
		else if (queueOperator == "size")
		{
			cout << queueBackPtr + 1 << "\n";
		}
		else if (queueOperator == "empty")
		{
			if (queueBackPtr == -1)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (queueOperator == "front")
		{
			if (queueBackPtr == -1)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << queue[queueFrontPtr] << "\n";
			}
		}
		else if (queueOperator == "back")
		{
			if (queueBackPtr == -1)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << queue[queueBackPtr] << "\n";
			}
		}
	}
}
