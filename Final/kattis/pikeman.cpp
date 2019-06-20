#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    ll n,time,a,b,c,t0;
    cin >> n >> time;
    vector<ll> t(n,0);
    cin >> a >> b >> c >> t[0];
    for(int i=1;i<n;i++){
        t[i] = (a*t[i-1]+b)%c+1;
    }
    sort(t.begin(),t.end());
    ll ans = 0; //penalty
    int i = 0;
    for( ;i<n;i++){
        if(i) t[i]+=t[i-1];
        if(t[i]>time){
            break;
        }
        else{
            ans = (ans+t[i])%1000000007; 
        }
    }
    cout << i << " " << ans << "\n";
    return 0;


}
