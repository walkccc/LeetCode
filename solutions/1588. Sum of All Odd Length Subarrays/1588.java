class Solution {
  public int sumOddLengthSubarrays(int[] arr) {
    int ans = 0;
    // Maintain two sums of subarrays ending at previous index.
    // Each time we meet a new number, we'll consider "how many times" it should
    // contribute to the newly built subarrays by calculating number of previous
    // even/odd-length subarrays.
    int prevEvenSum = 0; // sum of even-length subarrays
    int prevOddSum = 0;  // sum of odd-length subarrays

    for (int i = 0; i < arr.length; ++i) {
      // (i + 1) / 2 := # of previous odd-length subarrays.
      final int currEvenSum = prevOddSum + ((i + 1) / 2) * arr[i];
      // i / 2 + 1 := # of previous even-length subarrays (including 0).
      final int currOddSum = prevEvenSum + (i / 2 + 1) * arr[i];
      ans += currOddSum;
      prevEvenSum = currEvenSum;
      prevOddSum = currOddSum;
    }

    return ans;
  }
}
