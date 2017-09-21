#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE  = 2e5 + 10;

vector <pair<int, pair<int, int> > > cities;
int parent[MAX_SIZE];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	int x, p;
	cin >> n;
	int max_ele = 1;
	int max_p = 0;
	for(int i=1; i<=n; i++) {
		cin >> x >> p;
		cities.push_back(make_pair(x, make_pair(i, p)));
		if(p > max_p) {
			max_p = p;
			max_ele = i;
		}
	}
	parent[max_ele] = -1;
	sort(cities.begin(), cities.end());
	for(int i=0; i<n; i++) {
		int k=i+1;
		int j=i-1;
		int flag = 0;
		if(parent[cities[i].second.first] != -1) {
			while(k < n && j >= 0 && !flag) {
				if(cities[k].first - cities[i].first < cities[i].first - cities[j].first) {
					if(cities[k].second.second > cities[i].second.second) {
						parent[cities[i].second.first] = cities[k].second.first;
						flag = 1;
						// break;
					}
					else {
						k++;
					}
				}
				else if (cities[k].first - cities[i].first == cities[i].first - cities[j].first) {
					if(cities[k].second.second > cities[i].second.second && cities[j].second.second > cities[i].second.second) {
						if(cities[k].second.second > cities[j].second.second) {
							parent[cities[i].second.first] = cities[k].second.first;
							flag = 1;
							// break;
						}
						else {
							parent[cities[i].second.first] = cities[j].second.first;
							flag = 1;
							// break;
						}
					}
					else if(cities[k].second.second > cities[i].second.second) {
						parent[cities[i].second.first] = cities[k].second.first;
						flag = 1;
						// break;
					}
					else if(cities[j].second.second > cities[i].second.second) {
						parent[cities[i].second.first] = cities[j].second.first;
						flag = 1;
						// break;
					}
					else {
						k++;
						j--;
					}
				}
				else {
					if(cities[j].second.second > cities[i].second.second) {
						parent[cities[i].second.first] = cities[j].second.first;
						flag = 1;
						// break;
					}
					else {
						j--;
					}
				}
			}
			while(k < n && !flag) {
				if(cities[k].second.second > cities[i].second.second) {
					parent[cities[i].second.first] = cities[k].second.first;
					flag = 1;
					break;
				}
				else {
					k++;
				}
			}
			while(j >= 0 && !flag) {
				if(cities[j].second.second > cities[i].second.second) {
					parent[cities[i].second.first] = cities[j].second.first;
					flag = 1;
					break;
				}
				else {
					j--;
				}
			}
			// cout << cities[i].second.first << " : " << parent[cities[i].second.first] << " " << cities[i].first << " " << cities[i].second.second <<  endl;
		}
	}
	for(int i=1; i<=n; i++) {
			cout << parent[i] << " ";
		}
		cout << endl;
	return 0;
}