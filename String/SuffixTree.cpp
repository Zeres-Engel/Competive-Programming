#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstring>
#include <future>
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
    //* Suffix Tree (siêu khó)


    /*
        Quy ước:
            - E: {0,...,..., n}
            - E*: {string a, string b, string c, ...}
            - |x|: độ dài xâu
            w: prefix (x), x = wy
            w: suffix (x), x = yw
            ABA: both Prefix and Suffix 
            ABABA: 
            + 
        Bổ đề 1:
            Tính gối nhau giữa prefix and suffix:
                +   x = prefix (z)
                    y = prefix (z)
                -> x = prefix(y) (|x| <= |y|) and y = prefix(x) (|x| >= |y|)
                +   x = suffix (z)
                    y = suffix (z)
                -> x = suffix(y) (|x| <= |y|) and y = prefix(x) (|x| >= |y|)
        VD:
            - Tiền tố:
                BANANA
                BANAN
                BANA

            - Hậu tố:
                BANANA
                 ANANA
                  NANA
        Ta chọn @ là kí tự cầm canh: @, A, B, C, ..., Z
     */

    //* Trie Hậu Tố 

    /*
        Điều Kiện:
            + Không có bất kì xâu làm tiền tố của 1 xâu còn lại (S = {AB, ABC} là sai)
            + 
     */

    /*
        - Cây hậu tố là cấu trúc dữ liệu lưu hậu tố của một xâu: 
            + Dẫn xuất của rất nhiều cấu trúc dữ liệu:
                + Suffix Array
     */

    //VD Trie Hậu Tố.png
    // S = {BEAR, BELL, BID, BULL, BUY, SELL, STOCK, TOP}
    // -> Vì S phi tiền tố (prefix-free)
    
    /*
        Thực tế người ta thường bổ sung lính cầm canh @ vào cuối string, đảm bảo tính prefix-free
            S = {ABC@, AB@}
        Trie Hậu Tố 2.png

            BANANA@
             ANANA@
              NANA@
               ANA@
                NA@
                 A@
                  @
        ! nút lá: Nút mà không có con
        * Một vài Ví dụ dùng Trie Hậu Tố:
            * Kiểm tra Q is Substring T:
                Q = AN, T = BANANA@
                + Ta xét gốc trie và duyệt Q:
                    + Nếu Q[i] = T[j]: Nhảy xuống nhánh đó
                        + Nếu việc nhảy xuống một nốt khác thất bại -> is not Substr
                        + nếu duyệt hết Q -> tồn tại
                -> số nút lá gốc A là số lần xâu Q xuất hiện
                VD: dừng tại nhánh N có 2 lá -> xâu lặp lại 2 lần
            * Tìm xâu con lặp dài nhất:
                Tìm nút v sâu nhất của nhánh cây gốc có ít nhất 2 lá:
                -> |v| là xâu con lặp dài nhất
                VD: Nút v sâu nhất có nhẵn (ANA) có 2 lá  
            * Tìm xâu con lặp ít nhất k lần:
                Tìm nút v sâu nhất có ít nhất k lá 
                    VD: nút A có 3 lá -> lặp 3 lần
                        nút ANA có 2 lá -> lặp 2 lần
                        nút NA có 2 lá -> lặp 2 lần
                        nút BA có 1 lá -> lặp 1 lần
    !Bổ đề: xâu n có cây hậu tố không qúa 2n nút
     */
    //* Mảng Hậu Tố (Suffix Array) 
    /*
        Thứ tự từ điển tất cả các hậu tố của T.
        S = BANANA@ có hậu tố được đánh số:
            BANANA@ 1
             ANANA@ 2
              NANA@ 3
               ANA@ 4
                NA@ 5
                 A@ 6
                  @ 7 
        sắp xếp theo tứ tự từ điển:
            @: 7
            A@: 6
            ANA@: 4
            ANANA@: 2
            BANANA@: 1
            NA@: 5
            NANA@: 3
        -> SA(S): 7 6 4 2 1 5 3
        các số: 7 6 4 2 1 5 3 đánh dấu kí tự bắt đầu của hậu tố 
     */
     

    //* Mảng Tiền Tố Chung Dài Nhất (Longest Common Prefix)
    /* 
        LCP của string x, y = z thỏa mãn:
            + z = prefix(x) = prefix(y);
            VD:
                x = "SUFFIXTRIE"
                y = "SUFFIXTREE"
            ->  z = "SUFFIXTR"
        T = {...} -> SA(T) = {...} là mảng hậu tố T.
        -> LCP(T) = {...}:
        + l0 = 0
        + với mọi i > 0: 
            + li là độ dài tiền tố chung dài nhất giữa hậu tố tại a[i], và hậu tố tại a[i - 1]
        VD:
            T = BANANA@, SA(T) = (7, 6, 4, 2, 1, 5, 3) ta có:
            l0 = 0
            l1 = 0 (độ dài tiền tố chung A@ và @ (SA[7], SA[6]))
            l2 = 1 (ANA@ và A@ (S[4], S[6]))
            l3 = 3 (ANANA@ và ANA@ (S[2], S[4]))
            l4 = 0 (BANANA@ và ANANA@ (S[1],S[2]))
            l5 = 0 (NA@ và BANANA@(S[5],S[1]))
            l6 = 2 (NANA@ và NA@ (S[3], S[5]))
        Bản chất:
            Tiền tố chung dài nhất của 2 hậy tố là nhãn của nút tổ tiên thấp nhất (lowest common ancestor - LCA)
            LCP LCA.png dựa theo hình:
                Tiền tố chung dài nhất của A@ và ANA@ là nhãn A
                LCP ANANA@ và ANA@ là nhãn A
        -> Có rất nhiều thuật toán LCA to find LCA, O(1)
        -> LCP O(n) tuy nhiên Kasai đã đề xuất 1 thuật toán cực đơn giản để xây dựng LCP từ Suffix Array
     */

    //* Xât dựng Suffix Array, Longest Common Prefix, Suffix Tree (Suffix Array -> LCP -> Suffix Tree)
    
    //* Suffix Array (Suffix Array. PNG)

    /*
        S = BANANA@ có hậu tố được đánh số:
            BANANA@ 1
             ANANA@ 2
              NANA@ 3
               ANA@ 4
                NA@ 5
                 A@ 6
                  @ 7 
        sắp xếp theo tứ tự từ điển:
            @: 7
            A@: 6
            ANA@: 4
            ANANA@: 2
            BANANA@: 1
            NA@: 5
            NANA@: 3
        -> SA(S): 7 6 4 2 1 5 3
        ------------------------------------------------------
        + Có thể xây dựng trực tiế từp Suffix Tree O(n):
        + Thuật toán nhân đôi tiền tố:
            Dễ cài đặt: O(nlogn) nhưng trung bình cần O(n):
            - Ý tưởng:
                1.sắp xếp tăng dần các kí tự trong (BANANA@ -> @AAABNN) -> Ký tự bắt đầu của từng hậu tố (O(logn))
                2.gán số cho mỗi hậu tố đầu: (O(n))
                    + Hậu tố = kí tự bắt đầu có số = nhau
                    + Hậu tố != kí tự bắt đầu có số != nhau
                   1222344
                -> @AAABNN
                -> Khóa số -> ký tự đầu mỗi hậu tố -> dãy hậu tố tăng dần theo kí tự đầu (khóa chính)
                Gán khóa phụ (kp)= vị trí + khóa chính của một hậu tố gần nhất đứng sau = i + kc
                   1222344
                   @AAABNN
                -> 
                BANANA@ 1, kc: 3, kp: 1 + 2 = 3
                 ANANA@ 2, kc: 2, kp: 2 + 4 = 6
                  NANA@ 3, kc: 4, kp: 3 + 2 = 5
                   ANA@ 4, kc: 2, kp: 4 + 4 = 8 = -1
                    NA@ 5, kc: 4, kp: 5 + 2 = 7 = -1
                     A@ 6, kc: 2, kp: 6 + 1 = 7 = -1
                      @ 7, kc: 1, kp: 7 
                3. Sắp xếp lại lần nữa:
                    Nếu khóa chính = nhau:
                        + xét khóa phụ (nhỏ hơn xếp trước)
                    Đặt câu hỏi: khóa phụ = nhau thì phải làm sao -> cái nào trước cũng được
                    Lưu ý:
                        Với các hậu tố đã được sắp xếp, thì sẽ đc gán khóa mới:
                            + Hậu tố đầu: 0
                            + Hậu tố còn lại:
                                + Nếu nó có khóa chính và khóa phụ giống khóa trước:
                                    + khóa mới của nó = khóa mới liền trước
                                    + Nếu không thì khóa mới = hậu tố + 1
                                
    */

 

        /* 
            B(0):1 0
            BANANA
            A(1):0 13
            ANANA
            N(2):13 0
            NANA
            A(3):0 13
            ANA
            N(4):13 0
            NA
            A(5):0 -1
            A
            VD: 
                so sánh: BANANA và ANA
                   + B(0):1 0
                     BANANA
                   + A(3):0 13
                     ANA
                -> ANA < BANANA vì rank[0] (B) > rank[1] (A)
                so sánh: ANANA và ANA
                   + A(1):0 13
                     ANANA
                   + A(3):0 13
                     ANA
         */

    //* Xây dựng mảng tiền tố chung dài nhất

    /*
        T = BANANA@, SA(T) = (7, 6, 4, 2, 1, 5, 3) ta có:
            l0 = 0
            l1 = 0 (độ dài tiền tố chung A@ và @ (SA[7], SA[6]))
            l2 = 1 (ANA@ và A@ (S[4], S[6]))
            l3 = 3 (ANANA@ và ANA@ (S[2], S[4]))
            l4 = 0 (BANANA@ và ANANA@ (S[1],S[2]))
            l5 = 0 (NA@ và BANANA@(S[5],S[1]))
            l6 = 2 (NANA@ và NA@ (S[3], S[5]))
        Ý tưởng:
            + tính rank[i] = j <-> sa[j] = i;
            l0, l1, l2, l3, l4 theo thứ tự l[rank 1], l[rank 2], l[rank 3]
     */
    
    //* Xây dựng Suffix Tree
    /*
        Ý tưởng:
                Chèn lần lượt các mảng hậu tố vào cây 
                Nút lá cực phải là x -> lá 
                Mỗi khí xét tới hậu tố aj, ta đi từ lá của phải x -> gốc tới nút u có depth(u) = li
            Trường hợp 1:
                + Nếu depht(u) = li:
                    + Tạp 1 nút lá mới y làm con của u và đặt nhãn cạnh (u,y) ((u, y) nối với u là hậu tố ạ)
                VD: chèn ABCABEF@ sau đó chèn thêm ABEF@
                    u = AB là LCP ABCABEF@ và ABEF@
            Trường hợp 2:
                + Nếu depth(u) < LCPi:
                    + Thêm nút w làm con u và cha v để tách cạnh (u, v) làm 2 cạnh (u, w) và (w, v)
     */
    

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

namespace Suffixes {

    const int MAXN = 1 << 21;
    string s;
    int N, gap;
    int SA[MAXN], pos[MAXN], tmp[MAXN], LCP[MAXN];

    bool sufCmp(int i, int j) {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i < N && j < N) ? pos[i] < pos[j] : i > j;
    }

    void buildSA() {
        N = s.length();
        REP(i, N) SA[i] = i, pos[i] = s[i];
        for (gap = 1;; gap *= 2) {
            sort(SA, SA + N, sufCmp);
            REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(SA[i], SA[i + 1]);
            REP(i, N) pos[SA[i]] = tmp[i];
            if (tmp[N - 1] == N - 1) break;
        }
    }

    void buildLCP() {
        for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1) {
            for (int j = SA[pos[i] + 1]; s[i + k] == s[j + k];) {
                k++;
            }
            LCP[pos[i]] = k;
            if (k)--k;
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
        int test = 1; 
        while (test--) {
            solve();
        }
    }