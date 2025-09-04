#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N,arr[111],tmp,ans;
vector<int> v;

void back(int n){
    if(n == 3){
        for(int i = 2;i>=0;i--){
            if(arr[v[i]] == 1){
                bool check = 0;
                for(int j = v[i]+1;j<=100;j++){
                    if(arr[j] == 1){
                        check = 1;
                        break;
                    }
                }
                if(check) continue;
                ans++;
                return;
            }
        }
        return;
    }
    int k = 1;
    if(n != 0) k = v.back()+1;
    for(;k<=100;k++){
        arr[k]++;
        v.push_back(k);
        back(n+1);
        v.pop_back();
        arr[k]--;
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<3;j++){
            cin >> tmp;
            arr[tmp]++;
        }
    }
    back(0);
    cout << ans;
}