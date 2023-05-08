#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>

#define MAX 1010
using namespace std;

char v[MAX][MAX];
void f(int n,int x,int y) {

	
	if (n == 1) {
		// printf("%d %d\n", x, y);
		v[x][y] = 'X';
		return;
	}
	int unit = (int)pow(3, n - 2);
	//printf("%d", unit);
	f(n - 1,x-unit, y -unit);
	f(n - 1,x- unit,y+ unit);
	f(n - 1,x,y);
	f(n - 1,x+ unit,y- unit);
	f(n - 1,x+ unit,y+ unit);

}

int main() {

	int n;
	cin >> n;

	int len = (int)pow(3, n - 1);
	int size = len / 2 + 1;
	
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= len; j++) {
			v[i][j] = ' ';
		}
	}

	f(n,size,size);

	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= len; j++) {
			printf("%c", v[i][j]);
		}
		printf("\n");
	}

}