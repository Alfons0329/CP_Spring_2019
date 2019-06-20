#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v[8]={2,3,5,7,11,13,17,19};
            //0,0,0,0,0 ,0 ,0 ,0
            //operation increased ans[0] by 1, find maximum operation without blowup 
    int ans[8];
    ans[0]=1;
    for(int i=1;i<8;i++){
        ans[i] = v[i-1]*ans[i-1];
    }
    int res = 0;
    for(int i=0;i<8;i++){
        int tmp;
        cin >> tmp;
        res += (v[i]-tmp-1)*ans[i];
    }
    cout << res << "\n";
    return 0;
}
