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
 * @date 2026/03/09 21:42
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_INDEX_HPP
#define ALGORITHM_INDEX_HPP
#pragma once

/**
 * @dir Floyd-Warshall算法
 * @brief 所有顶点对之间的最短路径算法
 */

/**
 * @mainpage Floyd-Warshall算法
 * @showdate "%Y-%m-%d %H:%M:%S" 2026-03-09 23:30:00
 *
 * @tableofcontents{nested:2}
 *
 * @section intro 介绍
 *
 * Floyd-Warshall算法（简称Floyd算法）是一种用于求解**带权图中所有顶点对之间最短路径**的动态规划算法。
 * 它可以处理有向图或无向图，允许负权边（但不能有负权环，否则最短路径无定义）。
 * 该算法由Robert Floyd和Stephen Warshall分别独立提出，是经典的图论算法之一。
 *
 * @section principle 算法原理
 *
 * Floyd算法基于动态规划思想。定义状态 `dist[k][i][j]` 表示从顶点 i 到顶点 j 的、中间顶点仅取自集合 {0,1,...,k} 的最短路径长度。
 * 递推关系为：
 * ```
 * dist[k][i][j] = min( dist[k-1][i][j], dist[k-1][i][k] + dist[k-1][k][j] )
 * ```
 * 即考虑是否经过顶点 k 可以得到更短的路径。
 *
 * 在实际实现中，我们可以将空间优化到二维，使用同一个数组进行迭代，因为第 k 轮的状态只依赖于第 k-1 轮。
 *
 * @section step 算法步骤
 *
 * 1. 初始化距离矩阵 `dist`，其中 `dist[i][j]` 为边 (i,j) 的权值，若 i=j 则设为 0，若不存在边则设为 INF（一个大数）。
 * 2. 初始化前驱矩阵 `next`（可选），用于重建路径。`next[i][j]` 表示从 i 到 j 的最短路径上的下一个顶点。
 * 3. 对于 k 从 0 到 n-1（依次作为中间顶点）：
 *    - 对于 i 从 0 到 n-1：
 *      - 对于 j 从 0 到 n-1：
 *        - 如果 `dist[i][k] + dist[k][j] < dist[i][j]`，则更新 `dist[i][j]`，并更新 `next[i][j] = next[i][k]`。
 * 4. 检测负权环：如果存在 i 使得 `dist[i][i] < 0`，则说明图中存在负权环。
 *
 * @section example 示例
 *
 * 考虑以下有向图（顶点0,1,2）：
 * ```
 * 0 -> 1 (权值 3)
 * 1 -> 2 (权值 1)
 * 2 -> 0 (权值 7)
 * 0 -> 2 (权值 5)
 * ```
 * 初始距离矩阵（INF 表示无穷大）：
 * ```
 * [ [0, 3, 5],
 *   [INF, 0, 1],
 *   [7, INF, 0] ]
 * ```
 * 经过 Floyd 算法计算后，最终距离矩阵为：
 * ```
 * [ [0, 3, 4],
 *   [8, 0, 1],
 *   [7, 10, 0] ]
 * ```
 * 例如，从 1 到 0 的最短路径为 1->2->0，距离为 1+7=8。
 *
 * @section complexity 复杂度分析
 *
 * - 时间复杂度：O(n³)，其中 n 为顶点数。三重循环决定了这一复杂度。
 * - 空间复杂度：O(n²)，用于存储距离矩阵和前驱矩阵（可选）。
 *
 * @section implementation 代码实现
 *
 * 下面给出基于邻接矩阵的Floyd算法实现，包含距离计算和路径重建功能。
 *
 * @see floyd(), reconstructPath()
 *
 * @section pros_and_cons 优缺点
 *
 * 优点:
 * - 算法简单，易于实现和记忆。
 * - 一次性计算出所有顶点对之间的最短路径，适用于需要全局信息的场景。
 * - 可以处理负权边（但不能有负权环）。
 *
 * 缺点:
 * - 时间复杂度较高 O(n³)，对于大规模图（n 上万）不适用。
 * - 不能处理负权环（但可以检测）。
 * - 空间复杂度 O(n²)，对于稀疏图浪费空间（可用Johnson算法优化）。
 *
 * @section application 应用
 *
 * - 计算所有顶点对的最短路径，如交通网络分析、社交网络距离度量。
 * - 检测图中是否存在负权环。
 * - 传递闭包计算（仅判断连通性）。
 * - 作为某些算法的子过程（如最小环问题）。
 *
 * @section extension 扩展
 *
 * Floyd算法也可以用于求解**有向图的传递闭包**（只需将加法改为逻辑或，取小改为逻辑与）。
 * 对于稀疏图，可以考虑使用 n 次 Dijkstra（无负权）或 Bellman-Ford（有负权）来获得更好的平均性能。
 */

