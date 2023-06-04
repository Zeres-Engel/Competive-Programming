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
    
    // Tree 

    /*
        * root: node without parent
        * Internal node: node has >= 1 child
        * External node (leaf node): node has 0 child
        * Ancestor: parent, grand parent node
        * Depth of node: number of Ancestor
        * Height of tree: maximum depth of tree
        * Decendatns: Child, grandchild

        Traversal:
        * Preorder: 
        * Postorder:
        * Inorder:
    */

    // Binary Tree 
        
    struct tNode{
        int data;
        tNode *pLeft, *pRight;
    };

    tNode *root;

    //create new node
    tNode *newNode(int data){
        tNode *node = new tNode;
        node->data = data;
        node->pLeft = NULL;
        node->pRight = NULL;
        return node;
    }

    //insert new Node into tree
    void insertNode(tNode *p, int value){
        tNode *node = newNode(value);
        if (p->pLeft == NULL){
            p->pLeft = node;
        }
        else if (p->pRight == NULL) {
            p->pRight = node;
        }
        else {
            node->pLeft = p->pLeft;
            p->pLeft = node;
        }
    }
    
    //insert new Node into root
    void insertNewRoot(int value){
        tNode *node = newNode(value);
        node->pLeft = root;
        root = node;
    }

    void NLR(tNode *root){
        if (root!=NULL) {
            if(root!=NULL) {
                cout<<root->data<<" ";
            }
            NLR(root->pLeft);
            NLR(root->pRight);
        }
    }

    void LNR(tNode *root){
        if (root!=NULL) {
            LNR(root->pLeft);
            if(root!=NULL){
                cout<<root->data<<" ";
            }
            LNR(root->pRight);
        }
    }

    void LRN(tNode *root){
        if (root!=NULL) {
            LRN(root->pLeft);
            LRN(root->pRight);
            if (root!=NULL) {
                cout<<root->data<<" ";
            }
        }
    }

    void solve() {
        //create Nodes
        root = newNode(1);
        tNode *node2 = newNode(2);
        tNode *node3 = newNode(3);
        tNode *node4 = newNode(4);
        tNode *node5 = newNode(5);
        tNode *node6 = newNode(6);
        tNode *node7 = newNode(7);
        //assign childnodes
        root->pLeft = node2;
        root->pRight = node3;
        node2->pLeft = node4;
        node2->pRight = node5;
        node5->pLeft = node6;
        node5->pRight = node7;
        //traverse binary tree with NLR
        cout<<"traverse tree with NLR:";
        NLR(root);
        //traverse tree LNR
        cout<<"\ntraverse tree with LNR:";
        LNR(root);
        //traverse tree LRN
        cout<<"\ntraverse tree with LRN:";
        LRN(root);
        //insert new Node into tree
        insertNode(node2, 9);
        //traverse binary tree with NLR after insert new Node
        cout<<"\ntraverse tree with NLR:";
        NLR(root);
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