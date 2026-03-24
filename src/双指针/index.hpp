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
 * @date 2026/03/09 18:14
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_INDEX_HPP
#define ALGORITHM_INDEX_HPP
#pragma once

/**
 * @dir 双指针
 * @brief 双指针思想及其应用
 */

/**
 * @mainpage 双指针
 * @showdate "%Y-%m-%d %H:%M:%S" 2026-03-09 20:30:00
 *
 * @tableofcontents{nested:2}
 *
 * @section intro 介绍
 *
 * 双指针（Two Pointers）是一种简单而强大的算法技巧，通常用于数组、链表等线性结构。
 * 它通过维护两个指针（索引）在数据结构上移动，协同完成某些任务，例如搜索、反转、去重等。
 * 双指针技术可以显著降低时间复杂度，常将 O(n²) 的暴力解法优化至 O(n)。
 *
 * @section principle 基本原理
 *
 * 双指针的核心思想是使用两个指针（可以是同向移动、相向移动或快慢移动）来遍历数据结构，
 * 通过指针之间的关系（如大小比较、距离等）来高效地解决问题。常见的双指针模式包括：
 *
 * -
 * **左右指针（对撞指针）**：两个指针分别从序列的两端向中间移动，适用于有序数组的查找、反转、回文判断等。
 * - **快慢指针**：两个指针以不同速度移动，常用于链表环检测、寻找中点等。
 * -
 * **滑动窗口**：两个指针维护一个窗口，通过移动左右边界来调整窗口大小，常用于子数组/子串问题。
 *
 * @section patterns 常见模式
 *
 * ### 1. 左右指针（对撞指针）
 * 典型应用：有序数组的两数之和、反转数组、验证回文串。
 * 算法步骤：
 * - 初始化 left = 0, right = n-1。
 * - 循环直到 left >= right：
 *   - 根据条件判断，移动 left 或 right，或同时移动。
 *
 * ### 2. 快慢指针
 * 典型应用：链表环检测（Floyd 判圈算法）、寻找链表中间节点。
 * 算法步骤：
 * - 初始化 slow = head, fast = head。
 * - 循环直到 fast 到达末尾：
 *   - slow 每次走一步，fast 每次走两步。
 *   - 若相遇则有环；若 fast 到达 nullptr 则无环。
 *
 * ### 3. 滑动窗口
 * 典型应用：最长无重复子串、最小覆盖子串、长度最小的子数组。
 * 算法步骤：
 * - 初始化 left = 0, right = 0。
 * - 扩展 right 直到窗口满足条件，然后收缩 left 直到条件不再满足，记录最优解。
 *
 * @section examples 示例
 *
 * **两数之和 II - 输入有序数组**：
 * 给定升序数组和目标值 target，找到两个数使得它们的和等于 target。
 * ```
 * 数组: [2, 7, 11, 15], target = 9
 * left=0, right=3 → 2+15=17 >9 → right=2
 * left=0, right=2 → 2+11=13 >9 → right=1
 * left=0, right=1 → 2+7=9 ==9 → 返回 [0,1]
 * ```
 *
 * **反转数组**：
 * ```
 * 原数组: [1,2,3,4,5]
 * left=0, right=4 → 交换1和5 → [5,2,3,4,1]
 * left=1, right=3 → 交换2和4 → [5,4,3,2,1]
 * left=2, right=2 → 停止
 * ```
 *
 * **回文串判断**：
 * ```
 * 字符串: "racecar"
 * left=0('r'), right=6('r') → 相等，left=1, right=5
 * left=1('a'), right=5('a') → 相等，left=2, right=4
 * left=2('c'), right=4('c') → 相等，left=3, right=3 → 循环结束，是回文。
 * ```
 *
 * @section complexity 复杂度分析
 *
 * - 时间复杂度：通常为 O(n)，每个指针最多遍历整个序列一次。
 * - 空间复杂度：O(1)，只使用常数个额外变量。
 *
 * @section implementation 代码实现
 *
 * 下面给出了三个典型的双指针应用：
 * - `twoSum`：在有序数组中查找两数之和等于目标值的下标。
 * - `reverseArray`：反转数组。
 * - `isPalindrome`：判断字符串是否为回文串。
 *
 * @see twoSum(), reverseArray(), isPalindrome()
 *
 * @section pros_and_cons 优缺点
 *
 * **优点**：
 * - 简单直观，易于实现。
 * - 效率高，通常能达到线性时间复杂度。
 * - 空间占用小，为原地操作。
 *
 * **缺点**：
 * - 要求数据具有某种顺序（如有序数组）或特定结构（如链表）。
 * - 对于某些问题，需要仔细处理边界条件和指针移动逻辑。
 *
 * @section application 应用
 *
 * - 数组/字符串中的查找、匹配、反转问题。
 * - 链表环检测、交点问题。
 * - 滑动窗口类问题（子数组、子串）。
 * - 归并排序中的合并过程。
 *
 * @section extension 扩展
 *
 * 双指针思想可以推广到三指针（如三数之和）、多指针，以及与其他技术（如哈希表、二分查找）结合使用。
 */

#include <array>
#include <optional>
#include <string>
#include <utility>

/**
 * @brief 在有序数组中查找两个数，使它们的和等于目标值（左右指针法）
 *
 * @tparam N 数组大小
 * @param arr 升序排列的数组
 * @param target 目标和
 * @return std::optional<std::pair<std::size_t, std::size_t>> 如果找到，返回两个下标组成的
 * pair；否则返回 std::nullopt
 */
template<std::size_t N>
std::optional<std::pair<std::size_t, std::size_t>> twoSum(const std::array<int, N>& arr, int target) {
    std::size_t left  = 0;
    std::size_t right = N - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target)
            return std::make_pair(left, right);
        else if (sum < target)
            ++left;
        else
            --right;
    }
    return std::nullopt;
}

/**
 * @brief 反转数组（左右指针法）
 *
 * @tparam N 数组大小
 * @param arr 待反转的数组（原地修改）
 */
template<std::size_t N>
void reverseArray(std::array<int, N>& arr) {
    std::size_t left  = 0;
    std::size_t right = N - 1;
    while (left < right) {
        std::swap(arr[left], arr[right]);
        ++left;
        --right;
    }
}

/**
 * @brief 判断字符串是否为回文串（左右指针法，忽略大小写和非字母数字字符）
 *
 * @param s 输入字符串
 * @return true 如果是回文串
 * @return false 否则
 */
inline bool isPalindrome(const std::string& s) {
    std::size_t left  = 0;
    std::size_t right = s.length() - 1;
    while (left < right) {
        // 跳过非字母数字字符
        while (left < right && !std::isalnum(s[left])) ++left;
        while (left < right && !std::isalnum(s[right])) --right;
        if (std::tolower(s[left]) != std::tolower(s[right])) return false;
        ++left;
        --right;
    }
    return true;
}

#endif  // ALGORITHM_INDEX_HPP
