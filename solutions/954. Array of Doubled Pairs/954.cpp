class Solution {
 public:
  bool canReorderDoubled(vector<int>& arr) {
    unordered_map<int, int> count;

    for (const int a : arr)
      ++count[a];

    ranges::sort(arr, [](const int a, const int b) { return abs(a) < abs(b); });

    for (const int a : arr) {
      if (count[a] == 0)
        continue;
      if (count[2 * a] == 0)
        return false;
      --count[a];
      --count[2 * a];
    }

    return true;
  }
};
