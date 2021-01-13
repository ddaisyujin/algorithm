#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define INF 987654321
#define SZ 50

using namespace std;

bool ready[SZ]; // 값이 채워져있는가
vector<int> value(SZ); // 피보나치 수열값

// D
int fibonacci(int n) {
	
	if (n == 0) {
		value[0] = 0;
		return 0;
	}
	else if (n == 1) {
		value[1] = 1;
		return 1;
	}
	else if (ready[n]) return value[n];
	else {
		ready[n] = true;
		value[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main()
{

	int n,_n;
	scanf("%d", &n);
	vector<int> values;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &_n);
		values.push_back(_n);
	}

	fibonacci(*max_element(values.begin(), values.end())); 
	// 입력값의 최대값 찾기
	// 최댓값 한번 돌면, 배열에 착착착 입력됨

	value.insert(value.begin(), 1);
	// 이 문제(피보나치 수열)에서 발견된 규칙 
	// 1 개수는 피보나치 수열의 숫자와 같고, fibo[n] == 1[n]
	// 0 개수는 n-1번째의 1 개수와 같다. 1[n-1] ==  0[n]

	for (auto x : values)
	{
		printf("%d %d\n", value[x], value[x+1]);
	}
}