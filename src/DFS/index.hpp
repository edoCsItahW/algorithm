// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file index.hpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/09 18:18
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_INDEX_HPP
#define ALGORITHM_INDEX_HPP
#pragma once

/**
 * @dir 深度优先搜索
 * @brief 深度优先搜索思想及其实现
 */

/**
 * @mainpage 深度优先搜索
 * @showdate "%Y-%m-%d %H:%M:%S" 2026-03-09 21:15:00
 *
 * @tableofcontents{nested:2}
 *
 * @section intro 介绍
 *
 * 深度优先搜索（Depth-First Search, DFS）是一种用于遍历或搜索树或图的算法。
 * 其基本思想是从起始节点出发，沿着一条路径尽可能深入地探索，直到无法继续为止，然后回溯到上一个节点，继续探索其他分支。
 * DFS 是许多图算法的基础，如拓扑排序、连通分量检测、寻找桥和割点等。
 *
 * @section principle 算法原理
 *
 * DFS 遵循“不撞南墙不回头”的原则：
 * - 从一个未访问的节点开始，标记为已访问。
 * - 递归地访问其所有未被访问的邻接节点。
 * - 如果当前节点的所有邻接节点都已访问，则回溯到上一个节点。
 *
 * 实现上，DFS 可以使用递归或显式栈（非递归）来完成。递归方式简洁明了，但可能造成栈溢出（当图深度极大时）；非递归方式使用栈模拟递归，可避免此问题。
 *
 * @section step 算法步骤
 *
 * ### 递归版本
 * 1. 选择一个起始节点 `u`，标记 `visited[u] = true`。
 * 2. 对于 `u` 的每个邻接节点 `v`：
 *    - 如果 `v` 未被访问，则递归调用 DFS(v)。
 * 3. 当所有邻接节点都被处理后，返回上一层。
 *
 * ### 非递归版本（使用栈）
 * 1. 将起始节点压入栈中，并标记为已访问（可在入栈时标记）。
 * 2. 当栈非空时：
 *    - 弹出栈顶节点 `u`，访问（处理）该节点。
 *    - 对于 `u` 的每个邻接节点 `v`，若 `v` 未被访问，则将 `v` 压入栈，并标记为已访问。
 *
 * 注意：非递归版本中，为了模拟递归的访问顺序，压栈顺序通常与递归相反（例如，反向遍历邻接表），但这不影响遍历结果（只是顺序可能不同）。
 *
 * @section example 示例
 *
 * 考虑以下无向图（邻接表表示）：
 * ```
 * 0: 1, 2
 * 1: 0, 3, 4
 * 2: 0, 5
 * 3: 1
 * 4: 1, 5
 * 5: 2, 4
 * ```
 * 从节点 0 开始 DFS（按邻接表顺序）：
 * ```
 * 访问 0 → 递归访问 1 → 访问 1 → 递归访问 3 → 访问 3（回溯到 1）→ 递归访问 4 → 访问 4 → 递归访问 5 → 访问 5（回溯）... 最终访问顺序: 0,1,3,4,5,2
 * ```
 * 若采用非递归（栈）实现，顺序可能不同，但都能正确遍历所有节点。
 *
 * @section complexity 复杂度分析
 *
 * - 时间复杂度：O(V + E)，其中 V 是顶点数，E 是边数。每个节点和每条边都被访问一次。
 * - 空间复杂度：O(V)，递归栈（或显式栈）最坏情况下可能达到 V 的深度（如一条链）。
 *
 * @section implementation 代码实现
 *
 * 下面给出基于邻接表的 DFS 实现，包含递归版本和非递归版本。同时提供一个简单的图结构封装。
 *
 * @see Graph, dfsRecursive(), dfsIterative()
 *
 * @section pros_and_cons 优缺点
 *
 * 优点:
 * - 实现简单，特别是递归版本。
 * - 在树或图中，天然适合解决连通性、路径存在性问题。
 * - 可以方便地记录访问路径，用于回溯类问题（如八皇后、数独）。
 *
 * 缺点:
 * - 递归版本在深度过大时可能导致栈溢出。
 * - 对于大型图，递归开销较大，且不易优化。
 * - 与 BFS 相比，DFS 找到的路径不一定是最短路径。
 *
 * @section application 应用
 *
 * - 图的连通分量检测。
 * - 拓扑排序（结合后序时间戳）。
 * - 检测图中是否存在环。
 * - 回溯算法：全排列、组合、子集、N皇后、数独求解等。
 * - 树的遍历（前序、中序、后序）。
 * - 迷宫寻路、岛屿数量等网格问题。
 *
 * @section extension 扩展
 *
 * DFS 的时间戳（发现时间和完成时间）是图论中许多高级算法的基础，如 Tarjan 算法求强连通分量、割点和桥。
 * 在树中，DFS 可以结合剪枝技术解决许多优化问题（如分支限界）。
 */

