#include <bits/stdc++.h>
using namespace std;
long long solve(long long n,vector<long long> & nums,long long x){
    int ans =0;
    for (int i=0;i<nums.size();i++){
        long long sum = nums[i];
        if (sum==x) ans++;
        for (int j=i+1;j<nums.size();j++){
        if (sum+nums[j]==x) {
            ans++;
        }
        sum+=nums[j];
        }
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
