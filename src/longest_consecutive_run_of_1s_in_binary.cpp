/**
* Problem: Longest Consecutive Run of 1s in Binary
* URL: https://binarysearch.com/problems/Longest-Consecutive-Run-of-1s-in-Binary
* Date: Feb 08, 2021
*
* Algorithm:
*   Apply the algorithm to convert an int into binary.
*   Keep dividing by 2 till the quotient becomes 0.
*   And keep track of the count of remainders which are consecutive 1.
*
* Time complexity: O(log(n))
* Space complexity: O(1)
*
* Reference:
*   https://indepth.dev/posts/1019/the-simple-math-behind-decimal-binary-conversion-algorithms
*/

#include <longest_consecutive_run_of_1s_in_binary.hpp>

using namespace std;

int solve(int n) {
    int n_consecutive_run = 0;
    int quotient = n;
    int remainder;
    int cur_consecutive_run = 0;

    while (quotient > 0){
        remainder = quotient%2;
        quotient /= 2;

        if (remainder == 1){
            ++cur_consecutive_run;
        }
        else {
            // check if latest consecutive run of 1s is bigger than the stored one.
            n_consecutive_run = max(n_consecutive_run, cur_consecutive_run);
            // reset consecutive run of 1s to zero
            cur_consecutive_run = 0;
        }
    }

    // check the last batch of 1s (if available)
    n_consecutive_run = max(n_consecutive_run, cur_consecutive_run);

    return n_consecutive_run;
}
