#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator <(const Point &p) const {return x < p.x || (x == p.x && y < p.y);}
};

long long cross(const Point &O, const Point &A, const Point &B){
    return (A.x - O.x) * (long long)(B.y - O.y) - (A.y - O.y) * (long long)(B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P){
    int n = P.size(), k = 0;
    vector<Point> H(2 * n);
    sort(P.begin(), P.end());
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}

int N;
vector<Point> P;
vector<Point> Result;

int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        Point Temp;
        scanf("%d%d", &Temp.x, &Temp.y);
        P.push_back(Temp);
    }
    Result = convex_hull(P);
    for (int i = 0; i < Result.size(); i++)
        printf("%d %d\n", Result[i].x, Result[i].y);
    return 0;
}