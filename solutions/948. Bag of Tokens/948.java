class Solution {
  public int bagOfTokensScore(int[] tokens, int power) {
    int ans = 0;
    int score = 0;
    int i = 0;                 // the index of the smallest token
    int j = tokens.length - 1; // the index of the largest token

    Arrays.sort(tokens);

    while (i <= j && (power >= tokens[i] || score > 0)) {
      while (i <= j && power >= tokens[i]) {
        // Play the smallest face up.
        power -= tokens[i++];
        ++score;
      }
      ans = Math.max(ans, score);
      if (i <= j && score > 0) {
        // Play the largest face down.
        power += tokens[j--];
        --score;
      }
    }

    return ans;
  }
}
