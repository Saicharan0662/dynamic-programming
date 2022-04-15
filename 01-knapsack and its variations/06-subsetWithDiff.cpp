#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int countOfSubsetSum(int *arr, int target, int n){
	for(int i=0; i<=target; i++) dp[0][i] = 0;
	for(int i=0; i<=n; i++) dp[i][0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=target; j++){
			if(arr[i-1] <= j)
				dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
			else dp[i][j] = dp[i-1][j];
		}
	}
	
	return dp[n][target];
}

int subsetWithDiff(int *arr, int diff, int n){
	int sum = 0;
	for(int i=0; i<n; i++) sum += arr[i];
	
	int sum1 = (diff + sum)/2;
	
	return countOfSubsetSum(arr, sum1, n);
}

int main(){
	int arr[] = {1, 1, 2, 3};
	int n = sizeof(arr)/sizeof(int);
	int diff = 1;
	memset(dp, 0, sizeof(dp));
	
	cout<<subsetWithDiff(arr, diff, n);
	
	return 0;
}
