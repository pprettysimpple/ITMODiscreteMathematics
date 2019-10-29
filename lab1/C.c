//
// Created by kirill on 28.10.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include <stdatomic.h>

bool is_linear(int *a, int n) {
    int *z = malloc((1 << n) * sizeof(int));
    for (int i = 0; i < (1 << n); ++i) {
        int cur = 0;
        for (int j = i; j >= 0; j = (i & (j - 1))) {
            cur ^= a[j];
            if (!j) break;
        }
        z[i] = cur;
        if (z[i] && (i & (i - 1))) {
            free(z);
            return 0;
        }

    }
    free(z);
    return 1;
}

bool saves_zero(int *a, int n) {
    return !a[0];
}

bool saves_one(int *a, int n) {
    return a[(1 << n) - 1];
}

bool is_monotonic(int *a, int n) {
    for (int i = 0; i < (1 << n); i++) {
        for (int j = i; j >= 0; j = (i & (j - 1))) {
            if (a[i] < a[j]) return 0;
            if (!j) break;
        }
    }
    return 1;
}

bool is_self_dual(int *a, int n) {
    for (int i = 0; i < (1 << n); i++) {
        if (a[i] == a[((1 << n) - i - 1)]) {
            return 0;
        }
    }
    return 1;
}

signed main() {
    int n; scanf("%d", &n);
    int *cnt = malloc(5 * sizeof(int));
    memset(cnt, 0,5 * sizeof(int));

    for (int i = 0; i < n; i++) {
        int m; scanf("%d%*c", &m);
        int *a = malloc((1 << m) * sizeof(int));
        for (int j = 0; j < (1 << m); j++) {
            char c;
            scanf("%c", &c);
            a[j] = (int)c - '0';
        }
        scanf("%*c");

        if (!cnt[0] && !saves_one(a, m)) cnt[0]++;
        if (!cnt[1] && !saves_zero(a, m)) cnt[1]++;
        if (!cnt[2] && !is_monotonic(a, m)) cnt[2]++;
        if (!cnt[3] && !is_self_dual(a, m)) cnt[3]++;
        if (!cnt[4] && !is_linear(a, m)) cnt[4]++;
        free(a);
    }

    if (!cnt[0] || !cnt[1] || !cnt[2] || !cnt[3] || !cnt[4]) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    free(cnt);
    return 0;
}