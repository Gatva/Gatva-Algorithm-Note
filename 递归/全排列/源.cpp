#include<cstdio>
#include<vector>

#define SIZE 150
using namespace std;

int n=3, P[SIZE], hashmap[SIZE] = { false };

void generateP(int index) {

	// һ������������
	if (index == n + 1) {

		for (int i = 1; i <= n; i++) {
			printf("%d ", P[i]);
		}
		printf("\n");
		return;
	}
	for (int i =1; i <= n; i++) {
		if (hashmap[i] == false) {

			// ѡ���index���ֵ
			hashmap[i] = true;
			P[index] = i;

			// �Ե�index���Ժ�����н����������
			generateP(index + 1);

			// i�������ΪFALSE
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