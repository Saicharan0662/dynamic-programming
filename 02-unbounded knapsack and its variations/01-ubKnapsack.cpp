#include<bits/stdc++.h>
using namespace std;

// recursive solution
int ubKnapsack(int *val, int *wt, int W, int n){
	if(n == 0 || W == 0) return 0;
	
	if(wt[n-1] <= W)
		return max(val[n-1] + ubKnapsack(val, wt, W-wt[n-1], n), ubKnapsack(val, wt, W, n-1));
	else return ubKnapsack(val, wt, W, n-1);
}

// memoization solution
int dp[100][100];
int ubKnapsack_M(int *val, int *wt, int W, int n){
	if(n == 0 || W == 0) return 0;
	
	if(dp[n][W] != -1) return dp[n][W];
	
	if(wt[n-1] <= W)
		return dp[n][W] = max(val[n-1] + ubKnapsack(val, wt, W-wt[n-1], n), ubKnapsack(val, wt, W, n-1));
	else return dp[n][W] = ubKnapsack(val, wt, W, n-1);
}

// tabulation solution
int ubKnapsack_T(int *val, int *wt, int W, int n){
	for(int i=0; i<=W; i++) dp[0][i] = 0;
	for(int i=0; i<=n; i++) dp[i][0] = 0;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=W; j++){
			if(wt[i-1] <= j){
				dp[i][j] = max(val[i-1] + dp[i][j - wt[i-1]], dp[i-1][j]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
	
	return dp[n][W];
}

int main(){
	int val[] = {10, 40, 50, 70};
	int wt[] = {1, 3, 4, 5};
	int n = sizeof(wt)/sizeof(int);
	int W = 8;
	
	memset(dp, -1, sizeof(dp));
//	memset(dp, 0, sizeof(dp)); // for memoization solution
	cout<<ubKnapsack_T(val, wt, W, n);
	
	return 0;
}
