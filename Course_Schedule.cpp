#include "bits/stdc++.h"
using namespace std;
int pt[100010];
vector<int> adj[200020];
queue<int> q;
vector<int> sv;
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        pt[b]++;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++)if(pt[i] == 0)q.push(i);

    while(!q.empty()){

        int tmp = q.front();
        sv.push_back(tmp);
        q.pop();
        for(auto k : adj[tmp]){
            pt[k]--;
            if(pt[k] == 0)q.push(k);
        }
    }
    if(sv.size() < n)cout << "IMPOSSIBLE";
    else for(auto l : sv)cout << l << " ";

    return 0;
}

//https://cses.fi/problemset/result/8285040/
