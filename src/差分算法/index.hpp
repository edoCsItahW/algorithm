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
 * @date 2026/03/09 18:09
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_INDEX_HPP
#define ALGORITHM_INDEX_HPP
#pragma once

/**
 * @dir 差分
 * @brief 差分思想及其应用
 */

/**
 * @mainpage 差分
 * @showdate "%Y-%m-%d %H:%M:%S" 2026-03-09 18:10:00
 *
 * @tableofcontents{nested:2}
 *
 * @section intro 介绍
 *
 * 差分（Difference）是一种与前缀和互为逆运算的预处理技术，用于高效处理**区间批量增减**操作。
 * 当需要对数组的某个连续区间频繁地加上或减去同一个值，并在之后查询修改后的数组（或单点值）时，
 * 差分可以在 O(1) 时间内完成一次区间修改，而前缀和可以在 O(n) 时间内恢复最终数组（或通过维护前缀和实现 O(1) 单点查询）。
 * 差分与前缀和结合使用，是处理静态数组区间修改问题的经典技巧。
 *
 * @section principle 原理
 *
 * 对于一个长度为 n 的数组 `arr`，定义其差分数组 `diff` 满足：
 * ```
 * diff[0] = arr[0]
 * diff[i] = arr[i] - arr[i-1]   (1 ≤ i < n)
 * ```
 * 或者更常见地，为了方便区间操作，可以定义长度为 n+1 的差分数组，其中 `diff[i]` 表示相邻元素的差值，且多出的 `diff[n]` 用于处理右边界。
 *
 * 关键性质：
 * - 对原数组的区间 [l, r] 加上一个值 x，等价于：`diff[l] += x`，`diff[r+1] -= x`（如果 r+1 在范围内）。
 * - 原数组可以由差分数组的前缀和得到：`arr[i] = diff[0] + diff[1] + ... + diff[i]`。
 *
 * 这样，多次区间修改只需要 O(1) 时间更新差分数组，最后通过一次前缀和扫描即可得到最终的数组。
 *
 * @section step 算法步骤
 *
 * 1. **构建差分数组**：
 *    - 创建长度为 n+1 的数组 diff，并初始化为 0。
 *    - 对于 i = 0 到 n-1，将原数组 arr[i] 的影响添加到 diff 中：`diff[i] += arr[i]`，`diff[i+1] -= arr[i]`。
 *    实际上更简单的方式是直接按定义构建：`diff[0] = arr[0]`，然后 `diff[i] = arr[i] - arr[i-1]`，但为了统一区间操作，常采用 n+1 长度的版本。
 *
 * 2. **执行区间修改**：
 *    - 对于每次操作 [l, r] 增加 x，执行 `diff[l] += x`，`diff[r+1] -= x`。
 *
 * 3. **还原原数组**：
 *    - 计算差分数组的前缀和，得到最终数组：`res[0] = diff[0]`，`res[i] = res[i-1] + diff[i]` for i ≥ 1。
 *
 * @section example 示例
 *
 * 假设原数组 arr = [3, 5, 2, 7, 1]。
 *
 * 构建差分数组 diff（长度为 n+1=6）：
 * ```
 * diff[0] = arr[0] = 3
 * diff[1] = arr[1] - arr[0] = 2
 * diff[2] = arr[2] - arr[1] = -3
 * diff[3] = arr[3] - arr[2] = 5
 * diff[4] = arr[4] - arr[3] = -6
 * diff[5] = 0 (预留)
 * ```
 * 但更常用的是通过区间修改视角直接构建：初始 diff 全 0，然后对每个点 i 做区间 [i,i] 加 arr[i]。
 *
 * 现在进行两次区间修改：
 * - 对 [1,3] 加 10 → diff[1] += 10, diff[4] -= 10
 * - 对 [2,4] 加 5  → diff[2] += 5, diff[5] -= 5
 *
 * 差分数组变为：
 * ```
 * diff[0] = 3
 * diff[1] = 2 + 10 = 12
 * diff[2] = -3 + 5 = 2
 * diff[3] = 5
 * diff[4] = -6 -10 = -16
 * diff[5] = 0 -5 = -5
 * ```
 *
 * 最后通过前缀和还原数组：
 * ```
 * res[0] = diff[0] = 3
 * res[1] = res[0] + diff[1] = 3 + 12 = 15
 * res[2] = res[1] + diff[2] = 15 + 2 = 17
 * res[3] = res[2] + diff[3] = 17 + 5 = 22
 * res[4] = res[3] + diff[4] = 22 -16 = 6
 * ```
 * 最终数组为 [3, 15, 17, 22, 6]，与手动逐次修改结果一致。
 *
 * @section complexity 复杂度分析
 *
 * - **构建差分数组**：O(n)，只需遍历原数组一次。
 * - **单次区间修改**：O(1)，仅修改差分数组的两个位置。
 * - **还原原数组**：O(n)，需要一次前缀和扫描。
 * - **空间复杂度**：O(n)，需要额外的差分数组（长度为 n+1）。
 *
 * 如果需要在多次修改后进行多次单点查询，可以维护差分数组并在查询时计算前缀和，但这样每次查询是 O(index) 的；更高效的是在修改全部完成后一次性还原，或者使用树状数组支持动态查询。
 *
 * @section implementation 代码实现
 *
 * 下面给出一个基于 `std::array` 的模板实现，包含构建差分数组、区间修改以及从差分恢复原数组的函数。
 *
 * @see buildDiff(), rangeAdd(), recoverFromDiff()
 *
 * @section pros_and_cons 优缺点
 *
 * **优点**：
 * - 将区间修改操作降为 O(1)，极大提高批量修改效率。
 * - 实现简单，易于理解。
 * - 可与前缀和结合，实现离线处理大量区间操作。
 *
 * **缺点**：
 * - 如果需要在修改过程中穿插查询（在线查询），则每次查询需要 O(n) 时间（若直接还原整个数组）或 O(index) 时间（若动态计算前缀和），此时不如使用树状数组或线段树。
 * - 差分数组只能处理加减操作，不能处理乘除或赋值操作。
 * - 需要额外 O(n) 空间。
 *
 * @section application 应用
 *
 * - 处理多次区间增减操作后求最终数组（如“对某区间所有元素加 c”）。
 * - 与差分约束系统结合，解决一些线性不等式组问题。
 * - 在二维中可推广为二维差分，用于矩阵区域快速加减。
 * - 作为其他算法的基础，如扫描线、前缀和技巧的逆用。
 *
 * @section extension 扩展：二维差分
 *
 * 对于二维矩阵，定义二维差分数组 `diff`，对子矩阵 (x1,y1) 到 (x2,y2) 加 x 的操作为：
 * ```
 * diff[x1][y1] += x;
 * diff[x1][y2+1] -= x;
 * diff[x2+1][y1] -= x;
 * diff[x2+1][y2+1] += x;
 * ```
 * 之后对差分数组求二维前缀和即可恢复原矩阵。
 */

