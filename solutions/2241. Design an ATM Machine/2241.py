class ATM:
  def __init__(self):
    self.banknotes = [20, 50, 100, 200, 500]
    self.bank = [0] * 5

  def deposit(self, banknotesCount: List[int]) -> None:
    for i in range(5):
      self.bank[i] += banknotesCount[i]

  def withdraw(self, amount: int) -> List[int]:
    withdrew = [0] * 5

    for i in reversed(range(5)):
      withdrew[i] = min(self.bank[i], amount // self.banknotes[i])
      amount -= withdrew[i] * self.banknotes[i]

    if amount:
      return [-1]

    for i in range(5):
      self.bank[i] -= withdrew[i]
    return withdrew
