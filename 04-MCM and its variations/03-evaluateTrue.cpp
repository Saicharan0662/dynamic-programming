#include<bits/stdc++.h>
using namespace std;

int helper(string str, int i, int j, bool isTrue){
	if(i > j) return false;
	if(i == j){
		if(isTrue) return str[i] == 'T';
		else return str[i] == 'F';
	} 
	
	int res = 0;
	for(int k=i+1; k<=j-1; k+=2){
		int lt = helper(str, i, k-1, true);
		int lf = helper(str, i, k-1, false);
		int rt = helper(str, k+1, j, true);
		int rf = helper(str, k+1, j, false);
		
		if(str[k] == '&'){
			if(isTrue) res += (lt*rt);
			else res += (lt*rf + rt*lf + lf*rf);
		}
		else if(str[k] == '|'){
			if(isTrue) res += (lt*rt + lt*rf + lf*rt);
			else res += (lf*rf);
		}
		else{
			if(isTrue) res += (lt*rf + lf*rt);
			else res += (lf*rf + lt*rt);
		}
	}
	
	return res;
}

int evaluateToTrue(string str, int n){
	
	return helper(str, 0, n-1, true);
}

int main(){
	
	string str = "T|T&F^T";
	cout<<evaluateToTrue(str, str.length());
	
	return 0;
}
