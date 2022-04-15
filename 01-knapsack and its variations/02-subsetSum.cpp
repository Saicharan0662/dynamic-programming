#include<bits/stdc++.h>
using namespace std;

// recursive solution
bool isSubsetSum(int *arr, int target, int n){
	if(target == 0 && n == 0) return true;
	if(target == 0) return true;
	if(n==0) return false;
	
	if(arr[n-1] <= target)
		return isSubsetSum(arr, target, n-1) || isSubsetSum(arr, target-arr[n-1], n-1);
	else return isSubsetSum(arr, target, n-1);
}

// memoization solution
int dp[100][100];
bool isSubsetSum_M(int *arr, int target, int n){
	if(target == 0 && n == 0) return true;
	if(target == 0) return true;
	if(n==0) return false;
	
	if(dp[n][target] != -1) return dp[n][target];
	
	if(arr[n-1] <= target)
		return dp[n][target] = isSubsetSum(arr, target, n-1) || isSubsetSum(arr, target-arr[n-1], n-1);
	else return dp[n][target] = isSubsetSum(arr, target, n-1);
}

// tabulation solution
bool isSubsetSum_T(int *arr, int target, int n){
	for(int i=0; i<=target; i++) dp[0][i] = 0;
	for(int i=0; i<=n; i++) dp[i][0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=target; j++){
			if(arr[i-1] <= j)
				dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
			else dp[i][j] = dp[i-1][j];
		}
	}
	
	return dp[n][target];
}

int main(){
	
	int arr[] = {2, 3, 7, 8, 10};
	int n = 5;
	int target = 25;
	memset(dp, -1, sizeof(dp));
	
	cout<<isSubsetSum_M(arr, target, n);
	
	return 0;
}
