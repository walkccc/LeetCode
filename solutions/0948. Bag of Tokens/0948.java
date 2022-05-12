class Solution {
  public int bagOfTokensScore(int[] tokens, int power) {
    int ans = 0;
    int score = 0;
    int i = 0;                 // index of smallest token
    int j = tokens.length - 1; // index of largest token

    Arrays.sort(tokens);

    while (i <= j && (power >= tokens[i] || score > 0)) {
      while (i <= j && power >= tokens[i]) {
        // play the smallest face up
        power -= tokens[i++];
        ++score;
      }
      ans = Math.max(ans, score);
      if (i <= j && score > 0) {
        // play the largest face down
        power += tokens[j--];
        --score;
      }
    }

    return ans;
  }
}
