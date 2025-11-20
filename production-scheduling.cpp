#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5, oo = 1e9 + 7;
bool b[maxn];
int n, m, c_min = oo, f_opt = oo;
int t[maxn][maxn], c[maxn][maxn];
vector<int> x_opt, x;

// Nhap du lieu bai toan
void inputData(){
    cout << "Nhap so chi tiet can gia cong: ";
    cin >> n;
    cout << "Nhap so may: ";
    cin >> m;
    cout << "Nhap ma tran thoi gian T:\n";
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> t[i][j];
            t[i][0] += t[i][j]; // t[i][0] la thoi gian gia cong chi tiet i
        }
    }
    cout << "\n";
}

// Tinh cac phan tu ma tran c
void matrixC(){
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (i == j) continue;
            else{
                int s1 = 0, s2 = 0;
                for (int k = 1; k <= m; ++k){
                    s1 += t[i][k];
                    if (k > 1) s2 += t[j][k - 1];
                    c[i][j] = max(c[i][j], s1 - s2);
                }
                c_min = min(c_min, c[i][j]);
            }
        }
    }
}

// Sinh tat ca cach xep thu tu cac chi tiet
void bnb(int k, int time)
{
    // Tinh can duoi cua phuong an con, neu > f_opt thi bo qua
    int g = time + (n - k) * c_min;
    if (g >= f_opt) return;

    // Neu phuong an dang xet la phuong an hoan chinh
    if (k == n)
    {
        if (time < f_opt)
        {
            f_opt = time;
            x_opt = x;
        }
        return;
    }

    // Neu khong
    for (int i = 1; i <= n; ++i)
    {
        // Them nhung chi tiet chua nam trong phuong an con
        if (!b[i])
        {
            b[i] = true;
            x.push_back(i);
            if (k == 0)
                bnb(k + 1, time + t[i][0]);
            else
                bnb(k + 1, time + c[i][x[k - 1]]);
            x.pop_back();
            b[i] = false;
        }
    }
}

int main()
{
    inputData();
    matrixC();
    x.clear();
    bnb(0, 0);

    reverse(x_opt.begin(), x_opt.end());
    cout << "Thoi gian toi uu: " << f_opt << "\n";
    cout << "Thu tu gia cong chi tiet: ";
    for (int detail : x_opt) cout << detail << " ";
    cout << "\n";
}
