#include<bits/stdc++.h>
using namespace std;

int  t[1001][1001];

int LCS(string a, string b){
    int n, m;
    n = a.size();
    m = b.size();
    if(n == 0 || m == 0){
        return t[n][m]= 0;
    }
    if(t[n][m] != -1){
        return t[n][m];
    }
    if(a[0] == b[0]){
        return t[n][m] = 1 + LCS(a.substr(1), b.substr(1));
    }
    else{
        return t[n][m] = max(LCS(a, b.substr(1)), LCS(a.substr(1), b));
    }

}

int main(){
    string a; 
    string b;
    cin >> a >> b;
    memset(t, -1, sizeof(t));
    cout << LCS(a, b) << endl;
    return 0;
}