class Solution {
private:
    int helper(int n, vector<int> &memory) {
        if (n <= 0) return 0;
        if (n <= 2) return n;

        if (memory[n-1] != -1) {
            return memory[n-1];
        }

        memory[n-1] = helper(n-1, memory) + helper(n-2, memory);
        return memory[n-1];
    }
public:
    int climbStairs(int n) {
        vector<int> memory(n, -1);
        return helper(n, memory);
    }
};
