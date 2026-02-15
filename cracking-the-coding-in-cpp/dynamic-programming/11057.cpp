// 백준 온라인 저지 11057번 https://www.acmicpc.net/problem/11057
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

	vector<int> zeroAtTheEnd(1001, 1);
	vector<int> oneAtTheEnd(1001, 1);
	vector<int> twoAtTheEnd(1001, 1);
	vector<int> threeAtTheEnd(1001, 1);
	vector<int> fourAtTheEnd(1001, 1);
	vector<int> fiveAtTheEnd(1001, 1);
	vector<int> sixAtTheEnd(1001, 1);
	vector<int> sevenAtTheEnd(1001, 1);
	vector<int> eightAtTheEnd(1001, 1);
	vector<int> nineAtTheEnd(1001, 1);

	for (size_t i = 2; i <= 1000; i++)
	{
		oneAtTheEnd[i] = (zeroAtTheEnd[i - 1] % 10007) + (oneAtTheEnd[i - 1] % 10007);
		twoAtTheEnd[i] = (oneAtTheEnd[i] % 10007) + (twoAtTheEnd[i - 1] % 10007);
		threeAtTheEnd[i] = (twoAtTheEnd[i] % 10007) + (threeAtTheEnd[i - 1] % 10007);
		fourAtTheEnd[i] = (threeAtTheEnd[i] % 10007) + (fourAtTheEnd[i - 1] % 10007);
		fiveAtTheEnd[i] = (fourAtTheEnd[i] % 10007) + (fiveAtTheEnd[i - 1] % 10007);
		sixAtTheEnd[i] = (fiveAtTheEnd[i] % 10007) + (sixAtTheEnd[i - 1] % 10007);
		sevenAtTheEnd[i] = (sixAtTheEnd[i] % 10007) + (sevenAtTheEnd[i - 1] % 10007);
		eightAtTheEnd[i] = (sevenAtTheEnd[i] % 10007) + (eightAtTheEnd[i - 1] % 10007);
		nineAtTheEnd[i] = (eightAtTheEnd[i] % 10007) + (nineAtTheEnd[i - 1] % 10007);
	}

	cout << ((zeroAtTheEnd[N] % 10007)
		+ (oneAtTheEnd[N] % 10007)
		+ (twoAtTheEnd[N] % 10007)
		+ (threeAtTheEnd[N] % 10007)
		+ (fourAtTheEnd[N] % 10007)
		+ (fiveAtTheEnd[N] % 10007)
		+ (sixAtTheEnd[N] % 10007)
		+ (sevenAtTheEnd[N] % 10007)
		+ (eightAtTheEnd[N] % 10007)
		+ (nineAtTheEnd[N] % 10007)) % 10007;
}