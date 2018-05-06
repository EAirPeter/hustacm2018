#include <cstdio>
#include <cstring>

using namespace std;

int N;
long long M;
long long F[101][10001];

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		memset(F, 0x3f, sizeof(F));
		F[0][0] = 0;
		scanf("%d%lld", &N, &M);
		for (auto i = 1; i <= N; ++i) {
			long long c;
			int v;
			scanf("%lld%d", &c, &v);
			for (auto j = 0; j <= 10000 - v; ++j) {
				if (F[i - 1][j] < F[i][j])
					F[i][j] = F[i - 1][j];
				if (F[i - 1][j] + c < F[i][j + v])
					F[i][j + v] = F[i - 1][j] + c;
			}
		}
		for (auto i = 10000; i >= 0; --i)
			if (F[N][i] <= M) {
				printf("%d\n", i);
				break;
			}
	}
	return 0;
}
