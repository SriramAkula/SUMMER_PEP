#include <iostream>
using namespace std;

long long solve(long long a,long long b,long long ans){
    if(a==0 || b==0){
        return ans;
    }
    if(a>=b){
        ans+=a/b;
        solve(a%b,b,ans);
    }else{
        ans+=b/a;
        solve(a,b%a,ans);
    }
}
long long solve1(long long a, long long b) {
    if (b == 0) {
        return 0; 
    }
    return a / b + solve1(b, a % b);
}

int main() {
    long long a,b;
    cin>>a>>b;
    long long ans=0;
    long long res=solve1(a,b);
    cout<<res<<endl;
    return 0;
}