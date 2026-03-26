// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file template.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/26 13:33
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include <bits/stdc++.h>

namespace algo::fenwick {

    template<typename T>
    struct Fenwick {
        int n;

        // 实际上是原数组区间(i - lowbit(i), i]的和
        std::vector<int> bit;

        Fenwick(int n)
            : n(n)
            // 1-based是为了避免0导致lowbit(0)=0而陷入死循环
            , bit(n + 1, 0) {}

        void add(int i, T x) {
            // i, i + lowbit(i), i + lowbit(i) + lowbit(i + lowbit(i))
            // 累积lowbit，直到超过n
            // 从 i 开始，每步加上当前下标的 lowbit，将对应的 bit 节点加上 x。这样，之后任何前缀和查询都会将这次修改计入正确的位置。
            for (; i <= n; i += i & -i) bit[i] += x;
        }

        /**
         * - 目的：返回原数组下标 1 到 i 的元素和。
         * - 原理：区间 [1, i] 可被拆分成若干个不相交的树状数组节点覆盖的区间。例如，i=7 (111₂) 时，节点顺序为 bit[7]（覆盖 [7,7]），然后 i 减去 lowbit(7)=1 得 6，bit[6]（覆盖 [5,6]），再 i 减去
         * lowbit(6)=2 得4，bit[4]（覆盖 [1,4]），刚好覆盖整个 [1,7]。
         * - 过程：从 i 开始，每步减去当前下标的 lowbit，累加对应的 bit 值，直到 i 变为 0。
         *
         * @param i
         * @return
         */
        T sum(int i) {
            T s = 0;

            for (; i > 0; i -= i & -i) s += bit[i];

            return s;
        }

        T rangeSum(int left, int right) {
            // 利用前缀和的可减性，直接计算[l, r]的和。这是树状数组的标准用法
            return sum(right) - sum(left);
        }
    };

}  // namespace algo::fenwick
