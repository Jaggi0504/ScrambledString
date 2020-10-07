//Example great and eatgr are scrambled
//Example abcde and caebd are not scrambled

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int>mp;
//Using Memoization

bool solve_Mem(string a, string b) {
	if(a.compare(b) == 0) {
		return true;
	}
	if(a.length() <= 1) {
		return false;
	}
	string key = a;
	key.push_back(' ');
	key.append(b);
	if(mp.find(key) != mp.end()) {
		return mp[key];
	}
	bool flag = false;
	int n = a.length();
	for(int i=1;i<n;i++) {
		if(solve_Mem(a.substr(0, i), b.substr(n-i, i)) && solve_Mem(a.substr(i, n-1), b.substr(0, n-i)) ||
		   solve_Mem(a.substr(0, i), b.substr(0, i)) && solve_Mem(a.substr(i, n-i), b.substr(i, n-i)))  {
			flag = true;
			break;
		   } 
	}
	return mp[key] = flag;
}

//Using Recursion

bool solve(string a, string b) {
	if(a.compare(b) == 0) {
		return true;
	} 
	if(a.length() <= 1) {
		return false;
	}
	bool flag = false;
	int n = a.length();
	for(int i=1;i<n;i++) {
		if(solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i)) ||
		   solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i))) {
			flag = true;
			break;
		   }
	}
	return flag;
}
 
int main() {
	string a, b;
	cout<<"Enter the string 1:";
	cin>>a;
	cout<<"Enter the string 2:";
	cin>>b;
	if(a.length() != b.length()) {
		return false;
	}
	if(a.length() == 0 && b.length() == 0) {
		return true;
	}
	bool ans = solve_Mem(a, b);
	if(ans) {
		cout<<"true"<<endl;
	} else {
		cout<<"false"<<endl;
	}
	bool ans2 = solve(a, b);
	if(ans2) {
		cout<<"true"<<endl;
	} else {
		cout<<"false"<<endl;
	}
}
