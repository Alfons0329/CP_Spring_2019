#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    pair<double,double> A[31]; //first = long , second = short
    A[2].first = pow(2.0,-3.0/4.0);
    A[2].second = pow(2.0,-5.0/4.0);
    for(int i=3;i<31;i++){ //calculate Ai paper's longedge and shortedge
        A[i].first = A[i-1].second;
        A[i].second = A[i-1].first/2.0;
    }
    //for(auto x : A){
    //    cout << x.first << " " << x.second << "\n";
    //}
    int n;
    cin >> n;
    vector<int> paper(2,0);
    for(int i=0;i<n-1;i++){
        int tmp;
        cin >> tmp;
        paper.push_back(tmp);
    }
    bool ok = false;
    double res = 0;
    long long need = 2;
    for(int i=2;i<paper.size();i++){
        res+=A[i].first*(need/2);
        need-=paper[i];
        if(need <= 0){
            ok = true;
            break;
        }
        else{
            need*=2;
        }
    }
    if(ok) cout << fixed << setprecision(9) << res << "\n";
    else cout << "impossible\n";
}
