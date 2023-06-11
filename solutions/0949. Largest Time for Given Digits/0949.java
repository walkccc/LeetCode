class Solution {
  public String largestTimeFromDigits(int[] arr) {
    String ans = "";

    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        for (int k = 0; k < 4; ++k) {
          if (i == j || i == k || j == k)
            continue;
          final String hours = "" + arr[i] + arr[j];
          final String minutes = "" + arr[k] + arr[6 - i - j - k];
          final String time = hours + ':' + minutes;
          if (hours.compareTo("24") < 0 && minutes.compareTo("60") < 0 && ans.compareTo(time) < 0)
            ans = time;
        }

    return ans;
  }
}
