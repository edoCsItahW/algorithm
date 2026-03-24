// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file difference.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/02/25 23:47
 * @brief 差分算法是前缀和算法的逆运算。
 * @details 对于一个数组，其下标i，则差分数组diff[i + 1]表示数组中i + 1与i的元素的差。
 * 由于`diff[i] = arr[i] - arr[i - 1]`，可见求i位置的差要用到i - 1位置的差分。
 * 因此，为了方便计算，可以将diff数组初始化为0，然后从1开始遍历数组，计算diff[i]。
 * 对于给定区间[left, right]，其差diff = arr[right] - arr[left - 1]。
 * 与前缀和算法不同，差分算法不需要保存前缀和，只需要保存当前位置的差分即可。
 * 并且，差分通常设计还原算法，即求出原数组。
 * 差分的还原`arr[i] = diff[1] + diff[2] + ... + diff[i]`。
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */

#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

// int main() {
//     constexpr auto arr = std::array{1, 2, 3, 4, 5};
//
//     std::array<int, arr.size()> diff = {0};
//
//     for (auto i = 1; i < arr.size(); ++i) diff[i] = arr[i] - arr[i - 1];
//
//     constexpr auto left = 2, right = 4;
//
//     const int d = diff[right] - diff[left - 1];
//
//     std::cout << "The difference between [" << left << ", " << right << "] is " << d << std::endl;
//
//     return 0;
// }

namespace algo::difference {

    /*
     * 结果: 2 1 1 -1 -1
     */
    void case1() {
        int n /* 数组长度 */, m /* 操作次数 */;
        std::cin >> n >> m;

        std::vector diff(n + 1, 0);

        for (int i = 0, l /* 数学左闭区间 */, r /* 数学右闭区间 */, c /* 数 */; i < m; ++i) {
            std::cin >> l >> r >> c;

            // 区间l-r值改变后差数组的l和r+1位置会因改变而差的更多，所以对应数组的0-indexd位置l-1和r要改变
            diff[l - 1] += c;
            diff[r] -= c;
        }

        for (int j = 0, sum = diff[j]; j < diff.size() - 1; sum += diff[++j]) std::cout << sum << " ";
    }

    /*
     * 结果: 3 3 0 0
     * 3 2 -1 -1
     * 0 -1 -1 -1
     */
    void case2() {
        int n /* 矩阵行数 */, m /*矩阵列数*/, k /* 操作次数 */;
        std::cin >> n >> m >> k;

        std::vector diff(n + 1, std::vector(m + 1, 0));

        while (k--) {
            int x1 /* 左上x */, y1 /* 左上y */, x2 /* 右下x */, y2 /* 右下y */, c /* 数 */;
            std::cin >> x1 >> y1 >> x2 >> y2 >> c;

            diff[x1 - 1][y1 - 1] += c;
            diff[x2][y1 - 1] -= c;
            diff[x1 - 1][y2] -= c;
            diff[x2][y2] += c;
        }

        std::unordered_map<int, int> cache;
        const std::function<int(int, int)> origin = [&](int x, int y) -> int {
            if (x < 0 || y < 0) return 0;

            if (const auto key = (x + y) * (x + y + 1) / 2 + y; cache.find(key) != cache.end())
                return cache[key];
            else
                return cache[key] = diff[x][y] + origin(x - 1, y) + origin(x, y - 1) - origin(x - 1, y - 1);
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) std::cout << origin(i, j) << " ";

            std::cout << std::endl;
        }
    }

}  // namespace algo::difference
