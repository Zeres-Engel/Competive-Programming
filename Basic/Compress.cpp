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
     0    1     2     3      4
    100, 100, 2000, 1500, 900000
     0    1     3     2      4
    100  100  1500   2000  900000
    
    
    
--------------------------------------------------------------------------------------------------------------------------------------------------*/
    
    void compess(vector<ll> a) {
        int n = a.size();
        map<ll, ll> mp;
        for (int i = 0; i < n; i++) {
            mp[i] = a[i];
        }
        sort(mp.begin(), mp.end());
        ll cnt = 0, last = INT_MAX;
        for (pair <ll, ll> items : mp) {
            if (last != items.second) {
                cnt++;
                last = items.second;
            }
            a[items.first] = cnt;
        }
    }
    
    void solve() {
        int n = 5;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (auto items : a) {
            cout << items << ' ';
        }
        cout << endl;
        compess(a);
        for (auto items : a) {
            cout << items << ' ';
        }
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