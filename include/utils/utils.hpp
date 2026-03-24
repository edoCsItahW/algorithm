// Copyright (c) 2026. All rights reserved.
// This source code is licensed under the CC BY-NC-SA
// (Creative Commons Attribution-NonCommercial-NoDerivatives) License, By Xiao Songtao.
// This software is protected by copyright law. Reproduction, distribution, or use for commercial
// purposes is prohibited without the author's permission. If you have any questions or require
// permission, please contact the author: 2207150234@st.sziit.edu.cn

/**
 * @file utils.hpp
 * @author edocsitahw
 * @version 1.1
 * @date 2026/03/17 13:42
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#ifndef ALGORITHM_UTILS_HPP
#define ALGORITHM_UTILS_HPP
#pragma once

#include <iostream>
#include <sstream>
#include "fstr.hpp"

namespace algo {

    template<typename F>
    void test(const std::string_view data, F&& f) {
        // 保留原始缓冲区
        std::streambuf* originalCin = std::cin.rdbuf();

        // 构造输入字符串
        std::istringstream iss(data.data());

        // 替换cin的缓冲区
        std::cin.rdbuf(iss.rdbuf());

        // 执行测试
        f();

        // 恢复原始缓冲区
        std::cin.rdbuf(originalCin);
    }

    template<typename F>
    void test(F&& f, std::string_view data) {
        test(data, std::forward<F>(f));
    }

    template<typename F, typename... Args>
    void test(F&& f, Args&&... args) {
        std::ostringstream oss;

        ((oss << args << '\n'), ...);

        test(std::string_view(oss.str()), f);
    }

}  // namespace algo

#endif  // ALGORITHM_UTILS_HPP
