#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;

#define PI acos(-1)

typedef complex<double> base;
typedef vector<base> vb;

const int ALPHABET_SIZE = 26;
const int BASE = 31;
const int MAXN = 1000;
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
    
    // Palindrome Tree

    /* 
        Palindrome Tree là cấu trúc dữ liệu lưu trữ palindrome
        + Cung giữa 2 nút gán một chữ cái:  b --- a ---> aba 
        + Thêm liên kết hậu tố:
            + Nếu nút u có liên kết hậu tố với w khi:
                w là hậu tố không tầm thường lớn nhất của u: aba ---> a  (proper suffix) 
        -> Palindrome lớn nhất là proper suffix của 1 xâu là palindrome hậu tố lớn nhất của 1 xấu
        Palindrome Tree.png
     */
    
    /*
        Xây dựng Palindrome Tree chứa tất cả các nốt của 1 xâu s. 
            + 1 xâu có size = n sẽ có <= n palindromme substring
        -> palindrome tree không quá n + 2 nút (có 2 gốc nữa)

        Ta xử lý từng chữ cái 1 trong xâu:
            GS chữ cái x, có prefix p:
            -> xét từ x trở đi
            + Lưu lại t là longest suffix của p
            -> t chứa được trong 1 nút nào đó của Palindrome Tree
            (node link suffix node).
            tiếp tực như vậy
            Tìm palind của tiền tố p + x có dạn xAx
     */

    /*
        Ứng dụng:
            + Đếm số lượng palindrom xuất hiện thêm
            + Đếm số lượng xâu con liên tiếp là palindrome
            + số lần xuất hiện của palindrome trong xâu  
     */

struct Node {
    int start, end;
    int length;
    int insertEdg[26];
    int suffixEdg;
};
Node root1, root2;
Node tree[MAXN];
int currNode;
string s;
int ptr;
void insert(int idx) {
    int tmp = currNode;
    while (true)
    {
        int curLength = tree[tmp].length;
        if (idx - curLength >= 1 and s[idx] == s[idx-curLength-1])
            break;
        tmp = tree[tmp].suffixEdg;
    }
    if(tree[tmp].insertEdg[s[idx]-'a'] != 0) {
        currNode = tree[tmp].insertEdg[s[idx]-'a'];
        return;
    }
    ptr++;
    tree[tmp].insertEdg[s[idx]-'a'] = ptr;
    tree[ptr].length = tree[tmp].length + 2;
    tree[ptr].end = idx;
    tree[ptr].start = idx - tree[ptr].length + 1;
    tmp = tree[tmp].suffixEdg;
    currNode = ptr;
    if (tree[currNode].length == 1) {
        tree[currNode].suffixEdg = 2;
        return;
    }
    while (true) {
        int curLength = tree[tmp].length;
        if (idx-curLength >= 1 and s[idx] == s[idx-curLength-1]) {
            break;
        }
        tmp = tree[tmp].suffixEdg;
    }
    tree[currNode].suffixEdg = tree[tmp].insertEdg[s[idx]-'a'];
}

void PrintAllPalindrome() {
    for (int i = 3; i <= ptr; i++) {
        for (int j = tree[i].start; j <= tree[i].end; j++)
            cout << s[j];
        cout << endl;
    }
}

void initPalindromeTree(string key) {
    root1.length = -1;
    root1.suffixEdg = 1;
    root2.length = 0;
    root2.suffixEdg = 1;
    tree[1] = root1;
    tree[2] = root2;
    ptr = 2;
    currNode = 1;
    s = key;
    int l = s.length();
    for (int i = 0; i < l; i++)
        insert(i);
}

    void solve() {
        string s; cin >> s;
        initPalindromeTree(s);
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