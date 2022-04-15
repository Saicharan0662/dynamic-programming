#include<bits/stdc++.h>
using namespace std;
// longest repeated subsequence

int lrs(string s1, int n){
	int dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));
	
	for(int i=0; i<=n; i++){
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if((s1[i-1] == s1[j-1]) && (i != j))
				dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	return dp[n][n];
}

int main(){
	string s1 = "axxxy";
	
	cout<<lrs(s1, s1.length());
	
	return 0;
}
