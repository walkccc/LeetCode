class Solution {
  public int maxDistance(String s, int k) {
    return Math.max(Math.max(flip(s, k, "NE"), flip(s, k, "NW")),
                    Math.max(flip(s, k, "SE"), flip(s, k, "SW")));
  }

  private int flip(String s, int k, String direction) {
    int res = 0;
    int pos = 0;
    int opposite = 0;

    for (final char c : s.toCharArray()) {
      if (direction.indexOf(c) >= 0) {
        ++pos;
      } else {
        --pos;
        ++opposite;
      }
      res = Math.max(res, pos + 2 * Math.min(k, opposite));
    }

    return res;
  }
}
