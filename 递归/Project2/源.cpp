#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<string>
#include<algorithm>

#define MAX 30
using namespace std;

int id = 1;
int num_metric[MAX][MAX];
// 
void generateMetric(int x,int y,int edgeSize) {

	if (edgeSize == 0) {
		return;
	}
	else if (edgeSize == 1) {
		num_metric[x][y] = id;
		return;
	}

	int i,j,k,m = 0;
	for (i = x; i < x + edgeSize - 1; i++) {
		
		num_metric[x][i] = id++;
	}
	for (j = x; j < x + edgeSize - 1; j++) {
		num_metric[j][y + edgeSize - 1] = id++;
	}
	for (k = y + edgeSize - 1; k > y; k--) {
		num_metric[x + edgeSize-1][k] = id++;
	}

	for (m = x + edgeSize - 1; m > x; m--) {
		num_metric[m][y] = id++;
	}
	generateMetric(x + 1, y + 1, edgeSize - 2);
}

int main() {
	int n;
	scanf("%d", &n);
	generateMetric(1, 1, n);

	for (int i = 1; i <= n; i++) {
	
		for (int j = 1; j <= n; j++) {
			printf("%d", num_metric[i][j]);
			if (j != n) {
				printf(" ");
			}
			else {
				printf("\n");
			}
		}
	}
}