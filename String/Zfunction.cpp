#include <bits/stdc++.h>
#include <vector>
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
    
    // Z function (Hàm Z của một chuỗi S)
    /*
        Cho:
            + S độ dài n S[0 ... n - 1]
        -> hàm Z tương ứng Z[0 ... n - 1] với Z[i]: max(sufix shared)
        VD: S = "aaabaab"

         i      S[0 ... n - 1]      S[i ... n - 1]      Z[i]
         0      aaabaab             aaabaab             0 (quy ước nếu S = T)
         1      aaabaab             aabaab              2 ("aa")
         2      aaabaab             abaab               1 ("a")
         3      aaabaab             baab                0 
         4      aaabaab             aab                 2 ("aa")
         5      aaabaab             ab                  1 ("a")
         6      aaabaab             b                   0
        Ta tính được Z function tương ứng như sau:
               0 1 2 3 4 5 6
            S: a a a b a a b
            Z: 0 2 1 0 2 1 0
     */
    // tính Z function ngây thơ O(n^2)
    /* vector<int> Z (string s) {
        vector<int> tmp;
        tmp.push_back(0);
        int n = s.length();
        for (int i = 1; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (s[j] == s[j + i]) {
                    cnt++;
                }
                else {
                    break;
                }
            }
            tmp.push_back(cnt);
        }
        return tmp;
    }  */
    // Tối ưu Z 
    /* 
        Ta có:
            +    Z[k] = |d| > 0   -> S[k, ..., k + z[k] - 1] khớp với S[0 ... z[k] - 1]
                VD:  
                    i:  0 1 2 3 4    
                    S = a a b c d
                    vơi k = 1
                    k:    0 1 2 3
                    T = a a b c d
                    -> Z[k = 1] = 1 "a"
                    S có 1 vị trí khớp: S[0, Z[k]] = S[0, 1]
                    T có 1 vị trí khớp: S[k, k + Z[k]]
            + Đặt:
                l = k, r = k + Z[k] - 1, với Z[i]
                có 2 trường hợp:
                    + i <= r (k + Z[k] - 1):
                        vì S[l, r] giống S[0, r - l]
                        -> với k = k + 1
                        ko cần duyệt S[i,...,r] trước đó, chỉ cần lấy lại Z[i - l]
                        Tuy nhiên:
                            z[i - l] có thể > r - i + 1
                        -> z[i] = min (r - i + 1, z[i - l])
                        VD1:
                            S = aaabaab
                            i = 1:
                                + l = 1, r = 2 
                                Xét S[1,...,2] với S[0,...,1] khớp "aa" -> Z[1] = 2
                            i = 2:
                                + l = 2, r = 2
                                vì S[1,...,2] khớp S[0,...,1] -> S[2,2] khớp S[0,1]
                                Xét S[2,2]  với S[0, 1]
                        VD2:
                            k = 1:
                                aaabaab
                                 aabaab
                            -> khớp "aa" : 2
                            k = 2:
                                aaabaab
                                  abaab
                            vì "aa" đã khớp rồi suy ra đã có 1 phần tử được khớp
                                Z[k = 2] = Z[k = 2 -]
                            xét a != b 
                            -> khớp "a" : 1
                            k = 3
                                aaabaab
                                   baab
                        -> Khớp[k + 1] = Khớp[k] - 1 + Xét thêm từ[k]
                        Khởi tạo Z[k] = Z[k - l] 
                        Xét thêm:
                            ìf "=="
                            Z[k] ++ 
                        r = i + Z[i] - 1
                        Tuy nhiên:
                            z[i - l] có thể > r - i + 1
                            VD:
                            + k = 1
                                S = aaabc
                                T = aab
                                khởi tạo: Z[1] = Z[0] = 0
                                Xét:
                                    aaabc
                                    aab
                                    if S[Z[k]] == T[k + Z[k]]
                                        Z[k]++;
                                Z[2] = 2
                                l = k
                                r = k + Z[k] - 1 
                            + k = 2
                                Z[k] = Z[k - 1] = 2
                    + i > r:
                        không thể làm ăn gian 

    * Kết luận:
        Nếu ta xét:
            + l = k
            + r = k + z[k] - 1
        * -> S[l,...,r] khớp với S[0, r - l]
        Già sử với:
            + k = 1, Z[k] = 3:
                + l = k = 1
                + r = k + Z[k] - 1 = 3

            -> S[1, 3] khớp với S[0, 2]

            + k = 2, Z[k] = Z[k]
    */

    /*
        0123456789
        fdasffdaff
     */

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        // khoi tao z[i] theo thuat toan toi uu
        if (i <= r)  {
            int d = z[i - l];
            z[i] = min(r - i + 1, z[i - l]);
            /*
                Z[i] = Z[i - l]
                VD:
                    0123456789
                    abchjklabc
                + Z[7] = 3 
                    + (l, r) = (7, 9)
                    -> (7,8,9) khớp với (0,1,2)
                    -> Z[8] = Z[1] = Z[i - l] 
                    Tuy nhiên Z[i - l] có thể lớn hơn biên R:
                        VD:

                            *012345678
                            *aaaaabaaa
                            *aaabaaa Z[2]
                            *aaa Z[6]
                            *aa Z[7]
                        Z[6] aaa
                        Z[7] aa
                        Z[8] a
                            + Z[1] = 4
                            + Z[2] = 3
                            + Z[3] = 2
                            + Z[4] = 1
                            ...
                            + Z[6] = 3 -> S[6...9] = S[0...3]
                            !+ Z[7] = Z[2] = 4 (bị lố n) phải thay băng r - i + 1 vì Z[7] = Z[6] - 1 vì Z[6] đã đi hết (1,n)
                        !Ngược lại:
                            *012345678
                            *aaabaaaba
                            *aaaba Z[4]
                            *aaba Z[5]
                        Z[4] aaaaa
                        Z[5] aaaa
                        Z[6] aaa
                        Z[7] aa
                        Z[8] a
                            + Z[1] = 2
                            + Z[2] = 1
                            ...
                            + Z[4] = 4 -> S[4...8] khớp với S[0...4]
                            !+ Z[5] = r - i + 1 = 3 bị sai vì Z[5] = 2 
                        * Kết Luận:
                            * Z[i] = min(r - i + 1, Z[i - l])
                                * = Z[i - l] khi chuỗi khớp Suffix > Prefix
                                * = r - i + 1 = Z[i - 1] - 1 khi chuỗi khớp Prefix < Suffix
                        
             */
        }
        // tinh z[i]
        /* 
            Tính số lượng phân tử khớp thêm
         */
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        // cap nhat doan [l,r]
        /*  
            Không cập nhật khi: 
                Z[i - 1] != 0 
                Z+ = 0
                thì không cần cặp nhật nữa:
                VD
                    Z[3] khớp (3, 8) khớp thêm = 6 (0 -> 6)
                    Z[4] khớp (3, 8) khớp thêm = 0 (5 -> 5) thì đoạn khớp vẫn là (3, 8) 
                    nên không cần thiết cập nhật

        */
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        } 
    }
    return z;
}


    void solve() {
        string s; cin >> s;
        vector<int> Z =z_function(s);
        for (int i = 0; i < s.size(); i++) {
            cout << 'Z' << i << " = " << Z[i] << endl;
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