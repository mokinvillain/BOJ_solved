#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

char c[27];
vector<string> v,tmp,nxt;
ll N;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    for(int i = 0;i<26;i++) c[i] = 'a' + i;
    cin >> N;
    for(int i = 0;i<26;i++){
        string k = "";
        k += c[i];
        v.push_back(k);
        tmp.push_back(k);
    }
    while(v.size() < 1000000){
        for(string str : tmp){
            bool check = false;
            for(char ch : str){
                if(ch != str[0]) check = 1;
            }
            if(check){
                v.push_back(str+str[str.length()-1]);
                nxt.push_back(str+str[str.length()-1]);
            }
            else{
                for(int i = 0;i<26;i++){
                    v.push_back(str+c[i]);
                    nxt.push_back(str+c[i]);
                }
            }
        }
        tmp = nxt;
        nxt.clear();
    }
    cout << v[N-1];
}