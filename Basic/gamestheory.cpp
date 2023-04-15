#include <bits/stdc++.h>
#include <cmath>
#include <vector>
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
    1. Trò chơi bốc sỏi

    2. Trò chơi Nim chuẩn
    
    
--------------------------------------------------------------------------------------------------------------------------------------------------*/
    
    //1. Trò chơi bốc sỏi
/*
    Tóm tắt:
    + n viên sỏi
    + An vs Bình bốc luân phiên
    + 1 lượt có thể bốc (1, 2, 3) viên 
    + Người bốc được viên cuối thì là người thắng
    + An trước, Bình sau
*/
    
/*
    Giải:
        + n = 1, 2, 3 thì An thắng
        + n = 3: A -> A
        + n = 4: (A) -> B thắng -> bất lợi luôn luôn
            Nếu Bình thông minh:
                An: 1 | Bình 3 -> Bình thắng
                An: 2 | Bình 2 -> Bình thắng
                An: 3 | Bình 1 -> Bình thắng
            -> Bình luôn thắng
            Nếu Bình ngu:
                An: 1 | Bình 1, An: 2 -> An thắng
                An: 2 | Bình 1 -> An thắng
                An: 3 | Bình 1 -> Bình thắng
            
        -> Nếu Bình khôn Bình luôn thắng và nếu Bình ngu: An bốc (n - 1) Bình thắng
        + n = 5: A -> A thắng nếu khôn ngoan chỉ chọn 1 viên: có lợi 
            + An: 1 | Binh trở thành An (n = 4): An thắng
            + An: 2 | Binh trở thành An (n = 3): Bình thắng
            + An: 3 | Bình thắng
        -> Bình lợi thế hơn
        + n = 6: A -> B thắng khôn ngoan nên có lợi
            + An: 1 | Binh trở thành An (n = 5): Bình khôn Bình thắng
            + An: 2 | Binh trở thành An (n = 4): An khôn An thắng            
            + An: 3 | Binh trở thành An (n = 3): Bình khôn Bình thắng
        -> Bình lợi thế hơn
        + n = 7  A -> A thắng có lợi 
            + An : 1 | Bình (n = 6) -> An lợi hơn
            + An: 2 | Bình (n = 5) -> An lợi hơn
            + An: 3 | Bình (n = 4) An lợi hơn
        + n = 8 bất lợi 
            + An : 1 | Bình (n = 7) -> Bình lợi hơn
            + An: 2 | Bình (n = 6) -> Bình lợi hơn
            + An: 3 | Bình (n = 5) -> Bình lợi hơn
        -> một trong 2 chỉ cần rơi vào trường hợp mod 4 = 0 thì người đó sẽ bất lợi (dù có cố bốc từng viên chờ đợi sai lầm của B vẫn thua)
        -> mod 4 != 0 chỉ cần bốc 1 viên và chờ đợi Bình rơi vào mode 4 = 0 sẽ thắng
 */

    // Trò chơi tổ hợp:

    /* 
        + A trước, B sau lần lượt   ("An", "Bình")
        + Q trường hợp hợp lệ    (1, 2, 3 viên)
        + S tổng trạng thái của trò chơi (n)
        + T trạng thái trò chơi kết thúc  (T C S)   (có viên bi cuối cùng <= 3 viên, T = 0 khi viên bi cuối cùng đc lấy ra)

        VD: 8 viên bi

                                                ****
                                                ****


                                lấy 1           lấy 2            lấy 3

                                ****            ***              ***
                                ***             ***              **
    */

    // Chiến thuật thấng
    /*  
        Giả sử bảng phương án:
        N: 1, 2, 3, 5, 6, 7 người trước thắng
        P: 0, 4, 8 người sau thắng
        suy ra:
            + Nếu rơi vào m mod 4 != 0 sẽ có lợi và dễ ép đối thủ vào m mod 4 = 0
            + Nếu rơi vào m mod 4 = 0 sẽ bất lợi hơn phải lấy 1 viên đợi sai lầm
     */

    // Lời giải của trò chơi tổ hợp cân bằng:
    /*
        N: 1, 2, 3, 5, 6, 7 người trước thắng
        P: 0, 4, 8 người sau thắng
        xây dựng tập N, P
     */

    // Cách xây dựng:
    /**     
    // Hàm kiểm tra một trạng thái thuộc P (true) hay N (false)
    bool isInP(State u) {
        if (u in T) // nếu u là trạng thái kết thúc thì u thuộc P
            return true;
        
        // duyệt qua tất cả các trạng thái v trong tập hợp S
        for (State v in S) 
            if (u, v) in Q and isInP(v)
                return false; // nếu có v thuộc P thì u thuộc N
        
        return true; // nếu không thì u thuộc P
    }
    */


    /*
        u = 5
        -1 -1 -1 -1 -1
        for (4, 2) (Q truy vấn, v)
            isInp(v)        
     */

    // int dp[10000];
    /*
        + dp[u] = 0: trạng thái u thuộc N
        + dp[u] = 1: trạng thái u thuộc P
        + dp[u] = -1; trạng thái này chưa xét
     */
    // int n;
