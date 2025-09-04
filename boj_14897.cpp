#include <bits/stdc++.h>

using namespace std;

int arr[1010101],N,M,B;

struct Query{
    int idx,s,e;
};

bool cmp(const Query &u, const Query &v){
    if(u.s/B != v.s/B) return u.s/B < v.s/B;
    else return u.e < v.e;
}

Query tmp;
vector<Query> q;
int ans[1010101],check[1010101],res;

void press(){
    vector<int> C;
    for(int i=1; i<=N; i++) C.push_back(arr[i]);
    sort(C.begin(), C.end());
    C.erase(unique(C.begin(), C.end()), C.end());
    for(int i=1; i<=N; i++){
        arr[i] = lower_bound(C.begin(), C.end(), arr[i]) - C.begin();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    B = sqrt(N);
    for(int i = 1;i<=N;i++) cin >> arr[i];
    press();
    cin >> M;
    for(int i = 0;i<M;i++){
        cin >> tmp.s >> tmp.e;
        tmp.idx = i;
        q.push_back(tmp);
    }
    sort(q.begin(),q.end(),cmp);
    int s = q[0].s,e = q[0].e;
    for(int i = s;i<=e;i++){
        if(!check[arr[i]]) res++;
        check[arr[i]]++;
    }
    ans[q[0].idx] = res;
    for(int i = 1;i<M;i++){
        while(s < q[i].s){
            check[arr[s]]--;
            if(!check[arr[s]]) res--;
            s++;
        }
        while(s > q[i].s){
            s--;
            if(!check[arr[s]]) res++;
            check[arr[s]]++;
        }
        while(e > q[i].e){
            check[arr[e]]--;
            if(!check[arr[e]]) res--;
            e--;
        }
        while(e < q[i].e){
            e++;
            if(!check[arr[e]]) res++;
            check[arr[e]]++;
        }
        ans[q[i].idx] = res;
    }
    for(int i = 0;i<M;i++) cout << ans[i] << "\n";
}