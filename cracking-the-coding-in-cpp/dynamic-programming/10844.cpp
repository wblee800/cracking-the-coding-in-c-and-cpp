// 백준 온라인 저지 10844번 https://www.acmicpc.net/problem/10844
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <vector>
using namespace std;

#define TENBILLION 1000000000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int digit;
	cin >> digit;

	vector<long long> zeroAtTheEnd(101, 0);
	vector<long long> oneAtTheEnd(101, 1);
	vector<long long> twoAtTheEnd(101, 1);
	vector<long long> threeAtTheEnd(101, 1);
	vector<long long> fourAtTheEnd(101, 1);
	vector<long long> fiveAtTheEnd(101, 1);
	vector<long long> sixAtTheEnd(101, 1);
	vector<long long> sevenAtTheEnd(101, 1);
	vector<long long> eightAtTheEnd(101, 1);
	vector<long long> nineAtTheEnd(101, 1);

	for (size_t i = 2; i <= 100; i++)
	{
		zeroAtTheEnd[i] = oneAtTheEnd[i - 1] % TENBILLION;
		oneAtTheEnd[i] = (zeroAtTheEnd[i - 1] + twoAtTheEnd[i - 1]) % TENBILLION;
		twoAtTheEnd[i] = (oneAtTheEnd[i - 1] + threeAtTheEnd[i - 1]) % TENBILLION;
		threeAtTheEnd[i] = (twoAtTheEnd[i - 1] + fourAtTheEnd[i - 1]) % TENBILLION;
		fourAtTheEnd[i] = (threeAtTheEnd[i - 1] + fiveAtTheEnd[i - 1]) % TENBILLION;
		fiveAtTheEnd[i] = (fourAtTheEnd[i - 1] + sixAtTheEnd[i - 1]) % TENBILLION;
		sixAtTheEnd[i] = (fiveAtTheEnd[i - 1] + sevenAtTheEnd[i - 1]) % TENBILLION;
		sevenAtTheEnd[i] = (sixAtTheEnd[i - 1] + eightAtTheEnd[i - 1]) % TENBILLION;
		eightAtTheEnd[i] = (sevenAtTheEnd[i - 1] + nineAtTheEnd[i - 1]) % TENBILLION;
		nineAtTheEnd[i] = eightAtTheEnd[i - 1] % TENBILLION;
	}

	cout << (((zeroAtTheEnd[digit] + oneAtTheEnd[digit]) % TENBILLION) + ((twoAtTheEnd[digit] + threeAtTheEnd[digit]) % TENBILLION) +
		((fourAtTheEnd[digit] + fiveAtTheEnd[digit]) % TENBILLION) + ((sixAtTheEnd[digit] + sevenAtTheEnd[digit]) % TENBILLION) + 
		((eightAtTheEnd[digit] + nineAtTheEnd[digit]) % TENBILLION)) % TENBILLION;
}