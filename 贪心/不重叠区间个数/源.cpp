#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#define MAX 30
using namespace std;

// 定义结构体存储区间
struct Node
{
	int x, y;
};

//结构体数组
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
	// 排序
	sort(nodes, nodes + n,cmp);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", nodes[i].x, nodes[i].y);
	}

	printf("-----------------");

	int lastY = nodes[0].y;
	// 循环获取下一个区间
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		// 判断是否重叠
		if (nodes[i].x < lastY) {

			// 比较当前区间的右端点和已有区间的右端点
			// 更新已有区间的最大右端点
			lastY = nodes[i].y < lastY ? nodes[i].y : lastY;
			//printf("重叠%d %d\n", nodes[i].x, nodes[i].y);
		}
		else {
			cnt++;
			lastY = nodes[i].y;
			//printf("不重叠%d %d\n", nodes[i].x, nodes[i].y);

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

	//排序
	sort(numsSmaller, numsSmaller + n);

	// 配对，统计配对成功的数目
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
	// 排序
	sort(nodes, nodes + n, cmp);
	

	int cnt = 1;
	int lastY = nodes[0].y;

	// 遍历取下一区间
	for (int i = 0; i < n; i++) {
		// 判断该区间是否可以原有区间组合
		if (nodes[i].x > lastY) {
			// 不可以，cnt++
			cnt++;
			// 更新已有区间的最小右端点
			lastY = nodes[i].y;
		}
		// 更新已有区间的最小右端点
		lastY = nodes[i].y < lastY ? nodes[i].y : lastY;
	}
	printf("%d", cnt);
}
int main() {

	intervalConbine();
	
}