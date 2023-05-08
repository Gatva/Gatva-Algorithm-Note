#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

#define MAX 10010
using namespace std;

//
int ans = 0;
// 序列
int a[MAX];
// 总长度,目标数
int n, k;
bool isv[MAX] = { false };
void f(int index, int nowSum) {

	if (index == n + 1) {
		if (nowSum == k) {
			ans++;
		}
		return;
	}
	for (int i = 0; i <= (k - nowSum) / a[index]; i++) {
		f(index + 1, nowSum + i * a[index]);
	}
}

int main() {

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}

	f(1, 0);
	printf("%d", ans);
}