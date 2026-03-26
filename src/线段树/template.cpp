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
 * @date 2026/03/25 22:00
 * @brief
 * @copyright CC BY-NC-SA 2026. All rights reserved.
 * */
#include <bits/stdc++.h>

namespace algo::segmentTree {

    struct SegTree {
    private:
        int n;
        std::vector<long long> tree, lazy;

        void build(const std::vector<long long>& arr, int node, int left, int right) {
            if (left == right) {
                tree[node] = arr[left];
                return;
            }

            int mid = (left + right) / 2;

            build(arr, 2 * node, left, mid);
            build(arr, 2 * node + 1, mid + 1, right);

            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }

        /**
         * push 的作用是将当前节点的懒标记下传给直接子节点，并清除当前节点的标记。它只推一层，原因如下：
         * - 当前节点的子节点可能在未来某个时刻被访问（比如查询或更新时），到那时才会再次调用 push 继续下传标记。
         * - 如果 push 递归到底，那么每次更新一个节点都会把整棵子树全部更新，这会破坏懒标记带来的延迟性，使复杂度退化为 O(n)。
         * @param node
         * @param left
         * @param right
         */
        void push(int node, int left, int right) {
            if (lazy[node]) {
                int mid = (left + right) / 2;

                // 直接子节点 += 待加值 * (子树所占长度）（由于是区间跟新，所以子树每个节点都会加，所以要乘子节点数）
                tree[node * 2] += lazy[node] * (mid - left + 1);
                tree[node * 2 + 1] += lazy[node] * (right - mid);

                // 直接子节点的待加值还没有更新，比如还是0，所以传递懒标记
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];

                // 重置已加节点懒标记
                lazy[node] = 0;
            }
        }

        // 如需改为最大值/最小值，只需将 tree[node] = tree[node*2] + tree[node*2+1] 等处的 + 替换为 max/min，并将懒标记处理方式相应调整即可。
        void rangeAdd(int node, int left, int right, int qLeft, int qRight, long long value) {
            // 如果当前节点的区间完全被包含在要更新的区间内，直接更新合与懒标记等待某次push即可
            if (qLeft <= left && right <= qRight) {
                tree[node] += value * (right - left + 1);
                lazy[node] += value;

                return;
            }

            /*
             * 一个区间[qLeft, qRight]应该对应者一棵子树，而不是囊括不同的子树或其部分，
             * 并且线段树子节点的具体值依赖父节点的懒标记下推，如果直接更新值而不先下推，
             * 那结果就全部引用的旧的值
             */
            push(node, left, right);

            int mid = (left + right) / 2;

            if (qLeft <= mid) rangeAdd(node * 2, left, mid, qLeft, qRight, value);

            if (qRight > mid) rangeAdd(node * 2 + 1, mid + 1, right, qLeft, qRight, value);

            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }

        long long rangeSum(int node, int left, int right, int qLeft, int qRight) {
            // 具体原理同上
            if (qLeft < left && right <= qRight) return tree[node];

            push(node, left, right);

            int mid = (left + right) / 2;

            long long res = 0;

            if (qLeft <= mid) res += rangeSum(node * 2, left, mid, qLeft, qRight);

            if (qRight > mid) res += rangeSum(node * 2 + 1, mid + 1, right, qLeft, qRight);

            return res;
        }

    public:
        SegTree(const std::vector<long long>& arr)
            : n(arr.size())
            , tree(4 * n, 0)
            /* 关于为什么用4 * n:
             * 线段树通常使用数组存储，节点编号从 1 开始，左儿子为 2*i，右儿子为 2*i+1。
             * 对于长度为 n 的区间，树的最大节点数出现在 n 不是 2 的幂时。例如当 n=3 时，树需要 7 个节点（根节点编号 1，子节点
             * 2、3，再往下需要节点 4、5、6、7），而 2*n 只有 6 不够。经过推导，最坏情况下所需节点数不超过 4*n，因此竞赛中普遍开 4*n 大小，既安全又简单。
             */
            , lazy(4 * n, 0) {
            build(arr, 1, 0, n - 1);
        }

        void add(int left, int right, long long value) { rangeAdd(1, 0, n - 1, left, right, value); }

        long long sum(int left, int right) { return rangeSum(1, 0, n - 1, left, right); }
    };

}  // namespace algo::segmentTree
