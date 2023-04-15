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
    
    // Suffix Array

    /*  
        m có bỏ tao thì tao cũng sẽ không thù ghét m t chúc m sớm tìm được hạnh phúc con tao thì m cứ kệ 
        cha tao đi cũng được. Tao chỉ muốn dành thời gian cho công việc thôi

        - Là Cấu Trúc Dữ Liệu giúp Sort hậu tố theo thứ tự từ điển: 
     */

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
        các số: 7 6 4 2 1 5 3 đánh dấu kí tự bắt đầu của hậu tố 

     */

namespace HashSuffixArray {

    const int MAXN = 1 << 21;

    typedef unsigned long long hash;
    const hash BASE = 137;

    int N;
    char * S;
    int sa[MAXN];
    hash h[MAXN], hPow[MAXN];

    #define getHash(lo, size) (h[lo] - h[(lo) + (size)] * hPow[size])

    inline bool sufCmp(int i, int j)
    {
        int lo = 1, hi = min(N - i, N - j);
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (getHash(i, mid) == getHash(j, mid))
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return S[i + hi] < S[j + hi];
    }

    void buildSA()
    {
        N = strlen(S);
        hPow[0] = 1;
        for (int i = 1; i <= N; ++i)
            hPow[i] = hPow[i - 1] * BASE;
        h[N] = 0;
        for (int i = N - 1; i >= 0; --i)
            h[i] = h[i + 1] * BASE + S[i], sa[i] = i;

        stable_sort(sa, sa + N, sufCmp);
    }
} // end namespace HashSuffixArray


/*
Suffix array O(n lg^2 n)
LCP table O(n)
*/

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

namespace SuffixArray
{
    const int MAXN = 1 << 21;
    char * S;
    int N, gap;
    int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

    bool sufCmp(int i, int j)
    {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i < N && j < N) ? pos[i] < pos[j] : i > j;
    }

    void buildSA()
    {
        N = strlen(S);
        REP(i, N) sa[i] = i, pos[i] = S[i];
        for (gap = 1;; gap *= 2)
        {
            sort(sa, sa + N, sufCmp);
            REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
            REP(i, N) pos[sa[i]] = tmp[i];
            if (tmp[N - 1] == N - 1) break;
        }
    }
} // end namespace SuffixArray

    void solve() {
        char c[MAXN] = "BASSFASDAS234123O492573908457218TYEFIEWGJGJGKLSAGDKASGDKASGDKASGDJKASGDJKGASHJDGASJKDGAJSHVXCHJAGYUERTYWUYDGAUJKWDGJASGDHJASGDIOAGDFKWAHDFGLAWGDFISTGFUYDGCJHXVBCMHKZGFSJAGFAFHJKZXNJKCHWAIBKUDGHCIAWDHIAWODGHIAWDHKAWBUDKAHWJKLDHBKALWHDBKAWLBDHAWICHDOAWDHALWdhawFIQNWCIOFQ2HWEDFIWHNSKJHJZKJHFGSKDGHKZ,DSGJKA,EKJERHWITFYQWIURYEOWRPOUYWEIROUYJCQWOERYWOQEYR98Q38W47239084179356Y8437TRIUETYKJRGHFSJAKDFGJKSDJFHMDSBFMNGHSDJKGKCVKLLSDAWEOPQRPEWYRTIYUWETYGFHJBVHJCZXVBCZXNMVBSAJKFGWEORQYUIY234918379856235UIEGHRKAUWEGHSFAKAGHSEKFJGASKDJFGHJASKFGASKYUFGEITUAFGIAWUEFAYRTQ7WE2734651245DASDASDASDASDASDASDASDASDASMNBMASDSAFSGDHFJKJHJKLUYRYETQWREWYRIOPDASZXCBVNVMVDASGDAGYTERQWRQANANA@";
        // HashSuffixArray::S = c;
        // HashSuffixArray::buildSA();
        // for (int i = 0; i < strlen(c); i++) {
        //     cout << HashSuffixArray::sa[i] << ' ';
        // }
        SuffixArray::S = c;
        SuffixArray:: buildSA();
        for (int i = 0; i < strlen(c); i++) {
            cout << SuffixArray::sa[i] << ' ';
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
        return 0;
    }