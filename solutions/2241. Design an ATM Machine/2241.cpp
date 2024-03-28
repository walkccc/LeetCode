class ATM {
 public:
  ATM() : bank(5) {}

  void deposit(vector<int> banknotesCount) {
    for (int i = 0; i < 5; ++i)
      bank[i] += banknotesCount[i];
  }

  vector<int> withdraw(int amount) {
    vector<int> withdrew(5);

    for (int i = 4; i >= 0; --i) {
      withdrew[i] = min(bank[i], static_cast<long long>(amount) / banknotes[i]);
      amount -= withdrew[i] * banknotes[i];
    }

    if (amount > 0)
      return {-1};

    for (int i = 0; i < 5; ++i)
      bank[i] -= withdrew[i];
    return withdrew;
  }

 private:
  vector<int> banknotes{20, 50, 100, 200, 500};
  vector<long long> bank;
};
