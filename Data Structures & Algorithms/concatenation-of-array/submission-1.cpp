class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        const int original_length = static_cast<int>(nums.size());
        for (int i=0; i < original_length; i++) {
            nums.push_back(nums[i]);
            // my idea is the capacity extension only happen once due to c++ mechanism, because the original capacity is n, so the first time will extend it to 2 x n, and 2 x n is the size we want, so overall, the push_back is O(1)
        }
        return nums;
    }
};