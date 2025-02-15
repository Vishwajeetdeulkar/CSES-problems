#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int diceCombinations(int n){
    vector<int> dp(n+1,0);
    dp[0]=1; // only one way with sum 0, doing nothing
    for(int total=1;total<=n;total++){
        for(int diceFace=1;diceFace<=6;diceFace++){
            if(total - diceFace >=0){
                dp[total] = (dp[total]+dp[total-diceFace]) %mod;
            }
        }
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<diceCombinations(n);
    return 0;
}

// dp with 1 parameter as we only 1 state is changing with roll of a dice that is sum
//Each dp[total-diceFace] represents the number of ways to reach sum total if the last dice roll gave diceFace.