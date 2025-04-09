class Solution {
 public:
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                        string leaveBob) {
    const int arriveA = toDays(arriveAlice);
    const int leaveA = toDays(leaveAlice);
    const int arriveB = toDays(arriveBob);
    const int leaveB = toDays(leaveBob);
    int ans = 0;

    for (int day = 1; day <= 365; ++day)
      if (arriveA <= day && day <= leaveA && arriveB <= day && day <= leaveB)
        ++ans;

    return ans;
  }

 private:
  const vector<int> days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int toDays(const string& s) {
    const int month = (s[0] - '0') * 10 + (s[1] - '0');
    const int day = (s[3] - '0') * 10 + (s[4] - '0');
    int prevDays = 0;
    for (int m = 1; m < month; ++m)
      prevDays += days[m];
    return prevDays + day;
  }
};
