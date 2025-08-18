#include <iostream>
using namespace std;

const int INF = INT_MAX;

int upperBound(int arr[], int target, int N)
{
	int l = 0, r = N - 1;
	while( l <= r )
	{
		int mid = l + (r - l) / 2;

		if( arr[mid] <= target )
			l = mid + 1;
		else 
			r = mid - 1;
	}
	return (l < N ? arr[l] : INF);
}

int lowerBound(int arr[], int target, int N)
{
	int l = 0, r = N - 1;
	while( l <= r )
	{
		int mid = l + (r - l) / 2;

		if( arr[mid] >= target )
			r = mid - 1;
		else 
			l = mid + 1;
	}
	return (r >= 0 ? arr[r] : -INF);
}

int main()
{
	const int N = 5;
	int arr[N] = {1,2,3,4,5};
	
	int target = 2;

	cout << "target:      " << target << endl;

	cout << "upper bound: " << upperBound(arr,target,N) << endl;
	cout << "lower bound: " << lowerBound(arr,target,N) << endl;

}
