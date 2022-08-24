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
      if (prefixToIndex.count(prefix - target))
        leftLength = min(leftLength, i - prefixToIndex[prefix - target]);
      if (leftLength < INT_MAX)
        if (prefixToIndex.count(prefix + target))
          ans = min(ans, leftLength + prefixToIndex[prefix + target] - i);
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
