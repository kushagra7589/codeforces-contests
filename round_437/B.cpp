#include <bits/stdc++.h>

using  namespace std;

typedef long long ll;

#define pb push_back
#define  F first
#define S second
#define fast_cin() ios_base::sync_with_stdio(false)

int main()
{
	int n;
	cin >> n;
	if(n == 1)
	{
		printf("%d %d\n%d\n", 5, 1, 5);
		return 0;
	}
	int N = (n - 1) * 10;
	int M = 2;
	int a = 2, b = 5;
	printf("%d %d\n%d %d\n", N, M, a, b);
	return 0;
}