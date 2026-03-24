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
 * @date 2026/03/09 17:59
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_INDEX_HPP
#define ALGORITHM_INDEX_HPP
#pragma once

/**
 * @dir 快速排序
 * @brief 快速排序思想及其实现
 */

/**
 * @mainpage 快速排序
 * @showdate "%Y-%m-%d %H:%M:%S" 2026-03-09 16:30:00
 *
 * @tableofcontents{nested:2}
 *
 * @section intro 介绍
 *
 * 快速排序（Quick Sort）是一种基于分治思想的高效排序算法，由英国计算机科学家 Tony Hoare 于 1959 年提出。
 * 它通过一趟排序将待排序数据分割成独立的两部分，其中一部分的所有数据都比另一部分小，然后再按此方法对这两部分分别进行快速排序，
 * 整个排序过程可以递归进行，最终使整个数据变成有序序列。快速排序是实际应用中表现最好的排序算法之一。
 *
 * @section principle 算法原理
 *
 * 快速排序采用**分治法**（Divide and Conquer）：
 * 1. 分解: 从当前区间中选取一个元素作为基准（pivot），将区间划分为两个子区间，使得左子区间所有元素 ≤ 基准，右子区间所有元素 ≥ 基准。
 * 2. 解决: 递归地对两个子区间进行快速排序。
 * 3. 合并: 由于子区间是原址排序的，不需要合并操作，排序完成后整个数组自然有序。
 *
 * @section step 算法步骤
 *
 * 假设对数组 A 的 [left, right] 区间进行排序：
 * 1. 若 left >= right（区间内元素少于等于1个），则返回。
 * 2. 调用分区函数 partition，返回基准元素的最终位置 pivotIndex。
 *    - 分区函数通常选择最后一个元素（或随机元素）作为基准，通过两个指针将小于基准的元素移到左边，大于基准的移到右边。
 * 3. 递归调用快速排序处理左子区间 [left, pivotIndex-1]。
 * 4. 递归调用快速排序处理右子区间 [pivotIndex+1, right]。
 *
 * @section example 分区过程示例
 *
 * 以 Lomuto 分区方案为例（选择最后一个元素为基准）：
 * ```
 * 初始数组：[3, 7, 8, 5, 2, 1, 9, 6]  (基准为6)
 * 分区过程：
 * i指向左边界，j遍历数组，当arr[j]<=基准时，交换arr[i]和arr[j]并i++。
 * j=0: 3<=6 → swap(arr[0],arr[0]), i=1
 * j=1: 7>6  无操作
 * j=2: 8>6  无操作
 * j=3: 5<=6 → swap(arr[1],arr[3]) → [3,5,8,7,2,1,9,6], i=2
 * j=4: 2<=6 → swap(arr[2],arr[4]) → [3,5,2,7,8,1,9,6], i=3
 * j=5: 1<=6 → swap(arr[3],arr[5]) → [3,5,2,1,8,7,9,6], i=4
 * j=6: 9>6  无操作
 * 最后将基准arr[right]与arr[i]交换 → [3,5,2,1,6,7,9,8]
 * 基准6最终位置 i=4
 * ```
 *
 * 递归处理左子数组 [3,5,2,1] 和右子数组 [7,9,8]，最终得到有序数组。
 *
 * @section complexity 复杂度分析
 *
 * - 时间复杂度：
 *     - 最好情况：每次分区都均匀划分，时间复杂度为 O(n log n)。
 *     - 最坏情况：每次分区都极不平衡（例如数组已经有序且选择最左或最右为基准），时间复杂度退化为 O(n²)。
 *     - 平均情况：O(n log n)。通过随机化选择基准可以避免最坏情况。
 *
 * - 空间复杂度：
 *     - 递归调用栈深度平均为 O(log n)，最坏 O(n)（完全不平衡时）。
 *     - 排序是原址的，不需要额外辅助数组（除了递归栈），因此空间复杂度主要取决于递归深度。
 *
 * - 稳定性：
 *     快速排序是不稳定的，分区过程中可能改变相等元素的相对顺序。
 *
 * @section implementation 代码实现
 *
 * @see quickSort()
 *
 * @section pros_and_cons 优缺点
 *
 * 优点:
 * - 平均性能非常好，实际应用中通常比其他 O(n log n) 算法更快。
 * - 原址排序，空间复杂度低（递归栈除外）。
 * - 数据移动少，缓存友好。
 *
 * 缺点:
 * - 不稳定排序。
 * - 最坏时间复杂度 O(n²)，但可通过随机化基准或三数取中法有效避免。
 * - 对于小规模数据，递归开销可能比插入排序大（可优化，如小数组改用插入排序）。
 *
 * @section application 应用
 *
 * - 通用排序库（如 C 标准库的 qsort、C++ std::sort 的混合实现）。
 * - 对性能要求高且数据随机性强的场景。
 * - 可作为其他算法的基础（如快速选择、中位数查找）。
 */

#include <array>
#include <cstdlib>  // for rand()

template<std::size_t N>
int partition(std::array<int, N>& arr, int left, int right) {
    // 随机选择基准，避免最坏情况（简单实现中可选最后一个元素）
    // 这里使用最后一个元素作为基准（Lomuto分区）
    int pivot = arr[right];
    int i = left;  // i 指向小于基准的区域的末尾
    for (int j = left; j < right; ++j)
        if (arr[j] <= pivot) {
            std::swap(arr[i], arr[j]);
            ++i;
        }

    std::swap(arr[i], arr[right]);  // 将基准放到正确位置
    return i;
}

template<std::size_t N>
void quickSort(std::array<int, N>& arr, int left, int right) {
    if (left >= right) return;  // 递归终止条件

    int pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

#endif  // ALGORITHM_INDEX_HPP
