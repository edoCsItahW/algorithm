// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file dfs.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/18 14:46
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include "dfs/index.hpp"
#include <bitset>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

namespace algo::dfs {

    void case1() {
        int n /* 迷宫的行数 */, m /* 迷宫的列数 */;
        std::cin >> n >> m;

        const std::vector arr((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());
        int count   = 0;
        std::uint64_t visited = 0;

        // 1-indexed
        const std::function<void(int)> dfs = [&](const int index) {
            if (
                index >= n * m           // 上溢
                || visited & 1ull << index  // 重复
                || index < 0             // 下溢
                || arr[index] == 1       // 墙
            )
                return;

            if (arr[index] == 2) {
                count++;
                return;
            }

            visited |= 1ull << index;

            if (index / m) dfs(index - m);           // 向上
            if (index / m != n - 1) dfs(index + m);  // 向下
            if (index % m != m - 1) dfs(index + 1);  // 向右
            if (index % m) dfs(index - 1);           // 向左

            visited &= ~(1ull << index);
        };

        dfs(0);  // 1-indexed

        std::cout << count;
    }

    void case2() {
        int n;
        std::cin >> n;

        std::vector<std::pair<int, int>> path;  // 存储当前放置的皇后坐标

        struct Mark {
            std::bitset<32> rowUsed, colUsed;      // 行、列占用
            std::bitset<64> diag1Used, diag2Used;  // 两个对角线占用（范围0~2n-2）
            int n;

            Mark(int n)
                : n(n) {}

            // 映射主对角线索引 (r - c) 到 [0, 2n-2]
            [[nodiscard]] int diag1Index(int r, int c) const { return r - c + n - 1; }

            // 副对角线索引 (r + c) 自然在 [0, 2n-2] 内
            [[nodiscard]] int diag2Index(int r, int c) const { return r + c; }

            void set(int r, int c) {
                rowUsed.set(r);
                colUsed.set(c);
                diag1Used.set(diag1Index(r, c));
                diag2Used.set(diag2Index(r, c));
            }

            void reset(int r, int c) {
                rowUsed.reset(r);
                colUsed.reset(c);
                diag1Used.reset(diag1Index(r, c));
                diag2Used.reset(diag2Index(r, c));
            }

            [[nodiscard]] bool isSafe(int r, int c) const { return !rowUsed.test(r) && !colUsed.test(c) && !diag1Used.test(diag1Index(r, c)) && !diag2Used.test(diag2Index(r, c)); }
        };

        Mark mark(n);
        bool found = false;  // 标记是否找到解（可改为计数或输出所有解）

        std::function<void(int)> dfs = [&](int row) {
            if (found) return;

            if (row == n) {
                // 成功放置了 n 个皇后
                std::copy(path.begin(), path.end(), std::ostream_iterator<std::pair<int, int>>(std::cout, " "));

                found = true;
                return;
            }

            for (int col = 0; col < n; ++col)
                if (mark.isSafe(row, col)) {
                    mark.set(row, col);
                    path.emplace_back(row, col);

                    dfs(row + 1);  // 进入下一行

                    path.pop_back();
                    mark.reset(row, col);
                }
        };

        dfs(0);

        if (!found) std::cout << "No solution" << std::endl;
    }


}  // namespace algo::dfs

namespace std {
    std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& pair) {
        os << "(" << pair.first << ", " << pair.second << ")";
        return os;
    }
}  // namespace std
