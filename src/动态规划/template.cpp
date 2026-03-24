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
 * @date 2026/03/24 18:17
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include <bits/stdc++.h>

namespace algo::dp {

    template<std::size_t N>
    int knapsack01(int W, std::array<int, N>& v, std::array<int, N>& w) {
        std::vector<int> dp(W + 1);

        for (int i = 0; i < N; i++)
            for (int j = W; j >= w[i]; j--) dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);

        return dp[W];
    }

    template<std::size_t N>
    int knapsackComplete(int W, std::array<int, N>& v, std::array<int, N>& w) {
        std::vector<int> dp(W + 1);

        for (int i = 0; i < N; i++)
            for (int j = w[i]; j <= W; j++) dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);

        return dp[W];
    }

    template<std::size_t N>
    int knapsackMultiple(int W, std::array<int, N>& v, std::array<int, N>& w, std::array<int, N>& c) {
        std::vector<int> dp(W + 1);

        for (int i = 0; i < N; i++) {
            int cnt = c[i];  // 数量

            for (int k = 1; k <= cnt; k <<= 1) {
                int ww = w[i] * k, vv = v[i] * k;

                for (int j = W; j >= ww; --j) dp[j] = std::max(dp[j], dp[j - ww] + vv);
            }
        }

        return dp[W];
    }

    template<std::size_t N>
    int lis(std::array<int, N>& arr) {
        std::vector<int> tail;

        for (int x : arr)
            if (auto it = std::lower_bound(tail.begin(), tail.end(), x); it == tail.end())
                tail.push_back(x);
            else
                *it = x;

        return tail.size();
    }

    template<std::size_t N, std::size_t M>
    int lcs(std::array<int, N>& a, std::array<int, M>& b) {
        std::vector dp(N + 1, std::vector<int>(M + 1));

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);

        return dp[N][M];
    }


}  // namespace algo::dp
