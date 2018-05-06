#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
int D[24];
char S[25];

int dfs(int h, int c, int t, int u) {
	if (h == N)
		return u ? 0x3f3f3f3f : c;
	int s = D[h] & ~t;
	if (!s)
		return u ? 0x3f3f3f3f : dfs(h + 1, c, 0, 0);
	int ans = 0x3f3f3f3f;
	if (!u)
		ans = min(ans, dfs(h + 1, c, 0, D[h]));
	for (int ss = s; ss; ss = (ss - 1) & s) {
		if ((ss & u) == u) {
			bool flag = true;
			for (int i = 0; flag && i < M - 1; ++i)
				if (((3 << i) & ss) == (3 << i))
					flag = false;
			if (flag) {
				int cc = 0;
				for (int tt = ss; tt; ++cc) {
					int uu = tt & -tt;
					tt ^= uu;
				}
				ans = min(ans, dfs(h + 1, c + cc, ss, D[h] & ~(ss | ss << 1 | ss >> 1 | t)));
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%s", S);
		for (int j = 0; j < M; ++j)
			D[i] |= (S[j] == '#' ? 1 : 0) << j;
	}
	printf("%d\n", dfs(0, 0, 0, 0));
	return 0;
}
