#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using db = double;

#define PI acos(-1)

typedef complex<double> base;
typedef vector<base> vb;

const int ALPHABET_SIZE = 26;
const int BASE = 31;
const int MAXN = 10001;
const int NBIT = 18;
const int N = 1<<18;
const int MOD = (int)1e9+7;

int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
    
    
    
/*
--------------------------------------------------------------------------------------------------------------------------------------------------
        MAX value of N                      Time complexity
         10^9                              O(logN) or Sqrt(N)
         10^8                              O(N) Border case
         10^7                              O(N) Might be accepted
         10^6                              O(N) Perfect
         10^5                              O(N * logN)
         10^4                              O(N ^ 2)
         10^2                              O(N ^ 3)
         <= 160                            O(N ^ 4)
         <= 18                             O(2N*N2) 
         <= 10                             O(N!), O(2N)
    ==================================================================
    
    
    
    
    
    
--------------------------------------------------------------------------------------------------------------------------------------------------*/
    
    
    vector<ll> adj[MAXN], parent(MAXN), d(MAXN), num(MAXN), low(MAXN), tail(MAXN);
    vector<bool> visited(MAXN, false);
    
    ll timeDFS = 0, bridge = 0;
    vector<bool> joint(MAXN);
    void DFS(ll u, ll pre) {
        ll child = 0;
        num[u] = low[u] = ++timeDFS;
        for (ll v : adj[u]) {
            if (v == pre) {
                continue;
            }
            if (!num[v]) {
                DFS(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] == num[v]) {
                    bridge++;
                }
                child++;
                if (u == pre) {
                    if (child > 1) {
                        joint[u] = true;
                    }
                }
                else if (low[v] >= num[u]) {
                    joint[u] = true;
                }
            }
            else {
                low[u] = min(low[u], num[v]);
            }
        }
        tail[u] = timeDFS;
    } 
    
    void JointBridge(ll vertexs) {
        for (int i = 1; i <= vertexs; i++) {
            if (!num[i]) {
                DFS(i, i);
            }
        }
        ll cnt = 0;
        for (int i = 1; i <= vertexs; i++) {
            cnt += joint[i];
        }
        cout << cnt << ' ' << bridge;
    }
    
    /*
        Ý tưởng tìm cạnh cầu:
             
     */
    
    void solve() {
        int n, m; cin >> n >> m;
        for (int i = 0; i < m; i++) {
            ll x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        JointBridge(n);

        
    }

    int main() {       
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif  
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0);
        int test = 1;
        while (test--) {
            solve();
        }
    }