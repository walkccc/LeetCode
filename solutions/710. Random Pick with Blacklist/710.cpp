class Solution {
 public:
  Solution(int n, vector<int>& blacklist) : validRange(n - blacklist.size()) {
    for (const int b : blacklist)
      map[b] = -1;

    int maxAvailable = n - 1;

    for (const int b : blacklist)
      if (b < validRange) {
        // Find the slot that haven't been used.
        while (map.count(maxAvailable))
          --maxAvailable;
        map[b] = maxAvailable--;
      }
  }

  int pick() {
    const int num = rand() % validRange;
    const auto it = map.find(num);
    return it == map.cend() ? num : it->second;
  }

 private:
  const int validRange;
  unordered_map<int, int> map;
};
