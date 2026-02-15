// 백준 온라인 저지 9996번 https://www.acmicpc.net/problem/9996
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<string> words(N);

	string pattern;
	cin >> pattern;

	string patternBeforeAsterisk;
	for (int i = 0; i < pattern.find('*'); i++)
	{
		patternBeforeAsterisk.push_back(pattern[i]);
	}

	string patternAfterAsterisk;
	for (int i = pattern.find('*') + 1; i < pattern.size(); i++)
	{
		patternAfterAsterisk.push_back(pattern[i]);
	}

	string fWord;
	string bWord;
	for (int i = 0; i < N; i++)
	{
		cin >> words[i];

		if (words[i].size() < patternBeforeAsterisk.size() + patternAfterAsterisk.size())
		{
			cout << "NE" << '\n';
			continue;
		}

		fWord = words[i].substr(0, patternBeforeAsterisk.size());
		bWord = words[i].substr(words[i].size() - patternAfterAsterisk.size());

		// pattern 중 * 전에 나온 pattern과 같은 값이 존재하지 않으면,
		if (fWord.find(patternBeforeAsterisk) == string::npos)
		{
			cout << "NE" << '\n';
		}
		// 존재하면,
		else
		{
			// pattern 중 * 후에 나온 pattern과 같은 값이 존재하지 않으면,
			if (bWord.find(patternAfterAsterisk) == string::npos)
			{
				cout << "NE" << '\n';
			}
			// 존재하면,
			else
			{
				cout << "DA" << '\n';
			}
		}
	}
}
