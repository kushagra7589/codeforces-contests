#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define vi vector<int>

vector<bool> min_numbers;
vector<bool> max_numbers;
set<int> num_min;
set<int> num_max;

void getMaximum1(int a, int b, string res)
{
	if(res == "=")
	{
		max_numbers[b] = false;
	}
	else if(res == "<")
	{
		max_numbers[a] = false;
	}
	else
	{
		max_numbers[b] = false;
	}
}

void getMininimum1(int a, int b, string res)
{
	if(res == "=")
	{
		min_numbers[b] = false;
	}
	else if(res  == "<")
	{
		min_numbers[b] = false;
	}
	else if(res == ">")
	{
		min_numbers[a] = false;
	}
}

string Compare(int a, int b)
{
	string res;
	cout << "? " << a << " " << b << endl;
	fflush(stdout);
	cin >> res;
	fflush(stdout);
	return res;
}

void deleteMin1(int n)
{
	for(int i=1; i<=n; i++)
	{
		if(min_numbers[i] == false)
		{
			if(num_min.find(i) != num_min.end())
				num_min.erase(i);
		}
		
	}
}

void deleteMax1(int n)
{
	for(int i=1; i<=n; i++)
	{
		if(max_numbers[i] == false)
		{
			if(num_max.find(i) != num_max.end())
				num_max.erase(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n; 
		fflush(stdout);
		min_numbers.resize(n+1);
		max_numbers.resize(n+1);
		for(int i=1; i<=n; i++)
		{
			min_numbers[i] = true;
			max_numbers[i] = true;
			num_min.insert(i);
			num_max.insert(i);
		}
		string res;
		if(n > 1)
		{
			auto a = num_min.begin();
			auto b = a;
			b++;
			for(int i=0; i<n-2; i+=2)
			{
				int x = *a;
				int y = *b;
				a++; a++;
				b++; b++;
				res = Compare(x, y);
				getMininimum1(x, y, res);
				getMaximum1(x, y, res);
			}

			auto last = num_min.end();
			last--;
			auto before = last;
			before--;
			int y = *last;
			int x = *before;
			res = Compare(x, y);
			getMininimum1(x, y, res);
			getMaximum1(x, y, res);
			deleteMin1(n);
			deleteMax1(n);
			while(num_min.size() > 1)
			{

				int N = num_min.size();
				auto a = num_min.begin();
				auto b = a;
				b++;
				for(int i=0; i<N-2; i+=2)
				{	
					int x = *a;
					int y = *b;
					a++; a++;
					b++; b++;
					res = Compare(x, y);
					getMininimum1(x, y, res);
				}
				auto last = num_min.end();
				last--;
				auto before = last;
				before--;
				int y = *last;
				int x = *before;
				res = Compare(x, y);
				getMininimum1(x, y, res);
				deleteMin1(n);
			}

			while(num_max.size() > 1)
			{
				auto a = num_max.begin();
				auto b = a;
				b++;
				int N = num_max.size();
				for(int i=0; i<N-2; i+=2)
				{
					int x = *a;
					int y = *b;
					a++; a++;
					b++; b++;
					res = Compare(x, y);
					getMaximum1(x, y, res);
				}
				auto last = num_max.end();
				last--;
				auto before = last;
				before--;
				int y = *last;
				int x = *before;
				res = Compare(x, y);
				getMaximum1(x, y, res);
				deleteMax1(n);
			}

			cout << "! " << *(num_min.begin()) << " " << *(num_max.begin()) << endl;
			fflush(stdout);
		}
		else
		{
			cout << "! 1 1" << endl;
			fflush(stdout); 
		}
		num_min.clear();
		num_max.clear();
	}
}