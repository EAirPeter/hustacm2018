#include <cstdio>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	auto d = exgcd(b, a % b, y, x);
	y -= x * (a / b);
	return d;
}

int N, M;
long long A[100000];
long long B[100000];
long long C[100000];

int main() {
	scanf("%d%d", &N, &M);
	for (auto i = 0; i < N; ++i)
		scanf("%lld", &A[i]);
	auto d = exgcd(A[0], A[1], C[0], B[1]);
	for (auto i = 2; i < N; ++i)
		d = exgcd(d, A[i], C[i - 1], B[i]);
	for (auto i = N - 2; i > 0; --i) {
		B[i] *= C[i];
		C[i - 1] *= C[i];
	}
	B[0] = C[0];
	while (M--) {
		long long x;
		scanf("%lld", &x);
		if (x % d)
			printf("NO\n");
		else {
			auto e = x / d;
			for (auto i = 0; i < N; ++i)
				printf("%lld%c", B[i] * e, " \n"[i == N - 1]);
		}
	}
	return 0;
}
