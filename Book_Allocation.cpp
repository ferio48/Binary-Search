#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

bool isPossible(vector<int> &book, int m, int n, int mid)
{
	int studentCnt = 1;
	int pageCnt = 0;
	
	for(int i = 0; i < n; ++i)
	{
		if(pageCnt + book[i] <= mid)
		{
			pageCnt += book[i];
		}
		else
		{
			studentCnt++;
			if(studentCnt > m || book[i] > mid)
			{
				return false;
			}
			pageCnt = book[i];
		}
	}
	return true;
}

int allocateBook(vector<int> &book, int m)
{
	int s = 0, n = book.size();
	
	int sum = 0;
	
	for(int i = 0; i < n; ++i)
	{
		sum += book[i];
	}
	
	int e = sum;
	int ans = -1;
	
	int mid = s + (e - s)/2;
	
	while(s <= e)
	{
		if(isPossible(book, m, n, mid))
		{
			ans = mid;
			e = mid-1;
		}
		else
		{
			s = mid+1;
		}
		mid = s + (e-s)/2;
	}
	return ans;
}

int main()
{
	vector<int> book = {5,10,30,20,15};
	
	int m = 3;
	
	int ans = allocateBook(book, m);
	
	// int x = 0/2;
	
	cout << ans << endl;
	
	return 0;
}