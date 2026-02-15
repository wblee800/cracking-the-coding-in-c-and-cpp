// 백준 온라인 저지 4949번 https://www.acmicpc.net/problem/4949
// 제한 시간 : 1초
// 실행 시간 : 132ms

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// *(parenthesesOrBrackets.end() - 1)를 stack을 사용해 top으로 변경
// 스택, 큐는 순회를 할 수 있어도 하지 않는다.

int main()
{
	string sentence; // 문장을 담을 string
	stack<string> parenthesesOrBrackets; // () and []를 담는 stack

	getline(cin, sentence); // 공백을 포함한 문자열을 입력 후, sentence에 할당
	
	// sentence의 문자열이 "."이 아니면 반복
	while (sentence != ".")
	{
		for (int i = 0; i < sentence.size(); i++)
		{
			// 문자열 중 현재 문자가 여는 소괄호(parentheses)라면,
			if (sentence[i] == '(')
			{
				// parenthesesOrBrackets stack에 "(" push
				parenthesesOrBrackets.push("(");
			}
			// 문자열 중 현재 문자가 닫는 소괄호(parentheses)라면,
			else if (sentence[i] == ')')
			{
				// 괄호들을 담는 stack이 비어있거나 top의 값이 "(" 아니라면,
				if (parenthesesOrBrackets.empty() || parenthesesOrBrackets.top() != "(")
				{
					// 최종적으로 비어있는 값은 짝을 모두 찾았다는 의미이므로 짝이 안 맞게 ")" push
					parenthesesOrBrackets.push(")");
					cout << "no\n";
					break;
				}
				// top이 "("라면,
				else if (parenthesesOrBrackets.top() == "(")
				{
					// parenthesesOrBrackets stack에서 "(" 꺼내기
					parenthesesOrBrackets.pop();
				}
			}
			// 문자열 중 현재 문자가 여는 대괄호(brackets)라면,
			else if (sentence[i] == '[')
			{
				// parenthesesOrBrackets stack에 "[" push
				parenthesesOrBrackets.push("[");
			}
			// 문자열 중 현재 문자가 닫는 대괄호(brackets)라면,
			else if (sentence[i] == ']')
			{
				// 괄호들을 담는 stack이 비어있거나 top의 값이 "["가 아니라면,
				if (parenthesesOrBrackets.empty() || parenthesesOrBrackets.top() != "[")
				{
					// 최종적으로 비어있는 값은 짝을 모두 찾았다는 의미이므로 짝이 안 맞게 "]" push
					parenthesesOrBrackets.push("]");
					cout << "no\n";
					break;
				}
				// top이 "["라면,
				else if (parenthesesOrBrackets.top() == "[")
				{
					// parenthesesOrBrackets stack에서 "[" 꺼내기
					parenthesesOrBrackets.pop();
				}
			}
		}

		// ()와 []가 모두 짝을 맞췄다면,
		if (parenthesesOrBrackets.empty())
		{
			// "yes"출력
			cout << "yes\n";
		}
		// parenthesesOrBrackets가 비어있지 않다면,
		else
		{
			// stack의 top이 "("나 "["라면,
			if (parenthesesOrBrackets.top() == "(" || parenthesesOrBrackets.top() == "[")
			{
				// "no" 출력
				cout << "no\n";
			}
			
			while (!parenthesesOrBrackets.empty())
			{
				// parenthesesOrBrackets에 있는 값 빼내기
				parenthesesOrBrackets.pop();
			}
		}

		getline(cin, sentence); // 공백을 포함한 문자열을 입력 후, sentence에 할당
	}
}
