// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file template.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/24 21:54
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include <bits/stdc++.h>

namespace algo::unionFind {

    struct DSU {
        std::vector<int> p, sz;

        DSU(int n)
            : p(n)
            , sz(n, 1) {
            std::iota(p.begin(), p.end(), 0);
        }

        int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

        bool unite(int a, int b) {
            a = find(a), b = find(b);

            if (a == b) return false;

            if (sz[a] < sz[b]) std::swap(a, b);

            p[b] = a;
            sz[a] += sz[b];

            return true;
        }

        bool same(int a, int b) { return find(a) == find(b); }

        int size(int x) { return sz[find(x)]; }
    };

}  // namespace algo::unionFind
