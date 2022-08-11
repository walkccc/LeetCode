class Solution {
 public:
  double angleClock(int hour, int minutes) {
    const double hourHand = (hour % 12 + minutes / 60.0) * 30;
    const double minuteHand = minutes * 6;
    const double diff = abs(hourHand - minuteHand);
    return min(diff, 360 - diff);
  }
};
