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
 * @date 2026/03/24 16:47
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include <bits/stdc++.h>

namespace algo::dfs {

    void grpahDfs() {
        std::vector<std::vector<int>> graph;
        std::vector<bool> visited;

        const std::function<void(int)> dfs = [&](int u) {
            visited[u] = true;  // 标记已访问

            // 在这里处理节点 u，例如输出、记录等

            for (int v : graph[u])  // 遍历邻接点
                if (!visited[v]) dfs(v);
        };
    }

    void backtrackDfs() {
        std::vector<int> path;
        std::vector<bool> used;

        const std::function<void(int, int)> dfs = [&](int step, int n) {
            if (step == n) {  // 达到目标深度
                // 输出或处理当前解 path
                return;
            }

            for (int i = 0; i < n; ++i) {
                if (!used[i]) {  // 剪枝条件可根据题目修改
                    used[i] = true;
                    path.push_back(i);
                    dfs(step + 1, n);
                    path.pop_back();  // 回溯恢复
                    used[i] = false;
                }
            }

        };
    }

}  // namespace algo::dfs
