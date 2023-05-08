#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<math.h>
#include<algorithm>
#define MAX 10100
using namespace std;
/*
给定一个大小为（也就是或或或等，依次类推）的白色棋盘，其中有一个格子是黑色的
现在想用一种大小占三个小方格的形骨牌来覆盖整个棋盘
*/
// 结构体定义T型
struct T
{
	int x, y;
	T(int xx,int yy) {
		x = xx;
		y = yy;
	}
};


vector<T> vec;
// x,y为黑格子,sx,sy为棋盘起始位置
void chessboard(int sx, int sy, int x, int y,int len) {

	if (len == 1) {
		return;
	}
	// 分割
	int ans = len / 2;

	//printf("%d %d %d %d %d\n", sx, sy, x, y, len);
	// 处理左上

	//黑格子在当前块，根据黑格子得知第一块T牌中心位置，然后递归
	if (x<sx+ans&&y<sy+ans) {

		// 骨牌中心位置
		vec.push_back(T(sx + ans, sy + ans));

		chessboard(sx,sy,x,y,ans);
		
	}
	else {

		// 不在，覆盖,递归
		chessboard(sx, sy, sx + ans - 1, sy + ans - 1, ans);

	}

	// 处理左下
	if (x>=sx+ans&&y<sy+ans) {

		// 骨牌中心位置
		vec.push_back(T(sx+ans-1,sy+ans));

		chessboard(sx+ans,sy,x,y,ans);
	}
	else {

		// 不在，覆盖,递归
		chessboard(sx+ans,sy,sx+ans,sy+ans-1,ans);

	}
	
	// 处理右下
	if (x>=sx+ans&&y>=sy+ans) {

		// 骨牌中心位置
		vec.push_back(T(sx+ans-1,sy+ans-1));

		chessboard(sx+ans,sy+ans,x,y,ans);
	}
	else {

		// 不在，覆盖,递归
		chessboard(sx+ans,sy+ans,sx+ans,sy+ans,ans);

	}
	// 处理右上
	if (x<sx+ans&&y>=sy+ans) {

		// 骨牌中心位置
		vec.push_back(T(sx+ans,sy+ans-1));

		chessboard(sx,sy+ans,x,y,ans);
	}
	else {

		// 不在，覆盖,递归
		chessboard(sx,sy+ans,sx+ans-1,sy+ans,ans);

	}

}

bool cmp(T l, T r) {
	return l.x != r.x ? l.x < r.x : l.y < r.y;
}
int main() {
	int k, x, y;
	scanf("%d %d %d", &k, &x, &y);
	chessboard(0, 0, x-1, y-1, (int)pow(2, k));

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++) {
		printf("%d %d\n", vec[i].x+1, vec[i].y+1);
	}

	return 0;
}