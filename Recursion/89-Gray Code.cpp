class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for (int i = 0; i < n; i++) {
            // k = 2^(i)
            int k = 1 << i;
            int size = result.size();
            for (int j = size-1; j >=0; j--) {
                result.push_back(result[j]+k);
            }
        }
        return result;
    }
};

// 1:   0    => 0
//      1    => 1

// 2:   00   => 0
//      01   => 1
//      ----------- 除了第一位数，互为镜面对称
//      11   => 3  = 1 + 2^(2-1)
//      10   => 2  = 0 + 2^(2-1)

// 3:   000   => 0
//      001   => 1
//      011   => 3
//      010   => 2
//     ----------- 除了第一位数，互为镜面对称
//      110   => 6 = 2+4 = 2+2^(3-1)
//      111   => 7 = 3+4 = 3+2^(3-1)
//      101   => 5 = 1+4 = 1+2^(3-1)
//      100   => 4 = 0+4 = 0+2^(3-1)