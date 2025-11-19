#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5, oo = 1e9 + 7;
int n, m, c_min = oo;
int t[maxn][maxn], c[maxn][maxn];

struct Plan{ // ke hoach bo phan
    // s: thoi gian hien tai; g: can duoi; cnt: so chi tiet da co trong ke hoach
    // details: danh sach cac chi tiet (nguoc lai voi thu tu gia cong)
    int s, g;
    vector<int> details;
    Plan(){
        s = 0; g = 0;
        details.clear();
    }
    Plan(int i, int S, int G){
        details.push_back(i);
        s = S;
        g = G;
    }
};

struct Cmp{
    bool operator()(const Plan &x, const Plan &y){
        return y.g < x.g;
    }
};

// Uu tien ke hoach co can duoi nho hon
priority_queue<Plan, vector<Plan>, Cmp> p;

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
            t[i][0] += t[i][j];
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

// Lay cac phan tu 1...n chua co mat trong vector v
vector<int> notIn(vector<int> v)
{
    sort(v.begin(), v.end());
    vector<int> out(0);
    int i = 1;
    for (int d : v)
    {
        while (i <= n && i != d) out.push_back(i++);
        ++i;
    }
    while (i <= n) out.push_back(i++);
    return out;
}

void solve(){
    // Lap ke hoach bo phan voi chi tiet i la chi tiet cuoi
    for (int i = 1; i <= n; ++i){
        int sum = 0;
        for (int j = 1; j <= m; ++j)
            sum += t[i][j];
        p.push(Plan(i, sum, sum + (n - 1) * c_min));
    }

    int f_opt = oo;
    vector<int> x_opt;
    // Duyet qua cac ke hoach bo phan hien co; lan luot them cac chi tiet khac
    while (!p.empty()){
        Plan cur = p.top();
        p.pop();

        // Neu can duoi cua phuong an lon hon dap an hien tai
        if (cur.g >= f_opt) continue;
        // Neu phuong an da co day du cac chi tiet
        if (cur.details.size() == n)
        {
            if (f_opt > cur.s)
            {
                f_opt = cur.s;
                x_opt = cur.details;
            }
            continue;
        }
        // Neu khong:
        vector<int> unchecked = notIn(cur.details);
        int i = 1;
        int last = cur.details.back();
        Plan tmp;
        for (int d : unchecked)
        {
            tmp.details = cur.details;
            tmp.details.push_back(d);
            tmp.s = cur.s + c[d][last];
            tmp.g = tmp.s + (n - tmp.details.size()) * c_min;
            p.push(tmp);
        }
    }

    reverse(x_opt.begin(), x_opt.end());
    cout << "Thoi gian toi uu: " << f_opt << "\n";
    cout << "Thu tu gia cong chi tiet: ";
    for (int detail : x_opt) cout << detail << " ";
    cout << "\n";
}

int main(){
    inputData();
    matrixC();
    solve();
}
