import java.math.BigInteger;

class Solution {
  // Same as 3180. Maximum Total Reward Using Operations I
  public int maxTotalReward(int[] rewardValues) {
    BigInteger one = BigInteger.ONE;
    BigInteger dp = one; // the possible rewards (initially, 0 is achievable)

    Arrays.sort(rewardValues);

    for (final int num : rewardValues) {
      // Remove the numbers >= the current number.
      BigInteger maskBitsLessThanNum = one.shiftLeft(num).subtract(one);
      BigInteger bitsLessThanNum = dp.and(maskBitsLessThanNum);
      dp = dp.or(bitsLessThanNum.shiftLeft(num));
    }

    return dp.bitLength() - 1;
  }
}
