#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,SZ = 201010;
ll N,M,K,arr[SZ],T,L;
queue<ll> A,B,C;
vector<string> ans;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        A = {};
        ans.clear();
        cin >> N >> L;
        for(int i = 0;i<N;i++){
            cin >> K;
            A.push(K);
        }
        for(int i = 1;i<N/2;i*=2){
            bool check = 0;
            for(int k = 1;k<=N/i;k+=2){
                for(int j = 1;j<=i;j++){
                    B.push(A.front());
                    A.pop();
                    ans.push_back("AB ");
                }
                for(int j = 1;j<=i;j++){
                    C.push(A.front());
                    A.pop();
                    ans.push_back("AC ");
                }
                while(!B.empty() && !C.empty()){
                    if(B.front() <= C.front()){
                        A.push(B.front());
                        ans.push_back("BA ");
                        B.pop();
                    }
                    else{
                        A.push(C.front());
                        ans.push_back("CA ");
                        C.pop();
                    }
                }
                if(C.size() != i) check = 1;
                while(!B.empty()){
                    A.push(B.front());
                    ans.push_back("BA ");
                    B.pop();
                }
                while(!C.empty()){
                    A.push(C.front());
                    ans.push_back("CA ");
                    C.pop();
                }
            }
            if(!check){
                for(int j = 0;j<N*2;j++) ans.pop_back();
            }
        }
        for(int i = 0;i<N/2;i++){
            B.push(A.front());
            A.pop();
            ans.push_back("AB ");
        }
        while(!A.empty() && !B.empty()){
            if(B.front() <= A.front()){
                B.pop();
                ans.push_back("BC ");
            }
            else{
                A.pop();
                ans.push_back("AC ");
            }
        }
        bool check = 0;
        if(A.size() == N/2){
            check = 1;
        }
        while(!A.empty()){
            ans.push_back("AC ");
            A.pop();
        }
        while(!B.empty()){
            ans.push_back("BC ");
            B.pop();
        }
        if(check){
            for(int i = 0;i<(N/2)*3;i++) ans.pop_back();
        }
        cout << ans.size() << "\n";
        for(string i : ans) cout << i;
        cout << "\n";
    }
}