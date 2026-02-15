// 백준 온라인 저지 10828번 https://www.acmicpc.net/problem/10828
// 제한 시간 : 0.5초
// 실행 시간 : 0ms

// 핵심 : stack이 비어있는지, 혹은 비어있지 않다면 들어있는 정수의 개수가 몇 개인지 판단 + stack pointer 개념을 이용

#include <iostream>
using namespace std;

void stack_function(int N, int* stack, int* stack_pointer);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	// stack 연습을 위해 STL을 사용하지 않고, 정적 or 동적 배열 사용
	int* stack = new int[N];
	int* stack_pointer = new int(-1);

	stack_function(N, stack, stack_pointer);

	// 메모리 해제
	delete[] stack;
}

void stack_function(int N, int* stack, int* stack_pointer)
{
	string stack_opearion_string;
	int X;

	for (int i = 0; i < N; i++)
	{
		cin >> stack_opearion_string;

		if (stack_opearion_string == "push")
		{
			// stack에 넣을 정수 X 입력
			cin >> X;

			(*stack_pointer)++; // stack top의 위치로 이동
			stack[*stack_pointer] = X; // stack top에 X 대입
		}
		else if (stack_opearion_string == "pop")
		{
			// 만약 stack에 들어있는 정수가 없다면,
			if (*stack_pointer == -1)
			{
				// -1 출력
				cout << -1 << '\n';
			}
			// stack에서 가장 위에 있는 정수를 빼고, 그 수를 출력.
			else
			{
				cout << stack[*stack_pointer] << '\n'; // 가장 위에 있는 정수 출력
				(*stack_pointer)--; // 출력 후 stack_pointer값 1 빼기
			}
		}
		else if (stack_opearion_string == "size")
		{
			// stack에 들어있는 정수의 개수를 출력

			cout << (*stack_pointer) + 1 << '\n';
		}
		else if (stack_opearion_string == "empty")
		{
			// stack이 비어있으면, 1을 출력
			if (*stack_pointer == -1)
			{
				cout << 1 << '\n';
			}
			// 아니면 0을 출력
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (stack_opearion_string == "top")
		{
			// 만약 stack에 들어있는 정수가 없다면,
			if (*stack_pointer == -1)
			{
				// -1을 출력
				cout << -1 << '\n';
			}
			else
			{
				// stack top 출력
				cout << stack[*stack_pointer] << '\n';
			}
		}
	}
}
