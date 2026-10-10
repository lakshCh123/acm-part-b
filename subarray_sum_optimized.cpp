#include <bits/stdc++.h>
using namespace std;
long long solve(long long n,vector<long long> & nums,long long x){
    long long ans=0;
    map<long long,long long> freq;
    vector<long long> prefix(n+1);
    prefix[0]=0;
    freq[prefix[0]]++;
    for (int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+nums[i];
        if (freq.find(prefix[i+1]-x)!=freq.end()){
            ans+=freq[prefix[i+1]-x];
        }
        freq[prefix[i+1]]++;
    }
    return ans;
    
}
int main(){
    long long n,x;
    cin>>n>>x;
    vector<long long> nums(n);
    for (int i=0;i<n;i++) cin>>nums[i];
    cout<<solve(n,nums,x)<<endl;
    return 0;
}
