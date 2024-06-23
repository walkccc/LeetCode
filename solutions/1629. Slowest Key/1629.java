class Solution {
  public char slowestKey(int[] releaseTimes, String keysPressed) {
    char ans = keysPressed.charAt(0);
    int maxDuration = releaseTimes[0];

    for (int i = 1; i < keysPressed.length(); ++i) {
      final int duration = releaseTimes[i] - releaseTimes[i - 1];
      if (duration > maxDuration || (duration == maxDuration && keysPressed.charAt(i) > ans)) {
        ans = keysPressed.charAt(i);
        maxDuration = duration;
      }
    }

    return ans;
  }
}
