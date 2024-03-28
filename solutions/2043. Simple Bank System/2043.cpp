class Bank {
 public:
  Bank(vector<long long>& balance) : balance(move(balance)) {}

  bool transfer(int account1, int account2, long long money) {
    if (!isValid(account2))
      return false;
    return withdraw(account1, money) && deposit(account2, money);
  }

  bool deposit(int account, long long money) {
    if (!isValid(account))
      return false;
    balance[account - 1] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    if (!isValid(account))
      return false;
    if (balance[account - 1] < money)
      return false;
    balance[account - 1] -= money;
    return true;
  }

 private:
  vector<long long> balance;

  bool isValid(int account) {
    return 1 <= account && account <= balance.size();
  }
};
