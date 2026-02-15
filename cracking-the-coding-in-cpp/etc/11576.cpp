// 백준 온라인 저지 11576번 https://www.acmicpc.net/problem/11576
// 제한 시간 : 2초
// 실행 시간 : 0ms

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int radix_a, radix_b;
	cin >> radix_a >> radix_b;

	int digitCnt;
	cin >> digitCnt;

	vector<int> digitNum;
	int decimalNum = 0;
	
	int tmp;
	for (int i = 0; i < digitCnt; i++)
	{
		cin >> tmp;
		digitNum.push_back(tmp);
	}
	
	for (int i = 0; i < digitCnt; i++)
	{
		decimalNum += pow(radix_a, digitCnt - (1 + i)) * digitNum[i];
	}

	vector<int> radix_b_number;
	while (decimalNum > 0)
	{
		radix_b_number.push_back(decimalNum % radix_b);
		decimalNum /= radix_b;
	}

	
	for (vector<int>::reverse_iterator r_itr = radix_b_number.rbegin(); r_itr != radix_b_number.rend(); r_itr++)
	{
		cout << *r_itr << " ";
	}
}
