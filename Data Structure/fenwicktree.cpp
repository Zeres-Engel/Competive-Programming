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
    
    //Fenwick Tree (Cây chỉ nhị phân)

    /*
        Cho dãy 3 5 2 6 9 1 2 có 2 truy vấn:
            1. Tăng ax thêm y
            2. in ra tổng từ [l, r] 
     */

    /*
        Ý tưởng:
            + Prefix sum 
            + Biểu diễn nhị phân

        Ta thấy:
            Mọi số nguyên đêu có dạng nhị phân: 3 = 2^0 + 2^1
        Cụ thể:
            n = 2^i1 + 2^i2 + ... + 2^in
        Giả sử:
            Tổng [1, n]
            S[1, n] = 1 + 2 + 3 + ... + n 
            <=> 1 + 2^1 + (2^0 + 2^1) + ... + n
        Ví dụ:
            n = 1 = 2^0, tính tổng đoạn [1, 1]
            n = 5 = 2^2 + 2^0, tính tổng đoạn [1, 4] và [4, 5]
            n = 7 = 2^2 + 2^1 + 2^0, tính tổng đoạn [1, 4], [4,6], [6, 7]
     */

    /*
        ! Tất cả các bài giải đc bằng Fenwick Tree đều có thể giải được bằng Segment Tree
     */
    int fen[1000];

    // Dùng để nhận tham số i và tính tổng từ [1, i]

    ll Query(int i) {
        ll sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += fen[i];
        }
        return sum;
    }

    void Update(int i, int val){
        for(; i <= 1000 ; i += i & -i) fen[i] += val;
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