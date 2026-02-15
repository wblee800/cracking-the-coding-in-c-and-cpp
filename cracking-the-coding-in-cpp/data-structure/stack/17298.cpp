// 백준 온라인 저지 17298번 https://www.acmicpc.net/problem/17298
// 제한 시간 : 1초
// 실행 시간 : 816ms

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	vector<int> result(N, -1);
	stack<int> stack;
	for (int i = 0; i < N; i++)
	{
		while (!stack.empty() && A[stack.top()] < A[i])
		{
			result[stack.top()] = A[i];
			stack.pop();
		}
		stack.push(i);
	}

	for (int num : result)
	{
		cout << num << ' ';
	}
}
