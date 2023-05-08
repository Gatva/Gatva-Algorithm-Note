#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<math.h>
#define SIZE 20
/*
产生第index列的行号，对其进行全排列，规定每两个位置不能在同一对角线上
*/
int n;

// 第i行的皇后放在第P[i]个位置
int P[SIZE];
// 标记访问
bool hashtable[SIZE] = { false };

bool judge() {

	for (int i = 1; i <= n; i++) {

		for (int j = i+1; j <= n; j++) {

			int r = j - i;
			int c = abs(P[j] - P[i]);
			
			if (r == c) {
				//printf("%d %d\n", r, c);
				return false;
			}
		}
	}

	return true;
}
// 记录合法摆放数
int cnt = 0;
void generateP(int index) {

	// 产生完
	if (index == n + 1) {

		//判断是否合法
		if (judge()) {
			for (int i = 1; i <= n; i++) {
				//printf("%d ", P[i]);
			}
			//printf("\n");
			cnt++;
		}

		return;
		
	}
	for (int i = 1; i <= n; i++) {
		if (hashtable[i] == false) {

			P[index] = i;
			hashtable[i] = true;

			generateP(index + 1);
			hashtable[i] = false;
		}
	}

	// 寻找
}

bool canPut(int data,int index) {

	for (int i = 1; i < index; i++) {
		// 当前摆放位置是否和前面的位置产生冲突（在同一斜角线）
		if (abs(P[i] - data) == index - i) {
			return false;
		}
	}

	return true;
}

//回溯
void generateP2(int index) {

	if (index == n + 1) {

		cnt++;

		return;
	}
	for (int i = 1; i <= n; i++) {
		//printf("%d ", i);
		if (hashtable[i] == false && canPut(i,index)) {

			hashtable[i] = true;
			P[index] = i;
			//printf("\n %d %d\n", index, i);
			generateP2(index + 1);
			hashtable[i] = false;

		}
	}

}
int main() {

	scanf("%d", &n);
	generateP2(1);
	printf("%d", cnt);
}