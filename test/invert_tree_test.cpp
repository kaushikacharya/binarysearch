#include <invert_tree.hpp>
#include <lest.hpp>

const lest::test tests[] = {
    {CASE("Single node"){
        Tree* root = new Tree;
        root->val = 3;
        root->left = nullptr;
        root->right = nullptr;
        Tree* inverted_root = solve(root);
        EXPECT(inverted_root->val == 3);
        EXPECT(inverted_root->left == nullptr);
        EXPECT(inverted_root->right == nullptr);
    }},
    {CASE("Empty tree"){
        Tree* root = nullptr;
        Tree* inverted_root = solve(root);
        EXPECT(inverted_root == nullptr);
    }},
    {CASE("Test case 3"){
        Tree* root = new Tree;
        root->val = 8;
        root->left = nullptr;
        Tree* node_9 = new Tree;
        node_9->val = 9;
        node_9->left = nullptr;
        node_9->right = nullptr;
        root->right = node_9;

        Tree* inverted_root = solve(root);
        EXPECT(inverted_root->val == 8);
        EXPECT(inverted_root->right == nullptr);
        EXPECT(inverted_root->left->val == 9);
        EXPECT(inverted_root->left->left == nullptr);
        EXPECT(inverted_root->left->right == nullptr);
    }},
    {CASE("Test case 4"){
        Tree* root = new Tree;
        root->val = 0;

        Tree* node_2 = new Tree;
        node_2->val = 2;
        node_2->left = nullptr;
        node_2->right = nullptr;
        root->left = node_2;

        Tree* node_9 = new Tree;
        node_9->val = 9;
        node_9->left = nullptr;
        node_9->right = nullptr;
        root->right = node_9;

        Tree* inverted_root = solve(root);
        EXPECT(inverted_root->val == 0);
        EXPECT(inverted_root->left->val == 9);
        EXPECT(inverted_root->right->val == 2);

        EXPECT(inverted_root->left->left == nullptr);
        EXPECT(inverted_root->left->right == nullptr);
        EXPECT(inverted_root->right->left == nullptr);
        EXPECT(inverted_root->right->right == nullptr);
    }},



    {CASE("Test case 5"){
        Tree* root = new Tree;
        root->val = 0;

        Tree* node_2 = new Tree;
        node_2->val = 2;
        node_2->left = nullptr;
        node_2->right = nullptr;
        root->left = node_2;

        Tree* node_9 = new Tree;
        node_9->val = 9;

        Tree* node_7 = new Tree;
        node_7->val = 7;
        node_7->left = nullptr;
        node_7->right = nullptr;

        Tree* node_12 = new Tree;
        node_12->val = 12;
        node_12->left = nullptr;
        node_12->right = nullptr;

        node_9->left = node_7;
        node_9->right = node_12;
        root->right = node_9;

        Tree* inverted_root = solve(root);
        EXPECT(inverted_root->val == 0);
        EXPECT(inverted_root->right->val == 2);
        EXPECT(inverted_root->left->val == 9);
        EXPECT(inverted_root->right->left == nullptr);
        EXPECT(inverted_root->right->right == nullptr);

        EXPECT(inverted_root->left->left->val == 12);
        EXPECT(inverted_root->left->right->val == 7);

        EXPECT(inverted_root->left->left->left == nullptr);
        EXPECT(inverted_root->left->left->right == nullptr);

        EXPECT(inverted_root->left->right->left == nullptr);
        EXPECT(inverted_root->left->right->right == nullptr);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}

