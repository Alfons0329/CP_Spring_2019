#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    set<string> res;
    // split the word to three part and reverse, and put back together
    // find the lexicographically smallest word 
    for(int i=1;i<s.size()-1;i++){ //run all possible
        for(int j=i;j<s.size();j++){
            for(int k=j+1;k<s.size();k++){
                string tmp = s;
                reverse(tmp.begin(),tmp.begin()+i);
                reverse(tmp.begin()+j,tmp.begin()+k);
                reverse(tmp.begin()+k,tmp.end());
                res.insert(tmp);
            }
        }
    }
    cout << *res.begin() << "\n";
    return 0;
}
