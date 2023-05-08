#include<cstdio>
#include<algorithm>
#define MAX 10100
using namespace std;

struct N {
    int x, y;
};
N nodes[MAX];
bool cmp(N l, N r) {
    return l.x != r.x ? l.x < r.x : l.y < r.y;
}
int main() {

    int n;
    scanf("%d", &n);

    sort(nodes, nodes + n, cmp);

    int l = nodes[0].x;
    int r = nodes[0].y;
    int cnt = 0;
    for (int i = 1; i < n; i++) {

        // 与已有区间未重叠，区间++,更新右边界
        if (nodes[i].x >= r) {
            r = nodes[i];
            cnt++;
        }
        // 与已有区间重叠，右边界小于已有区间，更新右边界  
        if (nodes[i].y < r) {
            r = nodes[i];
            cnt++;
        }

    }

    printf("%d", cnt);
}