class Solution {
  public int findRadius(int[] houses, int[] heaters) {
    Arrays.sort(houses);
    Arrays.sort(heaters);

    int ans = 0;
    int i = 0; // Point to the heater that currently used

    for (final int house : houses) {
      while (i + 1 < heaters.length && house - heaters[i] > heaters[i + 1] - house)
        ++i; // Next heater is better
      ans = Math.max(ans, Math.abs(heaters[i] - house));
    }

    return ans;
  }
}
