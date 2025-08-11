class Solution {
 public:
  // Similar to 3265. Count Almost Equal Pairs I
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
  // Returns all possible numbers after 1 or 2 swaps.
  unordered_set<int> getSwaps(const string& digits) {
    const int n = digits.length();
    unordered_set<int> swaps{{stoi(digits)}};

    // Add all numbers after 1 swap.
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        string newDigits = digits;
        swap(newDigits[i], newDigits[j]);
        swaps.insert(stoi(newDigits));
      }

    // Add all numbers after 2 swaps.
    for (int i1 = 0; i1 < n; ++i1)
      for (int j1 = i1 + 1; j1 < n; ++j1)
        for (int i2 = 0; i2 < n; ++i2)
          for (int j2 = i2 + 1; j2 < n; ++j2) {
            string newDigits = digits;
            swap(newDigits[i1], newDigits[j1]);
            swap(newDigits[i2], newDigits[j2]);
            swaps.insert(stoi(newDigits));
          }

    return swaps;
  }
};
