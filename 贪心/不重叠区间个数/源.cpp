#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#define MAX 30
using namespace std;

// ����ṹ��洢����
struct Node
{
	int x, y;
};

//�ṹ������
Node nodes[MAX];
bool cmp(Node l, Node r) {
	return l.x != r.x ? l.x < r.x : l.y < r.y;
}
void getSumInterval() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &nodes[i].x, &nodes[i].y);
	}
	// ����
	sort(nodes, nodes + n,cmp);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", nodes[i].x, nodes[i].y);
	}

	printf("-----------------");

	int lastY = nodes[0].y;
	// ѭ����ȡ��һ������
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		// �ж��Ƿ��ص�
		if (nodes[i].x < lastY) {

			// �Ƚϵ�ǰ������Ҷ˵������������Ҷ˵�
			// �����������������Ҷ˵�
			lastY = nodes[i].y < lastY ? nodes[i].y : lastY;
			//printf("�ص�%d %d\n", nodes[i].x, nodes[i].y);
		}
		else {
			cnt++;
			lastY = nodes[i].y;
			//printf("���ص�%d %d\n", nodes[i].x, nodes[i].y);

		}
		//printf("%d\n", lastY);
	}
	printf("%d", cnt);
}

int numsSmaller[MAX];
int numsBigger[MAX];

void pairing() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &numsSmaller[i]);
	}
	for (int j = 0; j < m; j++) {
		scanf("%d", &numsBigger[j]);
	}

	//����
	sort(numsSmaller, numsSmaller + n);

	// ��ԣ�ͳ����Գɹ�����Ŀ
	sort(numsBigger, numsBigger + m);

	for (int i = 0; i < n; i++) {
		printf("%d ", numsSmaller[i]);
	}
	printf("\n");
	for (int j = 0; j < m; j++) {
		printf("%d ", numsBigger[j]);
	}
	printf("\n");
	int k = 0;
	int cnt = 0;
	for (int i = 0; i < m&&k<n; i++) {
		if (numsBigger[i] >= numsSmaller[k]) {
			printf("%d %d\n", numsBigger[i], numsSmaller[i]);
			k++;
			cnt++;
		}
	}
	printf("%d", cnt);
}

void intervalConbine() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &nodes[i].x, &nodes[i].y);
	}
	// ����
	sort(nodes, nodes + n, cmp);
	

	int cnt = 1;
	int lastY = nodes[0].y;

	// ����ȡ��һ����
	for (int i = 0; i < n; i++) {
		// �жϸ������Ƿ����ԭ���������
		if (nodes[i].x > lastY) {
			// �����ԣ�cnt++
			cnt++;
			// ���������������С�Ҷ˵�
			lastY = nodes[i].y;
		}
		// ���������������С�Ҷ˵�
		lastY = nodes[i].y < lastY ? nodes[i].y : lastY;
	}
	printf("%d", cnt);
}
int main() {

	intervalConbine();
	
}