#include <array>
#include <cstddef>

/**
 * @brief 构建差分数组（基于原数组）
 *
 * @tparam N 原数组的大小
 * @param arr 原数组
 * @return std::array<long long, N+1> 差分数组（长度 N+1）
 */
template<std::size_t N>
std::array<long long, N + 1> buildDiff(const std::array<int, N>& arr) {
    std::array<long long, N + 1> diff{};
    // 方式一：通过区间修改方式构建（更通用）
    for (std::size_t i = 0; i < N; ++i) {
        diff[i] += arr[i];
        diff[i + 1] -= arr[i];
    }
    // 或者直接按定义：
    // diff[0] = arr[0];
    // for (std::size_t i = 1; i < N; ++i) diff[i] = arr[i] - arr[i-1];
    // diff[N] = 0;
    return diff;
}

/**
 * @brief 对区间 [l, r] 加上值 x（下标从 0 开始）
 *
 * @tparam N 原数组的大小
 * @param diff 差分数组（长度 N+1）
 * @param l 区间左端点（包含）
 * @param r 区间右端点（包含）
 * @param x 要增加的值
 */
template<std::size_t N>
void rangeAdd(std::array<long long, N + 1>& diff, std::size_t l, std::size_t r, long long x) {
    diff[l] += x;
    if (r + 1 < N + 1) diff[r + 1] -= x; // 注意边界
}

/**
 * @brief 从差分数组恢复最终数组
 *
 * @tparam N 原数组的大小
 * @param diff 差分数组（长度 N+1）
 * @return std::array<long long, N> 恢复后的数组（使用 long long 避免溢出）
 */
template<std::size_t N>
std::array<long long, N> recoverFromDiff(const std::array<long long, N + 1>& diff) {
    std::array<long long, N> res{};
    long long prefix = 0;
    for (std::size_t i = 0; i < N; ++i) {
        prefix += diff[i];
        res[i] = prefix;
    }
    return res;
}

#endif  // ALGORITHM_INDEX_HPP
