class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int temp_counter = 0;
        for (int i=0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i]) {
                temp_counter += 1;
            }
            else {
                temp_counter = 0;
            }
            max = std::max(max, temp_counter);
        }
        return max;
    }
};