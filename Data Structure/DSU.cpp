#include <bits/stdc++.h>
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

int di[4] = {1, -1, 1, -1};
int dj[4] = {-1, 1, 1, -1};

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
    
    
    /* 
                                    Cấu Trúc Dữ Liệu Các Tập Hợp Rời Nhau

    Hỗ trợ thao tác tìm và gộp
        Gộp 2 phần tử vào cùng 1 tập hợp 
        Chỉ ra phần tử đó thuộc tập hợp

    Thao tác:
        Make set (a): Tạo tập hợp chứa phần tử a
        Union (a, b): Gộp 2 tập hợp với nhau
        Find (a): Tình phần tử đại diện cho tập hợp a thuộc
     */
    
vector<ll> parent(MAXN), size(MAXN), minset(MAXN), sum(MAXN), value(MAXN);

void MakeSet(ll vertexs) {
    for (ll i = 1; i <= vertexs; i++) {
        parent[i] = i;
        size[i] = 1;
        minset[i] = value[i];
        sum[i] = value[i];
    }
}

ll Find(ll v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = Find(parent[v]);
}

void Union(ll a, ll b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (size[a] <  size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        sum[a] += sum[b];
        minset[a] = min(minset[a], minset[b]);
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
        int test = 1; cin >> test;
        while (test--) {
            solve();
        }
    }