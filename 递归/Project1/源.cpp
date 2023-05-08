#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>
#include<algorithm>

#define MAX 30
using namespace std;
string s;
char buf[110];
struct Block
{
	int x, y;
	Block() {}
	Block(int xx, int yy) {
		x = xx;
		y = yy;
	}
};
void print(int n) {

	if (n == s.length()) {
		return;
	}
	print(n + 1);
	printf("%c", s[n]);
}


int num[MAX][MAX];
int n;

int tower(int r,int c) {

	if (r == n) {
		return 0;
	}
	// 当前最大路径长度=当前位置的数值+max(正下方路径长度，右下方路劲长度）
	return max(tower(r + 1, c), tower(r + 1, c + 1)) + num[r][c];
}
// 存储路径长度
int sum[MAX][MAX] = { 0 };

void dfs_tower(int r, int c, int temp) {

	if (r == n) {
		return;
	}

	sum[r][c] = sum[r][c] > temp ? sum[r][c] : temp;
	
	dfs_tower(r + 1, c, sum[r][c] + num[r + 1][c]);
	dfs_tower(r + 1, c + 1, sum[r][c] + num[r + 1][c + 1]);
}

void hanoi(int n,char from,char mid,char end) {

	if (n == 0) {
		return;
	}
	hanoi(n - 1, from, end, mid);// 移动上面n - 1个盘子，从A移动到B，以C为中介
	printf("%c->%c\n", from, end);// 移动第n个盘子，从A移动到C
	hanoi(n - 1, mid, from, end);// 将剩余n-1盘子移动到C，从B移动到C，以A为中介
}

int rounds = 0;
Block blocks[MAX];
/*
传入棋盘的起始位置(1,1),(1,n/2+1) (n/2+1,1),(n/2+1,n/2+1)
传入不能被覆盖的位置
传入棋盘的大小
*/
void chessboard(int start,int end,int cx,int cy,int size) {


	// 将棋盘一分为四
	int n = size / 2;

	//棋盘大小为0是返回
	if (n == 0) {
		return;
	}


	// 处理左上
	if (cx < start+n && cy < end+n) {

		blocks[rounds++] = Block(start +n, end + n );
		//如果包含了不能覆盖的位置，继续分割
		chessboard(start, end, cx, cy, n);
	}
	else {
		//printf("(start+n) %d (end+n) %d\n", start + n, end + n);
		//printf("cx%d,cy%d", cx, cy);
		////如果没包含，填充右下角
		//printf("左上%d %d\n", start+  n - 1, end + n - 1);
		chessboard(start, end, start + n - 1, end + n - 1, n);
	}

	// 处理左下
	if (cx > start + n-1 && cy < end + n) {
		blocks[rounds++] = Block(start + n-1, end + n);
		chessboard(start + n, end, cx, cy, n);
	}
	else {
		//printf("(start+n) %d (end+n) %d\n", start + n, end + n);
		//printf("cx%d,cy%d", cx, cy);
		//printf("左下%d %d\n", start + n, end + n - 1);
		chessboard(start + n, end, start + n, end + n - 1, n);
	}
	// 处理右下
	if (cx > start + n-1 && cy > end + n-1) {
		blocks[rounds++] = Block(start + n-1, end + n-1);
		chessboard(start + n, end + n, cx, cy, n);
	}
	else {
		//printf("cx%d,cy%d", cx, cy);
		//printf("右下%d %d\n", start + n, end + n);
		chessboard(start + n, end + n, start + n, end + n, n);
	}
	// 处理右上
	if (cx<start + n && cy>end + n-1) {
		blocks[rounds++] = Block(start + n, end + n-1);
		chessboard(start, end + n, cx, cy, n);
	}
	else {
		//printf("cx%d,cy%d", cx, cy);
		//printf("右上%d %d\n", start + n - 1, end + n);
		chessboard(start, end + n, start + n - 1, end + n, n);
	}
	
}

bool cmp(Block l, Block r) {
	return l.x != r.x ? l.x < r.x : l.y < r.y;
}

int main() {

	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &num[i][j]);
		}
	}

	dfs_tower(0, 0, num[0][0]);

	int max = -1;
	for (int i = 0; i < n; i++) {
		if (max < sum[n - 1][i]) {
			max = sum[n - 1][i];
		}
	}

	printf("%d", max);
}