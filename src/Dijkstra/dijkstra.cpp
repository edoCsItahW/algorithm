// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file dijkstra.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/23 12:45
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include "dijkstra/index.hpp"
#include <iostream>
#include <limits>
#include <queue>
#include <vector>


namespace algo::dijkstra {

    inline constexpr auto INF = std::numeric_limits<int>::max();

    void case1() {
        int n /* 点数 */, m /* 边数 */, s /* 起点编号 */, t /* 终点编号 */;
        std::cin >> n >> m >> s >> t;

        using Node   = int;
        using Widght = int;

        std::vector graph(n, std::vector<std::pair<Node, Widght>>{});

        for (int i = 0, u, v, w; i < m; ++i) {
            std::cin >> u >> v >> w;
            graph[u - 1].emplace_back(v - 1, w);
            graph[v - 1].emplace_back(u - 1, w);
        }

        std::vector dist(n, INF);
        dist[s - 1] = 0;

        std::priority_queue<std::pair<Widght, Node>, std::vector<std::pair<Widght, Node>>, std::greater<>> queue;

        queue.emplace(dist[s - 1], s - 1);

        while (!queue.empty()) {
            const auto [d /* 源邻最短距离（优队） */, i /* 邻点索引 */] = queue.top();
            queue.pop();

            if (d != dist[i]) continue;

            for (const auto& [u /* 末点索引 */, w /* 邻末距离 */] : graph[i])
                if (auto& v = dist[u]; v > d + w) {
                    v = d + w;
                    queue.emplace(v, u);
                }
        }

        std::cout << (dist[t - 1] == INF ? -1 : dist[t - 1]);
    }

}  // namespace algo::dijkstra
