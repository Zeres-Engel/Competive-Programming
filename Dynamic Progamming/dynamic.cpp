#include <bits/stdc++.h>
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
    
    
    
    
    
--------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*     
Thường xuất hiện trong các dạng bài toán:
	• Tìm số tối ưu
	• Tìm min/ max
	• Đếm số cấu hình Tổ hợp

Điều kiện có thể áp dụng được giải thuật quy hoạch động:
	• Bài toán lớn có thể phân rã thành các bài toán con nhỏ hơn
	• Kết hợp lời giải của các bài toán con để tìm lời giải của bài toán lớn hơn
	• Bài toán cơ sở quy hoạch bài toán con nhỏ nhất đã có lời giải
		○ VD số Fibonaci đã có 0, 1
	• Công thức truy hồi, phối hợp nghiệm của các bài toán con
	• Cần không gian lưu trữ: mảng 1 chiều, mảng 2 chiều…: Bảng phương án
	• Thuật toán quy hoạch động cần phải được thực hiện trong hữu hạn các bước

Giai đoạn của thuật toán Quy Hoạch Động:
	1. Phân rã
	2. Giải các bài toán con đấy và ghi nhận kết quả
	3. Tổng hợp lời giải
Cấu trúc con tối ưu: chia nhỏ bài toán của mình cho tới ghi gặp bài toán cơ sở có lời giải trước.
Overlapping sub problems 

                    7 MÔ HÌNH QUY HOẠCH ĐỘNG THƯỜNG GẶP

Mô hình 1:
    1/ Dãy con đơn điệu tăng dài nhất(longest discreasing subsequence ) LIS
        L[i] = max(L[i], L[j] + 1)
    VD: 3 1 2 8 4 5 
    Bảng phương án:
        3:  1    
        1:  1 1
        2:  1 1 2 (vì 1 < 2 nên dãy con tăng dài nhất mà số 2 đứng cuối là dãy 1, 2)
        8:  1 1 2 2 (vì 3 < 8 nên dãy là: 3, 8)
            1 1 2 3 (vì 8 đã ở trong dãy 3, 8 có đồ dài là 2 nhưng nếu ghép vô dãy của 2 có độ dài là 2 sẽ lớn hơn)
        4:  1 1 2 3 2 (3 < 4 dãy: 3, 4)
            1 1 2 3 2 (1 < 4 dãy: 1, 4)
            1 1 2 3 3 (2 < 4 dãy: 1, 2, 4)
        5:  1 1 2 3 3 2 (3 < 5 dãy 3, 5)
            1 1 2 1 3 2 (1 < 5 dãy 1, 5)
            1 1 2 1 3 3 (2 < 4 dãy 1, 2, 5)
            1 1 2 1 3 4 (4 < 5 dãy 1, 2, 4, 5) 
    2/ Tổng dãy con tăng dần đơn điệu lớn nhất:
        S[i] = max(S[i], a[i] + S[j])
    Bảng phương án: 
        S[i] = a[i]
                2 12 3 15 3 16 11 4 
        S[i]:   2 12 3 15 3 16 11 4 
        2: 
        12: 
        2 14 3 15 3 16 11 4 
        3: 
        2 14 5 15 3 16 11 4 
        2 14 5 15 3 16 11 4 
        15: 
        2 14 5 17 3 16 11 4 
        2 14 5 29 3 16 11 4 
        2 14 5 29 3 16 11 4 
