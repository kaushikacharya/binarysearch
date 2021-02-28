#ifndef INVERT_TREE_HPP
#define INVERT_TREE_HPP

#include <bits/stdc++.h>

using namespace std;

class Tree{
    public:
        int val;
        Tree* left;
        Tree* right;
};

Tree* solve(Tree* root);

#endif // INVERT_TREE_HPP
