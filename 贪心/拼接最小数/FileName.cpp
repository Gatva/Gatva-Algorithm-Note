#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<string> vec;

bool cmp(string l, string r) {


}
int n;
int main() {
    char buf[20];
    scanf("%d",&n);
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%s ", buf);
        vec[i] = buf;
    }
    sort(vec.begin(), vec.end(), cmp);

    string res = "";
    for (int i = 0; i < n; i++) {
        res += vec[i];
    }
    while (res.size() > 0 && res[0] == '0') {
        res.erase(res.begin());
    }
    printf("%s", res.c_str());

}