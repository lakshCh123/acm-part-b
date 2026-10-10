#include <bits/stdc++.h>
using namespace std;
int ans=0;
int solve(int index,int end ,vector<pair<int,int>>& intervals,int can_watch){ 
 if (index>=intervals.size()){
    ans=max(can_watch,ans);
    return can_watch;
 }
 if (intervals[index].first>=end)
 solve(index+1,intervals[index].second,intervals,can_watch+1);
 solve(index+1,end,intervals,can_watch);
 return ans;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> intervals(n);
    for (int i=0;i<n;i++){
        cin>>intervals[i].first>>intervals[i].second;
    }
    sort(intervals.begin(),intervals.end());
    cout<<solve(0,0,intervals,0);
    return 0;
}