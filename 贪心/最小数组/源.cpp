#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<string>

#define MAX 30
using namespace std;

//字符数组存储
string strs[MAX];
void minNum() {

	int n;
	scanf("%d ", &n);
	 
	// 获取数组串
	for (int i = 0; i < n; i++) {
		char buf[100];
	
		scanf("%s", buf);
		strs[i] = buf;
	}
	// 排序 
	sort(strs, strs + n);
	
	// 输出，前导0
	bool flag = false;
	string res = "";
	for (int i = 0; i < n; i++) {
		res += strs[i];
	}

	int i;
	for (i = 0; i < res.size(); i++) {
		if (res[i] != '0') {
			break;
		}
	}
	if (i == res.size() - 1) {
		printf("0");
	}
	printf("%s", res.substr(i).c_str());

}

int main() {

	minNum();
}