enum BoxCase { kEqualBalls, kEqualDistantBalls }

class Solution {
  public double getProbability(int[] balls) {
    final int n = Arrays.stream(balls).sum() / 2;
    return cases(balls, 0, 0, 0, 0, 0, n, BoxCase.kEqualDistantBalls) /
        cases(balls, 0, 0, 0, 0, 0, n, BoxCase.kEqualBalls);
  }

  private int[] fact = {1, 1, 2, 6, 24, 120, 720};

  // Assume we have two boxes A and B.
  double cases(int[] balls, int i, int ballsCountA, int ballsCountB, int colorsCountA,
               int colorsCountB, int n, BoxCase boxCase) {
    if (ballsCountA > n || ballsCountB > n)
      return 0;
    if (i == balls.length)
      return boxCase == BoxCase.kEqualBalls ? 1 : (colorsCountA == colorsCountB ? 1 : 0);

    double ans = 0;

    // balls taken from A for `balls[i]`
    for (int ballsTakenA = 0; ballsTakenA <= balls[i]; ++ballsTakenA) {
      final int ballsTakenB = balls[i] - ballsTakenA;
      final int newcolorsCountA = colorsCountA + (ballsTakenA > 0 ? 1 : 0);
      final int newcolorsCountB = colorsCountB + (ballsTakenB > 0 ? 1 : 0);
      ans += cases(balls, i + 1, ballsCountA + ballsTakenA, ballsCountB + ballsTakenB,
                   newcolorsCountA, newcolorsCountB, n, boxCase) /
             (fact[ballsTakenA] * fact[ballsTakenB]);
    }

    return ans;
  }
}
