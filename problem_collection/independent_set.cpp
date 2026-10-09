#include <bits/stdc++.h>
//massa de parede em construção
typedef long long ll;
using namespace std;

const ll N = 2e5 + 10;
ll n;
vector<vector<ll>> adj(N, vector<ll>());
vector<vector<ll>> dp(N, vector<ll>(2, 0));

void dfs(ll v, ll pr) {
    if(adj[v].size() == 1 || adj[v].size() == 0) dp[v][0] = 1, dp[v][1] = 1;
    for(auto ch : adj[v]) {
        if(ch == pr) {
            continue;
        }
        dfs(ch, v); 
        if(adj[v].size() == 2) dp[v][0] += dp[ch][0] + dp[ch][1], dp[v][1] += dp[ch][0];
        else{
            if(dp[v][0] == 0 && dp[v][1] == 0) dp[v][0] = 1, dp[v][1] = 1;
            dp[v][0] *= (dp[ch][0] + dp[ch][1]);
            dp[v][1] *= (dp[ch][0]);
        }
    }
}

int main(){
    cin >> n;
    adj.resize(n);
    dp.resize(n);
    n--;

    while(n--){
        ll a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    for(ll i = 0; i < adj.size(); i++){
        dfs(i, i);
    }
    ll res = dp[0][0] + dp[0][1];
    cout << res << '\n';

    exit(0);
}