class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = -1;
        for (int index=static_cast<int>(arr.size())-1; index >= 0; index--) {
            int val = arr[index];
            arr[index] = max;
            max = std::max(max, val);
        }
        return arr;
    }
};