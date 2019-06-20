#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<int> d;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        d.push_back(tmp);
    }
    bool ok = true;
    int behind=0; //the child number I can connect
    for(int i=d.size()-1;i>=0;i--){
        if(d[i]-1 > behind){
            ok=false;
            break;
        }
        else{
            behind-=(d[i]-1);
            behind++;
        }
        if(i==0) behind--;
    }
    if(ok && behind==1) cout << "YES\n";
    else cout << "NO\n";

}
