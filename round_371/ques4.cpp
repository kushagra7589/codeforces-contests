#include <bits/stdc++.h>

using namespace std;

void print_q(int x1, y1, x2, y2)
{
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	fflush(stdout);
	int start_x = 1;
	int end_x = n;
	int start_y = 1;
	int end_y = n;
	int output;
	int rect1_x1, rect1_x2, rect1_y1, rect1_y2, rect2_x1, rect2_x2, rect2_y1, rect2_y2;
	while(start_x < end_x)
	{
		int mid = (start_x + end_x)/2;
		print_q(mid, 1, n, n);
		fflush(stdout);
		cin >> output;
		fflush(stdout);
		if(output < 2)
		{
			end_x = mid;
		}
		else
		{
			start_x = mid + 1;
		}
	}
	rect1_x1 = start_x-1;
	start_x-=1;
	end_x = n;
	while(start_x < end_x)
	{
		int mid = (start_x + end_x)/2;
		print_q(mid, 1, n, n);
		fflush(stdout);
		cin >> output;
		fflush(stdout);
		if(output > 0)
		{
			start_x = mid+1;
		}
		else
		{
			end_x = mid;
		}
	}
	rect2_x1 = start_x-1;
	start_x -= 1;
	end_x = n;
	while(start_x < end_x)
	{
		int mid = (start_x + end_x)/2;
		print_q(rect2_x1, 1, mid, n);
		fflush(stdout);
		cin >> output;
		fflush(stdout);
		if(output > 0)
		{
			end_x = mid;
		}
		else
		{
			start_x = mid + 1;
		}
	}
	rect2_x2 = start_x - 1;
	end_x = n;
	print_q(rect1_x1, 1, rect2_x2, n);\
	fflush(stdout);
	cin >> output;
	fflush(stdout)
	int check = (output == 2) ? 2: 1;
	start_x = rect1_x1;
	end_x = n;
	while(start_x < end_x)
	{
		int mid = (start_x + end_x)/2;
		print_q(rect2_x1, 1, mid, n);
		fflush(stdout);
		cin >> output;
		fflush(stdout);
		if(output >= check)
		{
			end_x = mid;
		}
		else
		{
			start_x = mid + 1;
		}
	}
	rect1_x2 = start_x - 1;
	while(start_y < end_y)
	{
		int mid = (start_y + end_y)/2;
		print_q(rect2_x1, mid, n, n);
		fflush(stdout);
		cin >> output;
		fflush(stdout);
		if(output > 0)
		{
			end_y = mid;
		}
		else
		{
			start_y = mid+1;
		}
	}
	rect2_y1 = start_y - 1;
	end_y = n;
	start_y = rect2_y1;
	while(start_y < end_y)
	{
		int mid = (start_y + end_y)/2;
		print_q(rect2_x1, rect2_y1, n, mid);
		fflush(stdout);
		cin >> output;
		fflush(stdout);
		if(output > 0)
		{
			end_y = mid;
		}
		else
		{
			start_y = mid+1;
		}
	}
	rect2_y2 = start_y -1;
	end_y = n;
	print_q(1, 1, n, rect2_y2);
	fflush(stdout);
	cin >> output;
	fflush(stdout);
	check = (output == 2) ? 2 : 1;
	start_y = 1;
	end_y = (output == 2) ? rect2_y2 - 1 : n;
	while(start_y < end_y)
	{
		int mid = (start_y + end_y)/2;
		print_q(1, 1, n, mid);
		fflush(stdout);
		cin >> output;
		fflush(stdout);
		if(output >= check)
		{
			end_y = mid;
		}
		else
		{
			start_y = mid+1;
		}
	}	
  	return 0;
}