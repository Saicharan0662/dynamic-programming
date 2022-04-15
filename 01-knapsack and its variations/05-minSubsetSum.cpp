#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
void subsetSum(int *arr, int n, int range){
	for(int i=0; i<=range; i++) dp[0][i] = 0;
	for(int i=0; i<=n; i++) dp[i][0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=range; j++){
			if(arr[i-1] <= j)
				dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
			else dp[i][j] = dp[i-1][j];
		}
	}
}

int minSubsetSum(int *arr, int n){
	int range = 0;
	for(int i=0; i<n; i++) range += arr[i];
	
	memset(dp, 0, sizeof(dp));
	subsetSum(arr, n, range);
	
	vector<bool> v(range+1, false);
	for(int i=0; i<=range; i++){
		if(dp[n][i] == 1) v[i] = true;
	}
	
	int res = INT_MAX;
	for(int i=0; i<=range/2; i++){
		if(v[i]) res = min(res, range - 2*i);
	}
	
	return res;
}

int main(){
	int arr[] = {1, 3, 7};
	int n = sizeof(arr)/sizeof(int);
	cout<<minSubsetSum(arr, n);
	
	return 0;
}
