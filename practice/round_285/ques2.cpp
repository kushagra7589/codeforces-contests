#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> handle;
std::vector<string> v;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	int users = 0;
	string old, newer;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> old >> newer;
		handle[old] = newer;
		v.push_back(old);
	}
	unordered_map<string, string> temp;
	// for(unordered_map<string,string>::iterator i = temp.begin(); i != temp.end(); i++)
	// {
	// 	if(handle.find(i))
	// }
	vector<pair<string, string> > final;
	for(int i=0; i<v.size(); i++)
	{
		string search_string = "";
		if(handle.find(v[i]) != handle.end())
			search_string = handle[v[i]];
		while(handle.find(search_string) != handle.end())
		{
			string prev=search_string;
			search_string = handle[search_string];
			handle.erase(prev);
		}
		if(search_string != "")
			final.push_back(make_pair(v[i], search_string));
	}
	cout << final.size() << endl;
	for(int i=0; i<final.size(); i++)
	{
		cout << final[i].first << " " << final[i].second << endl;
	}
	return 0;
}