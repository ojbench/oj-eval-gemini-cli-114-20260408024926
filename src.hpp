#ifndef SRC_HPP
#define SRC_HPP

#include<algorithm>

void Init(int **&p,int n){//初始化，n为vector的个数,传入的p指向nullptr
    p = new int*[n + 1];
    for (int i = 1; i <= n; ++i) {
        p[i] = nullptr;
    }
}

void Add_element(int **&p,int x,int y){//在第x(1base)个vector后面添加一个元素y
    if (p[x] == nullptr) {
        p[x] = new int[3];
        p[x][0] = 1; // size
        p[x][1] = 1; // capacity
        p[x][2] = y;
    } else {
        if (p[x][0] == p[x][1]) {
            int *new_arr = new int[p[x][1] * 2 + 2];
            new_arr[0] = p[x][0];
            new_arr[1] = p[x][1] * 2;
            for (int i = 0; i < p[x][0]; ++i) {
                new_arr[i + 2] = p[x][i + 2];
            }
            delete[] p[x];
            p[x] = new_arr;
        }
        p[x][p[x][0] + 2] = y;
        p[x][0]++;
    }
}

int Get_element(int **&p,int x,int k){//获取第x(1base)个vector中第k个(1-base)元素的值
    return p[x][k + 1];
}

void Clear(int **&p,int n){//回收空间
    for (int i = 1; i <= n; ++i) {
        if (p[i] != nullptr) {
            delete[] p[i];
        }
    }
    delete[] p;
    p = nullptr;
}

#endif
