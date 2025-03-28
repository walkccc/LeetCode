class Solution {
  public double angleClock(int hour, int minutes) {
    final double hourHand = (hour % 12 + minutes / 60.0) * 30;
    final double minuteHand = minutes * 6;
    final double diff = Math.abs(hourHand - minuteHand);
    return Math.min(diff, 360 - diff);
  }
}
