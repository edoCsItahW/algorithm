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
 * @date 2026/03/24 15:54
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include <bits/stdc++.h>

namespace algo::bfs {

    inline constexpr auto dx = std::array{-1, 1, -0, 0};

    inline constexpr auto dy = std::array{0, 0, -1, 1};

    /**
     * @brief 适用于网格（二维矩阵）求最短步数的BFS算法模板
     * @param grid 字符矩阵，'#'表示障碍物，
     * @param start
     * @param target
     * @return 返回从start到target的最短步数，不可达返回-1
     */
    int gridBfs(const std::vector<std::string>& grid, std::pair<int, int> start, std::pair<int, int> target) {
        int n = grid.size(), m = grid[0].size();

        std::vector dist(n, std::vector(m, -1));
        std::queue<std::pair<int, int>> q;
        dist[start.first][start.second] = 0;

        q.push(start);

        while (!q.empty()) {
            auto [x, y] = q.front();
            if (std::make_pair(x, y) == target) return dist[x][y];

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }

        return -1;
    }

    /**
     * @brief 适用于图版本的BFS算法模板
     * @param start
     * @param adj 邻接表（0-based顶点）
     * @return dist数组，
     */
    std::vector<int> grapheBfs(int start, const std::vector<std::vector<int>>& adj) {
        std::vector dist(adj.size(), -1);
        std::queue<int> q;
        dist[start] = 0;

        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
        }

        return dist;
    }

}  // namespace algo::bfs
