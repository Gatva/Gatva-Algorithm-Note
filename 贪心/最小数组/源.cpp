#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<string>

#define MAX 30
using namespace std;

//�ַ�����洢
string strs[MAX];
void minNum() {

	int n;
	scanf("%d ", &n);
	 
	// ��ȡ���鴮
	for (int i = 0; i < n; i++) {
		char buf[100];
	
		scanf("%s", buf);
		strs[i] = buf;
	}
	// ���� 
	sort(strs, strs + n);
	
	// �����ǰ��0
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