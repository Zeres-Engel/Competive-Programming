#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using db = double;

#define PI acos(-1)

typedef complex<double> base;
typedef vector<base> vb;

const int ALPHABET_SIZE = 26;
const int BASE = 31;
const int MAXN = 100000001;
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
            // Dịkstra
    /* 
        O(v + e )
     */

    /* 
        * Ý tưởng:
            Giả sử xuất phát từ S tới t
            * d(s) = 0, d(...) = 1e9
            * visited(t) = true
            * u -> v: d[v] = min(d[v], d[u] + (u,v))
     */
    //priority queue
    /*
        Luôn di trì 1 cái thứ tự sao cho TOP luôn là phần tử lớn nhất
        
    */
    vector<ll> adj[MAXN], parent(MAXN), d(MAXN), num(MAXN), low(MAXN), tail(MAXN);
    vector<bool> visited(MAXN, false);
    

    void input() {
        // int n, m;
        // cin >> n >> m;
        // for (int i = 0; i < m; i++) {
        //     int x, y; cin >> x >> y >> w;
        //     adjw.push({y, w});
        // }
    }

    vector<pair<ll, ll>> adjw[MAXN];
    void dijkstra(ll begin, ll vertexs){
        //Mang luu khoang cach duong di
        vector<ll> d(vertexs + 1, 1e9);
        d[begin] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
        //khoang cach, dinh
        Q.push({0, begin});
        while(!Q.empty()){
            //Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
            pair<int, int> top = Q.top(); 
            Q.pop();
            int u = top.second;
            int kc = top.first;
            if(kc > d[u]) continue;
            //Relaxtion : Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S, cập
            //nhật khoảng cách với các đỉnh kề với u
            for(auto it : adjw[u]){
                int v = it.first;
                int w = it.second;
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    Q.push({d[v], v});
                }
            }
        }
        for(int i = 1; i <= vertexs; i++){
            cout << d[i] << ' ';
        }
}
    
    /* 

        d[1] = 0
        u = 1
        kc = 0
        chay for:
            v = 2
            w = 3
            d[v] > d[u] + w
            d[v] = d[u] + w

            v = 4
            w = 6
            
    
     */
    void solve() {
        int n, m, s; cin >> n >> m >> s;
        for (int i = 0; i < m; i++) {
            int x, y, z; cin >> x >> y >> z;
            adjw[x].push_back({y, z});
        }
        dijkstra(s, n);
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