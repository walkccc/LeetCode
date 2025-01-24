class ATM {
  public void deposit(int[] banknotesCount) {
    for (int i = 0; i < 5; ++i)
      bank[i] += banknotesCount[i];
  }

  public int[] withdraw(int amount) {
    int[] withdrew = new int[5];

    for (int i = 4; i >= 0; --i) {
      withdrew[i] = (int) Math.min(bank[i], (long) amount / banknotes[i]);
      amount -= withdrew[i] * banknotes[i];
    }

    if (amount > 0)
      return new int[] {-1};

    for (int i = 0; i < 5; ++i)
      bank[i] -= withdrew[i];
    return withdrew;
  }

  private int[] banknotes = {20, 50, 100, 200, 500};
  private long[] bank = new long[5];
}
