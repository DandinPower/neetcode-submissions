class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        
        int prevAnswer = 0;
        int currAnswer = 0;
        for (int i=1; i <=n; i++) {
            if (i == 1) {
                currAnswer += 1;
                prevAnswer = currAnswer;
            }
            else if (i == 2) {
                currAnswer += 1;
            }
            else {
                int temp = currAnswer;
                currAnswer += prevAnswer;
                prevAnswer = temp;
            }
        }
        return currAnswer;
    }
};
