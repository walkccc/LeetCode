class Solution {
  public int buttonWithLongestTime(int[][] events) {
    int ans = 0;
    int maxTimeTaken = 0;
    int prevTime = 0;

    for (int[] event : events) {
      final int index = event[0];
      final int time = event[1];
      final int timeTaken = time - prevTime;
      if (timeTaken > maxTimeTaken || timeTaken == maxTimeTaken && index < ans) {
        maxTimeTaken = timeTaken;
        ans = index;
      }
      prevTime = time;
    }

    return ans;
  }
}
