#include<bits/stdc++.h>
using namespace std;

string lcs(string s1, string s2, int n, int m){
	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));
	
	for(int i=0; i<=n; i++) dp[i][0] = 0;
	for(int i=0; i<=m; i++) dp[0][i] = 0;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	string res;
	int i = n, j = m;
	while(i>0 && j>0){
		if(s1[i-1] == s2[j-1]){
			res = s1[i-1] + res;
			i--; j--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1])
				i--;
			else j--;
		}
	}
	
	return res;
}

int main(){
	string s1 = "acbcf";
	string s2 = "abcdaf";
	
	cout<<lcs(s1, s2, s1.length(), s2.length());
	return 0;
}
