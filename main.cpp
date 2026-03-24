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


int main() {
    system("chcp 65001>nul");
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Test();

    return 0;
}
