// 백준 온라인 저지 1302번 https://www.acmicpc.net/problem/1302
// 제한 시간 : 2초
// 실행 시간 : 0ms

// 1. 입력 받은 책의 제목들을 사전순으로 정렬
// 2. 정렬한 제목들을 탐색해 중복되는 책의 제목을 카운팅
// 3. 가장 많이 팔린 책의 제목과 팔린 수를 저장
// 4. 만약 가장 많이 팔린 책의 제목이 두 개 이상이면, 사전 순서로 가장 앞에 있는 제목을 출력

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 오늘 하루 동안 팔린 책의 개수 입력
	int N;
	cin >> N;

	// 책의 제목들 입력
	vector<string> titlesOfBooks;
	string titleOfABook;

	// 중복되는 책 제목을 세기 위한 pair와 vector
	typedef pair<string, int> p;
	vector<p> countTitlesOfBooks;
	for (int i = 0; i < N; i++)
	{
		cin >> titleOfABook;
		titlesOfBooks.push_back(titleOfABook);
		countTitlesOfBooks.push_back(make_pair(titleOfABook, 0));
	}

	// countTitlesOfBooks 중복 제거
	countTitlesOfBooks.erase(unique(countTitlesOfBooks.begin(), countTitlesOfBooks.end()), countTitlesOfBooks.end());
	
	// 책 제목 사전 순으로 정렬
	sort(titlesOfBooks.begin(), titlesOfBooks.end());
	sort(countTitlesOfBooks.begin(), countTitlesOfBooks.end());

	// 중복되는 책 제목 카운팅
	vector<string>::iterator titlesOfBooksItr = titlesOfBooks.begin();
	while (titlesOfBooksItr != titlesOfBooks.end())
	{
		for (int i = 0; i < countTitlesOfBooks.size(); i++)
		{
			if (countTitlesOfBooks[i].first == *titlesOfBooksItr)
			{
				countTitlesOfBooks[i].second++;
				break;
			}
		}
		titlesOfBooksItr++;
	}

	int maxNumOfBooks = 0;
	int indexOfMaxNum = 0;
	for (int i = 0; i < countTitlesOfBooks.size(); i++)
	{
		if (countTitlesOfBooks[i].second > maxNumOfBooks)
		{
			maxNumOfBooks = countTitlesOfBooks[i].second;
			indexOfMaxNum = i;
		}
	}
	cout << countTitlesOfBooks[indexOfMaxNum].first;
}
