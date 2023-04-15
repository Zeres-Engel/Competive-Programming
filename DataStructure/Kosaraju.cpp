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
    
    /*                                     THUẬT TOÁN KOSARAJU
    
    Dùng để tìm số thành phần liên thông mạnh của đồ thị
    Đồ thị liên thông mạnh: Giữa hai đỉnh bất kì luôn có đường đi


    Bước 1: Gọi thuậttoán sắp xếp TOPPO (DFS)
    Bước 2: Xây dựng đồ thị lật ngược ban đầu
    Bước 3: Lần lượt pop các đỉnh trong stack ở bước 1 và liệt kê các thành phần liên thông mạnh
    Độ phức tạp O(2(v + e))

        int n, m;
    vector <int> dsk[10001], r_dsk[10001];
    bool visited[1001];
    stack <int> st;

    void DFS1(int u) {
        visited[u] = true;
        for (int items : dsk[u]) {
            if (!visited[items]) {
                DFS1(items);
            }
            st.push(items);
        }
    }

    void DFS2(int u) {
        visited[u] = true;
        cout << u << " ";
        for (int items : r_dsk[u]) {
            if (!visited[items]) {
                DFS2(items);
            }
            st.push(items);
        }
    }

    void SCC() {
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                DFS1(i);
            }   
        }
        cout << endl;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (!visited[u]) {
                DFS2(u);
            }
        }
    } */
    
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