#include <functional>
#include <iostream>
#include <stack>
#include <vector>

/**
 * @brief 简单的图类（邻接表表示）
 *
 * @tparam N 顶点数量（固定大小）
 */
template<std::size_t N>
class Graph {
public:
    using AdjList = std::vector<int>;  // 邻接表类型（每个节点存储相邻节点索引）

    /**
     * @brief 添加一条无向边
     * @param u 起点
     * @param v 终点
     */
    void addEdge(int u, int v) {
        adj_[u].push_back(v);
        adj_[v].push_back(u);  // 无向图
    }

    /**
     * @brief 获取邻接表（只读）
     */
    const std::array<AdjList, N>& adjacency() const { return adj_; }

private:
    std::array<AdjList, N> adj_;  // 邻接表数组
};

/**
 * @brief 深度优先搜索（递归版本）
 *
 * @tparam N 顶点数量
 * @param graph 图对象
 * @param start 起始节点索引
 * @param visitor 访问节点时的回调函数（可选）
 * @return std::vector<int> 访问顺序
 */
template<std::size_t N>
std::vector<int> dfsRecursive(const Graph<N>& graph, int start, std::function<void(int)> visitor = nullptr) {
    std::vector<int> visitedOrder;
    std::array<bool, N> visited{};

    std::function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        visitedOrder.push_back(u);
        if (visitor) visitor(u);
        for (int v : graph.adjacency()[u])
            if (!visited[v]) dfs(v);
    };

    dfs(start);
    // 如果图不连通，可以遍历所有节点
    for (int i = 0; i < N; ++i)
        if (!visited[i]) dfs(i);
    return visitedOrder;
}

/**
 * @brief 深度优先搜索（非递归版本，使用栈）
 *
 * @tparam N 顶点数量
 * @param graph 图对象
 * @param start 起始节点索引
 * @param visitor 访问节点时的回调函数（可选）
 * @return std::vector<int> 访问顺序
 */
template<std::size_t N>
std::vector<int> dfsIterative(const Graph<N>& graph, int start, std::function<void(int)> visitor = nullptr) {
    std::vector<int> visitedOrder;
    std::array<bool, N> visited{};
    std::stack<int> stk;

    stk.push(start);
    visited[start] = true;

    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        visitedOrder.push_back(u);
        if (visitor) visitor(u);

        // 为了模拟递归的顺序，可以反向压入邻接点，这样先访问邻接表中的第一个节点
        const auto& neighbors = graph.adjacency()[u];
        for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
            int v = *it;
            if (!visited[v]) {
                visited[v] = true;
                stk.push(v);
            }
        }
    }

    // 如果图不连通，处理剩余未访问节点
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            stk.push(i);
            visited[i] = true;
            while (!stk.empty()) {
                int u = stk.top();
                stk.pop();
                visitedOrder.push_back(u);
                if (visitor) visitor(u);
                for (auto it = graph.adjacency()[u].rbegin(); it != graph.adjacency()[u].rend(); ++it) {
                    int v = *it;
                    if (!visited[v]) {
                        visited[v] = true;
                        stk.push(v);
                    }
                }
            }
        }
    }

    return visitedOrder;
}

#endif  // ALGORITHM_INDEX_HPP
