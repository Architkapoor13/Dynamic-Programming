#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b){
    int n, m;
    n = a.size();
    m = b.size();
    if(n == 0 || m == 0){
        return 0;
    }
    if(a[0] == b[0]){
        return 1 + LCS(a.substr(1), b.substr(1));
    }
    else{
        return max(LCS(a, b.substr(1)), LCS(a.substr(1), b));
    }

}

int main(){
    string a; 
    string b;
    cin >> a >> b;
    cout << LCS(a, b) << endl;
    return 0;
}