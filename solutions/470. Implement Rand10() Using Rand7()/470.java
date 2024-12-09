/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */

class Solution extends SolBase {
  public int rand10() {
    int num = 40;

    while (num >= 40)
      num = (rand7() - 1) * 7 + rand7() - 1;

    return num % 10 + 1;
  }
}
