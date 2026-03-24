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
 * @date 2026/03/10 16:29
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_INDEX_HPP
#define ALGORITHM_INDEX_HPP
#pragma once

/**
 * @dir Dijkstra算法
 * @brief 单源最短路径算法（非负权边）
 */

/**
 * @mainpage Dijkstra算法
 * @showdate "%Y-%m-%d %H:%M:%S" 2026-03-10 10:15:00
 *
 * @tableofcontents{nested:2}
 *
 * @section intro 介绍
 *
 * Dijkstra算法是一种用于求解**带权有向图（或无向图）中单源最短路径**的经典算法，由荷兰计算机科学家Edsger W. Dijkstra于1956年提出。
 * 该算法要求图中所有边的权值非负，能够高效地计算出从给定源点到所有其他顶点的最短距离。
 * Dijkstra算法是许多实际应用（如路由协议、地图导航）的基础。
 *
 * @section principle 算法原理
 *
 * Dijkstra算法基于贪心策略，维护一个集合S（已确定最短路径的顶点）和一个距离数组dist（源点到各顶点的当前最短距离估计）。
 * 每次从尚未确定最短路径的顶点中选择一个距离最小的顶点u加入S，然后以u为中间点，更新u的所有邻接顶点v的距离（松弛操作）。
 * 由于所有边权非负，一旦某个顶点被加入S，其dist值即为最终最短距离，不再改变。
 *
 * @section step 算法步骤
 *
 * 1. 初始化：
 *    - 设源点为s，dist[s] = 0，其余顶点的dist为无穷大（INF）。
 *    - 使用优先队列（最小堆）存储待处理的顶点及其当前距离，初始将(s,0)入队。
 *    - 可选前驱数组pre，用于记录最短路径。
 *    图用vector<vector<pair<int, int>>>表示而不是vector<vector<int>>表示，已避免遍历值为INF的非必要边
 *
 * 2. 循环直到优先队列为空：
 *    - 从优先队列中取出距离最小的顶点u（如果u已处理过则跳过）。
 *    - 标记u为已确定（即将其加入集合S）。
 *    - 对u的每个邻接顶点v：
 *        - 如果通过u到达v的距离dist[u] + w(u,v) < dist[v]，则更新dist[v] = dist[u] + w(u,v)，
 *          并将(v, dist[v])入队，同时更新pre[v] = u。
 *
 * 3. 算法结束后，dist数组即为源点到各顶点的最短距离，若dist[i]仍为INF，则表示不可达。
 *
 * @section example 示例
 *
 * 考虑以下有向图（顶点0,1,2,3）：
 * ```
 * 0 -> 1 (权值 4)
 * 0 -> 2 (权值 2)
 * 1 -> 2 (权值 1)
 * 1 -> 3 (权值 5)
 * 2 -> 3 (权值 8)
 * 2 -> 1 (权值 3)
 * ```
 * 从顶点0开始运行Dijkstra算法：
 * - 初始：dist = [0, INF, INF, INF]，优先队列：[(0,0)]
 * - 取出0，更新邻接顶点1和2：
 *   dist[1] = 0+4 = 4，dist[2] = 0+2 = 2，队列：[(2,2), (4,1)]
 * - 取出2（当前最小距离），更新邻接顶点1和3：
 *   dist[1] = min(4, 2+3=5) → 仍为4；dist[3] = 2+8 = 10，队列：[(4,1), (10,3)]
 * - 取出1，更新邻接顶点3：
 *   dist[3] = min(10, 4+5=9) → 9，队列：[(9,3)]
 * - 取出3，无更新。
 * 最终dist = [0, 4, 2, 9]，即0->1最短距离4，0->2最短距离2，0->3最短距离9。
 *
 * @section complexity 复杂度分析
 *
 * 使用优先队列（二叉堆）实现时：
 * - 时间复杂度：O((V+E) log V)，其中V为顶点数，E为边数。每个顶点入队一次，每条边可能触发一次松弛操作，每次堆操作O(log V)。
 * - 空间复杂度：O(V)，用于存储dist、pre以及堆中的元素。
 *
 * 若使用朴素数组实现（每次找最小距离扫描所有顶点），时间复杂度为O(V²)，适用于稠密图。
 *
 * @section implementation 代码实现
 *
 * 下面给出基于邻接表+优先队列的Dijkstra算法实现，包含距离计算和路径重建功能。
 *
 * @see Graph, dijkstra(), reconstructPath()
 *
 * @section pros_and_cons 优缺点
 *
 * 优点:
 * - 算法思想简单，实现容易。
 * - 对于非负权图，效率高，适用广泛。
 * - 可以同时得到从源点到所有其他顶点的最短距离。
 *
 * 缺点:
 * - 不能处理负权边（负权边会导致贪心策略失效，应使用Bellman-Ford或SPFA）。
 * - 空间消耗与顶点数成正比，对于大规模图仍可接受。
 *
 * @section application 应用
 *
 * - 地图导航（如Google Maps、高德地图中的最短路径规划）。
 * - 网络路由协议（如OSPF、IS-IS）。
 * - 机器人路径规划。
 * - 作为其他算法的子过程（如Johnson算法中的重赋权）。
 *
 * @section extension 扩展
 *
 * - 使用斐波那契堆可将时间复杂度优化到O(V log V + E)，但实现复杂。
 * - 双向Dijkstra算法可用于加速两点间最短路径查询。
 * - 在稀疏图上，Dijkstra + 堆是最佳选择。
 */

