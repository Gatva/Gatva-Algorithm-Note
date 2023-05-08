#include<cstdio>

#define MAX 10100
// 重量和价值
int w[MAX], c[MAX];
int max_w, max_c;

int n,k;
void choose(int index,int ans_c,int ans_w) {

	// 递归出口
	if (index == n + 1) {

		if (ans_c > max_c) {
			max_c = ans_c;
		}
	}

	// 不选则第index件物品
	choose(index + 1, ans_c,ans_w);
	if (ans_w + w[index] < k) {
		// 选择第index件物品
		choose(index + 1, ans_c + c[index], ans_w + w[index]);
	}
}
int main() {

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", w + i);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
	}

	choose(1, 0, 0);

	printf("%d", max_c);
}