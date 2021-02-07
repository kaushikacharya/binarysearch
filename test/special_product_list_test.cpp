/**
* Problem: Special Product List
* URL: https://binarysearch.com/problems/Special-Product-List
* Date: Feb 07, 2021
*/

#include <special_product_list.hpp>
#include <lest.hpp>

const lest::test tests[] = {
    {CASE("Test case: 1"){
        vector<int> nums = {1, 2, 3, 4, 5};
        vector<int> prods = {120, 60, 40, 30, 24};
        EXPECT(solve(nums) == prods);
    }},
    {CASE("Test case: 2"){
        vector<int> nums = {3, 2, 1};
        vector<int> prods = {2, 3, 6};
        EXPECT(solve(nums) == prods);
    }},
    {CASE("Test case: 3"){
        vector<int> nums = {3, 2};
        vector<int> prods = {2, 3};
        EXPECT(solve(nums) == prods);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
