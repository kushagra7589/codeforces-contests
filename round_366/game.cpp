#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int flag = -1;
	int input;
	for(int i=0; i<n; i++){
		cin>>input;
		if(input%2 == 0)
			flag = -flag;
		if(flag == 1)
			cout<<1<<endl;
		else if(flag == -1)
			cout<<2<<endl;
	}
	return 0;
}