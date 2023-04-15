#include <bits/stdc++.h>
#include <cmath>
#include <cstring>
#include <ratio>
#include <string>
#include <type_traits>
using namespace std;
using ll = long long;
using db = double;

#define PI acos(-1)

typedef complex<double> base;
typedef vector<base> vb;

const int MAXN = 100000;
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

    //string matching

    // KMP

    /*
        VD1:
            xâu con chung của S vs T -> S có khớp với T hay không
            S = aaa
            T = aaaaaaaaa

            Tự nhiên ta thấy:
            + S[1], S[2], S[3] = T[1], T[2], T[3] 
            + S[1], S[2], S[3] = T[2], T[3], T[4]
            + S[1], S[2], S[3] = T[3], T[4], T[5]
            -> khớp ở 3 chõ

            Tốt hơn ta thấy: = (0)
            + S1 giống S2
            + S2 giống S3
            prefix độ dài 2 của S(S1 S2) = "aa" khớp với substring độ dài 2 in index = 2 (S(S2 S3)) = "aa". S tự khớp một phần \
            T1, T2, T3 = (1)
            + S1 = T1
            + S2 = T2
            + S3 = T3
            T2, T3, T4 = (2)
            + S2 = T2 (1)
            + S3 = T3 (1)
            + S1 = S2, S2 = S3 (0)
            -> S1 = T2, S2 = T3 (luôn đúng)
            - Chứng minh: S3 = T4 -> tìm thấy S trong vị trí 2 của T
            -> Sau phép chứng minh S trong T ở i = 1. Chỉ cần chứng minh S3 = T4 (DPCM)
        VD2:
            S = aaa
            T = aabaabaaa
            tự nhiên ta thấy:
            + S1 = T1
            + S2 = T2
            + S3 != T3
            -> Không khớp
            tiếp tự
            Ta thấy không thể tìm thấy S ở T2, T3 ngay vì
            + S2 = S3
            + S3 != T3
            -> S2 != T3
            + S1 = S2
            + S2 != T3
            -> S1 != T3
            Ta bắt đầu tìm ở vị trí 4, 5, 6
        VD3:
            S = tartan
            T = tartaric_acid
            ta thấy:
            S(2) = "ta" = T[4](2) = "ta"
            so sánh:
                + S[6] != T[6] -> không có kết quả ở vị trí 1
            chú ý:
                + S1 != S2
                + S1 != S3
                + S2 = T2
                + S3 = T3
            + S1 != S2
            + S1 != S3
            -> không thể có kết quả ở vị trí số 2 và số 3.
            ta lại có:
                + S1 = S4
                + S2 = S5
                + S4 = T4
                + S5 = T5
            -> S1 = T4, S2 = T5 ta có thể kiểm tra vị trí 4, 5 bằng cách xét S3 với T6
            attribute:
                S1 = S4
                S2 = S5

            xét lần 1 ở vị trí 1:
                +S1 = T1
                +S2 = T2
                +S3 = T3
                +S4 = T4
                +S5 = T5
                +S6 != T6
            vì:
                +S1 = S4 = T4
                +S2 = S5 = T5
            xét lần 2 ở vị trí 4:
                + S3 = T6
                + S4 != T7
            không cần xét nữa vì 
        VD4:
        S = "abde"
        T = "cabdmnabdehq"

        atribute:

        so sánh 
        lần 1:
        +S1 != T1
        lần 2:
        +S1 = T2
        +S2 = T3
        +S3 = T4
        +S4 = T5
        +S5 != T6
        vì S1 != S2, S3, S4, S5
        mà S5 != S6
        lần 3:
        +S1 != T6
        lần 4:
        +S1 = T7
        +S2 = T8
        +S3 = T9
        +S4 = T10
        +S5 = T11
        Ý tưởng chính:
            + S[i] là tiền tố độ dài i của xâu S
    */

    /*
        IDEAL:
        + Lookup table: avoiding check character maches at each index of string 
        + if characters don't match at any index.
            + uses lookup table -> shift patern where ís able to match
            + O(m + n)
     */

    /*
        ABABAABA
        00123123

        S[3] = S[1]
        S[4] = S[2]
        S[5] = S[3]
        S[6] = S[1]
        S[7] = S[2]
        S[8] = S[3]
    */
     
    int LookupTable[1000];


