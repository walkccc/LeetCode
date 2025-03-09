class Solution {
  public int minPartitions(String n) {
    return Character.getNumericValue(n.chars().max().getAsInt());
  }
}
