class Solution {
 public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int ans = 0;
    // Maintain two sums of subarrays ending in the previous index.
    // Each time we meet a new number, we'll consider "how many times" it should
    // contribute to the newly built subarrays by calculating the number of
    // previous even/odd-length subarrays.
    int prevEvenSum = 0;  // the sum of even-length subarrays
    int prevOddSum = 0;   // the sum of odd-length subarrays

    for (int i = 0; i < arr.size(); ++i) {
      // (i + 1) / 2 := the number of previous odd-length subarrays.
      const int currEvenSum = prevOddSum + ((i + 1) / 2) * arr[i];
      // i / 2 + 1 := the number of previous even-length subarrays
      // (including 0).
      const int currOddSum = prevEvenSum + (i / 2 + 1) * arr[i];
      ans += currOddSum;
      prevEvenSum = currEvenSum;
      prevOddSum = currOddSum;
    }

    return ans;
  }
};
