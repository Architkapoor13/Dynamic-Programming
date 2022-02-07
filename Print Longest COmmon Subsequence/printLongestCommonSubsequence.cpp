#include<bits/stdc++.h>
using namespace std;
string t[1001][1001];
string printLCS(string a, int m, string b, int n){
    for(int i = 0; i < m + 1; i++){
        t[i][0] = "";
    }
    for(int j = 0; j < n + 1; j++){
        t[0][j] = "";
    }
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n +1; j++){
            if(a[i-1] == b[j-1]){
                t[i][j] = a[i - 1] + t[i-1][j-1];
            }
            else{
                if(t[i-1][j].size() > t[i][j-1].size()){
                    t[i][j] = t[i-1][j];
                }
                else{
                    t[i][j] = t[i][j-1];
                }
            }
        }
    }
    return t[m][n];
}

int main(){
    string a,b;
    cin >> a >> b;

    string ans = printLCS(a, a.size(), b, b.size());
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}