#include <merging_k_sorted_lists.hpp>
#include <lest.hpp>

const lest::test tests[] = {
    {CASE("Test Case 1"){
        vector<vector<int>> lists{
        {},
        {},
        {10, 12},
        {},
        {3, 3, 13},
        {3},
        {10},
        {0, 7}
        };
        vector<int> merged_list{0, 3, 3, 3, 7, 10, 10, 12, 13};
        EXPECT(solve(lists) == merged_list);
    }},
    {CASE("Test Case 2"){
        vector<vector<int>> lists{
        {10, 12},
        {3, 3, 13},
        {3},
        {10},
        {0, 7}
        };
        vector<int> merged_list{0, 3, 3, 3, 7, 10, 10, 12, 13};
        EXPECT(solve(lists) == merged_list);
    }},
    {CASE("Test Case 3"){
        vector<vector<int>> lists{
        {},
        {}
        };
        vector<int> merged_list{};
        EXPECT(solve(lists) == merged_list);
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
