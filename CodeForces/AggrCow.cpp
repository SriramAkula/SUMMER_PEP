#include<bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int res=0;
        int lo=1;
        int hi=stalls.back()-stalls[0];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            bool flag = check(stalls,k,mid);
            if(flag){
                res=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return res;
        
    }
    bool check(vector<int> &stalls,int k,int dist){
        int count=1;
        int prev=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-prev>=dist){
                prev=stalls[i];
                count++;
            }
        }
        return (count>=k);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){

        int n,k;
        cin>>n>>k;
        vector<int> stalls;
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            stalls.push_back(p);
        }
        
        Solution a;
        int result=a.aggressiveCows(stalls,k);
        cout<<result;
    }

    
}