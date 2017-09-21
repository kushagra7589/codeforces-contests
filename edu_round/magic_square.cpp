#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 50;

int grid[MAX_SIZE][MAX_SIZE];

int odd[MAX_SIZE*MAX_SIZE];
int even[MAX_SIZE*MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1, j=0; i<=n*n; i+=2, ++j) {
		odd[j] = i;
	}
	for(int i=2, j=0; i<=n*n; i+=2, ++j) {
		even[j] = i;
		// cerr << even[j] << " ";
	}
	// cerr <<  endl;
	for(int i=0; i<MAX_SIZE; i++) {
		for(int j=0; j<MAX_SIZE; j++)
			grid[i][j] = 0;
	}
	int counter = 0;
	for(int i=1, j=0; i<=n && j <= n/2; i += 2, ++j) {
		// cerr << "loop 1" << endl;
		// cerr << "ROW: " << j << "No of odd's " << i << endl;
		// cerr << j << " : " << n/2 - i/2 << " " << n/2 + i/2 << endl ;
		for(int k=n/2 - i/2; k <= n/2 + i/2; k++) {
			// cerr << "loop 1.1 ";
			// cerr << k << " " << odd[counter] << endl;  
			grid[j][k] = odd[counter];
			counter++; 
		}
		// cout << endl ; 
	}
	for(int i=n-2, j=n/2 + 1; i>=1 && j<n; i-=2,  ++j) {
		// cerr << "loop 2 " << endl;
		// cerr << j << " : " << n/2 - i/2 << " " << n/2 + i/2 << endl ;
		// cerr << "ROW: " << j << "No of odd's " << i << endl;
		for(int k=n/2 - i/2; k <= n/2 + i/2; k++) {
			// cerr << "loop 2.2" << endl;
			// cerr << "loop 2.1 ";
			// cerr << k << " " << odd[counter] << endl;
			grid[j][k] = odd[counter];
			// cout << "j : " << j << " k : " << k << " grid[j][k] : " << grid[j][k] << endl;
			counter++; 
		}
		// cout << endl;
	}
	// for(int i=0; i<n; i++) {
	// 	for(int j=0; j<n; j++) {
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	counter = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(grid[i][j] == 0) {
				grid[i][j] = even[counter];
				counter++;
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}