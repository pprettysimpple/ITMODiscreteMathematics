//
// Created by kirill on 29.10.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

signed main() {
    int n, k; scanf("%d%d", &n, &k);

    int **arr = malloc(k * sizeof(int*));
    int *sz = malloc(k * sizeof(int*));

    int *vals = malloc(n * sizeof(int));
    memset(vals, -1, n * sizeof(int));

    for (int i = 0; i < k; i++) {
        sz[i] = 0;
        arr[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            int x; scanf("%d", &x);
            if (x >= 0) {
                if (x > 0) arr[i][sz[i]++] = j;
                else arr[i][sz[i]++] = j + n;
            }
        }
    }

    for (int step = 0; step < k; step++) {
        for (int i = 0; i < k; i++) {
            int cur_val = 0;
            int pos = -1;
            int cnt = 0;
            for (int j = 0; j < sz[i]; j++) {
                if (vals[arr[i][j] % n] == -1) {
                    cnt++;
                    pos = arr[i][j];
                    continue;
                }
                cur_val |= ((arr[i][j] < n) == vals[arr[i][j] % n]);
            }
            if (cur_val) continue;
            if (cnt == 1) {
                vals[pos % n] = (pos < n);
            }
            if (!cnt) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
}