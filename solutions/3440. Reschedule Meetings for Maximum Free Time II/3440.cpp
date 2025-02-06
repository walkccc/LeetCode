class Solution {
 public:
  int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    const int n = startTime.size();
    const vector<int> gaps = getGaps(eventTime, startTime, endTime);
    int ans = 0;
    vector<int> maxLeft(n + 1);   // maxLeft[i] := max(gaps[0..i])
    vector<int> maxRight(n + 1);  // maxRight[i] := max(gaps[i..n])

    maxLeft[0] = gaps[0];
    maxRight[n] = gaps[n];

    for (int i = 1; i < n + 1; ++i)
      maxLeft[i] = max(gaps[i], maxLeft[i - 1]);

    for (int i = n - 1; i >= 0; --i)
      maxRight[i] = max(gaps[i], maxRight[i + 1]);

    for (int i = 0; i < n; ++i) {
      const int currMeetingTime = endTime[i] - startTime[i];
      const int adjacentGapsSum = gaps[i] + gaps[i + 1];
      const bool canMoveMeeting =
          currMeetingTime <= max(i > 0 ? maxLeft[i - 1] : 0,  //
                                 i + 2 < n + 1 ? maxRight[i + 2] : 0);
      ans = max(ans, adjacentGapsSum + (canMoveMeeting ? currMeetingTime : 0));
    }

    return ans;
  }

 private:
  vector<int> getGaps(int eventTime, const vector<int>& startTime,
                      const vector<int>& endTime) {
    vector<int> gaps{startTime[0]};
    for (int i = 1; i < startTime.size(); ++i)
      gaps.push_back(startTime[i] - endTime[i - 1]);
    gaps.push_back(eventTime - endTime.back());
    return gaps;
  }
};
