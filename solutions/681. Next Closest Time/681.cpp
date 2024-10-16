class Solution {
 public:
  string nextClosestTime(string time) {
    const set<char> digitsSet{time[0], time[1], time[3], time[4]};
    string ans = time;

    ans[4] = nextClosest(digitsSet, ans[4], '9');
    if (time[4] < ans[4])
      return ans;

    ans[3] = nextClosest(digitsSet, ans[3], '5');
    if (time[3] < ans[3])
      return ans;

    ans[1] = nextClosest(digitsSet, ans[1], ans[0] == '2' ? '3' : '9');
    if (time[1] < ans[1])
      return ans;

    ans[0] = nextClosest(digitsSet, ans[0], '2');
    return ans;
  }

 private:
  char nextClosest(const set<char>& digitsSet, char digit, char limit) {
    auto it = digitsSet.upper_bound(digit);
    return it == digitsSet.end() || *it > limit ? *digitsSet.begin() : *it;
  }
};
