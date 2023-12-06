class Solution {
 public:
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    char ans = keysPressed[0];
    int maxDuration = releaseTimes[0];

    for (int i = 1; i < keysPressed.length(); ++i) {
      const int duration = releaseTimes[i] - releaseTimes[i - 1];
      if (duration > maxDuration ||
          (duration == maxDuration && keysPressed[i] > ans)) {
        ans = keysPressed[i];
        maxDuration = duration;
      }
    }

    return ans;
  }
};
