#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &Patterns,int wtime){
        int count=1;
        int prev=Patterns[0];
        for(int i=1;i<Patterns.size();i++){
            if(abs(Patterns[i]-prev)>wtime*2){
                prev=Patterns[i];
                count++;
            }
        }
        return (count<=3);
    }

int ToyFestival(vector<int> &Patterns) {

        // Write your code here
        sort(Patterns.begin(),Patterns.end());
        int lo=0;
        int hi=Patterns.back()-Patterns[0];
        int res=hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            bool flag = check(Patterns,mid);
            if(flag){
                res=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return res;
        
    }
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> Patterns(n);
        for(int i=0;i<n;i++){
            cin>>Patterns[i];
        }
        int res=ToyFestival(Patterns);
        cout<<res<<endl;
    }
    return 0;
}