#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, s, x;
	cin>>t>>s>>x;
	if(x - t < 0){
		cout<<"NO"<<endl;
	}
	else if(x == t+1){
		cout<<"NO"<<endl;
	}
	else if((x-t)%s == 0 || (x-t)%s == 1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}