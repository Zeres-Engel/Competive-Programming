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
    
    /*
        * các thao tác bit cơ bản 
            * Phép dịch trái: <<=   (x <<= y)
            * Phép dịch phỏi: =>>   (x >>= y)
            * NOT: !    (x != y)
            * AND: &    (x & y)
            * XOR: ^    (x ^= y)
            * ~x: 

        * Các mẹo:
            * lấy bội của 2.x: x <<= 1
            * a ^= b ^= a tráo đổi
            * (a & 1) = true (là số lẻ) còn lại là (số chẵn)
            
    */


    
    void solve() {
        int k = 3;
        cout << ~k;
        k += 1;
        cout << ~k;
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