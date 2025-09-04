#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll T,n,total;
char card1,card2,card3;

ll tras(char k){
    if(k - '0' < 10) return k-'0';
    else if(k == 'A') return 11;
    return 10;
}
int main(){
    cin.tie();
    ios::sync_with_stdio(0);
    cin >> T;
    while(T != 0){
        cin >> n;
        cin >> card1 >> card2 >> card3;
        
    }
}