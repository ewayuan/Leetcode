// Subset sums

// 题目描述：
// Find subset of elements that are selected from a given set of positive integers whose sum adds up to a given number K.

// 输入
// A Set of Distinct Intgers and target K    

// 输出
// List of List of Integers. The order is based on the number, Smaller number first.


// 样例输入
// [1,2,3,4,5,6] 6    
// 样例输出
// [[1,2,3],[1,5],[2,4],[6]]



#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
void subsetSums_helper(vector<int>& elements,vector<vector<int>>& results, vector<int>& cur, int K, int index) {
    int size = elements.size();
    
    if (K == 0) {
        results.push_back(cur);
        return;
    }
    if (index > size || K < 0) {
        return;
     }
    // 选
    cur.push_back(elements[index]);
    subsetSums_helper(elements,results,cur,K-elements[index], index+1 );
    cur.pop_back();
            
    // 不选

    subsetSums_helper(elements,results,cur,K, index+1);

}

vector<vector<int>> subsetSums(vector < int > elements, int K) {
    sort(elements.begin(), elements.end());
    vector<vector<int>> results;
    vector<int> cur;
    if (elements.size() == 0) {
        results.push_back({});
        return results;
    }
    subsetSums_helper(elements, results, cur, K, 0);
    return results;
}



/******************************结束写代码******************************/


int main() {
    vector < vector < int > > res;

    int _elements_size = 0;
    cin >> _elements_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _elements;
    int _elements_item;
    for(int _elements_i=0; _elements_i<_elements_size; _elements_i++) {
        cin >> _elements_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _elements.push_back(_elements_item);
    }


    int _K;
    cin >> _K;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    
    res = subsetSums(_elements, _K);
    for(int res_i=0; res_i < res.size(); res_i++) {
        for(int res_j=0; res_j < res[res_i].size(); res_j++) {
            cout << res[res_i][res_j] << " ";
        }
        cout << endl;
    }
    
    return 0;

}
