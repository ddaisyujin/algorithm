#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void change(string& str, bool flag, int dir)
{
	if (flag == true && dir == 1) // 시계방향
	{
		int len = str.length();
		char imsi = str[len-1];
		for (int i = len - 1; i >=1 ; i--) {
			str[i] = str[i - 1];
		}
		str[0] = imsi;
	}
	else if (flag == true && dir == -1) //반시계방향
	{
		int len = str.length();
		char imsi = str[0];
		for (int i = 0; i < len - 1; i++) {
			str[i] = str[i + 1];
		}
		str[len-1] = imsi;
	}
}

int main()
{
	string T[4];

	getline(cin, T[0]);
	getline(cin, T[1]);
	getline(cin, T[2]);
	getline(cin, T[3]);


	int K;
	int idx, dir;
	// 1 시계(오), -1 반시계(왼)
	// 짝수 num은 1 시계(왼), -1 반시계(오)

	cin >> K;
	for (int j = 0; j < K; j++)
	{

		bool flag[4] = { false,false,false,false };

		cin >> idx >> dir;

		// 바퀴가 다른 극끼리 맞물려있는가?-----------
		flag[idx - 1] = true;

		for (int i = idx - 1; i < 3; i++)
		{
			if (T[i][2] != T[i + 1][6])
				flag[i + 1] = true;
			else
				break;
		}
		for (int i = idx - 1; i > 0; i--)
		{
			if (T[i][6] != T[i - 1][2])
				flag[i - 1] = true;
			else
				break;
		}

		// 바퀴 회전시키기--------------------------
		if (idx % 2 == 0)
		{
			change(T[0], flag[0], dir*(-1));
			change(T[1], flag[1], dir);
			change(T[2], flag[2], dir*(-1));
			change(T[3], flag[3], dir);
		}
		else
		{
			change(T[0], flag[0], dir);
			change(T[1], flag[1], dir*(-1));
			change(T[2], flag[2], dir);
			change(T[3], flag[3], dir*(-1));
		}

	}

	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		if (T[i][0] == '1')
		{
			sum += pow(2,i);
		}
	}

	printf("%d", sum);
}