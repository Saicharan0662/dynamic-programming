#include<bits/stdc++.h>
using namespace std;

// recursive solution
bool isScrambled(string s1, string s2){
	if(s1 == s2) return true;
	if(s1.length() != s2.length()) return false;
	if(s1.length() < 1) return false;
	
	int n = s1.length();
	for(int k=1; k<n; k++){
		bool flag1 = false, flag2 = false;
		// if swapped condition
		if(isScrambled(s1.substr(0, k), s2.substr(n-k, k)) && isScrambled(s1.substr(k, n-k), s2.substr(0, n-k))){
			flag1 = true;
		}
		// if not swapped condition
		else if(isScrambled(s1.substr(0, k), s2.substr(0, k)) && isScrambled(s1.substr(k, n-k), s2.substr(k, n-k))){
			flag2 = true;
		}
		
		if(flag1 || flag2) return true;
	}
	
	return false;
}

// memoization solution
unordered_map<string, bool> mp;
bool isScrambled_M(string s1, string s2){
	if(s1 == s2) return true;
	if(s1.length() != s2.length()) return false;
	if(s1.length() < 1) return false;
	
	string key = s1 + " " + s2;
	if(mp.find(key) != mp.end()) return true;
	
	int n = s1.length();
	bool flag = false;
	for(int k=1; k<n; k++){
		if(isScrambled(s1.substr(0, k), s2.substr(n-k, k)) && isScrambled(s1.substr(k, n-k), s2.substr(0, n-k))){
			flag = true;
			mp[key] = flag;
			return true;
		}
		else if(isScrambled(s1.substr(0, k), s2.substr(0, k)) && isScrambled(s1.substr(k, n-k), s2.substr(k, n-k))){
			flag = true;
			mp[key] = flag;
			return true;
		}
	}
	
	mp[key] = flag;
	return flag;
}

int main(){
	string s1, s2;
	cin>>s1>>s2;
	
	cout<<isScrambled_M(s1, s2);
	
	return 0;
}
