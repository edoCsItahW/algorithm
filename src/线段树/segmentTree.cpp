// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file segmentTree.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/24 22:08
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include "segmentTree/index.hpp"
#include <functional>
#include <iostream>

namespace algo::segmentTree {

    void case1() {
        int n /* 序列长度 */, m /* 操作次数 */;
        std::cin >> n >> m;

        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) std::cin >> arr[n];

        std::vector<int> tree, lazy;

        const std::function<void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                tree[node] = arr[l];
                return;
            }

            int mid = (l + r) / 2;

            build(node * 2, 1, mid);
            build(node * 2 + 1, mid + 1, r);

            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        };

        const auto push = [&](int node, int l, int r) {
            if (lazy[node] != 0) {
                int mid = (l + r) / 2;

                tree[node * 2] += lazy[node] * (mid - l + 1);
                tree[node * 2 + 1] += lazy[node] * (r - mid);
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
                lazy[node] = 0;
            }
        };

        for (int i = 0, o, l, r; i < m; ++i) {
            std::cin >> o >> l >> r;

            // switch (o) {
            //     case 1: int x; std::cin >> x;
            //
            //
            //     case 2:
            //
            //     default:
            // }
        }
    }

}  // namespace algo::segmentTree
