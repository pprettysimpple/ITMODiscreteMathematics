//
// Created by kirill on 28.10.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

int **g;
int *size;
int *used;

void add_edge(int a, int b) {
    for (int i = 0; i < size[a]; i++) {
        if (g[a][i] == b) return;
    }
    g[a][size[a]++] = b;
}

bool find(int u, int v) {
    if (used[u]) return 0;
    if (u == v) return 1;
    used[u] = 1;
    for (int i = 0; i < size[u]; i++) {
        if (find(g[u][i], v)) return 1;
    }
    return 0;
}

signed main() {
    int n, m; scanf("%d%d", &n, &m);
    g = malloc(2 * n * sizeof(int*));
    size = malloc(2 * n * sizeof(int));
    used = malloc(2 * n * sizeof(int));
    memset(used, 0, 2 * n * sizeof(int));
    memset(size, 0, 2 * n * sizeof(int));

    for (int i = 0; i < 2 * n; i++)
        g[i] = malloc(2 * n * sizeof(int));

    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        if (a < 0) a = -a + n;
        if (b < 0) b = -b + n;
        --a, --b;
        add_edge((a + n) % (2 * n), b);
        add_edge((b + n) % (2 * n), a);
    }

    for (int i = 0; i < n; i++) {
        int f1 = find(i, i + n);
        memset(used, 0, 2 * n * sizeof(int));
        int f2 = find(i + n, i);
        memset(used, 0, 2 * n * sizeof(int));
        if (f1 && f2) {
            printf("YES\n");
            return 0;
        }
    }

    for (int i = 0; i < 2 * n; i++) free(g[i]);

    free(g);
    free(used);
    free(size);

    printf("NO\n");

    return 0;
}