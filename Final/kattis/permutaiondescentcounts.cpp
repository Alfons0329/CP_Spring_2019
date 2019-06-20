#include<bits/stdc++.h>
using namespace std;

int dp[101][101];
int main(){
    int p;
    cin >> p;


    for(int i=0;i<101;i++){
        dp[i][0]=1;
    }
    //dp[i][j] 代表分析到第i個數的des值為j 的個數
    for(int i=2;i<101;i++){
        for(int j=1;j<i;j++){
            dp[i][j]=(dp[i-1][j-1]*(i-j)+dp[i-1][j]*(j+1))%1001113;
        }
    }

    while(p--){
        int k,n,v;
        cin >> k >> n >> v;
        cout << k << " " << dp[n][v] << "\n";
    }

}
