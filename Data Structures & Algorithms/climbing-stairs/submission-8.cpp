class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n <= 2) return n;
        
        int prevAnswer = 1;
        int currAnswer = 2;
        
        for (int i=3; i <=n; i++) {
            int temp = currAnswer;
            currAnswer += prevAnswer;
            prevAnswer = temp;
        }
        return currAnswer;
    }
};
