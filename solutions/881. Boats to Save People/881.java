class Solution {
  public int numRescueBoats(int[] people, int limit) {
    int ans = 0;

    Arrays.sort(people);

    for (int i = 0, j = people.length - 1; i <= j; ++ans) {
      final int remain = limit - people[j--];
      if (people[i] <= remain)
        ++i;
    }

    return ans;
  }
}
