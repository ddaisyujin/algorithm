#include <algorithm>
#include <iostream>
#define INF 987654321

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int* value = new int[n+1];

	value[1] = 0;
	for (int x = 2; x <= n; x++)
	{
		value[x] = INF;

		if ( x%2 == 0 )
		{
			value[x] = min(value[x/2] + 1, value[x]);
		}
		if( x % 3 == 0 )
		{
			value[x] = min(value[x / 3] + 1, value[x]);
		}
			value[x] = min(value[x - 1] + 1, value[x]);
		}

	printf("%d", value[n]);
}