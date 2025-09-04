#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

string str,cur = "";
set<string> ans;
bool check[10];

void back(int n){
    if(n == 6){
        ans.insert(cur);
        return;
    }
    if(n == 0 || n == 5 || n == 4){
        for(int i = 0;i<6;i++){
            if(check[i] || (n >= 1 && n <= 3)) continue;
            check[i] = 1;
            cur.push_back(str[i]);
            back(n+1);
            check[i] = 0;
            cur.pop_back();
        }
    }
    else{
        for(int i = 1;i<=3;i++){
            if(!check[i]){
                check[i] = 1;
                cur.push_back(str[i]);
                back(n+1);
                check[i] = 0;
                cur.pop_back();
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> str;
    back(0);
    cout << ans.size() << "\n";
    for(string i : ans) cout << i << "\n";
}