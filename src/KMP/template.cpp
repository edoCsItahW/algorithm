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
 * @date 2026/03/26 13:19
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include <bits/stdc++.h>

namespace algo::kmp {

    std::vector<int> prefix(const std::string& str) {
        int n = str.size();

        std::vector pi(n, 0);

        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];

            while (j > 0 && str[i] != str[j]) j = pi[j - 1];

            if (str[i] == str[j]) ++j;

            pi[i] = j;
        }

        return pi;
    }

    std::vector<int> kmp(const std::string& text, const std::string& pattern) {
        if (pattern.empty()) return {};

        std::vector<int> pi = prefix(pattern);
        std::vector<int> matches;

        int n = text.size(), m = pattern.size();

        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];

            if (text[i] == pattern[j]) ++j;

            if (j == m) {
                matches.push_back(i - m + 1);
                j = pi[j - 1];
            }
        }

        return matches;
    }

}  // namespace algo::kmp
