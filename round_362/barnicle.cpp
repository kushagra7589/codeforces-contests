#include <bits/stdc++.h>

using namespace std;

int main(){
	string input;
	cin>>input;
	int last = input.length();
	// cout<<last<<endl;
	// cout<<input[last-1]<<endl;
	char a = input[0];
	char dot = '.';
	string d;
	int i;
	for(i=2; input[i] != 'e'; i++){
		// cout<<input[i]<<" ";
		d.append(string(1, input[i]));
	}
	// cout<<endl;
	i++;
	string b;
	for(i; i < last; i++){
		b.append(string(1, input[i]));
	}
	// cout<<"a = "<<a<<" d = "<<d<<" b = "<<b<<endl;
	int num = stoi(b);
	string output;
	output.append(string(1, a));
	if(d.length() == 1 && d[0] == '0'){
		if(num > 0)
			output.append(string(num, '0'));
	}
	else if(d.length() <= num){
		output.append(d);
		if(num - d.length() > 0){
			output.append(string(num - d.length(), '0'));
		}
	}
	else{
		if(num > 0){
			output.append(d.substr(0, num));
		}
		output.append(string(1, dot));
		output.append(d.substr(num));

	}
	cout<<output<<endl;
	return 0;
}