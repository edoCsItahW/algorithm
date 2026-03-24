// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file dynamicProgramming.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/22 18:21
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include "dp/index.hpp"
#include <iostream>
#include <vector>


namespace algo::dp {

    void case1() {
        int n /* 台阶总数 */;
        std::cin >> n;

        std::vector dp(n + 2, 0);
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < n + 2; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        std::cout << dp[n + 1];
    }

    void case2() {
        int N /* 物品数量 */, V /* 背包容量 */;
        std::cin >> N >> V;

        using Widght = int;
        using Value = int;
        using Item = std::pair<Widght, Value>;

        std::vector items(N, Item{});

        for (std::size_t i{0}; i < N; ++i)
            std::cin >> items[i].first >> items[i].second;

        // std::vector dp(N + 1, std::vector(V + 1, 0));  // 索引范围: [0, N]
        // for (int i = 1; i <= N; ++i)
        //     for (int j /* 容量 */ = 0; i <= V; ++j) {
        //         dp[i][j] = dp[i - 1][j];
        //
        //         if (const auto& [prevW, prevV] = items[i - 1]; j >= prevW)
        //             dp[i][j] = std::max(dp[i][j], dp[i - 1][j - prevW] + prevV);  // 比较
        //     }
        //
        // std::cout << dp[N][V];

        // 滚动数组优化
        std::vector dp(V + 1, 0);

        for (int i = 1, j = V; i <= N; ++i, j = V)
            for (const auto& item = items[i - 1]; j >= item.first; --j)
                dp[j] = std::max(dp[j], dp[j - item.first] + item.second);

        std::cout << dp[V];
    }

    void case_1() {
        std::string text1, text2;
        std::getline(std::getline(std::cin, text1), text2);


    }

}  // namespace algo::dp
