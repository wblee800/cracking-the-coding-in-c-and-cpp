// 백준 온라인 저지 1181번 https://www.acmicpc.net/problem/1181
// 제한 시간 : 2초
// 실행 시간 : 52ms

// 핵심 : 길이가 짧은 순, 길이가 같으면 사전 순, 중복 제거

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool SortWords(string a, string b)
{
	if (a == b)
	{
		return 0;
	}
	else if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == b[i])
			{
				continue;
			}
			else
			{
				return a[i] < b[i];
			}
		}
	}
	else
	{
		return a.size() < b.size();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 단어 개수
	int N;
	string word;
	vector<string> words;

	cin >> N;
	// 단어 개수만큼 반복
	for (int i = 0; i < N; i++)
	{
		// 단어 입력
		cin >> word;
		// words에 단어 저장
		words.push_back(word);
	}

	// 길이가 짧은 순으로 정렬 + 길이가 같으면, 사전 순으로 정렬
	sort(words.begin(), words.end(), SortWords);

	// 중복 제거
	words.erase(unique(words.begin(), words.end()), words.end());

	// 조건에 맞게 정렬된 배열의 원소들 출력
	for (string i : words)
	{
		cout << i << "\n";
	}
}
