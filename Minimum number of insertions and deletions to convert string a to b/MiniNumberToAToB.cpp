#include<bits/stdc++.h>
using namespace std;

int LCS(string a, int m, string b, int n){
	    int **t = new int*[m + 1];
	    for(int i = 0; i  < m + 1; i++){
	        t[i] = new int[n + 1];
	    }
	    for(int i = 0 ; i < m + 1; i++){
	        t[i][0] = 0;
	    }
	    for(int i=  0; i < n + 1; i++){
	        t[0][i] = 0;
	    }
	    for(int i = 1; i < m + 1; i ++){
	        for(int j = 1; j < n + 1; j++){
	            if(a[i-1] == b[j-1]){
	                t[i][j] = 1 + t[i-1][j-1];
	            }
	            else{
	                t[i][j] = max(t[i-1][j], t[i][j-1]);
	            }
	        }
	    }
	    return t[m][n];
	}
	int minOperations(string str1, string str2) 
	{
	    int lcs = LCS(str1, str1.size(), str2, str2.size());
	    return str1.size()-lcs + str2.size() - lcs;
	} 

int main(){
    string a, b;
    cin >> a >> b;
    cout << minOperations(a, b) << endl;
    return 0;
}