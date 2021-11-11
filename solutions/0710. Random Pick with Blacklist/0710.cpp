class Solution {
 public:
  Solution(int N, vector<int>& blacklist) : validRange(N - blacklist.size()) {
    for (const int b : blacklist)
      map[b] = -1;

    int maxAvailable = N - 1;

    for (const int b : blacklist)
      if (b < validRange) {
        while (map.count(maxAvailable))  // find the slot that haven't been used
          --maxAvailable;
        map[b] = maxAvailable--;
      }
  }

  int pick() {
    const int num = rand() % validRange;
    return map.count(num) ? map[num] : num;
  }

 private:
  const int validRange;
  unordered_map<int, int> map;
};
