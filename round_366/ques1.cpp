#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string ans = "I hate";
	for(int i=2; i<=n; i++){
		if(i%2 == 0)
		{
			ans += " that I love";
		}
		else
		{
			ans += " that I hate";
		}
	}
	ans += " it";
	cout<<ans<<endl;
	return 0;
}