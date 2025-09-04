#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
string str;
int check[511];
bool c;

void back(int cur,int n){
    if(n == N+1){
        if(c) return;
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=N;j++) if(check[j] == i) cout << j << " ";
        }
        c = 1;
        return;
    }
    int tmp = str[cur] - '0';
    if(tmp == 0) return;
    if(!check[tmp]){
        check[tmp] = n;
        back(cur+1,n+1);
        check[tmp] = 0;
    }
    if(cur >= str.length() - 1) return;
    tmp = (str[cur] - '0')*10 + (str[cur+1] - '0');
    if(check[tmp]) return;
    if(tmp > N) return;
    check[tmp] = n;
    back(cur+2,n+1);
    check[tmp] = 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> str;
    if(str.length() > 9){
        N += 9;
        N += (str.length() - 9)/2;
    }
    else N = str.length();
    back(0,1);
}