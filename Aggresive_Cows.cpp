#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

bool isPossible(vector<int> &ds, int cows, int n, int mid)
{
	int cowsCnt = 1;
	int lastPos = ds[0];
	
	for(int i = 0; i < n; ++i)
	{
		if(ds[i] - lastPos >= mid)
		{
			cowsCnt++;
			if(cowsCnt == cows)
			{
				return true;
			}
			lastPos = ds[i];
		}
	}
	return false;
}


int aggresiveCows(vector<int> &ds, int cows)
{
	sort(ds.begin(), ds.end());
	
	int s = 0;
	int n = ds.size();
	
	int e = ds[n-1];
	int ans = -1;
	
	int mid = s + (e-s)/2;
	
	while(s <= e)
	{
		if(isPossible(ds, cows, n, mid))
		{
			ans = mid;
			s = mid+1; //Since, we want the max value so we move toward the right part
		}
		else
		{
			e = mid-1;
		}
		mid = s + (e-s)/2;
	}
	return ans;
}

int main()
{
	vector<int> ds = {4,2,1,3,6};
	int cows = 2;
	
	int maxdis = aggresiveCows(ds, cows);
	
	cout << maxdis << endl;
	
	return 0;
}