/*     
    Bảng phương án:
        5: -1 -1 -1 -1 -1 (4,2)
        4: -1 -1 -1 -1 -1 (3,1)
        3: -1 -1 -1 -1 -1 (2,0)
        2: -1 -1 -1 -1 -1 (1,0)
        1: -1 -1 -1 -1 -1 (0,0)
        0: -1 -1 -1 -1 -1 (1,0)
        0: 1 0 -1 -1 -1 (2,0)
        1: 1 0 0 -1 -1 (2,0)
        0: 1 0 0 -1 -1 (3,1)
        2: 1 0 0 0 -1 (3,1)
        1: 1 0 0 0 -1 
*/
// Giải thuật Quay Lui
/*     bool isInP(int u) {
        if (dp[u] != -1) // nếu u đã được tính trước đó thì
            return dp[u];
        if (u == 0) { // u = 0 là trạng thái kết thúc nên thuộc P
            dp[u] = 1;
            return 1;
        } 
        // Từ u chỉ có thể đi tới các v hợp lệ
        // Duyệt các cấu hình hợp lệ
        for (int v = u - 1; v >= max(u - 3, 0); v--) {
            if (isInP(v)) { //Chỉ trả về khi đạt trạng thái kết thúc
                dp[u] = 0; // Nếu đạt trạng thái kết thúc thì nó thuộc mảng N
                return false; // để dừng vòng đệ quy
            } 
        }
        // u không đi được trạng thái nào thuộc P
        dp[u] = 1;
        return true; //để tiếp tục vòng đệ quy
    } */

