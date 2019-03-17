#include<bits/stdc++.h>

using namespace std;
int res;
int cal(const vector<int> &seq){
    vector<int> ans;
    for (int x : seq){
        if(ans.empty() || ans.back() < x){
            ans.push_back(x);
        }
    }

    if(ans.size() > res)
    {
        printf("Update res to %d ", ans.size());
        for(int it : ans)
        {
            printf("%d ", it);
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
        res = 0;
        for(int l = 0 ; l < n ; l++){
            for(int r = l ; r < n ; r++ ){
                res = max (res, cal(vector<int>(a+l, a+r+1)));
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
