#include <longest_consecutive_run_of_1s_in_binary.hpp>
#include <lest.hpp>

const lest::test tests[] = {
    {CASE("Test Case 1"){
        int n = 156;
        EXPECT(solve(n) == 3);
    }},
    {CASE("Test Case 2"){
        int n = 10;
        EXPECT(solve(n) == 1);
    }},
    {CASE("Test Case 3"){
        int n = 11;
        EXPECT(solve(n) == 2);
    }},
    {CASE("Test Case 4"){
        int n = 1;
        EXPECT(solve(n) == 1);
    }},
    {CASE("Test Case 5"){
        int n = 6;
        EXPECT(solve(n) == 2);
    }},
    {CASE("Test Case 6"){
        int n = 0;
        EXPECT(solve(n) == 0);
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
