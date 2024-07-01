class Solution {
 public:
  int minSumOfLengths(vector<int>& arr, int target) {
    int ans = INT_MAX;
    int leftLength = INT_MAX;
    int prefix = 0;
    unordered_map<int, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < arr.size(); ++i) {
      prefix += arr[i];
      prefixToIndex[prefix] = i;
    }

    prefix = 0;

    for (int i = 0; i < arr.size(); ++i) {
      prefix += arr[i];
      if (const auto it = prefixToIndex.find(prefix - target);
          it != prefixToIndex.cend())
        leftLength = min(leftLength, i - it->second);
      if (leftLength < INT_MAX)
        if (const auto it = prefixToIndex.find(prefix + target);
            it != prefixToIndex.cend())
          ans = min(ans, leftLength + it->second - i);
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
