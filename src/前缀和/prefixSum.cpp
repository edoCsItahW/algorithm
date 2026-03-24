// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file prefixSum.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/02/25 23:25
 * @brief 前缀和算法
 * @details 对于一个数组，其下标为i，则前缀和数组prefixSum[i + 1]表示数组中0到i个元素的和。
 * 由于`prefixSum[i] = prefixSum[i-1] + arr[i-1]`，可见求i位置的前缀要用到i-1位置的前缀和。
 * 因此，为了方便计算，可以将prefixSum数组初始化为{0}，然后从1开始遍历数组，计算prefixSum[i]。
 * 对于给定的区间[left, right]，其前缀和sum = prefixSum[right + 1] - prefixSum[left]。
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */

#include "prefixSum/index.hpp"
#include <iostream>
#include <iterator>
#include <vector>

// inline int main_() {
//     constexpr auto arr = std::array{1, 2, 3, 4, 5};
//
//     std::array<int, arr.size()> prefixSum = {0};
//
//     for (int i = 1; i < arr.size(); ++i) prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
//
//     constexpr int left = 2, right = 4;
//
//     const int sum = prefixSum[right + 1] - prefixSum[left];
//
//     std::cout << "The sum of [" << left << ", " << right << "] is " << sum << std::endl;
//
//     return 0;
// }


namespace algo::prefix_sum {

    /**
     *
     * 结果6\n14\n1
     */
    void case1() {
        int n /* 数组长度 */, q /* 查询次数 */;
        std::cin >> n >> q;

        std::vector prefix(n + 1, 0);  // 前缀和数组

        for (int i = 1, num /* 数组元素 */; i <= n /* 等价于<= n + 1 */; ++i) {
            std::cin >> num;

            prefix[i] = prefix[i - 1] + num;
        }

        while (q--) {
            int l /* 数学左闭区间 */, r /* 数学右闭区间 */;
            std::cin >> l >> r;

            std::cout << prefix[r] - prefix[l - 1] << std::endl;
        }
    }

    /**
     * 结果: 12
     * 28
     * 33
     */
    void case2() {
        int n /* 矩阵行数 */, m /* 矩阵列数 */, q /* 查询次数 */;
        std::cin >> n >> m >> q;

        std::vector prefix(n + 1, std::vector(m + 1, 0));

        for (int i = 1; i <= n; ++i)
            for (int j = 1, num /* 矩阵元素 */; j <= m; ++j) {
                std::cin >> num;

                prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1] + num;
            }

        while (q--) {
            int x1 /* 左上x */, x2 /* 右下x */, y1 /* 左上y */, y2 /* 右下y */;
            std::cin >> x1 >> y1 >> x2 >> y2;

            std::cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << std::endl;
        }
    }

}  // namespace algo::prefix_sum
