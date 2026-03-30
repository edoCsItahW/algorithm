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
 * @date 2026/03/28 13:28
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include <bits/stdc++.h>

namespace algo::manacher {

    std::vector<int> manacher(const std::string& s) {
        std::string t = "#";

        for (char c : s) {
            t += c;
            t += '#';
        }

        int n = t.size();

        std::vector<int> d(n);

        for (int i = 0 /* 遍历字符索引 */, l = 0 /* 最右回文左区间 */, r = -1 /* 最右回文右区间 */; i < n; ++i) {
            // 初始半径
            int k = i > r
                      // 如果 i > r，说明 i 不在当前已知的最右回文区间内，无法利用对称性，只能从半径1开始暴力扩展
                      ? 1
                      // 如果 i <= r，则 i 在区间内。令 j = l + r - i，即 i 关于中心 mid = (l + r)/2 的对称点。
                      // 由于区间 [l, r] 本身是回文，所以 t[j]为中心的回文信息可以部分转移到
                      // i。但转移的半径不能超过 r - i + 1，因为超过右边界就无法保证对称性。因此 k 初始取 min(d[j], r - i + 1)
                      : std::min(d[l + r - i], r - i + 1);

            // 暴力拓展
            while (
                i - k >= 0               // 左边界内
                && i + k < n             // 右边界内
                && t[i - k] == t[i + k]  // 是回文
            )
                ++k;

            d[i] = k--;  // ++k后才检测到不是，所以++前的k才是合法的

            if (i + k > r) {  // 如果当前回文右端点超过最右端点r，则需要更新左右边界
                l = i - k;
                r = i + k;
            }
        }

        return d;
        // 原串中回文长度: len = d[i] - 1
        // 原串中回文中心：若 t[i] 是字符（非 #），则中心在原串字符位置 i/2；若 t[i] 是 #，则中心在原串两个字符之间，对应位置 i/2（整数除法）
    }

}  // namespace algo::manacher
