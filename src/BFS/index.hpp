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
 * @date 2026/03/09 18:21
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_INDEX_HPP
#define ALGORITHM_INDEX_HPP
#pragma once

/**
 * @dir 广度优先搜索
 * @brief 广度优先搜索思想及其实现
 */

/**
 * @mainpage 广度优先搜索
 * @showdate "%Y-%m-%d %H:%M:%S" 2026-03-09 22:00:00
 *
 * @tableofcontents{nested:2}
 *
 * @section intro 介绍
 *
 * 广度优先搜索（Breadth-First Search, BFS）是一种用于遍历或搜索树或图的算法。
 * 其基本思想是从起始节点出发，逐层向外扩展，先访问离起始节点最近的节点，再访问更远的节点。
 * BFS 是许多图算法的基础，如最短路径（无权图）、连通分量检测、二分图判定等。
 *
 * @section principle 算法原理
 *
 * BFS 遵循“层层推进”的原则：
 * - 从一个未访问的节点开始，将其放入队列并标记为已访问。
 * - 从队列中取出一个节点，访问该节点，并将其所有未被访问的邻接节点放入队列（并标记为已访问）。
 * - 重复上述过程，直到队列为空。
 *
 * 由于队列的先进先出特性，BFS 保证每个节点被访问时，都是按照距离起始节点的层数顺序进行的。
 *
 * @section step 算法步骤
 *
 * 1. 初始化队列，将起始节点 `s` 入队，标记 `visited[s] = true`。
 * 2. 当队列非空时：
 *    - 出队一个节点 `u`，访问（处理）该节点。
 *    - 对于 `u` 的每个邻接节点 `v`：
 *      - 如果 `v` 未被访问，则将 `v` 入队，并标记 `visited[v] = true`。
 * 3. 若图不连通，可继续对未访问节点执行上述过程。
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
 * 从节点 0 开始 BFS（按邻接表顺序）：
 * ```
 * 队列初始: [0]
 * 出队0, 访问0 → 邻接1,2入队 → 队列 [1,2]
 * 出队1, 访问1 → 邻接0(已访问),3,4入队 → 队列 [2,3,4]
 * 出队2, 访问2 → 邻接0(已访问),5入队 → 队列 [3,4,5]
 * 出队3, 访问3 → 邻接1(已访问) → 队列 [4,5]
 * 出队4, 访问4 → 邻接1(已访问),5(已在队中或未访问？通常已入队但未访问，为避免重复入队，我们在入队时标记已访问，故5已被标记) → 队列 [5]
 * 出队5, 访问5 → 邻接2(已访问),4(已访问) → 队列空
 * 最终访问顺序: 0,1,2,3,4,5 (按层顺序: 第0层:0; 第1层:1,2; 第2层:3,4,5)
 * ```
 *
 * @section complexity 复杂度分析
 *
 * - 时间复杂度：O(V + E)，其中 V 是顶点数，E 是边数。每个节点和每条边都被访问一次。
 * - 空间复杂度：O(V)，队列中最多存储一层的节点，最坏情况下可能存储所有节点。
 *
 * @section implementation 代码实现
 *
 * 下面给出基于邻接表的 BFS 实现，同时提供一个简单的图结构封装。
 *
 * @see Graph, bfs()
 *
 * @section pros_and_cons 优缺点
 *
 * 优点:
 * - 在无权图中可以找到最短路径（以边数计）。
 * - 实现简单，使用队列即可。
 * - 逐层遍历的特性适用于许多问题（如拓扑排序的 Kahn 算法、二分图判定）。
 *
 * 缺点:
 * - 空间消耗可能较大（特别是图的分支因子很大时）。
 * - 与 DFS 相比，不适合深度很大的路径搜索（但适合找最短路径）。
 *
 * @section application 应用
 *
 * - 无权图的最短路径（如迷宫问题）。
 * - 连通分量检测。
 * - 二分图判定。
 * - 拓扑排序（Kahn 算法）。
 * - 网络流中的 Edmonds-Karp 算法（寻找增广路）。
 * - 社交网络中的“六度分隔”问题。
 *
 * @section extension 扩展
 *
 * BFS 可以用于求解一些最优性问题，如“最少步数”、“最短变换路径”。在树中，BFS 即为层序遍历。
 * BFS 的时间戳（距离数组）可用于计算节点之间的层次关系。
 */

#include <array>
#include <functional>
#include <queue>
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
 * @brief 广度优先搜索
 *
 * @tparam N 顶点数量
 * @param graph 图对象
 * @param start 起始节点索引
 * @param visitor 访问节点时的回调函数（可选）
 * @return std::vector<int> 访问顺序
 */
template<std::size_t N>
std::vector<int> bfs(const Graph<N>& graph, int start, std::function<void(int)> visitor = nullptr) {
    std::vector<int> visitedOrder;
    std::array<bool, N> visited{};
    std::queue<int> q;

    // 从起始节点开始
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visitedOrder.push_back(u);
        if (visitor) visitor(u);

        for (int v : graph.adjacency()[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // 如果图不连通，继续访问剩余未访问节点
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                visitedOrder.push_back(u);
                if (visitor) visitor(u);
                for (int v : graph.adjacency()[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    return visitedOrder;
}

/**
 * @brief 广度优先搜索，同时计算最短距离（无权图）
 *
 * @tparam N 顶点数量
 * @param graph 图对象
 * @param start 起始节点索引
 * @return std::pair<std::vector<int>, std::vector<int>> 第一个 vector 为访问顺序，第二个 vector 为距离数组（-1 表示不可达）
 */
template<std::size_t N>
std::pair<std::vector<int>, std::vector<int>> bfsWithDistance(const Graph<N>& graph, int start) {
    std::vector<int> visitedOrder;
    std::array<bool, N> visited{};
    std::vector dist(N, -1);
    std::queue<int> q;

    visited[start] = true;
    dist[start]    = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visitedOrder.push_back(u);

        for (int v : graph.adjacency()[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v]    = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // 剩余未连通节点已经不可达，距离保持 -1
    return {visitedOrder, dist};
}

#endif  // ALGORITHM_INDEX_HPP
