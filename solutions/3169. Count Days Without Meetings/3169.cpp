class Solution {
 public:
  int countDays(int days, vector<vector<int>>& meetings) {
    int freeDays = 0;
    int prevEnd = 0;

    ranges::sort(meetings);

    for (const vector<int>& meeting : meetings) {
      const int start = meeting[0];
      const int end = meeting[1];
      if (start > prevEnd)
        freeDays += start - prevEnd - 1;
      prevEnd = max(prevEnd, end);
    }

    return freeDays + max(0, days - prevEnd);
  }
};
