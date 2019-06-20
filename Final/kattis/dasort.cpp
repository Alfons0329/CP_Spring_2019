#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    int p,k,n;
    cin >> p;
    while(p--){
        cin >> k >> n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        vector<int> old_v = v;
        sort(v.begin(),v.end()); 
        int count=0;
        for(int i=0;i<v.size();i++){
            if(old_v[i]==v[count]){
                count++;
            }
        }
        cout << k << " " << v.size()-count << "\n";
    }


}
