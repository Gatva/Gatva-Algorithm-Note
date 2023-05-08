#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<math.h>
#include <algorithm>

using namespace std;
int ff(int num) {
	if (num == 1) {
		return 0;
	}

	int sum = 0;
	for (int i = 1; i <= num / 2; i++) {
		int r = ff(num - i);

		sum += r+1;
	}
	printf("%d %d \n", num, sum);
	return sum;
}


/*
����һ����������������ʾ����������������֮�ͣ���������������ֵ��
*/

int maxMul(int n) {

	// ����
	if (n == 1) {
		return 1;
	}

	// n�ֽ�������
	int maxres = 0;
	for (int i = 1; i <= n / 2; i++) {

		// �ֽ��ĳ˻��뱾��Ƚ�
		int ans1 =max(n-i, maxMul(n - i));
		int ans2 = max(i,maxMul(i));

		if (maxres < ans1*ans2) {
			maxres = ans1*ans2;
		}
	}
	return maxres;
}


/*
����һ����������������ʾ����������������֮�ͣ������������ж����ֲ�ͬ�ķ�����
*/
// �ֽ�����n,�ֽ����������������bound,��ǰ�ݹ����Ϊdeep
int f(int n, int bound,int deep) {

	int res = 0;
	// �ҵ�һ�ַֽⷽʽ
	if (n <= bound) {
		res++;
	}

	// �޷������ֽ�
	if (n <= 1) {
		return res;
	}

	// �ֱ���iΪbound�������ֽ�
	for (int i = 1; i <= bound && i<n; i++) {
		// ����ո��жϵݹ����
		for (int i = 0; i < deep; i++) {
			printf(" ");
		}
		printf("%d %d\n",n-i,i);
		
		res += f(n - i, i,deep+1);

	
	}

	return res;
}

int ff(int num,int bound) {

	if (num <= 1 || bound <= 0) {
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= bound; i++) {

		ans += ff(num - i, i);
		
	}
	return ans;
}



int main() {

	int n;
	scanf("%d", &n);

	printf("%d", f(n,n-1,0));
}