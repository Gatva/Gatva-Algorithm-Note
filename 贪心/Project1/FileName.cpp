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

        // ����������δ�ص�������++,�����ұ߽�
        if (nodes[i].x >= r) {
            r = nodes[i];
            cnt++;
        }
        // �����������ص����ұ߽�С���������䣬�����ұ߽�  
        if (nodes[i].y < r) {
            r = nodes[i];
            cnt++;
        }

    }

    printf("%d", cnt);
}