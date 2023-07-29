class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> count;
    unordered_set<int> occurrences;

    for (const int a : arr)
      ++count[a];

    for (const auto& [_, value] : count)
      if (!occurrences.insert(value).second)
        return false;

    return true;
  }
};
