class Solution {
  public int countSeniors(String[] details) {
    return (int) Arrays.stream(details)
        .filter(detail -> Integer.parseInt(detail.substring(11, 13)) > 60)
        .count();
  }
}
