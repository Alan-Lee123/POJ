#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef __int64 lld;
const int maxn = 1005;
struct Point{
    int x, y;
    Point(){}
    Point(int a, int b) : x(a), y(b){}
    bool operator < (const Point & cmp)const {
        return x < cmp.x || (x == cmp.x && y < cmp.y);
    }
}p[maxn], ss[maxn * maxn];

bool operator == (const Point &a, const Point &b){
    return a.x == b.x && a.y == b.y;
}
int n;

int main(){
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        int cnt = 0, num = 1;
        lld res = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                ss[cnt++] = Point(p[i].x + p[j].x, p[i].y + p[j].y);
            }
        }
        sort(ss, ss + cnt);
        for (int i = 1; i < cnt; i++){
            if (ss[i] == ss[i-1]){
                res += num;
                num++;
            }else {
                num = 1;
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}