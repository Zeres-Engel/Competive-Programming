#include <bits/stdc++.h>
#include <cctype>
using namespace std;
using ll = long long;
using db = double;

#define PI acos(-1)

typedef complex<double> base;
typedef vector<base> vb;

const int baseC = 31;
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

    //hash

    /* ý tưởng:
            a, b, c... z -> số 
            a, c, z, d = 1,3,26, 4
            Lưu ý:
                a = 1 thay vì 0 để tránh abc và bc có giá trị bằng nhau
                base là một số nguyên tố
            ý tưởng chính:
                2 string ở hệ cơ số <base> (base > 26) -> hệ cơ số 10 (DEC) rồi so sánh
                - tuy nhiên: 1 xâu -> 10 có thể không lưu trữ được
                - khắc phục: chuyển sang hệ cơ số 10 ta lấy đồng dư: 
                    x mod MOD = y mod MOD (MOD là một số nguyên tố)
                Dễ dàng thấy x mod MOD = y mod MOD -> a = b là sai vì chỉ là điều kiện cần
                tuy nhiên ta chấp nhận vì đánh giá độ chính xác của thuật toán hash
     */

    // cài đặt
    /*
        - gọi biểu diễn thập phân của s là mã Hash của xâu đó 
            + 2 xâu bằng nhau khi mã Hash bằng nhau
        công thức mã hash:
            - Hashing Function: H(k) = k mod m
            - Giả random ứng dụng hash:
                X[n + 1] = (a*X[n] + c) mod m
                    + 2 <= a < m (a = 1 thì sẽ ra lại quy luật lặp lại 74217412)
                    + 0 <= c < m (c = 0 thì sẽ ra lại chính số đó 33333333)
                    + m = 9 random (0....m - 1) là (0.... 8)
    
            -> hashS = (hashS*base + (P[i] - 'a' + 1)) mod MOD
                phân tích:
                    + hashS in (0... MOD - 1)
            - Hashing 1 chuỗi con:
                    S = (4,1,2,5,2)
                    chuỗi con T = (1,2,5)
                    để thu đc được chuỗi con ta chỉ cần
                    lấy S = (4,1,2,5,2) - S(4).base^4 (4,0,0,0,0) - S(2).base^1 (0,0,0,0,2) = (1,2,5)
            -> Để cài đặt ý tưởng này ta phải tính thêm S(i...).base^x
                pow[i] = (pow[i-1] * base) mod MOD để tính base^x
    */

ll BasePow[MAXN], Hashing[MAXN];

ll getHashT(int i,int j) {
    return (Hashing[j] - Hashing[i - 1] * BasePow[j - i + 1] + 1ll* MOD * MOD) % MOD;
}    

void Searching(string s, string pat) {
    int s_len = s.length(), p_len = pat.length();
    s = " " + s; pat = " " + pat;
    BasePow[0] = 1;
    for (int i = 1; i <= s_len; i++) {
        BasePow[i] = (BasePow[i - 1] * baseC) % MOD;
    }
    for (int i = 1; i <= s_len; i++) {
        Hashing[i] = ('a' <= s[i] && s[i] <= 'z') ? (Hashing[i - 1] * baseC + s[i] - 'a' + 1) % MOD : (Hashing[i - 1] * baseC + s[i] - 'A' + 1) % MOD;
    }
    ll hashP = 0;
    for (int i = 1; i <= p_len; i++) {
        hashP = ('a' <= s[i] && s[i] <= 'z') ? (hashP * baseC + pat[i] - 'a' + 1) % MOD : (hashP * baseC + pat[i] - 'A' + 1) % MOD;
    }
    for (int i = 1; i <= s_len - p_len + 1; i++) {
        if (hashP == getHashT(i, i + p_len - 1)) {
            cout << i << ' ';
        }
    }
}

    void solve() {
        string a; cin >> a;
        string b; cin >> b;
        Searching(a, b);
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