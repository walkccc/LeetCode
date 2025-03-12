class Solution {
 public:
  int countPairs(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> count;
    const int maxLen = to_string(ranges::max(nums)).length();

    for (const int num : nums) {
      const string digits =
          string(maxLen - to_string(num).length(), '0') + to_string(num);
      for (const int swap : getSwaps(digits))
        ans += count[swap];
      ++count[num];
    }

    return ans;
  }

 private:
  // Returns all possible numbers after 1 swap.
  unordered_set<int> getSwaps(const string& digits) {
    const int n = digits.length();
    unordered_set<int> swaps{{stoi(digits)}};

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        string newDigits = digits;
        swap(newDigits[i], newDigits[j]);
        swaps.insert(stoi(newDigits));
      }

    return swaps;
  }
};
