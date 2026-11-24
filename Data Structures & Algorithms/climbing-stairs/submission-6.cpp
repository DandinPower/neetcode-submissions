class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        
        int prevAnswer = 1;
        int currAnswer = 2;
        int temp;
        for (int i=3; i <=n; i++) {
            temp = currAnswer;
            currAnswer += prevAnswer;
            prevAnswer = temp;
        }
        return currAnswer;
    }
};
