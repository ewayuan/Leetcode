// Lucky numbers
 
// 题目描述：
// Lucky Numbers

// 888 is a lucky number. And for each American phone number, we can actually add some operators to make it become 888. For example:

// phone number is 7765332111, you will have

// 7/7*65*3+3*21*11 = 888

// 776+5+3*32+11*1 = 888

// We want to get a full list of all the operation equations that can get a certain lucky number


// Additional information:

// String num will always be 10 digits since it is a phone number.

// we can have "0" but we cannot have "05", "032".

// If a number cannot be divided, you cannot use it. For example, 55/2 is not allowed, you need to make sure the division can always be an integer result.

// 0 cannot be divided.

// 输入
// a string represents the num and a target

// 输出
// The list of string that can compute the target


// 样例输入
// "123456"
// 1
// 样例输出
// 1*2*3-4+5-6
// 1*2-3*4+5+6
// 1+2+3-4+5-6
// 1-2-3+4-5+6
// 12+3-4*5+6
// 12-3*4-5+6
// 12/3-4-5+6


#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <string>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
void luckyNumbers_helper(string num, int target, string temp, int pos, int current, int last, vector<string>& results) {
    //cout << "temp: " << temp << endl;
    if (num.size() == 0 && current == target) {
        results.push_back(temp);
    }
    
    for (int i = 1; i <= num.size(); i++) {
        //if (i != pos) break;
        string m = num.substr(0,i);
        //cout << "m: " << m << endl;
        long long n = stoll(m);
        //cout << "n: " << n << endl;
        if (m[0] == '0' && i!= pos) break;
        string next = num.substr(i);
        if (temp.size() == 0) {
            luckyNumbers_helper(next, target, m, i+1, n,n,results);
        } else {
            luckyNumbers_helper(next, target, temp + "+" + m,  i+1, current + n, n, results);
            luckyNumbers_helper(next, target,  temp + "-" + m, i+1, current - n, -n,results);
            luckyNumbers_helper(next, target, temp + "*" + m, i+1, (current - last) + last * n, last * n, results);
            if (n != 0 && last % n == 0) {
                luckyNumbers_helper(next, target, temp + "/" + m, i+1, (current - last) + last / n, last / n, results);
            }
         }
         
    }
}


vector<string> luckyNumbers(string num, int target) {
    vector<string> results;
    luckyNumbers_helper(num, target, "", 0, 0,0, results);
    return results;
}

/******************************结束写代码******************************/


int main() {

    vector<string> res = luckyNumbers("123456", 1);
    int n = res.size();
    for(int res_i=0; res_i < n; res_i++) {
        cout << res[res_i] << endl;;
    }
    
    return 0;

}


/*
int main() {
    vector < string > res;

    string _num;
    getline(cin, _num);
    int _target;
    cin >> _target;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    
    res = luckyNumbers(_num, _target);
    sort(res.begin(), res.end());
    for(int res_i=0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }
    
    return 0;

}

*/