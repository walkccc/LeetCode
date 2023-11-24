class Solution {
 public:
  int numberOfRounds(string loginTime, string logoutTime) {
    const int start = getMinutes(loginTime);
    int finish = getMinutes(logoutTime);
    if (start > finish)
      finish += 60 * 24;
    return max(0, finish / 15 - (start + 14) / 15);
  }

 private:
  int getMinutes(const string& time) {
    const int h = stoi(time.substr(0, 2));
    const int m = stoi(time.substr(3));
    return 60 * h + m;
  }
};
