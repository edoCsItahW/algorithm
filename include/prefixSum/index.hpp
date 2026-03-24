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
 * @date 2026/03/17 13:39
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_PREFIX_SUM_INDEX_HPP
#define ALGORITHM_PREFIX_SUM_INDEX_HPP
#pragma once

namespace algo::prefix_sum {

    /**
     * @brief 题1：一维数组的区间和查询
     *
     * @details
     * **题目描述**
     * 给定一个长度为 $n$ 的整数数组 $a$，有 $q$ 次查询，每次查询给定两个整数 $l$ 和 $r$，求数组 $a$ 从下标 $l$ 到 $r$（包含 $l$ 和 $r$）的所有元素的和。
     *
     * **输入格式**
     * 第一行包含两个整数 $n, q$，表示数组长度和查询次数。
     * 第二行包含 $n$ 个整数，表示数组 $a$。
     * 接下来 $q$ 行，每行包含两个整数 $l, r$，表示一次查询。
     *
     * **输出格式**
     * 对于每次查询，输出一行一个整数，表示对应区间和。
     *
     * **样例输入**
     *
     * ```text
     * 5 3
     * 1 2 3 4 5
     * 1 3
     * 2 5
     * 1 1
     * ```
     *
     * **样例输出**
     *
     * ```text
     * 6
     * 14
     * 1
     * ```
     *
     * **数据范围与提示**
     *
     * - $1 \leq n, q \leq 10^5$
     * - $-10^9 \leq a[i] \leq 10^9$
     * - $1 \leq l \leq r \leq n$
     * - 提示：使用前缀和预处理，每次查询 O(1) 输出。
     */
    void case1();

    /**
     * ## 题3：二维子矩阵和查询
     *
     * **题目描述**
     * 给定一个 $n$ 行 $m$ 列的整数矩阵 $a$，有 $q$ 次查询，每次查询给出一个子矩阵的左上角坐标 $(x_1, y_1)$ 和右下角坐标 $(x_2, y_2)$，求这个子矩阵中所有元素的和。
     *
     * **输入格式**
     * 第一行包含三个整数 $n, m, q$，表示矩阵的行数、列数和查询次数。
     * 接下来 $n$ 行，每行包含 $m$ 个整数，表示矩阵 $a$。
     * 接下来 $q$ 行，每行包含四个整数 $x_1, y_1, x_2, y_2$，表示一次查询。
     *
     * **输出格式**
     * 对于每次查询，输出一行一个整数，表示子矩阵和。
     *
     * **样例输入**
     *
     * ```text
     * 3 3 3
     * 1 2 3
     * 4 5 6
     * 7 8 9
     * 1 1 2 2
     * 2 2 3 3
     * 1 2 3 3
     * ```
     *
     * **样例输出**
     *
     * ```text
     * 12
     * 28
     * 33
     * ```
     *
     * **数据范围与提示**
     *
     * - $1 \leq n, m \leq 1000$，$1 \leq q \leq 10^5$
     * - $-10^9 \leq a[i][j] \leq 10^9$
     * - $1 \leq x_1 \leq x_2 \leq n$，$1 \leq y_1 \leq y_2 \leq m$
     * - 提示：预处理二维前缀和，查询 O(1)。
     */
    void case2();

}  // namespace algo::prefix_sum

#endif  // ALGORITHM_PREFIX_SUM_INDEX_HPP
