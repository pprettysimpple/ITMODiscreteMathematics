//
// Created by kirill on 28.10.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

int* get_z(int *a, int n) {
    int *z = malloc((1 << n) * sizeof(int));
    memset(z, 0, (1 << n) * sizeof(int));
    for (int i = 0; i < (1 << n); ++i) {
        int cur = 0;
        for (int j = i; j >= 0; j = (i & (j - 1))) {
            cur ^= a[j];
            if (!j) break;
        }
        z[i] = cur;
    }
    return z;
}

signed main() {
    int n; scanf("%d", &n);
    int *a = malloc((1 << n) * sizeof(int));

    for (int i = 0; i < (1 << n); ++i) scanf("%*d%d", a + i);

    int *z = get_z(a, n);

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = n - 1; j >= 0; --j) {
            printf("%d", ((i >> j) & 1));
        }
        printf(" %d\n", z[i]);
    }
    return 0;
}