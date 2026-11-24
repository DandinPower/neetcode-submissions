class Solution {

private:
    vector<int> memory;

    int helper(int n) {
        if (n == 0) {
            memory[n] = 0;
        }        
        else if (n == 1) {
            memory[n] = 1;
        }
        else if (n == 2) {
            memory[n] = 2;
        }
        else {
            memory[n] = helper(n-1) + helper(n-2);

        }
        return memory[n];
    }

public:

    int climbStairs(int n) {
        memory.reserve(n+1);
        return helper(n);
    }
};
