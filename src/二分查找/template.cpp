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
 * @date 2026/03/24 16:21
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include <bits/stdc++.h>

namespace algo::binarySearch {

    template<std::size_t N>
    int intergetBinarySearch(std::array<int, N> arr, int target) {
        int low = 0, high = N - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return mid;

            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    // double lo = 0, hi = 1e9;
    // for (int iter = 0; iter < 60; ++iter) {   // 60 次足够 1e-18 精度
    //     double mid = (lo + hi) / 2;
    //     if (check(mid)) {
    //         lo = mid;                         // 保留可行半区
    //     } else {
    //         hi = mid;
    //     }
    // }
    // double ans = lo;                          // 最终逼近值

    // 找到第一个使得 comp(val, a[mid]) 为真的位置
    // auto it = lower_bound(a.begin(), a.end(), val);
    // 若需要自定义比较函数
    // auto it = lower_bound(a.begin(), a.end(), val, [](int x, int y) { return x < y; });

}  // namespace algo::binarySearch
