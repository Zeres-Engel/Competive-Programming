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
     
     //Topological Sort
    
    /*          
            1  ->  2  ->   3
            |      |       |
            6      4  ->   5

            1 2 3 4 5 6
        Hoạt động trên đồ thị có hướng:
        Thứ tự TOPO: u có đường đi tới v thì u đứng trước v 
     */


      /*
            
                                THUẬT TOÁN SẮP XẾP TOPPO

    Trong đồ thị có hướng, đưa ra các thứ tự duyệt các cái đỉnh sao cho có đường đi từ x 
    cho đến y nếu có đường đi thì x sẽ xuất hiện trước

    DFS: Đỉnh được thăm xong đầu tiên trong thuật toán sẽ là đỉnh không có đường đi đến 
    các đỉnh khác.
        Code tham khảo:
            void DFS(int u) {
                visited[u] = true;
                for (int v : dsk[u]) {
                    if (!visited[v]) {
                        DFS(v);
                    }
                }
                topo.push_back(u);
            }


    BFS (Kahn thuật toán xóa dần đỉnh)
    Tính được bán bậc vào của các đỉnh. Các đỉnh có bán bậc vào là 0 là các định có số lần 
    xuất hiện đâù tiên của thuật toán Topo. Đẩy các đỉnh đó vào hàng đợi
        Code tham khảo:
    void Kahn() {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (int v : dsk[u]) {
                if (!visited[v]) {
                    in[v]--;
                    if (in[v] == 0) {
                        q.push(v);
                    }
                }
            }
        }
        for (int x : topo) {
            cout << x << " ";
        }
    } 
     */

    vector<int> topo;
    bool visited[1];
    int in[22];
    int n;
    vector<int> dsk[23413];


    void DFS(int u) {
        visited[u] = true;
        for (int v : dsk[u]) {
            if (!visited[v]) {
                DFS(v);
            }
        }
        topo.push_back(u);
    }

    void Kahn() {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (int v : dsk[u]) {
                if (!visited[v]) {
                    in[v]--;
                    if (in[v] == 0) {
                        q.push(v);
                    }
                }
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
        int test = 1; cin >> test;
        while (test--) {
            solve();
        }
    }
     
