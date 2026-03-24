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
 * @date 2026/03/24 18:13
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include <bits/stdc++.h>

namespace algo::dijkstra {

    using ll = long long;

    inline constexpr auto INF = std::numeric_limits<ll>::max();

    std::vector<ll> dijkstra(const std::vector<std::vector<std::pair<ll, ll>>>& graph, int start) {
        int n = graph.size();
        std::vector dist(n, INF);
        dist[start] = 0;
        std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<>> pq;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;  // 跳过过时的记录

            for (auto [v, w] : graph[u])
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
        }

        return dist;
    }

}  // namespace algo::dijkstra
