#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int a, b;
	int m = 0;
	int c = 0;
	for(int i=0; i<n; i++){
		cin>>a>>b;
		if(a>b)
			m++;
		else if(a < b)
			c++;
	}
	if(m > c)
		cout<<"Mishka";
	else if(m < c)
		cout<<"Chris";
	else
		cout<<"Friendship is magic!^^";
	cout<<endl;
	return 0;
}