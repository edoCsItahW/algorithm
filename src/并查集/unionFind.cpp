// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file unionFind.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/24 21:09
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include "unionFind/index.hpp"
#include <iostream>
#include <vector>
#include <numeric>


namespace algo::unionFind {

    void case1() {
        int n /* 计算机的数量 */, m /* 操作的数量 */;
        std::cin >> n >> m;

        std::vector parent(n + 1, 0);
        std::vector rank(n + 1, 0);
        std::iota(parent.begin(), parent.end(), 0);

        const auto find = [&](int idx) {
            while (idx != parent[idx]) {
                parent[idx] = parent[parent[idx]];
                idx = parent[idx];
            }

            return idx;
        };

        const auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);

            if (ra == rb) return;

            if (rank[ra] < rank[rb])
                parent[ra] = rb;
            else if (rank[ra] > rank[rb])
                parent[rb] = ra;
            else {
                parent[rb] = ra;
                rank[ra]++;
            }
        };

        for (int i = 0, o /* 操作类型 */, u /* 计算机 */, v /* 计算机 */; i < m; ++i) {
            std::cin >> o >> u >> v;

            switch (o) {
                case 1:
                    unite(u, v);
                    break;
                case 2:
                    std::cout << (find(u) == find(v) ? "Yes" : "No") << std::endl;
                    break;
                default:
                    std::cerr << "error operator parsing";
            }
        }
    }

    void case2() {

    }

}  // namespace algo::unionFind
