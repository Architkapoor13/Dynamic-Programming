#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];
string printLCS(string a, int m, string b, int n){
    for(int i = 0 ; i < m + 1; i++){
        t[i][0] = 0;
    }
    for(int i = 0; i < n + 1; i++){
        t[0][i] = 0;
    }
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(a[i-1] ==  b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    int i = m, j = n;
    string ans = "";
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            ans += a[i-1];
            i--;
            j--;
        }
        else{
            if(t[i-1][j] > t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    return ans;
}

int main(){
    string a, b;
    cin >> a >> b;
    string ans = printLCS(a, a.size(), b, b.size());
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}