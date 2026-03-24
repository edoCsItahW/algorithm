// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file lcs.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/23 16:56
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include "lcs/index.hpp"
#include <iostream>
#include <iterator>
#include <vector>


namespace algo::lcs {

    void case1() {
        std::string text1, text2;
        std::getline(std::getline(std::cin, text1), text2);

        int maxLen = 0;
        for (const auto& c1 : text1)
            for (const auto& c2 : text2)
                if (c1 == c2) ++maxLen;

        std::cout << maxLen;
    }

    void test2() {
        int n;
        std::cin >> n;

        std::vector arr((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());

        std::vector len(n, 1);
        std::vector cnt(n, 1);
        int maxLen = 1;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j) {}
    }

}  // namespace algo::lcs
