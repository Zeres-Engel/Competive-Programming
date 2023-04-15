#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;

#define PI acos(-1)

typedef complex<double> base;
typedef vector<base> vb;

const int NBIT = 18;
const int N = 1<<18;
const int MOD = (int)1e9+7;

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
    
    
    
    
    
--------------------------------------------------------------------------------------------------------------------------------------------------*/
    
     //primitive test
    int revBit(int nbit, int mask) {
        int i, j;
        for (i = 0, j = nbit - 1; i <= j; ++i, --j) {
            if ((mask >> i & 1) != (mask >> j & 1)) {
                mask ^= 1<<i;
                mask ^= 1<<j;
            }
        }
        return mask;
    }

    void FFT(int n, vb& a, bool invert) {
        base W[N];
        if (n == 1) {
            return;
        }
        int i, j, k;
        for (i = 0; i < n; ++i) {
            j = revBit(NBIT, i);
            if (i < j) {
                swap(a[i], a[j]);
            }
        }
        vb anext(n);
        for (int step = 1; step < n; step <<= 1) {
            double ang = PI / step;
            if (invert) {
                ang = -ang;
            }
            base w(1), wn(cos(ang), sin(ang));
            for (i = 0; i < step; ++i) {
                W[i] = w;
                w *= wn;
            }
            int start_even = 0;
            int start_odd  = start_even + step;
            while (start_even < n) {
                for (i = 0; i < step; ++i) {
                    anext[start_even + i] = a[start_even + i] + W[i] * a[start_odd + i];
                    anext[start_even + i + step] = a[start_even + i] - W[i] * a[start_odd + i];
                }
                start_even += 2*step;
                start_odd  = start_even + step;
            }
            for(i = 0; i < n; ++i) {
                a[i] = anext[i];
            }
        }
        if (invert) {
            for(i = 0; i < n; ++i) {
                a[i] /= n;
            }
        }
    }

    // n = rank(p) + rank(q) + 1
    vector<base> MulPoly (vector<base> p, vector<base> q, int n) {
        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << ' ';
        }
        vector <base> h(n);
        FFT(p.size(), p, false);
                for (int i = 0; i < p.size(); i++) {
            cout << p[i] << ' ';
        }
        FFT(q.size(), q, false);
        for (int i = 0; i < n; i++) {
            h[i] = p[i] * q[i];
        }
        FFT(h.size(), h, true);
        return h;
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