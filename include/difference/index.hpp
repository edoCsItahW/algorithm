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
 * @date 2026/03/17 14:14
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_DIFFERENCE_INDEX_HPP
#define ALGORITHM_DIFFERENCE_INDEX_HPP
#pragma once

namespace algo::difference {

    /**
     * **题2：一维数组的区间加法（差分）**
     * 题目描述：给定一个长度为n的整数数组a（初始全为0），进行m次区间加法操作，每次操作将数组的某个区间[l, r]内的每个元素加上一个值c。请输出所有操作完成后的数组a。
     *
     * 输入格式：
     * 第一行包含两个整数n和m，表示数组长度和操作次数。
     * 接下来m行，每行包含三个整数l, r, c，表示将区间[l, r]内的每个元素加上c。
     *
     * 输出格式：
     * 输出一行，包含n个整数，表示最终数组。
     *
     * 样例输入：
     * 5 2
     * 1 3 2
     * 2 5 -1
     *
     * 样例输出：
     * 2 1 1 -1 -1
     *
     * 解释：
     * 初始数组 [0,0,0,0,0]
     * 第一次操作后 [2,2,2,0,0]
     * 第二次操作后 [2,1,1,-1,-1]
     *
     * 数据范围与提示：
     * 1 ≤ n, m ≤ 10^5
     * -10^9 ≤ c ≤ 10^9
     * 1 ≤ l ≤ r ≤ n
     * 提示：使用差分数组，每次操作O(1)，最后求前缀和得到原数组。
     */
    void case1();

    /**
     * **题4：二维矩阵的矩形区域加法（二维差分）**
     * 题目描述：给定一个n行m列的整数矩阵a（初始全为0），进行k次矩形区域加法操作，每次操作将一个子矩阵内所有元素加上一个值c。请输出所有操作完成后的矩阵。
     *
     * 输入格式：
     * 第一行包含三个整数n, m, k，表示矩阵的行数、列数和操作次数。
     * 接下来k行，每行包含五个整数x1, y1, x2, y2, c，表示将左上角(x1,y1)到右下角(x2,y2)的子矩阵内每个元素加上c。
     *
     * 输出格式：
     * 输出n行，每行m个整数，表示最终矩阵。
     *
     * 样例输入：
     * 3 4 2
     * 1 1 2 2 3
     * 2 2 3 4 -1
     *
     * 样例输出：
     * 3 3 0 0
     * 3 2 -1 -1
     * 0 -1 -1 -1
     *
     * 解释：
     * 初始全0，第一次加3到(1,1)-(2,2)：
     * [3,3,0,0; 3,3,0,0; 0,0,0,0]
     * 第二次加-1到(2,2)-(3,4)：
     * [3,3,0,0; 3,2,-1,-1; 0,-1,-1,-1]
     *
     * 数据范围与提示：
     * 1 ≤ n, m ≤ 1000，1 ≤ k ≤ 10^5
     * -10^9 ≤ c ≤ 10^9
     * 1 ≤ x1 ≤ x2 ≤ n, 1 ≤ y1 ≤ y2 ≤ m
     * 提示：使用二维差分数组，每次操作O(1)修改，最后求二维前缀和恢复矩阵。
     */
    void case2();

}  // namespace algo::difference

#endif  // ALGORITHM_DIFFERENCE_INDEX_HPP
