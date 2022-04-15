#include<bits/stdc++.h>
using namespace std;

// recurssive solution
int countOfSubsetSum(int *arr, int target, int n){
	if(n == 0 && target == 0) return 1;
	if(target == 0) return 1;
	if(n == 0) return 0;
	
	if(arr[n-1] <= target)
		return countOfSubsetSum(arr, target, n-1) + countOfSubsetSum(arr, target-arr[n-1], n-1);
	else return countOfSubsetSum(arr, target, n-1);
}

// memoization solution
int dp[100][100];
int countOfSubsetSum_M(int *arr, int target, int n){
	if(n == 0 && target == 0) return 1;
	if(target == 0) return 1;
	if(n == 0) return 0;
	
	if(dp[n][target] != -1) return dp[n][target];
	
	if(arr[n-1] <= target)
		dp[n][target] = countOfSubsetSum_M(arr, target, n-1) + countOfSubsetSum_M(arr, target-arr[n-1], n-1);
	else return countOfSubsetSum_M(arr, target, n-1);
	return dp[n][target];
}

// tabulation solution
int dp2[100][100];
int countOfSubsetSum_T(int *arr, int target, int n){
	for(int i=0; i<=target; i++) dp2[0][target] = 0;
	for(int i=0; i<=n; i++) dp2[i][0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=target; j++){
			if(arr[i-1] <= j)
				dp2[i][j] = dp2[i-1][j] + dp2[i-1][j - arr[i-1]];
			else dp2[i][j] = dp2[i-1][j];
		}
	}
	
	return dp2[n][target];
}

int main(){
	int arr[] = {2, 3, 5, 4, 1};
	int n = 5;
	int target = 7;
	memset(dp, -1, sizeof(dp));
	memset(dp2, 0, sizeof(dp2)); // for tabulation
	
	cout<<countOfSubsetSum_M(arr, target, n);
	
	return 0;
}
