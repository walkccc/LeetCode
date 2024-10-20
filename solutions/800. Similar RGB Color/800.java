class Solution {
  public String similarRGB(String color) {
    String[] kShorthands = {"00", "11", "22", "33", "44", "55", "66", "77",
                            "88", "99", "aa", "bb", "cc", "dd", "ee", "ff"};
    StringBuilder ans = new StringBuilder("#");

    for (int i = 1; i < color.length(); i += 2) {
      final int currValue = Integer.parseInt(color.substring(i, i + 2), 16);
      String closestShorthand = findClosestShorthand(currValue, kShorthands);
      ans.append(closestShorthand);
    }

    return ans.toString();
  }

  private static final int maxSimilarity = 255 * 255;

  private String findClosestShorthand(int targetValue, String[] shorthands) {
    String closest = shorthands[0];
    int minSimilarity = Integer.MAX_VALUE;

    for (final String shorthand : shorthands) {
      final int shorthandValue = Integer.parseInt(shorthand, 16);
      final int similarity = (targetValue - shorthandValue) * (targetValue - shorthandValue);
      if (similarity < minSimilarity) {
        closest = shorthand;
        minSimilarity = similarity;
      }
    }

    return closest;
  }
}
