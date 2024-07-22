// According to the constraint rewardValues[i] <= 5 * 10^4, the maximum total
// reward < 2 * (5 * 10^4) = 10^5. We can use bitset to record whether each
// `rewardValue` is achievable in O(1).
//
// Let's use `rewardValues = [1, 3, 4]` as an example.
//
// The maximum reward is 4, so the maximum possible total < 2 * 4 = 8.
// Therefore, we can set the size of the bitset to 8 to represent possible
// total rewards from 0 to 7.
//
// Let's define a bitset `dp` to record whether each total reward is
// achievable. dp[num] = true if reward `num` is achievable.
//
// Initially, dp = 0b00000001 := reward 0 is achievable.
//
// * rewardValues[0] = 1, for each dp[i] = 1, where i + 1 < 10, dp[i + 1] = 1.
//   => dp = 0b00000011 := rewards 0 and 1 are achievable.
//
// * rewardValues[1] = 3, for each dp[i] = 1, where i + 3 < 10, dp[i + 3] = 1.
//   => dp = 0b00011011 := rewards 0, 1, 3, and 4 are achievable.
//
// * rewardValues[2] = 4, for each dp[i] = 1, where i + 4 < 10, dp[i + 4] = 1.
//   => dp = 0b10011011 := rewards 0, 1, 3, 4, 5, and 7 are achievable.
//
// Therefore, the maximum total reward is 7.

import java.math.BigInteger;

class Solution {
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
