#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int ans[11]={1};
    for(int i=1;i<11;i++){
        ans[i]=(i*ans[i-1])%10;
    }
    while(T--){
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}
