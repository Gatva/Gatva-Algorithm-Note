#include<cstdio>

#define MAX 10100
// �����ͼ�ֵ
int w[MAX], c[MAX];
int max_w, max_c;

int n,k;
void choose(int index,int ans_c,int ans_w) {

	// �ݹ����
	if (index == n + 1) {

		if (ans_c > max_c) {
			max_c = ans_c;
		}
	}

	// ��ѡ���index����Ʒ
	choose(index + 1, ans_c,ans_w);
	if (ans_w + w[index] < k) {
		// ѡ���index����Ʒ
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