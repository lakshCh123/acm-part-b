#include <bits/stdc++.h>
using namespace std;
bool check(vector<long long> time,long long mid,long long t){
    long long ans =0;
    for (long long i=0;i<time.size();i++){
    ans+=mid/time[i];
    }
    return ans>=t;
}
long long solve(vector<long long > &time,long long t){
    long long max1 = *min_element(time.begin(),time.end())*t;
    for (int i=1;i<=max1;i++){
        if(check( time,i,t)) return i;
    }
    return max1;
}
int main(){
    long long n,t;
    cin>>n>>t;
    vector<long long> time(n);
    for (long long i=0;i<n;i++){
        cin>>time[i];
    }
    cout<<solve(time,t)<<endl;
    return 0;
}