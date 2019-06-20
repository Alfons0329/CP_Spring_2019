#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q,m,s,l;

bool valid(ll mi){
    ll qslot = (mi/q)*m; //find the max number of q slot
    ll remain = (mi%q)*m;
    if(l==0 && s==0) return true;
    else if(l==0 && s!=0){
        if(s>(qslot+remain)) return false;
    }
    else if(l!=0 && s==0){
        if(l>qslot) return false;
    }
    else{
        if(l>qslot) return false;
        remain = remain + (qslot-l)*q;
        if(s>remain) return false;
    }
    return true;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> q >> m >> s >> l;
    ll lo=0,hi=s+q*l;
    while(lo < hi){ //binary search
        ll mi = (lo+hi)/2;
        if(valid(mi)){
            hi = mi;
        }
        else{
            lo = mi+1;
        }
    }
    cout << lo << "\n";

}
