class Solution {
 public:
  int convertTime(string current, string correct) {
    const vector<int> ops{60, 15, 5, 1};
    int diff = getMinutes(correct) - getMinutes(current);
    int ans = 0;

    for (const int op : ops) {
      ans += diff / op;
      diff %= op;
    }

    return ans;
  }

 private:
  int getMinutes(const string& s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
  }
};
