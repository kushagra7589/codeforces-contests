#include <bits/stdc++.h>

using namespace std;

string names[] =  {"Aa", "Ab", "Ac", "Ad", "Ae", "Af", "Ag", "Ah", "Ai", "Aj", "Ak", "Al", "Am", "An", "Ao", "Ap", "Aq", "Ar", "As", "At", "Au", "Av", "Aw", "Ax", "Ay", "Az", "Ba", "Bb", "Bc", "Bd", "Be", "Bf", "Bg", "Bh", "Bi", "Bj", "Bk", "Bl", "Bm", "Bn", "Bo", "Bp", "Bq", "Br", "Bs", "Bt", "Bu", "Bv", "Bw", "Bx", "By", "Bz"};

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string what;
	int arr[52];
	for(int i = 1; i <= n - k + 1; i++)
	{
		cin >> what;
		if(what == "NO")
		{
			arr[i] = 0;
		}
		else
		{
			arr[i] = 1;
		}
	}
	int x = 0;
	int done[52];
	for(int i=0; i<52; i++)
		done[i] = -1;
	for(int i = 1; i <= n - k + 1; i++)
	{
		if(arr[i])
		{
			for(int j=i; j < i + k - 1; j++)
			{
				if(done[j] == -1)
				{
					done[j] = x;
					x++;
				}
			}
		}
		else
		{
			if(done[i] == -1)
			{
				done[i] = done[i + k - 1] = x;
				x++;
			}
			else
			{
				done[i + k - 1] = done[i];
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(done[i] == -1)
		{
			done[i] = x;
			x++;
		}
	}

	for(int i = 1; i <= n; i++)
	{
		cout << names[done[i]] << " ";
	}
	cout << endl;
	return 0;
}