#include<cstdio>
#include<iostream>

using namespace std;

void stringof01(int n) {

	if (n == 0) {
		return;
	}

	for (int i = 0; i < 2; i++) {
		printf("%d", i);
		stringof01(n - 1);
	}
}
int main() {
	int n;
	cin >> n;
	stringof01(n);
}