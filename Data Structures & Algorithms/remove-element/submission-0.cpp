class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i=0; i<static_cast<int>(nums.size()); i++) {
            if (nums[i] != val) {
                if (i > k) {
                    nums[k] = nums[i];
                }
                k += 1;
            }
        }
        return k;
    }
};