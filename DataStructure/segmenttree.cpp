#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;

#define PI acos(-1)

typedef complex<double> base;
typedef vector<base> vb;

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
    
    //Segment Tree

    /*
        1. Thay giá trị a[x] = y;
        2. In ra giá trị nhỏ nhất trong [l, r] 
     */

    /*
        Cài đặt Segment Tree:
            4372589
        1. Ta đánh số thứ tự trong mảng khác:
                                         4...9
                        4...2                          5...9
                4...3          7..2             5...8         9...9

            4..4    3..3   7...7   2...2     5...5  8...8     9...9
        Nhận xét: 
            Trong ST[...]:
                Nếu ST[id] là cha
                -> ST[id*2] sẽ là con 1 và ST[id*2 + 1] là con 2
        Dễ dàng chứng minh số lượng node <= 4*N
        Giao thức cơ bản của Segment Tree:
            Build();
            Update()]]
            Query();
     */

    /*
        Xây dựng Segment Tree:
                                     [1]
                                    4...9

                         [2]                            [3]         
                        4...2                          5...9

                 [4]              [5]               [6]           [7]
                4...3            7...2             5...8         9...9

             [8]      [9]     [10]    [11]      [12]   [13]       [7]  
            4...4    3...3   7...7   2...2     5...5   8...8     9...9

        Thứ tự tạo:
            ST[1] = [4...9]
            ST[2] = [4...2]
            ST[3] = [4...3]
            !ST[4] = [4...4] (Node[4] = 4 = a[i])
            !ST[5] = [3...3] (Node[5] = 3 = a[i])
            ST[6] = [7...2]
            !ST[7] = [7...7] (Node[7] = 7 = a[i])
            !ST[8] = [2...2] (Node[8] = 2 = a[i])
            ST[9] = [5...9]
            ST[10] = [5...8]
            !ST[11] = [5...5] (Node[11] = 5 = a[i])
            !ST[12] = [8...8] (Node[12] = 8 = a[i])
            ST[13] = [9...9] (Node[13] = 9 = a[i])
         
     */


    int n;
    const int MaAN = 1000;
    int a[MaAN];

    class SegmentTree{
        int low[4*MaAN], high[4*MaAN], Node[4*MaAN], Leaf[MaAN], findleft, findright;
        // Mảng low và high: lưu giá trị mà nó quản lý:
        /*
            Ví dự Node index = 1 lưu [1, n]:
                low[1] = 1; high[1] = n;
         */
        // Mảng Node và Leaf:
        /*
            Dễ dàng thấy:
                Arr có N phần tử:
                -> Segment Tree có N lá:
            Node: để lưu lại giá trị chính xác của từng lá (giá trị mảng A)
            Leaf: Lưu lại index của Node:
            VD:
                                        4...9
                        4...2                          5...9
                4...3          7..2             5...8         9...9

            4..4    3..3   7...7   2...2     5...5  8...8     9...9
        Thứ tự tạo:
            ST[1] = [4...9]
            ST[2] = [4...2]
            ST[3] = [4...3]
            !ST[4] = [4...4] (Node[4] = 4 = a[i])
            !ST[5] = [3...3] (Node[5] = 3 = a[i])
            ST[6] = [7...2]
            !ST[7] = [7...7] (Node[7] = 7 = a[i])
            !ST[8] = [2...2] (Node[8] = 2 = a[i])
            ST[9] = [5...9]
            ST[10] = [5...8]
            !ST[11] = [5...5] (Node[11] = 5 = a[i])
            !ST[12] = [8...8] (Node[12] = 8 = a[i])
            ST[13] = [9...9] (Node[13] = 9 = a[i])
         */

        public:
            void Build(int index, int l, int r) {
                low[index] = l;
                high[index] = r;
                // cout << index << ':' << low[index] << ' ' << high[index] << endl;
                /*
                    Nếu l == r:
                        thì Node đó sẽ quản lý: [5...5]; [4...4]
                        Lưu lại giá trị cho mảng arr
                        Vì Segment Tree chỉ lưu phân đoạn
                 */
                if (l == r) {
                    /*
                        Node: để lưu lại giá trị của mỗi phân đoạn:
                        VD:
                            [1...2] không có giá trị Node
                            [1...4] không có giá trị Node
                            [4...4] Node = 4
                            [2...2] Node = 2
                            [2...4] Node = min[Node[2...3], Node[3...4]] 
                            = min(min(Node[2...2],Node[3...3]), min(Node[3...3], Node[4...4]))
                            = min(min(2,3), min(3, 4))
                            = min(2,3)
                            = 2 
                            -> Node[2...4] = 2;
                     */
                    Node[index] = a[l];
                    // cout << Node[index] << ' ';
                    /* 
                        Lưu lại node có giá trị [l] có thứ tự bao nhiêu trong Segmentree
                        Leaf[vị trí trong a] = vị trí ST
                     */
                    Leaf[l] = index;
                    // cout << l << ' ' << Leaf[l] << endl;
                    // cout << "----\n";
                    return;
                }
                // Đánh dấu bị trí ở ô index*2 để vẫn giữ thứ tự đánh số của Segment Tree
                Build(index*2, l, (r + l)/2);
                // Đánh dấu bị trí ở ô index*2 để vẫn giữ thứ tự đánh số của Segment Tree
                Build(index*2 + 1, (r + l)/2 + 1, r);
                // Node để lưu lại giá trị bé nhất của phân đoạn đó
                Node[index] = min(Node[index*2], Node[index* 2 + 1]);
            }

            int Find(int index) {
                // Nếu số nằm ngoài phạm vi tìm kiếm
                //VD: l = 2, r = 3, index nắm [4, 7] -> lộn nhánh nên đi nhánh khác
                if (findleft > high[index] || findright < low[index]) {
                    return 1e9;
                }
                // Nếu số đó nằm trong phạm vi tìm kiếm 
                //VD: l = 2, r = 5, index nắm [2, 3]
                if (findleft <= low[index] && high[index] <= findright) {
                    return Node[index];
                }
                // Nếu số đó nằm trong những phạm vi tìm kiếm còn lại
                //VD: l = 2, r = 7, index: [1, 7]
                /* 
                    Đệ quy xuống [1, 4] và [4, 7] tìm min
                    Đệ quy xuống [1, 2] và [2, 4] và [4, 5] và [5, 7] tìm Min
                    và trả kết quả
                 */
                return min(Find(index*2), Find(index*2 + 1));
            }
/*                                         [1]
                                          4...9

                         [2]                                [3]         
                        4...2                              5...9

                 [4]              [5]               [6]            [7]
                4...3            7...2             5...8          9...9

             [8]     [9]     [10]    [11]      [12]    [13]        [7]  
            4...4   3...3   7...7   2...2     5...5    8...8      9...9 

            VD: thay a[1] = 3 -> 1;
            a[1] = 1
            -> ST[Leaf] = Node
            = ST[9] = 3 -> 1
            ST[9] = 1
            -> ST[4] = 3 -> 1
            -> ST[2] = 2 -> 1
            -> ST[1] = 1 -> 1
            Dễ thấy:
                Nếu Node[pos] bị thay đổi kéo theo các Node[pos/2] cũng thay đổi:
                    Node[9]
                    Node[4]
                    Node[2]
                    Node[1]
*/
            void Update(int index, int val){
                // index: vị trí phần tử cần được đc thay đổi
                // pos = vị trí trong Segment Tree
                int pos = Leaf[index];
                // giá trị của Node trong Segment Tree được thay đổi = Val
                Node[pos] = val;
                // Cập nhật lại các giá trị của nó 
                /*
                    VD: thay 3 = a[1] 
                 */
                for(pos /= 2; pos > 0 ; pos /= 2) {
                    Node[pos] = min(Node[pos * 2], Node[pos * 2 + 1]);
                }
            }

            int Query(int l, int r) {
                findleft = l;
                findright = r;
                return Find(1);
            }

            void print() {
                for (int i = 1; i < 2*n; i++) {
                    cout << Node[i] << ' ';
                }
            }

    }SegmentTree;


    void solve() {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        SegmentTree.Build(1, 1, n);     
        cout << SegmentTree.Query(1, 5) << endl;
        SegmentTree.print();
    }           

    int main() {       
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif  
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0);
        solve();
    }