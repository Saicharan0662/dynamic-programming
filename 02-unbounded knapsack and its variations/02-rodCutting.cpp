#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int maxProfit(int *length, int *price, int n){
	for(int i=0; i<=n; i++) dp[0][i] = 0; 
	for(int i=0; i<=n; i++) dp[i][0] = 0;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(length[i-1] <= j){
				dp[i][j] = max(price[i-1] + dp[i-1][j - length[i-1]], dp[i-1][j]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
	
	return dp[n][n];
}

int main(){
	int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = 8;
	memset(dp, 0, sizeof(dp));
	
	cout<<maxProfit(length, price, n);
	return 0;
}
