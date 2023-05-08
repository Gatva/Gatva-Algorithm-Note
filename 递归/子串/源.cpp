#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

#define MAX 10010
using namespace std;

// –Ú¡–
int nums[MAX];
vector<int> path;
// set»›∆˜¥Ê¥¢
set<vector<int>> sets;
int n;
void ff(int startIndex) {

	sets.insert(path);
	for (int i = startIndex; i <= n; i++) {

		path.push_back(nums[i]);

		ff(i + 1);

		path.pop_back();

	}
}



vector<vector<int>> res;
int deep;

void f(int startIndex) {


	res.push_back(path);
	
	for (int i = 0; i < path.size(); i++) {
		printf("%d ",path[i]);
	}
	printf("\n");
	deep++;

	for (int i = startIndex; i <= n; i++) {

		path.push_back(i);
		
		f(i+ 1);
		path.pop_back();
	}
}

bool cmp_instable(vector<int> l, vector<int> r) {
	return l.size() < r.size();
}
bool cmp(vector<int> l, vector<int> r) {
	if (l.size() != r.size()) {
		return l.size() < r.size();
	}
	else {
		return l < r;
	}
		
}

vector<vector<int>> vec;
map<int, int> mp;
vector<int> solution3_res;
void find_subCollection3(int index) {

	if (index == n + 1) {
		for (int i = 0; i < n; i++) {
			printf("%d", res[i]);
			printf(i == n - 1 ? "\n" : " ");
		}
	}

	for (map<int, int> ::iterator it = mp.begin(); it != mp.end(); it++) {
		printf("%d %d\n", it->first, it->second);
		if (it->second > 0) {
			solution3_res.push_back(it->first);
			mp[it->first]--;

			find_subCollection3(index + 1);
			solution3_res.pop_back();
			mp[it->first]++;
		}
	}
}
int main() {

	scanf("%d", &n);

	f(1);

	printf("-----------≈≈–Ú«∞----------");

	sort(res.begin(), res.end(), cmp_instable);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
}