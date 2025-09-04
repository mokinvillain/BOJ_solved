#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N,arr[300][300],tmp,cur,M,mx;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> M;
        cur = 0;
        for(int j = 0;j<M;j++){
            cin >> tmp;
            arr[i*2][cur] = 1;
            arr[i*2+1][cur] = 2;
            arr[i*2+2][cur] = 1;
            while(tmp--){
                cur++;
                if(arr[i*2][cur] != 1) arr[i*2][cur] = 3;
                if(arr[i*2+2][cur] != 1) arr[i*2+2][cur] = 3;
            }
            cur++;
            mx = max(mx,cur);
            arr[i*2][cur] = 1;
            arr[i*2+1][cur] = 2;
            arr[i*2+2][cur] = 1;
        }
    }
    for(int i = 0;i<=N*2;i++){
        if(arr[i][0] == 0) return 0;
        for(int j = 0;j<=mx;j++){
            if(arr[i][j] == 1) cout << "+";
            else if(arr[i][j] == 2) cout << "|";
            else if(arr[i][j] == 3) cout << "-";
            else cout << " "; 
        }
        cout << "\n";
    }
}