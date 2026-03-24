// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for
// commercial purposes is prohibited without the author's permission. If you have any
// questions or require permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file index.hpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/09 18:06
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_INDEX_HPP
#define ALGORITHM_INDEX_HPP
#pragma once

/**
 * @dir 前缀和
 * @brief 前缀和思想及其应用
 */

/**
 * @mainpage 前缀和
 * @showdate "%Y-%m-%d %H:%M:%S" 2026-03-09 17:20:00
 *
 * @tableofcontents{nested:2}
 *
 * @section intro 介绍
 *
 * 前缀和（Prefix Sum）是一种经典的预处理技术，用于快速计算数组中任意连续子数组的和。
 * 它通过构建一个辅助数组，使得区间和查询的时间复杂度从 O(n) 降低到
 * O(1)，特别适合需要大量区间和查询的场景。
 * 前缀和思想可以推广到二维矩阵（二维前缀和）以及高维空间，是算法竞赛和数据处理中常用的优化手段。
 *
 * @section principle 原理
 *
 * 对于一个长度为 n 的数组 `arr`，定义其前缀和数组 `prefix` 满足：
 * ```
 * prefix[0] = 0
 * prefix[i] = arr[0] + arr[1] + ... + arr[i-1]   (1 ≤ i ≤ n)
 * ```
 * 即 `prefix[i]` 表示原数组前 i 个元素的和（从下标 0 到 i-1）。
 *
 * 那么，任意子数组 `arr[l..r]`（包含 l 和 r，0 ≤ l ≤ r < n）的和可以表示为：
 * ```
 * sum(l, r) = prefix[r+1] - prefix[l]
 * ```
 *
 * @section step 算法步骤
 *
 * 1. **构建前缀和数组**：
 *    - 创建一个长度为 n+1 的数组 prefix，初始化 prefix[0] = 0。
 *    - 从 i = 1 到 n，依次计算 prefix[i] = prefix[i-1] + arr[i-1]。
 *
 * 2. **查询区间和**：
 *    - 对于给定区间 [l, r]（下标从 0 开始），返回 prefix[r+1] - prefix[l]。
 *
 * @section example 示例
 *
 * 假设原数组 arr = [2, 4, 1, 5, 3]。
 *
 * 构建前缀和数组 prefix：
 * ```
 * prefix[0] = 0
 * prefix[1] = 0 + arr[0] = 2
 * prefix[2] = 2 + arr[1] = 6
 * prefix[3] = 6 + arr[2] = 7
 * prefix[4] = 7 + arr[3] = 12
 * prefix[5] = 12 + arr[4] = 15
 * ```
 *
 * 查询子数组 arr[1..3]（元素 4,1,5）的和：
 * ```
 * sum = prefix[4] - prefix[1] = 12 - 2 = 10
 * ```
 *
 * @section complexity 复杂度分析
 *
 * - **预处理时间复杂度**：O(n)，只需遍历原数组一次。
 * - **单次查询时间复杂度**：O(1)，仅需两次数组访问和一次减法。
 * - **空间复杂度**：O(n)，需要额外存储前缀和数组（长度为 n+1）。
 *
 * @section implementation 代码实现
 *
 * 下面给出一个基于 `std::array` 的模板实现，包含构建前缀和与查询区间和的函数。
 *
 * @see buildPrefixSum(), rangeSum()
 *
 * @section pros_and_cons 优缺点
 *
 * **优点**：
 * - 查询效率极高，适合大量区间和查询的场景。
 * - 实现简单，易于理解和调试。
 * - 可扩展到二维（矩阵子矩阵和）甚至更高维度。
 *
 * **缺点**：
 * - 需要额外的 O(n) 空间，如果原数组很大且查询很少，可能浪费空间。
 * - 仅适用于静态数组（元素不频繁修改）。若原数组频繁修改，则每次修改后需要更新前缀和，退化为
 * O(n) 更新，此时应使用树状数组或线段树。
 * -
 * 只能处理加法类运算（如求和），对于最大值、最小值等其他运算不适用（可用其他数据结构如稀疏表）。
 *
 * @section application 应用
 *
 * - 频繁的区间求和查询（如统计学生成绩总分、销售数据汇总）。
 * - 作为其他算法的基础，例如：
 *   - 二维前缀和用于图像处理中的区域亮度计算。
 *   - 前缀和与差分结合，用于快速处理区间增减操作。
 *   - 前缀异或可用于快速计算区间异或值。
 * - 算法竞赛中常见题型，如“连续子数组和等于 k 的个数”等。
 *
 * @section extension 扩展：二维前缀和
 *
 * 对于二维矩阵，可以定义二维前缀和 `prefix[i][j]` 表示从 (0,0) 到 (i-1,j-1) 的子矩阵和。
 * 查询左上角 (x1,y1) 到右下角 (x2,y2) 的子矩阵和公式为：
 * ```
 * sum = prefix[x2+1][y2+1] - prefix[x1][y2+1] - prefix[x2+1][y1] + prefix[x1][y1]
 * ```
 * 其构建与查询同样为 O(1) 时间。
 */

#include <array>
#include <cstddef>

/**
 * @brief 构建一维前缀和数组
 *
 * @tparam N 原数组的大小
 * @param arr 原数组（下标 0 到 N-1）
 * @return std::array<long long, N+1> 前缀和数组，其中 prefix[0] = 0，prefix[i] 为
 * arr[0..i-1] 的和
 */
template<std::size_t N>
std::array<long long, N + 1> buildPrefixSum(const std::array<int, N>& arr) {
    std::array<long long, N + 1> prefix{};
    prefix[0] = 0;
    for (std::size_t i = 1; i <= N; ++i) prefix[i] = prefix[i - 1] + arr[i - 1];
    return prefix;
}

/**
 * @brief 查询区间 [l, r] 的和（下标从 0 开始）
 *
 * @tparam N 原数组的大小
 * @param prefix 由 buildPrefixSum 构建的前缀和数组
 * @param l 区间左端点（包含）
 * @param r 区间右端点（包含）
 * @return long long 区间和
 */
template<std::size_t N>
long long rangeSum(
    const std::array<long long, N + 1>& prefix, std::size_t l, std::size_t r
) {
    // 确保 l <= r 且 r < N
    return prefix[r + 1] - prefix[l];
}

#endif  // ALGORITHM_INDEX_HPP