/* 
    Phân tích giải thuật:
        5:
        4 3 2
        + v = 4 (true) dp[5] = 0 false
        4:
        3 2 1
        + v = 3 (false)
        + v = 2 (false)
        + v = 1 (false)
        dp[4] = 1 true
        u = 3:
        2 1 0 
        + v = 2 (false) 
        + v = 1 (false)
        + v = 0 (true) dp[3] = 0 false
        u = 2:
        1 0  
        + v = 1 (false) 
        + v = 0 (true) dp[2] = 0 false
        u = 1:
        0
        + v = 0 (true) dp[1] = 0 false
        u = 0:
        trạng thái kết thúc dp[0] = 1 false 
    Cứ n lần false sẽ có lần true và dẫn đến lựa chọn true để bắt đầu một n cấu hình mới
*/

    // Trò chơi Nim chuẩn (tổ hợp cân bằng) (đóng sỏi là con của Nim)
    /*
        + n đống sỏi (p1, p2,... pn)
        + trạng thái của pn sỏi (cho biết số lượng của pn)     
        - 2 người chơi A, B:
            + chọn đống i và bốc s sỏi (pi = pi - s)
            + Cấu hình kết thúc khi sỏi hết
        Phân tích:
            + A trước, B sau
            + T: trường hợp hợp lệ: s > 0
            + S: p1 + p2 + ... + pn
            + Q: trường hợp kết thúc: khi đám sỏi = 0
        Khác trò đống sỏi:
            + chỉ có 1 đống sỏi | n đống sỏi
            + chỉ bốc 1, 2, 3 | s > 0
    */

        // Giá trị Nim
        /*
            Mục tiêu: Xác định người thắng trong trường hợp họ chơi tối ưu (Xác định chiến thuật thắng)
                - Khó khăn:
                    + nhiều đống sỏi phải dp nhiều chiều 
            giá trị Nim (g) để kết hợp nhiều trạng thái thành một số nguyên duy nhất
         */

         /*
            Giải:
                Với 1 đống sỏi p viên sỏi:
                    - số lượng sỏi trong đống: p -> giá trị Nim là p cho biết đống sỏi còn lại
                    - thấy:
                        p > 0 thuộc N
                        p = 0 thuộc P
                        vì chúng ta có thể lấy một lượng sỏi vô hạn và người chơi tối ưu
                    -> thuộc N khi Nim > 0 và thuộc P khi Nim = 0 
                
                Tiếp theo: ghép đống sỏi đơn thành n cụ thể:
                    A ^ B để biết giá trị Nim của trò chơi
                    Phép tuyển chặt để gộp các cột lại:
                        + (A ^ B) ^ C = A ^ (B ^ C) và A ^ B = B ^ A (thứ tự các cột không quan trọng)
                        + A ^ 0 = A (nghĩ là khi thêm một đống sỏi thì giá trị Nim vẫn như cũ)
            
                        + A ^ A  = 0 (một phần tử đối(!) của mỗi trạng thái là chính nó 
                            gs:
                                2 đống sỏi giống nhau: 
                                    + p sỏi
                                    + chiến lược chiến thắng cho người sau là sao chép y chang người trước:
                                        .    .
                                        ..   ..
                                        ...  ...
                                       người sau luôn thắng
                            )
                        -> g = 0
                    3 thuộc tính này tương đồng với phép XOR 
                    Thực chất phép XOR là phép cộng mod 2 trên từng bit
                    Gọi Nim là tổng Nim
                    Tổng Nim của trạng thái (p1, p2,... pn) g = p1 ^ p2 ^ ... ^ pn
                    Ví dụ: với trò chơi Nim có ba đống sỏi với số sỏi lần lượt là 5, 7, 3 thì tổng Nim là 0101 ⊕ 0111 ⊕ 0011 = 0001.
                    Kết luận ta sẽ lấy kết quả của mảng dp và XOR từng mảng với nhau 
                                bool isInP(vector<int> v) {
                                    int g = 0;
                                    for (auto p: v)
                                        g ^= p;
                                    return (g == 0);
                                }   
          */
        // Trò chơi tổng

        /*
            + trò chơi G1(S1, Q1, T1), G2(S2, Q2, T2) ...
            Trò chơi tổng: G = G1 + G2
                + S = S1 * S2
                + Q = (Q1 * x2) U (x1 * Q2)
                + T = {(x1, x2) : x1 thuộc T1 ^ x2 thuộc T2}
            Ví dụ: trò chơi có 3 đống sỏi là tổng của G1, G2, G3 
        */
    const int MAX_N = 100000; 
    vector<int> v;

    int dp[MAX_N];

    bool convertG(int u) {
        if (dp[u] != -1) {
            return dp[u];
        }
        if (u == 0) { 
            dp[u] = 1;
            return 1;
        } 
        for (int v = u - 1; v >= max(u - 3, 0); v--)
            if (convertG(v)) {
                dp[u] = 0;
                return false; 
            }
        dp[u] = 1;
        return true;
    }

    ll convertDEC(int n) {
        ll S = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] == 1) {
                S += pow(2, n - 1 - i)*dp[i];
            }
        }
        return S;
    }

    void NimRecords(vector<ll> g) {
        for (ll &x : g) {
            fill(dp, dp + x + 1, -1);
            convertG(x);
            v.push_back(convertDEC(x));
        }
    }

    bool isInP() {
        ll g = 0;
        for (ll p: v)
            g ^= p;
        return (g == 0);
    }

    void solve() {
        vector<ll> c;
        c.push_back(7);
        c.push_back(2);
        c.push_back(9);
        NimRecords(c);
        cout << isInP();
        for (auto x : v) {
            cout << x << ' ';
        }
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