#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
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

bool isEqualSumPartition(int *arr, int n){
	int sum = 0;
	for(int i=0; i<n; i++) sum += arr[i];
	
	if(n%2) return false;
	return isSubsetSum_T(arr, sum/2, n);
}

int main(){
	
	int arr[] = {1, 5, 11, 5};
	int n = 4;
	memset(dp, -1, sizeof(dp));
	cout<<isEqualSumPartition(arr, n);
	
	return 0;
}
