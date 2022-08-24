class Solution {
 public:
  int numberOfRounds(string startTime, string finishTime) {
    const int start = getMinutes(startTime);
    int finish = getMinutes(finishTime);
    if (start > finish)
      finish += 60 * 24;
    return max(0, finish / 15 - (start + 14) / 15);
  }

 private:
  int getMinutes(const string& s) {
    return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3));
  }
};
