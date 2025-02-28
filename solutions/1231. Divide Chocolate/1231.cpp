class Solution {
 public:
  int maximizeSweetness(vector<int>& sweetness, int k) {
    int l = sweetness.size() / (k + 1);
    int r = accumulate(sweetness.begin(), sweetness.end(), 0) / (k + 1);

    while (l < r) {
      const int m = (l + r) / 2;
      if (canEat(sweetness, k, m))
        l = m + 1;
      else
        r = m;
    }

    return canEat(sweetness, k, l) ? l : l - 1;
  }

 private:
  // Returns true if can eat m sweetness (the minimum sweetness of each piece).
  bool canEat(const vector<int>& sweetness, int k, int m) {
    int pieces = 0;
    int sum = 0;  // the running sum

    for (const int s : sweetness) {
      sum += s;
      if (sum >= m) {
        if (++pieces > k)
          return true;
        sum = 0;
      }
    }

    return false;
  };
};
