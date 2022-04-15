#include<bits/stdc++.h>
using namespace std;

// recursive solution
int knapsack(int *wt, int *val, int W, int n){
	if(n==0 || W == 0) return 0;
	
	if(wt[n-1] <= W)
		return max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
	return knapsack(wt, val, W, n-1);
}

// memoization solution
int dp[100][100];
int knapsack_M(int *wt, int *val, int W, int n){
	if(n==0 || W==0) return 0;
	if(dp[n][W] != -1) return dp[n][W];
	
	if(wt[n-1] <= W){
		dp[n][W] = max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
		return dp[n][W];
	}
	dp[n][W] = knapsack(wt, val, W, n-1);
	return dp[n][W];
}

// tabulation solution
int knapsack_T(int *wt, int *val, int W, int n){
	for(int i=0; i<=n; i++) dp[i][0] = 0;
	for(int i=0; i<=W; i++) dp[0][i] = 0;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=W; j++){
			if(wt[i-1] <= j)
				dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	
	return dp[n][W];
}

int main(){
	int val[] = { 10, 40, 30, 50 }; 
	int wt[] = { 5, 4, 6, 3 }; 
	int W = 10; 
	int n = 4;
	
	memset(dp, -1, sizeof(dp));
	//	memset(dp, 0, sizeof(dp)); // for memoization solution
	cout<<knapsack_T(wt, val, W, n);
	
	return 0;
}
