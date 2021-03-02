class Solution {
 public:
  Solution(vector<int>& w) : accumulated(move(w)) {
    for (int i = 1; i < accumulated.size(); ++i)
      accumulated[i] += accumulated[i - 1];
  }

  int pickIndex() {
    const int target = rand() % accumulated.back();
    int l = 0;
    int r = accumulated.size();

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (accumulated[m] > target)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  vector<int> accumulated;
};
