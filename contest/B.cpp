#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll h1,h2,w1,w2,cnt,ans;
bool A[11][11],B[11][11],table[22][22],rev_B[11][11],check;
char tmp;

void dfs(int x,int y){
    if(table[x][y]) return;
    table[x][y] = 1;
    if(x == 0 || x == 21 || y == 0 || y == 21){
        check = 1;
        return;
    }
    cnt++;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}

void solve(int i,int j){
    for(int k = 0;k<h2;k++){
        for(int l = 0;l<w2;l++){
            if(table[i+k][j+l] && B[k][l]) return;
            if(B[k][l]) table[i+k][j+l] = 1;
        }
    }
    for(int k = 0;k<22;k++){
        for(int l = 0;l<22;l++){
            if(table[k][l]) cout << "*";
            else cout << ".";
        }
        cout << "\n";
    }
    for(int k = 0;k<22;k++){
        for(int l = 0;l<22;l++){
            check = 0;
            cnt = 0;
            dfs(k,l);
            if(!check) ans = max(ans,cnt);
        }
    }
}

void rotate(){
    for(int i = 0;i<h2;i++){
        for(int j = 0;j<w2;j++){
            rev_B[h2-j-1][i] = B[i][j];
        }
    }
    swap(h2,w2);
    for(int i = 0;i<h2;i++){
        for(int j = 0;j<w2;j++) B[i][j] = rev_B[i][j];
    }
}

void rever(){
    for(int i = 0;i<h2;i++){
        for(int j = 0;j<w2;j++){
            rev_B[i][w2-j-1] = B[i][j];
        }
    }
    for(int i = 0;i<h2;i++){
        for(int j = 0;j<w2;j++){
            B[i][j] = rev_B[i][j];
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> h1 >> w1;
    for(int i = 0;i<h1;i++){
        for(int j = 0;j<w1;j++){
            cin >> tmp;
            if(tmp == '*') A[i][j] = 1;
        }
    }
    cin >> h2 >> w2;
    for(int i = 0;i<h2;i++){
        for(int j = 0;j<w2;j++){
            cin >> tmp;
            if(tmp == '*') B[i][j] = 1;
        }
    }
    for(int i = 0;i<21-h1;i++){
        for(int j = 0;j<21-w1;j++){
            memset(table,0,sizeof(table));
            for(int k = 0;k<h1;k++){
                for(int l = 0;l<w1;l++){
                    table[i+k][j+l] = A[k][l];
                }
            }
            for(int p = 0;p<4;p++){
                for(int k = 0;k<21-h2;k++){
                    for(int l = 0;l<21-w2;l++){
                        solve(k,l);
                    }
                }
                rotate();
            }
            rever();
            for(int p = 0;p<4;p++){
                for(int k = 0;k<21-h2;k++){
                    for(int l = 0;l<21-w2;l++){
                        solve(k,l);
                    }
                }
                rotate();
            }
        }
    }
    cout << ans;
}