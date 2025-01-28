class Solution {
 public:
  int buttonWithLongestTime(vector<vector<int>>& events) {
    int ans = 0;
    int maxTimeTaken = 0;
    int prevTime = 0;

    for (const vector<int>& event : events) {
      const int index = event[0];
      const int time = event[1];
      const int timeTaken = time - prevTime;
      if (timeTaken > maxTimeTaken ||
          timeTaken == maxTimeTaken && index < ans) {
        maxTimeTaken = timeTaken;
        ans = index;
      }
      prevTime = time;
    }

    return ans;
  }
};
