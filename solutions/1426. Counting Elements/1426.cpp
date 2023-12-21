class Solution {
 public:
  int countElements(vector<int>& arr) {
    unordered_set<int> arrSet{arr.begin(), arr.end()};
    return ranges::count_if(arr,
                            [&arrSet](int a) { return arrSet.count(a + 1); });
  }
};
