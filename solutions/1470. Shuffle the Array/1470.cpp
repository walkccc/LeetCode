class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(2 * n); // Initialize result array
        int i = 0, j = n, k = 0;
        while (i < n && j < 2 * n) {
            result[k++] = nums[i++]; // Add xi to result
            result[k++] = nums[j++]; // Add yi to result
        }
        return result;
    }
};
