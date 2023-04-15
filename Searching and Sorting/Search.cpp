#include <bits/stdc++.h>
#include <cmath>
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

db f(db x) {
    return -x*x + 2*x + 3;
}

db TernarySearch(db left, db right) {
    ll N_ITER = 1000;
    for (int i = 0; i < N_ITER; i++) {
        db x1 = left + (right - left)/3.0;
        db x2 = right - (right - left)/3.0;
        if (f(x1) < f(x2)) {
            right = x2;
        }
        else {
            left = x1;
        }
    }
    return  f(left);
}

    void solve() {
        cout << TernarySearch(0, 1) << endl;
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