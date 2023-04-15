#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = (int)1e9+7;

    /*
                                    LÝ THUYẾT ĐỒ THỊ
        
        1/ Đồ thị bao gồm 2 yếu tố là: đỉnh và cạnh
        2/ Đơn đồ thị vô hướng: giữa 2 đỉnh có 1 cạnh là cạnh đơn
        3/ Đa đồ thị vô hướng: giữa 2 đỉnh có nhiều hơn 1 cạnh
        4/ Giả đồ thị vô hướng: 1 đỉnh có thể có 1 cạnh bắt đầu từ đỉnh đó và 
        kết thúc ngay đỉnh đó là canh khuyên.
        5/ Đơn đồ thị có hướng: giữa 2 đỉnh có 1 cạnh là cạnh đơn nhưng có hướng 
        (từ A sang B hoặc từ B sang A) cạnh này gọi là cung
        6/ Đa đồ thị có hướng: giữa 2 đỉnh có 1 cạnh là cạnh đơn nhưng có hướng
        7/ Đỉnh kề: 2 đỉnh nối nhau bơi 1 cạnh
        8/ Cạnh liên thuộc: Cạnh nối giữa 2 đỉnh là cạnh liên thuộc của 2 đỉnh đó
        9/ Bậc của đỉnh trên đồ thị vô hướng: Là số cạnh liên thuộc của đỉnh đó 
        (số cạnh của đồ thị bằng (tổng bậc)/2)
        10/ Bán bậc của đỉnh trên đồ thị có hướng: Là số cung đi ra từ đỉnh đó, 
        bán bậc ra là số cung đi ra, bán bậc vào là số cung đi vào
        (tổng bán bậc vào của bán bậc ra và bán bậc vào ra số cạnh)
        11/ Đường đi: là cạnh của của đỉnh trên đồ thị
        12/ Chu trình: Cũng là đường đi với các cạnh phân biệt có đỉnh đầu trùng với đỉnh cuối nhưng các cạnh phải 
        phân biệt với nhau
        13/ Chu trình đơn: ngoài trừ đỉnh đầu và đỉnh cuối tất cả các đỉnh đều không được trung nhau
        14/ Liên thông: Tạo thành khối liên thông tất cả các đỉnh đều có đường đi giữa 2 đỉnh
        15/ Liên thông mạnh: Đồ thị có 2 đỉnh bất kì luôn có đường đi với nhau
        16/ Liên thông yếu: Đồ thị tồn tại ít nhất hai trong các đỉnh bất kì không có đường đi giữa chúng
    
                                        BIỂU DIỄN ĐỒ THỊ

    1/ Ma trận kề:
        + Biểu diễn bằng mảng 2 chiều
        + Cạnh a[i][j]
        (int a[n][n])

    2/ Danh sách cạnh:
        + Biểu diễn lưu bằng đỉnh đầu và đỉnh cuối 
        + Dừng pair để lưu (i, j)
        (vector <pair<int, int>> dsc)

    3/ Danh sách kề 
        + Biểu diễn lưu bằng đỉnh và danh sách các đỉnh kề: 
        + Dùng mảng vector để lưu
        (vector <int> dsk[1001]
                                        DFS & BFS

    DFS: Thuật toán tìm kiếm theo chiều sâu
    + Ứng dụng: Khá nhiều nhưng chủ yếu là để mở rộng đồ thị
    + Mã giả:
        DFS(u) {
            <Thăm đỉnh u>
            visited [u] = true; // Đánh dấu đã được thăm
            for (v : adj[u]) { // Duyệt tất cả các đỉnh kề với u
                if (!visited[v]) { // Nếu chưa được thăm
                    DFS(v);
                }
            }
        }
    + Độ phức tạp:
        - Ma trận kề: O(v*v)
        - Danh sách cạnh: O(v*e)
        - Danh sách kề: O(v + e) (nên dùng để có độ phức tạp tốt nhất)

    BFS: Thuật toán tìm kiếm theo chiều rộng 
    + Ứng dụng:
    + Mã giả:
        queue = rỗng // Tạo một hàng đợi rỗng
        push(queue, u); // Đẩy đỉnh u vào hàng đợi
        visited[u] = true; // Đánh dấy đỉnh u đã được thăm
        while(queue != rỗng) {
            v = queue.front(); // Lấy đỉnh ở đầu hàng đợi
            queue.pop() // Xóa đỉnh đầu ở hàng đợi 
            <Thăm đỉnh v>
            for (int x: dsk[v]) { // Duyệt danh sách kề của v
                if (!visited[x]) // Nếu x chưa được thăm 
                    push(queue, x);
                    visited[x] = true;
            }
        }
    + Độ phức tạp:
        - Ma trận kề: O(v*v)
        - Danh sách cạnh: O(v*e)
        - Danh sách kề: O(v + e)

                                    ĐƯỜNG ĐI TRONG LƯỚI Ô VUÔNG

    Bài toán 1: Đếm số thành phần liên thông trên lưới. 
    Duyệt các ô chung cạnh:
                                i - 1,j

                        i,j - 1    i,j   i,j + 1

                                i + 1, j
        lượng di chuyển của i (-1, 0, 0, 1)
        Lượng di chuyển của j (0, -1, 1, 0)
        Chúng ta chỉ cần một vòng for duyệt từ 1 cho tới 4 rồi xét các cặp di chuyển 

    Code tham khao:    
        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,1,0} ;

    void DFS(int i, int j) {
        visited[i][j] = true;
        Duyệt các đỉnh kề
        for (int k = 0; k < 4; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
        Đảm bảo điểm này vẫn nằm trên lướt
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m) {
                if (a[i1][j1] == 'x' && !visited[i1][j1]) {
                    DFS(i1,j1);
                }
            }
        }
    }

        int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0} ;

    void BFS(int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        a[i][j] = 'o';
        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            Duyệt các đỉnh liền kề
            for (int k = 0; k < 4; k++) {
                int i1 = top.first + dx[k];
                int j1 = top.second + dy[k];
                if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m) {
                    if (a[i1][j1] == 'x' && !visited[i1][j1]) {
                        q.push({i1,j1});
                        visited[i1][j1] = true;
                    }
                }
            }
        }
    }
    
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

                                    THUẬT TOÁN KOSARAJU
    
    Dùng để tìm số thành phần liên thông mạnh của đồ thị
    Đồ thị liên thông mạnh: Giữa hai đỉnh bất kì luôn có đường đi


    Bước 1: Gọi thuậttoán sắp xếp TOPPO (DFS)
    Bước 2: Xây dựng đồ thị lật ngược ban đầu
    Bước 3: Lần lượt pop các đỉnh trong stack ở bước 1 và liệt kê các thành phần liên thông mạnh
    Độ phức tạp O(2(v + e))

        int n, m;
    vector <int> dsk[10001], r_dsk[10001];
    bool visited[1001];
    stack <int> st;

    void DFS1(int u) {
        visited[u] = true;
        for (int items : dsk[u]) {
            if (!visited[items]) {
                DFS1(items);
            }
            st.push(items);
        }
    }

    void DFS2(int u) {
        visited[u] = true;
        cout << u << " ";
        for (int items : r_dsk[u]) {
            if (!visited[items]) {
                DFS2(items);
            }
            st.push(items);
        }
    }

    void SCC() {
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                DFS1(i);
            }   
        }
        cout << endl;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (!visited[u]) {
                DFS2(u);
            }
        }
    }
    
                                Cấu Trúc Dữ Liệu Các Tập Hợp Rời Nhau

    Hỗ trợ thao tác tìm và gộp
        Gộp 2 phần tử vào cùng 1 tập hợp 
        Chỉ ra phần tử đó thuộc tập hợp

    Thao tác:
        Make set (a): Tạo tập hợp chứa phần tử a
        Union (a, b): Gộp 2 tập hợp với nhau
        Find (a): Tình phần tử đại diện cho tập hợp a thuộc

    int n, m;
    int parrent[10001];
    int size[10001];

    void make_set() {
        for (int i = 1; i <= n; i++) {
            parrent[i] = i;
        }
    }

    int find(int v) {
        if (v == parrent[v]) {
            return v;
        }
        Trong quá trình tìm parent cũng sẽ xét các parent của các số khác
        return parrent[v] = find(parrent[v]);
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            Cây có số lượng phần tử ít hơn thì sẽ thay đổi cha ít hơn
            if (size[a] <  size[b]) {
                swap(a, b);
            }
            parrent[b] = a;
            size[a] += size[b];
        }
    }

                                THUẬT TOÁN KRUSKAL
    
    Tìm cây khung nhỏ nhất:
    Bước 1: Khởi tạo một cây khung rỗng
    Bước 2: Sắp xếp các cạnh trên đồ thị theo chiều dài tăng dần
    Bước 3: Lặp chừng nào mà số cạnh của cây khun nhỏ hơn n - 1 và tập cạnh còn khác rỗng
        Tìm cạnh ngắn nhất
        Loại bỏ ra khỏi tập cạnh
        Nêu cây khung hiện tại cho thêm cạnh e vào không tạo thành chu trình (Sử dụng DSU để check)
            Cho cạnh E đó vào cây khung rỗng và côngj thêm chiều dài 

    Code tham khảo:
    struct edge{
        int u, v;
        int w;
    };

    int n, m;
    int parent[1001], sz[1001];
    vector<edge> dsc;
    void make_set() {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1; 
        }
    }

    int find(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    bool Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (sz[a] <  sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool cmp(edge a, edge b) {
        return a.w < b.w;
    }

    void Kruskal() {
        vector<edge> mst;
        int d = 0;
        sort(dsc.begin(), dsc.end(), cmp);
        for (int i = 0; i < m; i++) {
            if (mst.size() == n - 1) {
                break;
            }
            edge e = dsc[i];// Chọn e là cạnh nhỏ nhất
            if (Union(e.u, e.v)) {
                mst.push_back(e);
                d += e.w;
            }
        }
        if (mst.size()  != n - 1) {
            cout << 0;
        }
        else {
            for (auto it : mst) {
                cout << it.u << " " << it.v << " " << it.w << endl;
            }
        }
    }

    int main() { 
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0);
        cin >> n >> m;  
        edge e;
        while (m--) {
            int x, y, w; cin >> x >> y >> w;
            edge e;
            e.u = x; e.v = y;  e.w = w;
            dsc.push_back(e);
        }
        Kruskal();
    } 

                                        THUẬT TOÁN PRIM
    
    Bước 1: Tạo một khung cây rỗng.
    Bước 2: Lặp Xóa Đỉnh trên đồ thị và đưa vào khun cây (điểm bất kì)
        Chọn ra cạnh nhỏ nhất tạo bới những điểm hiện tại trên khung cây và các điểm chưa xóa 
        trên đồ thị {2, 3, 4, 5, 6}  và   {1} 
                    {3, 4, 5, 6} và {1, 2}
    Bước 3: In ra kết quả
    Không sử dụng hàng đợi ưu tiên:

    const int maxn = 1001;
 
struct canh{
	int x, y, w;
};
 
int n, m; //n : so luong dinh, m so luong canh
vector<pair<int,int>> adj[maxn];
bool used[maxn]; // used[i] = true : i thuoc tap V(MST), used[i] = false : i thuoc tap v
 
void nhap(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	memset(used, false, sizeof(used));
}
 
void prim(int u){
	vector<canh> MST; // cay khung
	int d = 0; // chieu dai cay khung
	used[u] = true; // dua dinh u vao tap V(MST)
	while(MST.size() < n - 1){
		e = (x, y) : Cạnh ngắn nhất có x thuộc V và y thuộc V(MST)
		int min_w = INT_MAX;
		int X, Y; // luu 2 dinh cua canh e
		for(int i = 1; i <= n; i++){
			neu dinh i thuoc tap V(MST)
			if(used[i]){
				duyet danh sach ke cua dinh i
				for(pair<int,int> it : adj[i]){
					int j = it.first, trongso = it.second;
					if(!used[j] && trongso < min_w){
						min_w = trongso;
						X = j; Y = i;
					}
				}
			}
		}
		MST.push_back({X, Y, min_w});
		d += min_w;
		used[X] = true; // cho dinh X vao V(MST), loai X khoi tap V
	}
	cout << d << endl;
	for(canh e : MST){
		cout << e.x <<  " " << e.y << " " << e.w << endl;
	}
}
 
int main(){        
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
	nhap();
	prim(4);
}     

Sử dụng hàng đợi ưu tiên:
const int maxn = 1001;
 
struct canh{
	int x, y, w;
};
 
 
int n, m; //n : so luong dinh, m so luong canh
vector<pair<int,int>> adj[maxn];
bool used[maxn]; // used[i] = true : i thuoc tap V(MST), used[i] = false : i thuoc tap v
int parent[maxn], d[maxn];
 
void nhap(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	memset(used, false, sizeof(used));
	for(int i = 1; i <= n; i++) d[i] = INT_MAX;
}
 
 
void prim(int u){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
	vector<canh> MST;
	int res = 0;
	Q.push({0, u});
	while(!Q.empty()){
		pair<int,int> top = Q.top(); Q.pop();
		int dinh = top.second, trongso = top.first;
 
		if(used[dinh]) continue;
		res += trongso;
		used[dinh] = true;
		if(u != dinh){
			MST.push_back({dinh, parent[dinh], trongso});
		}
		duyet tat ca cac dinh ke 
		for(auto it : adj[dinh]){
			int y = it.first, w = it.second;
			if(!used[y] && w < d[y]){
				Q.push({w, y});
				d[y] = w;
				parent[y] = dinh;
			}
		}
	}
	cout << res << endl;
	for(auto it : MST){
		cout << it.x << " " << it.y << " " << it.w << endl;
	}
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	nhap();
	prim(6);
}
                                Thuật toán Dijkstra

    Thuật toán tìm đường đi ngắn nhất giữa 2 đỉnh bất kì trên đồ thị

    const int maxn = 100001;
int n, m, s, t;
vector<pair<int, int>> adj[maxn];
 
void nhap(){
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		
	}
}
 
const int INF = 1e9;
int pre[maxn];
 
void dijkstra(int s){
	Mang luu khoang cach duong di
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
    {khoang cach, dinh}
	Q.push({0, s});
	while(!Q.empty()){
		Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if(kc > d[u]) continue;
		Relation : Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S, cập
		nhật khoảng cách với các đỉnh kề với u
		for(auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << d[i] << ' ';
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	nhap();
	dijkstra(s);
}

                            CHU TRÌNH EULER 

Đường đi mà chỉ đi qua 1 cạnh đúng 1 lần

Điều kiện để có chu trình Euler: (Điểm xuất phát và điểm kết thúc giống nhau)

    + Đồ thị vô hướng:
        - Các đỉnh có bậc khác 0 của đồ thị liên thông với nhau
        - Tất cả các đỉnh của đồ thị đều có bậc chẵn

    + Đồ thị có hướng:
        - Các đỉnh có bậc khác 0 của đồ thị thuộc cùng một thành phần liên thông
        - Mọi đỉnh thuộc đồ thị đều có bán bậc ra bằng bán bậc vào

Điều kiện để có đường đi Euler: (Điểm xuất phát và điểm kết thúc không giống nhau)

    + Đồ thị vô hướng:
        - Các đỉnh có bậc khác 0 của đồ thị liên thông với nhau
        - Đồ thị có 0 hoặc 2 đỉnh có bậc lẻ, trong trường hợp có 2 đỉnh bậc lẻ thì
        đường đi sẽ bắt đầu từ đỉnh có bậc lẻ từ 1 và kết thúc ở đỉnh có bậc lẻ thứ 2

    + Đồ thị có hướng:
        - Các đỉnh có bậc khác 0 của đồ thị cùng thuộc cùng một thành phần liên thông
        - Tồn tại 2 đỉnh có độ chênh lệch giữa bán bậc ra và bán bậc vào là 1
*/  