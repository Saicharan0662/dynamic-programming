#include<bits/stdc++.h>
using namespace std;

// utility function
bool isPalindrome(string str, int i, int j){
	while(i <= j){
		if(str[i++] != str[j--]) return false;
	}
	return true;
}

// recursive solution
int helper(string str, int i, int j){
	if(i>=j) return 0;
	if(isPalindrome(str, i, j)) return 0;
	
	int res = INT_MAX;
	for(int k=i; k<j; k++){
		int tempAns = helper(str, i, k) + helper(str, k+1, j) + 1;
		res = min(res, tempAns);
	}
	
	return res;
}

// memoization solution
int dp[100][100];
int helper_M(string str, int i, int j){
	if(i>=j) return 0;
	if(isPalindrome(str, i, j)) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	int res = INT_MAX;
	for(int k=i; k<j; k++){
		int tempAns = helper_M(str, i, k) + helper_M(str, k+1, j) + 1;
		res = min(res, tempAns);
	}
	
	return dp[i][j] = res;
}

// memoization optimized solution
int helper_MO(string str, int i, int j){
	if(i>=j) return 0;
	if(isPalindrome(str, i, j)) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	int res = INT_MAX;
	for(int k=i; k<j; k++){
		int left, right;
		
		if(dp[i][k] != -1) left = dp[i][k];
		else{
			left = helper_M(str, i, k);
			dp[i][k] = left;
		}
		
		if(dp[k+1][j] != -1) right = dp[k+1][j];
		else{
			right = helper_M(str, k+1, j);
			dp[k+1][j] = right;
		}
		
		int tempAns = left + right + 1;
		res = min(res, tempAns);
	}
	
	return dp[i][j] = res;
}

int pal_Partitioning(string str){
	return helper_MO(str, 0, str.length()-1);
}

int main(){
	string str = "abcba";
	memset(dp, -1, sizeof(dp));
	cout<<pal_Partitioning(str);
	
	return 0;
}
