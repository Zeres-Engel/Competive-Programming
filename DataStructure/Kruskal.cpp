#include <algorithm>
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
    
    //Minimum Spanning Tree (Cây khung nhỏ nhất)

    /* 
        cây khung có trọng số cực tiểu là cây khung nhỏ nhất:
        
    Một số tính chất của MST:
        * Tính chất chu trình: Trong 1 chu trình e(max edge) -> không tồn tại MST chứa e
        * Đường đi hẹp nhất: 2 đỉnh u và v. w(max edge) trong đường đi uv -> trong MST không tồn tại đường đi uv
        * Tính duy nhất: all vertex different -> 1 MST, some vertex is the same -> > 1 MST
        * Tính chất cạnh nhỏ nhất: e(min edge) -> mọi MST đều đi qua e
     */

    //Thuật toán Kruskal

    /* 
        * Ý tưởng: Makeset mỗi đỉnh là 1 cây khung. Duyệt theo thứ tự rồi Union lại 
     */
    

struct edge {
    ll u, v;
    ll weight;
};

vector<ll> parent(MAXN), size(MAXN);
vector<edge> EdgeSet;

void MakeSet(ll vertexs) {
    for (ll i = 1; i <= vertexs; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

ll Find(ll v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = Find(parent[v]);
}

bool Union(ll a, ll b) {
    a = Find(a);
    b = Find(b);
    if (a == b) {
        return false;
    }
    else {
        if (size[a] <  size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
}

bool cmp(edge a, edge b) {
    return a.weight < b.weight;
}

void Kruskal(ll edges, ll vertexs) {
    vector<edge> MST;
    ll d = 0;
    sort(EdgeSet.begin(), EdgeSet.end(), cmp);
    for (int i = 0; i < edges; i++) {
        if (MST.size() == vertexs - 1) {
            break;
        }
        edge e = EdgeSet[i];
        if (Union(e.u, e.v)) {
            MST.push_back(e);
            d += e.weight;
        }
    }
    if (MST.size() != vertexs - 1) {
        cout << -1 << endl;
    }
    else {
        cout << "Minimum Spanning Tree:\n";
        for (edge item : MST) {
            cout << item.u << '-' << item.v << ':' << item.weight << endl;
        }
    }
}

    void solve() {
        
        
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