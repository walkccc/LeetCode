class Solution {
 public:
  bool canReorderDoubled(vector<int>& A) {
    unordered_map<int, int> count;

    for (const int a : A)
      ++count[a];

    sort(A.begin(), A.end(),
         [](const int a, const int b) { return abs(a) < abs(b); });

    for (int a : A) {
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
