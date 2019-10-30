//
// Created by kirill on 29.10.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

signed main() {
    int n; scanf("%d", &n);

    int **in = malloc(n * sizeof(int*));
    int **in_vals = malloc(n * sizeof(int*));
    int *vals = malloc(n * sizeof(int));
    int *sz = malloc(n * sizeof(int));
    int *deph = malloc(n * sizeof(int));

    memset(vals, 0, n * sizeof(int));
    memset(sz, 0, n * sizeof(int));
    memset(deph, 0, n * sizeof(int));

    int k = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", sz + i);
        if (!sz[i]) {
            sz[i] = -(k++);
            continue;
        }

        in[i] = malloc(sz[i] * sizeof(int));
        in_vals[i] = malloc((1 << sz[i]) * sizeof(int));
        for (int j = 0; j < sz[i]; j++) {
            scanf("%d", in[i] + j);
            in[i][j]--;
        }
        for (int j = 0; j < (1 << sz[i]); j++) {
            scanf("%d", in_vals[i] + j);
        }
    }
    int *ans = malloc((1 << k) * sizeof(int));
    for (int mask = 0; mask < (1 << k); mask++) {
        memset(vals, 0, n * sizeof(int));
        int cur_mask = 0;
        for (int i = 0; i < k; i++) {
            cur_mask |= (((mask >> i) & 1) << (k - 1 - i));
        }
        for (int u = 0; u < n; u++) {
            if (sz[u] <= 0) {
                vals[u] = ((cur_mask >> (-sz[u])) & 1);
                continue;
            }
            int res = 0;
            for (int j = 0; j < sz[u]; j++) {
                int v = in[u][j];
                deph[u] = max(deph[u], deph[v] + 1);
                res |= (vals[v] << (sz[u] - j - 1));
            }
            vals[u] = in_vals[u][res];
        }
        ans[mask] = vals[n - 1];
    }

    printf("%d\n", deph[n - 1]);

    for (int i = 0; i < (1 << k); i++) {
        printf("%d", ans[i]);
    }

    return 0;
}