Mô hình 2:
    1/ Subset Sum Problem (tìm dãy con có tổng bằng S cho trước)
    Cấu trúc con tối ưu:
        res[i]: Bằng true nếu ta có thể tạo ra dãy con có tổng bằng S
        đáp án là res[S]
        res[0] = true (Dãy con có tổng bằng 0 khi không chọn dãy con nào)
        Mỗi khi xét res[i] để biết là true hay false ta xét res[i - a[j]]
        VD: S = 10
        1, 3, 7, 2
        để check res[7]: ta check res[10 - 7] = res[3]
        Khác với mô hình đổi tiền 4 thì mô hình này ta xét tổng từ lớn đến bé (res[S] -> res[0])
        Vì ra muốn tìm dãy con có tổng bằng S
        Bảng phương án:
        a[1]: 1
        5: 1 0 0 0 0 0 
        4: 1 0 0 0 0 0 
        3: 1 0 0 0 0 0 
        2: 1 0 0 0 0 0 
        1: 1 1 0 0 0 0 
        a[2]: 3
        5: 1 1 0 0 0 0 
        4: 1 1 0 0 1 0 
        3: 1 1 0 1 1 0 
        2: 1 1 0 1 1 0 
        1: 1 1 0 1 1 0 
        a[3]: 7
        5: 1 1 0 1 1 0 
        4: 1 1 0 1 1 0 
        3: 1 1 0 1 1 0 
        2: 1 1 0 1 1 0 
        1: 1 1 0 1 1 0 
        a[4]: 2
        5: 1 1 0 1 1 1 
        4: 1 1 0 1 1 1 
        3: 1 1 0 1 1 1 
        2: 1 1 1 1 1 1 
        1: 1 1 1 1 1 1 

Mô hình 3:
    1/ Cho 2 xây X, Y. Tìm xâu con chung có độ dài lớn nhất.
    Cấu trúc con tối ưu:
        F[i][j]: Lưu dộ dài xâu con chung dài nhất bởi i ký tự của X và j ký tự của i
        F[i][0] = 0 (Xâu thứ nhất chọn ra ba nhiêu ký tự mà xâu 2 không chọn cái nào thì độ dài của xâu con chung là: 0)
        F[0][i] = 0
        Xét ký tự X[i] và Y[j]:
            + X[i] = Y[j] -> F[i][j] = F[i - 1]
            + X[i] != Y[j] -> F[i][j] = max(F[i - 1][j], F[i][j - 1]) 
            F[i - 1][j]: chọn xâu con với kí tự Y[j] trước đó
            F[i][j - 1]: chọn xâu con với khí tự X[i] trước đó 
            
        Bảng phương án:
            T F I S H R O V
            Z 0 0 0 0 0 0 0 0 
            H 0 0 0 0 1 1 1 1 
            F 0 1 1 1 1 1 1 1 
            T 1 1 1 1 1 1 1 1 
            D 1 1 1 1 1 1 1 1 
            F 1 2 2 2 2 2 2 2 
            H 1 2 2 2 3 3 3 3 
            F 1 3 3 3 3 3 3 3 

