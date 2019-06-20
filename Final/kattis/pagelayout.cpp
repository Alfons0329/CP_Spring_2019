#include<bits/stdc++.h>
using namespace std;

int res = 0;
vector<int> v[20];      //all stories
vector<int> used_v[20]; //the stories we included now
                        //in solve function we use used_num to control the size
bool overlap(vector<int>& v1,vector<int>& v2){
    return !(v1[0]>=v2[1] || v1[2]>=v2[3] || v2[0]>=v1[1] || v2[2]>=v1[3] );
}

void solve(int tmp,int& n,int num,int used_num){ //run all possible
    if(num==n){
        res = max(tmp,res);
        return;
    }
    solve(tmp,n,num+1,used_num);
    bool ok=true;
    for(int j=0;j<used_num;j++){ //find overlap
        if(overlap(v[num],used_v[j])){
            ok=false;
            break;
        }
    }
    if(ok){
        used_v[used_num] = v[num]; //put it in included story
        solve(tmp+v[num][4],n,num+1,used_num+1);
    }
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n,w,h,x,y;
    while(cin >> n){
        if(!n) break;
        for(int i=0;i<n;i++){
            cin >> w >> h >> x >> y;
            v[i]={x,x+w,y,y+h,w*h};
        }
        solve(0,n,0,0);
        cout << res << "\n";
        res = 0;
    }
    return 0;
}
