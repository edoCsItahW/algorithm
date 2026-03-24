// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file binarySearch.cpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/02/26 10:21
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include "binarySearch/index.hpp"
#include <iostream>
#include <vector>
#include <iterator>

// template<std::size_t N>
// constexpr int binarySearch(const std::array<int, N>& arr, int target) {
//     int l = 0, r = N - 1;
//
//     while (l <= r) {
//         int mid = l + (r - l) / 2;
//
//         if (arr[mid] == target) return mid;
//
//         if (arr[mid] < target)
//             l = mid + 1;
//
//         else
//             r = mid - 1;
//     }
//
//     return -1;
// }
//
//
// inline int main_() {
//     std::array<int, 10> arr = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
//     int target = 15;
//
//     std::cout << binarySearch(arr, target) << std::endl;
//
//     return 0;
// }

namespace algo::binary_search {

    void case1() {
        int n /* 数组长度 */, target /* 目标值 */;
        std::cin >> n >> target;

        const std::vector arr((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());

        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == target) {
                std::cout << mid;
                return;
            }

            if (arr[mid] > target)
                r = mid - 1;

            else l = mid + 1;
        }

        std::cout << -1;
    }

    void case2() {
        int n /* 数组长度 */, target /* 目标值 */;
        std::cin >> n >> target;

        const std::vector arr((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());


    }

}  // namespace algo::binarySearch
