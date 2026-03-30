#include "binarySearch/index.hpp"
#include "dfs/index.hpp"
#include "difference/index.hpp"
#include "dijkstra/index.hpp"
#include "dp/index.hpp"
#include "include/utils/utils.hpp"
#include "lcs/index.hpp"
#include "prefixSum/index.hpp"
#include "unionFind/index.hpp"


using namespace std;

void Test() {
    // algo::test("5 3\n1 2 3 4 5\n1 3\n2 5\n1 1\n", algo::prefix_sum::case1);

    // algo::test("5 2\n1 3 2\n2 5 -1\n", algo::difference::case1);

    // algo::test("3 3 3\n1 2 3\n4 5 6\n7 8 9\n1 1 2 2\n2 2 3 3\n1 2 3 3\n", algo::prefix_sum::case2);

    // algo::test("3 4 2\n1 1 2 2 3\n2 2 3 4 -1\n", algo::difference::case2);

    // algo::test("6 9\n1 3 5 7 9 11\n", algo::binary_search::case1);

    // algo::test("3 3\n0 0 2\n1 0 1\n0 0 2", algo::dfs::case1);

    // algo::test("8", algo::dfs::case2);

    // algo::test(algo::dp::case1, "10");

    // algo::test(algo::dp::case2, "4 5", "1 2", "2 4", "3 4", "4 5");

    // algo::test(algo::dijkstra::case1, "4 5 1 4\n1 2 1\n1 3 2\n2 3 1\n2 4 3\n3 4 1\n");

    // algo::test(algo::lcs::case1, "abcde", "ace");

    algo::test(algo::unionFind::case1, "4 7", "1 1 2", "2 1 2", "2 1 3", "1 2 3", "2 1 3", "1 3 4", "2 1 4");
}

#include <iterator>
#include <vector>

std::vector<int> prefix(const std::string& str) {
    int n = str.size();

    std::vector pi(n, 0);

    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        std::cout << std::endl << '"';
        std::copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout, " "));
        std::cout << "\", i = " << i << ", pi: [";
        std::copy(pi.begin(), pi.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << ']' << std::endl;
        std::cout << ' ' << std::string(2 * i, ' ') << 'i' << std::endl << ' ' << std::string(2 * j, ' ') << 'j' << std::string(2 * (n - j), ' ') << ", j = pi[i - 1] = " << j << std::endl;
        while (j > 0 && str[i] != str[j]) {
            std::cout << "x[j = pi[" << j << "-1]] -> ";
            j = pi[j - 1];
        }

        if (str[i] == str[j]) {
            ++j;
            std::cout << "=[++j=" << j << "]" << std::endl;
        }

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

// int main() {
//     system("chcp 65001>nul");
//     ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//
//     // Test();
//     return 0;
// }
