#ifndef SRC_HPP
#define SRC_HPP

#include <algorithm>
#include <cstdlib>

void Init(int **&p, int n) {
    p = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; ++i) {
        p[i] = nullptr;
    }
}

void Add_element(int **&p, int x, int y) {
    if (p[x] == nullptr) {
        p[x] = (int *)malloc(3 * sizeof(int));
        p[x][0] = 1; // size
        p[x][1] = 1; // capacity
        p[x][2] = y;
    } else {
        if (p[x][0] == p[x][1]) {
            p[x][1] *= 2;
            p[x] = (int *)realloc(p[x], (p[x][1] + 2) * sizeof(int));
        }
        p[x][p[x][0] + 2] = y;
        p[x][0]++;
    }
}

int Get_element(int **&p, int x, int k) {
    return p[x][k + 1];
}

void Clear(int **&p, int n) {
    for (int i = 1; i <= n; ++i) {
        if (p[i] != nullptr) {
            free(p[i]);
        }
    }
    free(p);
    p = nullptr;
}

#endif
