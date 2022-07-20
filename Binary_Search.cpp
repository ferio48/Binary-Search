/*
-->Binary search algo:
-->Every iteration converts the size of array
to be searched into half.
-->Check for mid value in every iteration.
Time complexity - O(logn). As every iteration we
are searching the half array either left side
or the right side.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

int binSearchRecursive(int start, int end, vector<int> &nums, int x)
{
	int mid = (start+end)/2;
	
	if(nums[mid] == x)
		return mid;
	else if(nums[mid] > x)
		binSearchRecursive(start, mid-1, nums, x);
	else
		binSearchRecursive(mid+1, end, nums, x);
}

int binarySearch(vector<int> &nums, int x)
{
	int n = nums.size();
	int a = binSearchRecursive(0, n, nums, x);
	
	return a;
}

int binarySearchIterative(vector<int> &nums, int key)
{
	int start = 0;
	int end = nums.size()-1;
	
	int mid = (start+end)/2; // This formula 
	// gives wrong value when the value of start 
	// and end is maximum which is (2^31 - 1)
	// ,so we get mid as (2^31-1 + 2^31-1)/2, 
	// which get out of int range so we get an error. 
	
	while(start <= end)
	{
		if(nums[mid] == key)
			return mid;
		
		if(nums[mid] > key)
			end = mid-1;
		
		else
			start = mid+1;
		
		mid = start + (end - start)/2; //Use this formula instead.
	}
	return -1;
}

int main()
{
	vector<int> nums = {4,6,7,8,5,3,23};
	sort(nums.begin(), nums.end());
	
	int x = 1018 ^ 4;
	
	int i = binarySearchIterative(nums, x);
	
	cout << x << endl;
	
	return 0; 
}