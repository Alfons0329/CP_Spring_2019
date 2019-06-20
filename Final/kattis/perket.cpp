#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int s,b;
        cin >> s >> b;
        v.push_back({s,b});
    }
    int res = INT_MAX;
    for(int i=1;i<(1<<n);i++){ //run all Combination and find minimum
        int rs=1,rb=0;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                rs *= v[j].first;
                rb += v[j].second;
            }
        }
        res = min(abs(rs-rb),res);
    }
    cout << res << "\n";
    return 0;
}
