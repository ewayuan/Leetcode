// form polygon

// 题目描述：
// You have several sticks with different lengths, what you need to do is to decide if those sticks can make one polygon with equal sides.

// You output will be true or false

// 输入
// list of integers to represent sticks

// number of sides of the polygon, 3 to 100

// 输出
// boolean, true or false


// 样例输入
// [1,2,3,2,1] 3
// [1,2,3,2,1] 4

// 样例输出
// true
// false


#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/

bool formPolygon_helper(vector < int >& sticks,vector <int>& visited, int target, int pre_sum,  int sides) {
    if (sides == 1) return true;
    for (int i = 0; i < sticks.size(); i++) {
        if (!visited[i]) {
            int now_cur = pre_sum + sticks[i];
            if (now_cur > target) break;
            visited[i] = 1;
            if (now_cur == target && formPolygon_helper(sticks, visited, target, now_cur, sides-1)) return true;
            else if (formPolygon_helper(sticks, visited, target, now_cur, sides)) return true;
            visited[i] = 0;
        }
    }
}

bool formPolygon(vector < int > sticks, int sides) {
    sort(sticks.begin(), sticks.end());
    int sum = accumulate(sticks.begin(), sticks.end(), 0);
    if (sum % sides != 0) {
        return false;
    }
    int n = sticks.size();
    vector <int> visited(n,0);
    int target = sum / sides;
    return formPolygon_helper(sticks, visited, target, 0, sides);
}
/******************************结束写代码******************************/


int main() {
    bool res;

    int _sticks_size = 0;
    cin >> _sticks_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _sticks;
    int _sticks_item;
    for(int _sticks_i=0; _sticks_i<_sticks_size; _sticks_i++) {
        cin >> _sticks_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _sticks.push_back(_sticks_item);
    }


    int _sides;
    cin >> _sides;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    
    res = formPolygon(_sticks, _sides);
    cout << res << endl;
    
    return 0;

}
