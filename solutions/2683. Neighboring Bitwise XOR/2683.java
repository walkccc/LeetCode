class Solution {
  public boolean doesValidArrayExist(int[] derived) {
    //      original = [O[0], O[1], ..., O[n - 1]]
    //       derived = [O[0]^O[1], O[1]^O[2], ..., O[n - 1]^O[0]]
    // XOR(derivedd) = 0
    return Arrays.stream(derived).reduce((a, b) -> a ^ b).getAsInt() == 0;
  }
}
