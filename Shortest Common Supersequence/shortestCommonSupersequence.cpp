#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int LCS(string a, int m, string b, int n){
        int **t = new int*[m+1];
        for(int i = 0; i < m + 1; i++){
            t[i] = new int [n+1];
        }
        for(int i = 0; i < m + 1; i++){
            t[i][0] = 0;
        }
        for(int i = 0; i < n + 1; i++){
            t[0][i] = 0;
        }
        for(int i = 1; i < m + 1; i++){
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
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return m + n - LCS(X, m, Y, n);
    }
};

int main()
{   
    string a,b;
    cin >> a >> b;
    Solution ans;
    cout << ans.shortestCommonSupersequence(a, b, a.size(), b.size()) << endl;
    return 0;
}