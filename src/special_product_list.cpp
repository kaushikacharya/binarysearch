/**
* Problem: Special Product List
* URL: https://binarysearch.com/problems/Special-Product-List
* Date: Feb 07, 2021
*
* Algorithm:
*   Iterate first from left to right.
*   As we iterate assign output value at that position with a value which is product of all the elements on its left.
*   Now repeat the iteration from right to left and assign value of product of all the elements on its right.
*
* Time complexity: O(n) since there are only two iterations.
* Space complexity: O(n) for storing nums and the output vector.
*/

#include <special_product_list.hpp>

using namespace std;

vector<int> solve(vector<int>& nums) {
    vector<int> prods(nums.size(), 1);

    int prod = 1;
    for (unsigned int i=1; i < nums.size(); ++i){
        prod *= nums[i-1];
        prods[i] *= prod;
    }

    prod = 1;
    for (int i=nums.size()-2; i >=0; --i){
        prod *= nums[i+1];
        prods[i] *= prod;
    }

    return prods;
}
