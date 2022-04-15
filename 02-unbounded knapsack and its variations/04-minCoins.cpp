#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int minCoins(int *coins, int n, int sum){
	for(int i=0; i<=sum; i++) dp[0][i] = INT_MAX-1; // 0 coins so, we need infinite coins -> mathematicaly 
	for(int i=0; i<=n; i++) dp[i][0] = 0;
	
	// initializing for the first (coins[0]) coin
	for(int i=1; i<=sum; i++){
		if(i%coins[0] == 0)
			dp[1][i] = i/coins[0];
		else dp[1][i] = INT_MAX -1;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			if(coins[i-1] <= j)
				dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	
	return dp[n][sum];
}

int main(){
	int arr[] = {25, 10, 5};
	int n = 3;
	int sum = 30;
	
	cout<<minCoins(arr, n, sum);
	
	return 0;
}
