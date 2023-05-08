#include<cstdio>
#include<vector>

#define SIZE 150
using namespace std;

int n=3, P[SIZE], hashmap[SIZE] = { false };

void generateP(int index) {

	// 一组排列完后输出
	if (index == n + 1) {

		for (int i = 1; i <= n; i++) {
			printf("%d ", P[i]);
		}
		printf("\n");
		return;
	}
	for (int i =1; i <= n; i++) {
		if (hashmap[i] == false) {

			// 选择第index项的值
			hashmap[i] = true;
			P[index] = i;

			// 对第index项以后的序列进行排列组合
			generateP(index + 1);

			// i用完后置为FALSE
			hashmap[i] = false;
		}
		
	}

}

bool chess[SIZE][SIZE];
int k;
void chessboard(int r,int c) {


}
int main() {
	generateP(1);
	return 0;
}