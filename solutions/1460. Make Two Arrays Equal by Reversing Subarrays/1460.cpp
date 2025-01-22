class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    return unordered_multiset<int>(arr.begin(), arr.end()) ==
           unordered_multiset<int>(target.begin(), target.end());
  }
};
