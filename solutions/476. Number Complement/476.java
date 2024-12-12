class Solution {
  public int findComplement(int num) {
    for (long i = 1; i <= num; i <<= 1)
      num ^= i;
    return num;
  }
}