Mô hình 4:
    1/ Cho mệnh gía các tờ tiền đổi sao cho số tờ tiền là ít nhất
    Cấu trúc con tối ưu:
        cnt[0] = 0 (kết quẩ của bài toán đơn giản nhất)
        cnt[i] = Số tờ tiền tối thiểu để có được số tiền là i
        giả sử đồng xu thứ j có mệnh giá là C[j]
        C[j] : cnt[i - C[j]] với mọi ( 0 <= (i - C[j]) <= S) 
        i - C[j] số tiền khi chưa cho C[j] vào 
        VD: 
            Đồng C[j] = 3 muốn check xem cnt[5]: số đồng C[j] tối thiểu để có được 5
            Ta sẽ tiếp tục check số đồng 5 - C[j] tức là cnt[5 - C[j]] = cnt[5 - 3] = cnt[2]
        Bảng phương án:
            1: 
            1 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 
            1 2 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 
            1 2 3 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 
            1 2 3 4 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 
            1 2 3 4 5 1000000000 1000000000 1000000000 1000000000 1000000000 
            1 2 3 4 5 6 1000000000 1000000000 1000000000 1000000000 
            1 2 3 4 5 6 7 1000000000 1000000000 1000000000 
            1 2 3 4 5 6 7 8 1000000000 1000000000 
            1 2 3 4 5 6 7 8 9 1000000000 
            1 2 3 4 5 6 7 8 9 10 
            3: 
            1 2 1 4 5 6 7 8 9 10 
            1 2 1 2 5 6 7 8 9 10 
            1 2 1 2 3 6 7 8 9 10 
            1 2 1 2 3 2 7 8 9 10 
            1 2 1 2 3 2 3 8 9 10 
            1 2 1 2 3 2 3 4 9 10 
            1 2 1 2 3 2 3 4 3 10 
            1 2 1 2 3 2 3 4 3 4 
            5: 
            1 2 1 2 1 2 3 4 3 4 
            1 2 1 2 1 2 3 4 3 4 
            1 2 1 2 1 2 3 4 3 4 
            1 2 1 2 1 2 3 2 3 4 
            1 2 1 2 1 2 3 2 3 4 
            1 2 1 2 1 2 3 2 3 2 
    2/ Bài toán cái túi(Vali): Cho đồ vật A[i] có khối lượng B[i] và cái túi có trọng lượng W
    Làm sao để bỏ đồ vật vào túi sao cho giá trị cái túi là lớn nhất
    Cấu trúc con tối ưu:
        res[i][j]: Giá trị lớn nhất của cái túi khi nó có trọng lượng là j (W) bằng cách lựa chọn các đồ vật
        từ 1 đến i
        VD:
            w: {1, 3, 5} V = 5
            v: {4, 2, 5}

            res[i][j]:
                    0 1 2 3 4 5 
                0   0 0 0 0 0 0
                1   0 4 4 4 4 4 (mỗi đồ vật chỉ được bỏ vô 1 lần)
                2   0 
                3
            + Khi xét đến đồ vật thứ i có 2 lựa chọn:
                + Cho nó vào túi: 
                + Không cho nó vào túi: res[i][j] = res[i - 1][j]
            Công thức truy hồi: res[i][j] = min(res[i][j], res[i - 1][j - w[i]] + v[i])  
    Mô hình 5: Nhân ma trận
    
*/

//Model 4: 

    // Vali

    // void solve() {
    //     int n, V; cin >> n >> V;
    //     int w[n + 1], v[n + 1];
    //     for (int i = 1; i <= n; i++) {
    //         cin >> w[i];
    //     }
    //     for (int i = 1; i <= n; i++) {
    //         cin >> v[i];
    //     }
    //     int res[n + 1][V + 1];
    //     memset(res, 0, sizeof(res));
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 0; j <= V; j++) {
    //             res[i][j] = res[i - 1][j];
    //             if (j >= w[i]) {
    //                 res[i][j] = max(res[i][j], v[i] + res[i - 1][j - w[i]]);
    //             }
    //         }
    //     }
    //     cout << res[n][V];
    // }

    //Coin
    // void solve() {
    //     int n, S; cin >> n >> S;
    //     int c[n];
    //     vector<int> cnt(S + 1, 1e9);
    //     cnt[0] = 0;
    //     for (int i = 0; i < n; i++) {
    //         cin >> c[i];
    //         for (int j = 0; j <= S; j++) {
    //             if (j >= c[i]) {
    //                 cnt[j] = min(cnt[j], cnt[j - c[i]] + 1);
    //             }
    //         } 
    //     }
    //     if (cnt[S] == 1e9) {
    //         cout << -1  << endl;
    //     }
    //     else {
    //         cout << cnt[S] << endl;
    //     }
    // }

    void solve() {
        int n, S; cin >> n >> S;
        int c[n];
        vector<int> cnt(S + 1, 1e9);
        cnt[0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            for (int j = 0; j <= S; j++) {
                if (j >= c[i]) {
                    cnt[j] = min(cnt[j], cnt[j - c[i]] + 1);
                }
            } 
        }
        if (cnt[S] == 1e9) {
            cout << -1  << endl;
        }
        else {
            cout << cnt[S] << endl;
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
        return 0;
    }