#include<bits/stdc++.h>
using namespace std;

int minOperations(string s1, string s2, int n, int m){
	int dp[n+1][m+1];
	memset(dp, -1, sizeof(dp));
	
	for(int i=0; i<=n; i++) dp[i][0] = 0;
	for(int i=0; i<=m; i++) dp[0][i] = 0;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	int deletions = s1.length() - dp[n][m];
	int insertions = s2.length() - dp[n][m];
	
	return deletions + insertions;
}

int main(){
	string s1 = "heap";
	string s2 = "pea";
	
	cout<<minOperations(s1, s2, s1.length(), s2.length());
	
	
	return 0;
}
