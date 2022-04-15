#include<bits/stdc++.h>
using namespace std;

// recusive code
int lcs(string s1, string s2, int n, int m){
	if(n==0 || m==0) return 0;
	
	if(s1[n-1] == s2[m-1])
		return 1 + lcs(s1, s2, n-1, m-1);
	return max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
}

// memoization code
int dp[100][100];
int lcs_m(string s1, string s2, int n, int m){
	if(n==0 || m==0) return 0;
	
	if(dp[n][m] != -1) return dp[n][m];
	
	if(s1[n-1] == s2[m-1])
		return dp[n][m] = (1 + lcs(s1, s2, n-1, m-1));
	return dp[n][m] = max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
}

//tabulation code
int lcs_t(string s1, string s2, int n, int m){
	for(int i=0; i<=n; i++) dp[i][0] = 0;
	for(int i=0; i<=m; i++) dp[0][i] = 0;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	return dp[n][m];
} 

int main(){
	string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
	memset(dp, 0, sizeof(dp));
	//	memset(dp, -1, sizeof(dp)); // for memoization solution
	
	cout<<lcs_t(s1, s2, s1.length(), s2.length());
	
	return 0;
}
