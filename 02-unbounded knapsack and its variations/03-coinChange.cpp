#include<bits/stdc++.h>
using namespace std;

// recursive solution
int totalWays(int *coins, int n, int sum){
    if(sum == 0)
        return 1;
    if(sum <  0 || n <= 0)
        return 0;
    return totalWays(coins, n-1, sum) + totalWays(S, n, sum - coins[n-1]);
}

// tabulation solution
int dp[100][100];
int totalWays(int *coins, int n, int sum){
	for(int i=0; i<=sum; i++) dp[0][i] = 0;
	for(int i=0; i<=n; i++) dp[i][0] = 1;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			if(coins[i-1] <= j)
				dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
			else dp[i][j] = dp[i-1][j];
		}
	}
	
	return dp[n][sum];
}

int main(){
	int arr[] = {1, 2, 3};
	int n = 3;
	int sum = 4;
	
	cout<<totalWays(arr, n, sum);
	
	return 0;
}
