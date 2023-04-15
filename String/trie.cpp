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
    
    // Trie (cây tiền tố)
    /*
        Một cấu trúc dữ liệu quản lý chuỗi cho phép:
            + Thêm 1 xâu
            + Xóa 1 xâu
            + Kiểm tra 1 xâu 
        Hình vẽ trie.png:
            + nút 1 là nút gốc
            + nút 7: ‘bg’, 
            + nút 8: 'db'
            + nút 10: acd
            S = {ab, acd,bg,db,dc,}
            tuy nhiên: nút 4 ta không biết đc là xâu "d" hay chỉ là 1 phần đường đi
            -> tại nút U lưu thêm nó có phải nút kết thúc hay không
     */

    typedef struct TrieNode* Node;

    struct TrieNode {
        TrieNode *children[ALPHABET_SIZE];
        bool isEndOfWord;
    };
    /*
        Tạo node gốc node 1 = false
        Trỏ đến 26 kí tự = NULL đánh dấu
                                    root
                                    
            0(a)    1(b)  2(c)   3(d)   4(e)     ...     25(z)
            NULL    NULL  NULL   NULL   NULL     ...    NULL
     */
Node getNode(void) {
    Node pNode =  new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = NULL;
    }
    return pNode;
}

    /*
        + Tạo node tmp = node root 
        + Duyệt toàn bộ string key
        VD:
        s = {"anh", "anc", "a", "c"}
                                                root

                        0(a)     1(b    2(c)    3(d)    4(e)     ...     25(z)
                        true     NULL   true    NULL    NULL     ...    NULL
                14(n)
              
        8(h)          3(c)
      true            true

     */
    void insert(Node root, string key) {
        Node pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = getNode();
            }
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }
 
    /* 
        tương tự với Search:
     */
    bool search(Node root, string key) {
        Node pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index]) {
                return false;
            }
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl->isEndOfWord);
    }
 

    void solve() {
        // node root = getNode();
        // string keys[] = {"the", "a", "there",
        //             "answer", "any", "by",
        //              "bye", "their" };
        // keys->append("dsf");
        for (char i = 'a'; i <= 'z'; i++) {
            cout << i << endl;
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