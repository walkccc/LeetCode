class Solution {
  public int maxConsecutiveAnswers(String answerKey, int k) {
    int ans = 0;
    int maxCount = 0;
    int[] count = new int[2];

    for (int l = 0, r = 0; r < answerKey.length(); ++r) {
      maxCount = Math.max(maxCount, ++count[answerKey.charAt(r) == 'T' ? 1 : 0]);
      while (maxCount + k < r - l + 1)
        --count[answerKey.charAt(l++) == 'T' ? 1 : 0];
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
