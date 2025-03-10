class Solution {
  public int badSensor(int[] sensor1, int[] sensor2) {
    final boolean oneDefect = canReplace(sensor2, sensor1);
    final boolean twoDefect = canReplace(sensor1, sensor2);
    if (oneDefect && twoDefect)
      return -1;
    if (!oneDefect && !twoDefect)
      return -1;
    return oneDefect ? 1 : 2;
  }

  private boolean canReplace(int[] A, int[] B) {
    int i = 0; // A's index
    int j = 0; // B's index
    int droppedValue = -1;

    while (i < A.length)
      if (A[i] == B[j]) {
        ++i;
        ++j;
      } else {
        droppedValue = A[i];
        ++i;
      }

    return j == B.length - 1 && B[j] != droppedValue;
  }
}
