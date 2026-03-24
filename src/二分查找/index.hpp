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
 * @date 2026/03/09 18:12
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_INDEX_HPP
#define ALGORITHM_INDEX_HPP
#pragma once

/**
 * @dir 二分查找
 * @brief 二分查找思想及其实现
 */

/**
 * @mainpage 二分查找
 * @showdate "%Y-%m-%d %H:%M:%S" 2026-03-09 19:05:00
 *
 * @tableofcontents{nested:2}
 *
 * @section intro 介绍
 *
 * 二分查找（Binary Search）是一种在**有序**数组中查找特定元素的高效算法。
 * 它通过每次将查找范围缩小一半，将对数级的时间复杂度应用于查找操作。
 * 二分查找不仅是一种基础的查找算法，更是众多算法思想（如分治法、二分答案）的核心组成部分。
 *
 * @section principle 算法原理
 *
 * 二分查找利用数组的有序性，每次比较中间元素与目标值：
 * - 若相等，则查找成功；
 * - 若中间元素大于目标值，则说明目标值只可能出现在左半部分，继续在左半部分查找；
 * - 若中间元素小于目标值，则继续在右半部分查找。
 *
 * 每次比较都将搜索区间缩小一半，因此时间复杂度为 O(log n)。
 *
 * @section step 算法步骤
 *
 * 假设在有序数组 `arr` 的 `[left, right]` 区间内查找目标值 `target`：
 * 1. 初始化 `left = 0`，`right = arr.length - 1`。
 * 2. 当 `left <= right` 时循环：
 *    - 计算中点 `mid = left + (right - left) / 2`（避免整数溢出）。
 *    - 如果 `arr[mid] == target`，返回 `mid`。
 *    - 如果 `arr[mid] > target`，则 `right = mid - 1`（目标在左半部分）。
 *    - 如果 `arr[mid] < target`，则 `left = mid + 1`（目标在右半部分）。
 * 3. 循环结束仍未找到，返回 -1 或特定标识。
 *
 * @section example 示例
 *
 * 在有序数组 `[1, 3, 5, 7, 9, 11]` 中查找 `7`：
 * ```
 * left=0, right=5, mid=2 (值为5) → 5<7 → left=3
 * left=3, right=5, mid=4 (值为9) → 9>7 → right=3
 * left=3, right=3, mid=3 (值为7) → 7==7 → 返回3
 * ```
 *
 * @section complexity 复杂度分析
 *
 * - 时间复杂度：O(log n)，每次将区间减半。
 * - 空间复杂度：迭代版本 O(1)，递归版本 O(log n)（栈空间）。
 *
 * @section implementation 代码实现
 *
 * 下面给出基于 `std::array` 的模板实现，包括：
 * - 基本二分查找（返回第一个匹配的索引）。
 * - 查找第一个大于等于目标值的元素（lower_bound）。
 * - 查找第一个大于目标值的元素（upper_bound）。
 *
 * @see binarySearch(), lowerBound(), upperBound()
 *
 * @section pros_and_cons 优缺点
 *
 * 优点:
 * - 查找效率极高，适合大规模有序数据的查找。
 * - 实现简单，是算法学习的入门经典。
 *
 * 缺点:
 * - 要求数组必须有序，若无序则需要先排序（增加额外开销）。
 * - 依赖于随机访问（如数组），不适合链表等顺序结构。
 * - 插入删除操作困难，维护有序性成本高。
 *
 * @section application 应用
 *
 * - 有序数组中的元素查找。
 * - 求解“最大值最小化”或“最小值最大化”问题（二分答案）。
 * - 在旋转排序数组中查找元素（变种）。
 * - 在函数单调性基础上寻找零点或极值点。
 *
 * @section variants 常见变种
 *
 * - **lower_bound**：查找第一个大于等于 target 的位置。
 * - **upper_bound**：查找第一个大于 target 的位置。
 * - 查找最后一个小于等于 target 的位置。
 * - 在无限序列/范围内查找目标（如二分答案）。
 *
 * 这些变种通过调整循环条件和边界处理实现。
 */

#include <array>
#include <cstddef>
#include <optional>

/**
 * @brief 标准二分查找，在有序数组中查找目标值
 *
 * @tparam N 数组大小
 * @param arr 有序数组（升序）
 * @param target 待查找的值
 * @return std::optional<std::size_t> 若找到则返回索引，否则返回 std::nullopt
 */
template<std::size_t N>
std::optional<std::size_t> binarySearch(const std::array<int, N>& arr, int target) {
    std::size_t left  = 0;
    std::size_t right = N - 1;
    while (left <= right) {
        std::size_t mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            if (mid == 0) break;  // 防止 underflow
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return std::nullopt;
}

/**
 * @brief 查找第一个大于等于 target 的位置（lower_bound）
 *
 * @tparam N 数组大小
 * @param arr 有序数组（升序）
 * @param target 目标值
 * @return std::size_t 第一个 ≥ target 的索引，如果所有元素都小于 target，则返回 N
 */
template<std::size_t N>
std::size_t lowerBound(const std::array<int, N>& arr, int target) {
    std::size_t left  = 0;
    std::size_t right = N;  // 右边界开区间 [left, right)
    while (left < right) {
        std::size_t mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;  // left == right
}

/**
 * @brief 查找第一个大于 target 的位置（upper_bound）
 *
 * @tparam N 数组大小
 * @param arr 有序数组（升序）
 * @param target 目标值
 * @return std::size_t 第一个 > target 的索引，如果所有元素都 ≤ target，则返回 N
 */
template<std::size_t N>
std::size_t upperBound(const std::array<int, N>& arr, int target) {
    std::size_t left  = 0;
    std::size_t right = N;
    while (left < right) {
        std::size_t mid = left + (right - left) / 2;
        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

#endif  // ALGORITHM_INDEX_HPP