#include <algorithm>
#include <array>
#include <limits>
#include <vector>

// 定义无穷大（用于表示不可达）
constexpr int INF = std::numeric_limits<int>::max() / 2;  // 除以2防止加法溢出

/**
 * @brief Floyd-Warshall算法，计算所有顶点对的最短路径距离
 *
 * @tparam N 顶点数量
 * @param graph 邻接矩阵，graph[i][j] 表示从 i 到 j 的边权，若不存在边应为 INF，对角线为 0
 * @param next 输出参数，前驱矩阵，用于路径重建。如果为 nullptr，则不计算前驱
 * @return std::array<std::array<int, N>, N> 最短路径距离矩阵
 */
template<std::size_t N>
std::array<std::array<int, N>, N> floyd(const std::array<std::array<int, N>, N>& graph, std::array<std::array<int, N>, N>* next = nullptr) {
    // 初始化距离矩阵
    std::array<std::array<int, N>, N> dist = graph;

    // 初始化前驱矩阵（如果提供了next指针）
    if (next != nullptr) {
        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < N; ++j)
                if (i == j || graph[i][j] == INF)
                    (*next)[i][j] = -1;  // 无前驱
                else
                    (*next)[i][j] = j;  // 直接指向 j
        }
    }

    // Floyd 主循环
    for (std::size_t k = 0; k < N; ++k) {
        for (std::size_t i = 0; i < N; ++i) {
            // 剪枝：如果 dist[i][k] 为 INF，则无法通过 k 更新
            if (dist[i][k] == INF) continue;
            for (std::size_t j = 0; j < N; ++j) {
                if (dist[k][j] == INF) continue;
                int newDist = dist[i][k] + dist[k][j];
                if (newDist < dist[i][j]) {
                    dist[i][j] = newDist;
                    if (next != nullptr) (*next)[i][j] = (*next)[i][k];  // 路径更新：i->j 经过 k，所以下一个节点同 i->k
                }
            }
        }
    }

    // 检测负权环：如果存在 dist[i][i] < 0，则存在负权环
    for (std::size_t i = 0; i < N; ++i) {
        if (dist[i][i] < 0) {
            // 可以抛出异常或标记，这里简单返回空矩阵或通过其他方式通知
            // 实际应用中可能需要处理
        }
    }

    return dist;
}

/**
 * @brief 重建从 start 到 end 的最短路径
 *
 * @tparam N 顶点数量
 * @param next 由 floyd 计算得到的前驱矩阵
 * @param start 起点
 * @param end 终点
 * @return std::vector<int> 路径顶点序列（包含起点和终点），如果不可达则返回空向量
 */
template<std::size_t N>
std::vector<int> reconstructPath(const std::array<std::array<int, N>, N>& next, int start, int end) {
    std::vector<int> path;
    if (next[start][end] == -1) return path;  // 不可达
    path.push_back(start);
    int cur = start;
    while (cur != end) {
        cur = next[cur][end];
        if (cur == -1) {
            // 不应发生，但以防万一
            return {};
        }
        path.push_back(cur);
    }
    return path;
}

#endif  // ALGORITHM_INDEX_HPP
