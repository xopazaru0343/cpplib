#include<bits/stdc++.h>
//massa de parede em construção
typedef long long ll;
using namespace std;

const ll N = 2e5 + 10;
ll n;
vector<vector<ll>> adj(N, vector<ll>());
vector<vector<ll>> dp(N, vector<ll>(2, 0));
void dfs(ll v, ll pr) {
    for(ll i = 0; i < adj[v].size(); i++) {
        ll ch = adj[v][i];
        if(ch == pr) {
            continue;
        }
        dfs(ch, v);
        dp[v][0] *= (dp[ch][0] + dp[ch][1]);
        dp[v][1] *= (dp[ch][0]);
    }
    if(adj[v].size() == 0){
        dp[v][0] = 1, dp[v][1] = 1;
    }
    else{
        dp[v][0] += 1, dp[v][1] += 1;
    } 
}

int main(){
    cin >> n;
    n--;
    while(n--){
        ll a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    dfs(0, 0);
    ll res = dp[0][0] + dp[0][1];
    cout << res << '\n';
    exit(0);
}