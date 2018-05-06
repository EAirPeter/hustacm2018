#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	double r, g, h, i, t, a, b;
	scanf("%lf%lf%lf%lf%lf%lf%lf", &r, &g, &h, &i, &t, &a, &b);
	bool k = false;
	for (;;) {
		auto d = sqrt(i / t);
		auto e = hypot(a, b - r);
		if (fabs(d - e) < 1e-8) {
			printf("%.8f\n", k ? 0.0 : a);
			return 0;
		}
		k = true;
		auto lgh = hypot(g, h);
		auto dot = a * g + (b - r) * h;
		auto cos = dot / (e * lgh);
		auto f = (e * e - d * d) / (e * 2 * cos - d * 2);
		auto x = f * g / sqrt(g * g + h * h);
		auto y = r + f * h / sqrt(g * g + h * h);
		if ((int) y == (int) b) {
			printf("%.16f\n", x);
			break;
		}
		b = ceil(b) * 2.0 - b;
	}
	return 0;
}