/*  
    0 1 2 3 4 5 6 7 8 9 10 11
    A B X A B C A B C A  B  Y

    0 1 2 3 4 5 
    A B C A B Y
    0 0 0 1 2 0

    i = 0, j = 0:
        S[0] = A = A = P[0]
    i = 1, j = 1:
        S[1] = B = B = P[1]
    i = 2, j = 2:
        S[2] = X != C = P[2]
        j > 0:
            j = table[j - 1]
            j -> vị trí đã lặp C = 0 (vì C chưa phải pre = suf)
    i = 2, j = 0:
        S[2] = X != A = P[0]
    i = 3, j = 0:
        S[3] = A = A = P[0]
    i = 4, j = 1:
        S[4] = B = B = P[1]
    ...
    i = 8, j = 5;
        S[8] = C != Y = S[5]
        j > 0:
            Vì before S[5] = Y đã khớp nên ta check S[4]:
                TH!: table[4] = 0 chưa lặp lần nào
                       S = "ABEFGH"
                       P = "ABCB"
                    B in P chỉ xuất hiện trong B in S 1 vị trí
                TH2: table[4] = 2 đã lặp trong S
                       S = "ABEFBGH"
                       P = "ABEFBJ"
                    B in P có thể xuất hiện thêm một lần nữa trong S
                        S = "ABEFBGH"
                        P =    "ABEFBJ"
                    lúc này ta sẽ phải check thêm E và G
 */
    void string_search(string str, string pat) {
        int i = 0, j = 0, s_len = str.length(), p_len = pat.length();
        while (i < s_len && j < p_len) {
            if (str[i] == pat[j]) {
                i++;
                j++;
            } 
            else if (j > 0) {
                j = LookupTable[j - 1];
            } 
            else {
                i++;
            }
        }
        if (j == p_len) {
            printf("Found pattern at index: %d\n", (i - j));
        }
        else
            printf("Could not find the pattern\n");
    }

    /*
        01234567
        ABABAABA
        00123123 

        table[3] = 1
        table[4] = 2
        table[5] = 3
        table[6] = 1
        table[7] = 2
        table[8] = 3
     */
    
    /* 
        01234567
        ABABAABA
        00123123

        i = 0, j = 1
        i = 0, j = 2
            S[0] = A = A = S[2]
            i = tiền + 1 = 1
            table[hậu = j = 2] = tiền + 1 = 1
        i = 1, j = 3
            S[1] = B = B = S[3]
            i = tiền + 1 = 2
            table[hậu = j = 3] = tiền + 1 = 2
        i = 2, j = 4
            S[2] = A = A = S[4]
            i = tiền + 1 = 3
            table[hậu = j = 4] = tiền + 1 = 3
        i = 3, j = 5
            S[3] = B != A = S[5]
            vì i > 0 suy ra before B = before A
            kiểm tra before B:
                TH1: before B đã từng lặp:
                    "A[X]......AB......AA"
                    -> có khả năng A xuất hiện ở 1 vị trí trước đó trong "A...A"
                    ta xét s.begin + 1
                    i -> table[hậu = A] = tiền + 1
                TH2: before B chưa từng lặp:
                    "...AB....AA"
                    i -> 0 và bắt đầu tìm kiếm 1 cặp mới
     */
    void BuildLookupTable(string pat) {
        int p_len = pat.length(), idx = 0, j = 1;
        /*
            j: con trỏ di chuyển khắp chuỗi pat
            i: con trỏ đánh dấu các cặp có cùng độ dài
            đánh dấu các cặp bằng nhau
            table: để đánh dấu các cặp prefix == suffix
                table[hậu tố] = tiền tố + 1
                VD: abcab
                    12012
         */
        memset(LookupTable, 0, sizeof(LookupTable));
        int cnt = 0;
        while (j < p_len) {
            if (pat[idx] == pat[j]) {
                idx++;
                LookupTable[j] = idx;
                j++;
            }
            else if (idx > 0) {
                idx = LookupTable[idx - 1];
            }
            else {
                j++;
            }
            cnt++;
        }
    }
    
    void solve() {
        string str, pat;
        // getline(cin, str);
        getline(cin, pat);
        // pat = str;
        // int s_len = str.length();
        int p_len = pat.length();
        BuildLookupTable(pat);
        // for (int i = 0; i < s_len; i++) {
        //     cout << str[i] << ' ';
        // }
        // cout << endl;
        // for (int i = 0; i < p_len; i++) {
        //     cout << pat[i] << ' ';
        // }
        // cout << '\n';
        cout <<pat << endl;
        for (int i = 0; i < p_len; i++) {
            cout << LookupTable[i];
        }
        // string_search(str, pat);
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