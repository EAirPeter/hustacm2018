#include <cstdio>
#include <utility>

using namespace std;

int N, M;
int U[100001];
int V[100001];
int Z[100001];

int ufs(int p) {
	if (p == U[p])
		return p;
	auto u = ufs(U[p]);
	V[p] ^= V[U[p]];
	U[p] = u;
	return u;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i <= N; ++i) {
		U[i] = i;
		Z[i] = 1;
	}
	bool f = false;
	for (int i = 1; i <= M; ++i) {
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		--a;
		auto ra = ufs(a);
		auto rb = ufs(b);
		if (ra == rb) {
			if ((V[a] ^ V[b]) != k) {
				printf("%d\n", i);
				f = true;
			}
			continue;
		}
		if (Z[ra] > Z[rb]) {
			swap(a, b);
			swap(ra, rb);
		}
		U[ra] = rb;
		Z[rb] += Z[ra];
		V[ra] = k ^ V[a] ^ V[b];
	}
	if (!f)
		printf("-1\n");
	return 0;
}
