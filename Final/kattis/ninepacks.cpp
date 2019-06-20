#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int h,b;
    cin >> h;
    vector<ll> ch(100002,INT_MAX); ch[0]=0;
    vector<ll> cb(100002,INT_MAX); cb[0]=0;
    for(int i=0;i<h;i++){ //find hotdog's possible value
        int tmp;
        cin >> tmp;
        for(int j=ch.size()-tmp-1;j>=0;j--){
            if(ch[j] < ch[j+tmp]){
                ch[j+tmp] = ch[j]+1;
            }
        }
    }
    cin >> b;
    for(int i=0;i<b;i++){ //find buns
        int tmp;
        cin >> tmp;
        for(int j=cb.size()-tmp-1;j>=0;j--){
            if(cb[j] < cb[j+tmp]){
                cb[j+tmp] = cb[j]+1;
            }
        }
    }
    /*
    for(int i=0;i<101;i++){
        cout << i << " : " << ch[i] << "\n"; 
    }
    for(int i=0;i<101;i++){
        cout << i << " : " << cb[i] << "\n"; 
    }
    */
    bool ok = false;
    ll res = INT_MAX;
    for(int i=1;i<100002;i++){
        if(ch[i]+cb[i] < res){
            res = ch[i]+cb[i];
            ok = true;
        }
    }
    if(ok)cout << res << "\n";
    else cout << "impossible\n";
}
