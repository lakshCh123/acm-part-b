#include <bits/stdc++.h>
using namespace std;

int solve(string &a, string &b, int i, int j) {
    if (i==a.size()) return b.size()-j;
    if (j==b.size()) return a.size()-i;
    if (a[i] == b[j]) {
        return solve(a,b, i+1, j+1);
    }
    int insert = solve(a, b, i, j + 1);
    int delete1 = solve(a, b, i + 1, j);
    int replace = solve(a, b, i + 1, j + 1);
    return 1 + min({insert, delete1, replace});
}

int main() {
    string a,b;
    cin>>a>>b;
    cout<< solve(a,b,0,0)<<'\n';
    return 0;
}