#include <array>
#include <functional>
#include <limits>
#include <optional>
#include <queue>
#include <vector>

constexpr int INF = std::numeric_limits<int>::max() / 2;

/**
 * @brief 简单的图类（邻接表表示，支持有向边）
 *
 * @tparam N 顶点数量（固定大小）
 */
template<std::size_t N>
class Graph {
public:
    struct Edge {
        int to;      // 目标顶点
        int weight;  // 边权
    };

    using AdjList = std::vector<Edge>;

    /**
     * @brief 添加一条有向边
     * @param from 起点
     * @param to 终点
     * @param weight 权值（必须非负）
     */
    void addDirectedEdge(int from, int to, int weight) { adj_[from].push_back({to, weight}); }

    /**
     * @brief 添加一条无向边（相当于两条反向有向边）
     * @param u 端点1
     * @param v 端点2
     * @param weight 权值
     */
    void addUndirectedEdge(int u, int v, int weight) {
        addDirectedEdge(u, v, weight);
        addDirectedEdge(v, u, weight);
    }

    /**
     * @brief 获取邻接表（只读）
     */
    const std::array<AdjList, N>& adjacency() const { return adj_; }

private:
    std::array<AdjList, N> adj_;
};

/**
 * @brief Dijkstra算法结果类型
 *
 * @tparam N 顶点数量
 */
template<std::size_t N>
struct DijkstraResult {
    std::array<int, N> dist;  // 最短距离数组，INF表示不可达
    std::array<int, N> prev;  // 前驱顶点数组，-1表示无前驱（源点或不可达）
};

/**
 * @brief 单源最短路径 Dijkstra算法（优先队列优化）
 *
 * @tparam N 顶点数量
 * @param graph 图对象
 * @param source 源点索引
 * @return DijkstraResult<N> 包含距离和前驱的结果
 */
template<std::size_t N>
DijkstraResult<N> dijkstra(const Graph<N>& graph, int source) {
    std::array<int, N> dist;
    std::array<int, N> prev;
    dist.fill(INF);
    prev.fill(-1);
    dist[source] = 0;

    // 优先队列：存储 (距离, 顶点)，距离小的优先
    using Pair = std::pair<int, int>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // 如果取出的距离大于当前记录的距离，说明该顶点已被更新过，跳过
        if (d > dist[u]) continue;

        // 遍历邻接顶点
        for (const auto& edge : graph.adjacency()[u]) {
            int v       = edge.to;
            int w       = edge.weight;
            int newDist = dist[u] + w;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                prev[v] = u;
                pq.emplace(newDist, v);
            }
        }
    }

    return {dist, prev};
}

/**
 * @brief 重建从源点到目标顶点的最短路径
 *
 * @tparam N 顶点数量
 * @param result Dijkstra算法结果（包含前驱数组）
 * @param target 目标顶点
 * @return std::vector<int> 路径顶点序列（包含源点和目标点），若不可达则返回空向量
 */
template<std::size_t N>
std::vector<int> reconstructPath(const DijkstraResult<N>& result, int target) {
    std::vector<int> path;
    if (result.dist[target] == INF) return path;  // 不可达

    int cur = target;
    while (cur != -1) {
        path.push_back(cur);
        cur = result.prev[cur];
    }
    std::reverse(path.begin(), path.end());
    return path;
}

#endif  // ALGORITHM_INDEX_HPP
