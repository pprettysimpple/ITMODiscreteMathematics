#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

typedef long long ull;

signed main() {
    int n;
    scanf("%d", &n);
    ull *arr = malloc(n * sizeof(ull));
    for (int i = 0; i < n; ++i) {
        scanf("%lld", arr + i);
    }
    ull s;
    scanf("%lld", &s);
    ull ans = 0;
    ull *code = malloc(32 * sizeof(ull));
    memset(code, 0, 32 * sizeof(ull));
    for (ull i = 0; i < 32; i++) {
        if (!((s >> i) & 1LL)) continue;
        ull cur = -(1LL);
        for (ull j = 0; j < n; j++) {
            if ((arr[j] >> i) & 1LL) {
                cur &= arr[j];
            } else {
                cur &= ~arr[j];
                code[i] += (1LL << j);
            }
        }
        ans |= cur;
    }
    if (s == 0) {
        printf("1&~1");
        return 0;
    }
    if (ans != s) {
        printf("Impossible");
        return 0;
    }
    bool is_first = 1;
    for (ull i = 0; i < 32; i++) {
        if (!((s >> i) & 1LL)) continue;
        if (!is_first) putchar('|');
        is_first = 0;
        for (ull j = 0; j < n; j++) {
            if ((code[i] >> j) & 1LL) putchar('~');
            printf("%lld", j + 1LL);
            if (j + 1LL != n) putchar('&');
        }
    }
    return 0;
}