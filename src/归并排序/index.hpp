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
 * @date 2026/03/06 22:47
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef LEETCODE_INDEX_HPP
#define LEETCODE_INDEX_HPP
#pragma once

/**
 * @dir 归并排序
 * @brief 归并排序思想及其实现
 */

/**
 * @mainpage 归并排序
 * @showdate "%Y-%m-%d %H:%M:%S" 2026-03-06 22:47:00
 *
 * @tableofcontents{nested:2}
 *
 * @section intro 介绍
 *
 * 归并排序（Merge Sort）是一种基于分治思想的高效排序算法。它将待排序数组不断分成两半，分别排序后再合并，最终得到完全有序的序列。
 * 该算法由约翰·冯·诺伊曼于1945年提出，是经典的外部排序算法基础。
 *
 * @section principle 算法原理
 *
 * 归并排序采用**分治法**（Divide and Conquer）：
 * 1. 分解: 将当前区间一分为二，即求中间点 `mid = (left + right) / 2`。
 * 2. 解决: 递归地对两个子区间进行归并排序。
 * 3. 合并: 将两个已排序的子区间合并成一个有序区间。
 *
 * @section step 算法步骤
 *
 * 假设对数组 A 的 [left, right] 区间进行排序：
 * 1. 若 left >= right（区间内元素少于等于1个），则返回。
 * 2. 计算中点 mid，将区间分为 [left, mid] 和 [mid+1, right]。
 * 3. 递归调用归并排序处理左子区间。
 * 4. 递归调用归并排序处理右子区间。
 * 5. 合并两个有序子区间：
 *     - 创建一个临时数组（或使用原数组的一部分）来存放合并结果。
 *     - 用两个指针分别指向两个子区间的起始位置，比较元素大小，将较小者放入临时数组，并移动对应指针。
 *     - 将剩余元素直接复制到临时数组末尾。
 *     - 将临时数组的内容复制回原数组的对应位置。
 *
 * @section example 合并过程示例
 *
 * ```
 * 初始数组：[8, 4, 5, 7, 1, 3, 6, 2]
 *               分             分
 *           [8,4,5,7]      [1,3,6,2]
 *           分     分      分     分
 *         [8,4]  [5,7]   [1,3]  [6,2]
 *        分  分   分  分  分  分  分  分
 *       [8] [4]  [5] [7] [1] [3] [6] [2]
 *        合  合  合  合   合  合 合  合
 *        [4,8]  [5,7]    [1,3]  [2,6]
 *             合              合
 *          [4,5,7,8]     [1,2,3,6]
 *                     合
 *             [1,2,3,4,5,6,7,8]
 * ```
 *
 * @section complexity 复杂度分析
 *
 * - 时间复杂度：
 *     最好、最坏、平均情况均为 O(n log n)。因为每次分解需要 log n 层，每层合并操作涉及所有元素 O(n)。
 *
 * - 空间复杂度：
 *     需要额外的临时数组，通常为 O(n)。递归调用栈深度为 O(log n)，但辅助空间占主导。
 *
 * - 稳定性：
 *     归并排序是稳定的，合并时遇到相等元素优先复制左侧子数组的元素，保持相对顺序。
 *
 * @section implementation 代码实现
 *
 * @see mergeSort()
 *
 * @section pros_and_cons 优缺点
 *
 * 优点:
 * - 时间复杂度稳定，始终为 O(n log n)。
 * - 稳定排序。
 * - 适合外部排序（如处理无法一次性装入内存的大文件，可结合多路归并）。
 *
 * 缺点:
 * - 需要 O(n) 的额外空间，在内存受限环境下可能不适用。
 * - 对于小规模数据，常数开销比快速排序、插入排序大（但可优化，如小数组改用插入排序）。
 *
 * @section application 应用
 *
 * - 对稳定性有要求的大规模数据排序。
 * - 链表排序（因为链表不需要额外空间，且合并操作方便，空间复杂度可降为 O(log n)）。
 * - 外部排序的基础。
*/

#include <array>

template<std::size_t N>
void merge(std::array<int, N>& arr, int left, int mid, int right) {
    std::array<int, N> temp;

    int i = left, j = mid + 1, k = 0;  // k表示临时数组当前处理到的下标，i、j表示左右子数组当前处理到的下标

    while (i <= mid && j <= right)  // 确保左右子数组都处理完毕
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i];
}

template<std::size_t N>
void mergeSort(std::array<int, N>& arr, int left, int right) {
    if (left <= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

#endif  // LEETCODE_INDEX_HPP
