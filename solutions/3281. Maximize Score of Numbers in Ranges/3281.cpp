class Solution {
 public:
  int maxPossibleScore(vector<int>& start, int d) {
    ranges::sort(start);

    long l = 0;
    long r = (start.back() + d) - start.front() + 1;

    while (l < r) {
      const long m = (l + r) / 2;
      if (isPossible(start, d, m))
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }

 private:
  bool isPossible(const vector<int>& start, int d, long m) {
    int lastPick = start[0];
    for (int i = 1; i < start.size(); ++i) {
      if (lastPick + m > start[i] + d)
        return false;
      lastPick = max(lastPick + m, static_cast<long>(start[i]));
    }
    return true;
  }
};
