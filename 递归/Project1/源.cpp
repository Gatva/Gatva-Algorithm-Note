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
	// ��ǰ���·������=��ǰλ�õ���ֵ+max(���·�·�����ȣ����·�·�����ȣ�
	return max(tower(r + 1, c), tower(r + 1, c + 1)) + num[r][c];
}
// �洢·������
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
	hanoi(n - 1, from, end, mid);// �ƶ�����n - 1�����ӣ���A�ƶ���B����CΪ�н�
	printf("%c->%c\n", from, end);// �ƶ���n�����ӣ���A�ƶ���C
	hanoi(n - 1, mid, from, end);// ��ʣ��n-1�����ƶ���C����B�ƶ���C����AΪ�н�
}

int rounds = 0;
Block blocks[MAX];
/*
�������̵���ʼλ��(1,1),(1,n/2+1) (n/2+1,1),(n/2+1,n/2+1)
���벻�ܱ����ǵ�λ��
�������̵Ĵ�С
*/
void chessboard(int start,int end,int cx,int cy,int size) {


	// ������һ��Ϊ��
	int n = size / 2;

	//���̴�СΪ0�Ƿ���
	if (n == 0) {
		return;
	}


	// ��������
	if (cx < start+n && cy < end+n) {

		blocks[rounds++] = Block(start +n, end + n );
		//��������˲��ܸ��ǵ�λ�ã������ָ�
		chessboard(start, end, cx, cy, n);
	}
	else {
		//printf("(start+n) %d (end+n) %d\n", start + n, end + n);
		//printf("cx%d,cy%d", cx, cy);
		////���û������������½�
		//printf("����%d %d\n", start+  n - 1, end + n - 1);
		chessboard(start, end, start + n - 1, end + n - 1, n);
	}

	// ��������
	if (cx > start + n-1 && cy < end + n) {
		blocks[rounds++] = Block(start + n-1, end + n);
		chessboard(start + n, end, cx, cy, n);
	}
	else {
		//printf("(start+n) %d (end+n) %d\n", start + n, end + n);
		//printf("cx%d,cy%d", cx, cy);
		//printf("����%d %d\n", start + n, end + n - 1);
		chessboard(start + n, end, start + n, end + n - 1, n);
	}
	// ��������
	if (cx > start + n-1 && cy > end + n-1) {
		blocks[rounds++] = Block(start + n-1, end + n-1);
		chessboard(start + n, end + n, cx, cy, n);
	}
	else {
		//printf("cx%d,cy%d", cx, cy);
		//printf("����%d %d\n", start + n, end + n);
		chessboard(start + n, end + n, start + n, end + n, n);
	}
	// ��������
	if (cx<start + n && cy>end + n-1) {
		blocks[rounds++] = Block(start + n, end + n-1);
		chessboard(start, end + n, cx, cy, n);
	}
	else {
		//printf("cx%d,cy%d", cx, cy);
		//printf("����%d %d\n", start + n - 1, end + n);
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