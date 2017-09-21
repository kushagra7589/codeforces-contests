#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	int n = input.length();
	int i =0 , j = n-1;
	bool  palin = true;
	bool deleted = false;
	int index = -1;
	while(i <= j && palin == true) {
		if(input[i] == input[j]) {
			i++;
			j--;
		}
		else if(input[i] != input[j]) {
			if(input[i+1] == input[j] && !deleted) {
				deleted = true;
				index = i+1;
				i++;
			}
			else if(input[i] == input[j-1] && !deleted) {
				deleted = true;
				index = j+1;
				j--;
			}
			else{
				palin = false;
				break;
			}
		}
	}
	if(palin){

		cout << "YES" << endl ;
		if(deleted == false)
			index = i;
		cout << index << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}