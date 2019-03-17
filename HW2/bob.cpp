#include<bits/stdc++.h>

using namespace std;

int cal(const vector<int> &seq, int res){
    vector<int> ans;
    for (int x : seq){
        if(ans.empty() || ans.back() < x){
            ans.push_back(x);
        }
    }
    if(1)
    {
        printf("Increasing seq: ");
        for(int x : ans)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    return ans.size();
}

int main(){
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        int n;
        scanf("%d",&n);
        static int a[1000005];
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
        }
        int ans = 0;
        for(int l = 0 ; l < n ; l++){
            for(int r = l ; r < n ; r++ ){
                ans = max (ans, cal(vector<int>(a+l, a+r+1), ans));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
