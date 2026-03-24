// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file twoPointers.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/23 22:16
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include <iostream>
#include <string>
#include <unordered_map>

namespace algo::twoPointers {

    void case2() {
        /*
         * int last[256];
         * std::fill_n(last, 256, -1);
         * int left = 0, maxLen = 0;
         * int n = s.size();
         *
         * for (int i = 0; i < n; ++i) {
         *     unsigned char c = s[i];
         *     if (last[c] >= left)
         *         left = last[c] + 1;
         *
         *     last[c] = i;
         *     maxLen = std::max(maxLen, i - left + 1);
         * }
         *
         * return maxLen;
         */

        std::string s;
        std::getline(std::cin, s);

        int maxLength = 0;
        std::unordered_map<char, int> charMap;

        for (int i{0}, left{0}; i < s.size(); ++i) {
            if (charMap.contains(s[i]) && charMap[s[i]] >= left) left = charMap[s[i]] + 1;

            charMap[s[i]] = i;

            maxLength = std::max(maxLength, i - left + 1);
        }

        std::cout << maxLength;
    }

}  // namespace algo::twoPointers