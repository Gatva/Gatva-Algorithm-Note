#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<math.h>
#include<algorithm>
#define MAX 10100
using namespace std;
/*
����һ����СΪ��Ҳ���ǻ���ȣ��������ƣ��İ�ɫ���̣�������һ�������Ǻ�ɫ��
��������һ�ִ�Сռ����С������ι�����������������
*/
// �ṹ�嶨��T��
struct T
{
	int x, y;
	T(int xx,int yy) {
		x = xx;
		y = yy;
	}
};


vector<T> vec;
// x,yΪ�ڸ���,sx,syΪ������ʼλ��
void chessboard(int sx, int sy, int x, int y,int len) {

	if (len == 1) {
		return;
	}
	// �ָ�
	int ans = len / 2;

	//printf("%d %d %d %d %d\n", sx, sy, x, y, len);
	// ��������

	//�ڸ����ڵ�ǰ�飬���ݺڸ��ӵ�֪��һ��T������λ�ã�Ȼ��ݹ�
	if (x<sx+ans&&y<sy+ans) {

		// ��������λ��
		vec.push_back(T(sx + ans, sy + ans));

		chessboard(sx,sy,x,y,ans);
		
	}
	else {

		// ���ڣ�����,�ݹ�
		chessboard(sx, sy, sx + ans - 1, sy + ans - 1, ans);

	}

	// ��������
	if (x>=sx+ans&&y<sy+ans) {

		// ��������λ��
		vec.push_back(T(sx+ans-1,sy+ans));

		chessboard(sx+ans,sy,x,y,ans);
	}
	else {

		// ���ڣ�����,�ݹ�
		chessboard(sx+ans,sy,sx+ans,sy+ans-1,ans);

	}
	
	// ��������
	if (x>=sx+ans&&y>=sy+ans) {

		// ��������λ��
		vec.push_back(T(sx+ans-1,sy+ans-1));

		chessboard(sx+ans,sy+ans,x,y,ans);
	}
	else {

		// ���ڣ�����,�ݹ�
		chessboard(sx+ans,sy+ans,sx+ans,sy+ans,ans);

	}
	// ��������
	if (x<sx+ans&&y>=sy+ans) {

		// ��������λ��
		vec.push_back(T(sx+ans,sy+ans-1));

		chessboard(sx,sy+ans,x,y,ans);
	}
	else {

		// ���ڣ�����,�ݹ�
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