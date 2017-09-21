#include <bits/stdc++.h>

using namespace std;

int main()
{
	// freopen ("important.in","r+",stdin);
	// freopen ("important.out","w+",stdout);
	int n;
	cin >> n;
	string A;
	char arr[n + 1];
	for(int i = 0; i < n; i++)
	{
		cin >> A;
		arr[i] = A[0];
	}
	cout << "Yes" << endl;
	int i;
	for(i = 1; i < n; i++)
	{
		cout <<  arr[i - 1] << "|" << "~" << arr[i - 1] << "|";
	}
	cout << arr[i - 1] << "|" << "~" << arr[i - 1] << endl;
	return 0;
}