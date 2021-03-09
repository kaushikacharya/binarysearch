/**
* Problem: Merging K Sorted Lists
* URL: https://binarysearch.com/problems/Merging-K-Sorted-Lists
* Date: Mar 08, 2021
*/

#include<merging_k_sorted_lists.hpp>

vector<int> solve(vector<vector<int>>& lists){
    int approach = 2;
    vector<int> merged_list;

    if (approach == 1){
        merged_list = solve_approach_1(lists);
    }
    else {
        merged_list = solve_approach_2(lists);
    }

    return merged_list;
}

vector<int> solve_approach_1(vector<vector<int>>& lists){
    // Approach: Stores each row's smallest element which has not been added to merged list in a list.
    // Time Complexity: O(n*n*m), where n=number of rows, m=longest column
    //  Explanation can be understood from approach 2.
    //  Space complexity: O(m+n)

    // count total number of elements
    unsigned int n_elements = 0;

    // Keep a list of pairs having first element as i'th row of lists and second element as j'th value of lists[i]
    // This keeps only one element from a row. The next min element is chosen from this list.
    // lists[i,0...,(j-1)] elements are already pushed into merged list.
    list<pair<unsigned int, unsigned int>> min_pos_list;

    for (unsigned int i=0; i != lists.size(); ++i){
        if (lists[i].size() > 0){
            min_pos_list.push_back(make_pair(i, 0));
        }
        n_elements += lists[i].size();
    }

    vector<int> merged_list;
    merged_list.reserve(n_elements);

    int min_elem;
    list<pair<unsigned int, unsigned int>>::iterator min_it;

    while (!min_pos_list.empty()){
        min_elem = INT_MAX;

        for (list<pair<unsigned int, unsigned int>>::iterator it=min_pos_list.begin(); it != min_pos_list.end(); ++it){
            unsigned int i = (*it).first;
            unsigned int j = (*it).second;

            if (lists[i][j] < min_elem){
                min_elem = lists[i][j];
                min_it = it;
            }
        }

        merged_list.push_back(min_elem);

        unsigned int i = (*min_it).first;
        unsigned int j = (*min_it).second;

        // remove min_it from min_pos_list
        min_pos_list.erase(min_it);

        while (++j < lists[i].size()){
            if (lists[i][j] == min_elem){
               merged_list.push_back(min_elem);
            }
            else {
                min_pos_list.push_back(make_pair(i, j));
                break;
            }
        }
    }

    return merged_list;
}


vector<int> solve_approach_2(vector<vector<int>>& lists){
    // Approach: Stores each row's smallest element which has not been added to merged list in a set.
    // Time Complexity: O(log(n)*n*m), where n=number of rows, m=longest column
    // In this approach, finding smallest among the smallest elements set takes
    //      a) find function: O(1)
    //      b) erase function: O(log(n))
    //    This is due to set's implementation as a balanced binary search tree.
    //    Reference: https://stackoverflow.com/questions/2558153/what-is-the-underlying-data-structure-of-a-stl-set-in-c  (Toli's answer)
    //  n*m portion is because of number of elements in lists.
    //  Space complexity: O(m+n)

    // count total number of elements
    unsigned int n_elements = 0;
    // Store the smallest unseen element of each row
    set<tuple<int, unsigned int, unsigned int>> min_pos_set;

    for (unsigned int i=0; i != lists.size(); ++i){
        if (lists[i].size() > 0){
            min_pos_set.insert(make_tuple(lists[i][0], i, 0));
        }
        n_elements += lists[i].size();
    }

    vector<int> merged_list;
    merged_list.reserve(n_elements);

    while (!min_pos_set.empty()){
        set<tuple<int, unsigned int, unsigned int>>::iterator min_it = min_pos_set.begin();
        int min_elem = get<0>(*min_it);
        unsigned int i = get<1>(*min_it);
        unsigned int j = get<2>(*min_it);
        merged_list.push_back(min_elem);
        min_pos_set.erase(min_it);

        while (++j < lists[i].size()){
          if (lists[i][j] == min_elem){
                merged_list.push_back(min_elem);
            }
            else {
                min_pos_set.insert(make_tuple(lists[i][j], i, j));
                break;
            }
        }
    }

    return merged_list;
}
