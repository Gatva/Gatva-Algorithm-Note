#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<math.h>
#define SIZE 20
/*
������index�е��кţ��������ȫ���У��涨ÿ����λ�ò�����ͬһ�Խ�����
*/
int n;

// ��i�еĻʺ���ڵ�P[i]��λ��
int P[SIZE];
// ��Ƿ���
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
// ��¼�Ϸ��ڷ���
int cnt = 0;
void generateP(int index) {

	// ������
	if (index == n + 1) {

		//�ж��Ƿ�Ϸ�
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

	// Ѱ��
}

bool canPut(int data,int index) {

	for (int i = 1; i < index; i++) {
		// ��ǰ�ڷ�λ���Ƿ��ǰ���λ�ò�����ͻ����ͬһб���ߣ�
		if (abs(P[i] - data) == index - i) {
			return false;
		}
	}

	return true;
}

//����
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