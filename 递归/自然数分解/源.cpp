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
给定一个正整数，将它表示成至少两个正整数之和（即，），求的最大值。
*/

int maxMul(int n) {

	// 出口
	if (n == 1) {
		return 1;
	}

	// n分解的最大结果
	int maxres = 0;
	for (int i = 1; i <= n / 2; i++) {

		// 分解后的乘积与本身比较
		int ans1 =max(n-i, maxMul(n - i));
		int ans2 = max(i,maxMul(i));

		if (maxres < ans1*ans2) {
			maxres = ans1*ans2;
		}
	}
	return maxres;
}


/*
给定一个正整数，将它表示成至少两个正整数之和（即，），问有多少种不同的方案。
*/
// 分解整数n,分解后的最大整数不超过bound,当前递归深度为deep
int f(int n, int bound,int deep) {

	int res = 0;
	// 找到一种分解方式
	if (n <= bound) {
		res++;
	}

	// 无法继续分解
	if (n <= 1) {
		return res;
	}

	// 分别以i为bound，继续分解
	for (int i = 1; i <= bound && i<n; i++) {
		// 输出空格，判断递归深度
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