class Solution:
  def distMoney(self, money: int, children: int) -> int:
    # Everyone must receive at least 1 dollar.
    money -= children
    if money < 0:
      return -1

    count7 = money // 7
    remaining = money % 7

    # Distribute 8 dollars to every child.
    if count7 == children and remaining == 0:
      return count7

    # Need to move 1 dollar from the last child with 4 dollars to one of other
    # children. That's why we need to substract 1.
    if count7 == children - 1 and remaining == 3:
      return count7 - 1

    # Though there might be child with 4 dollars, since count7 < children - 1,
    # we have 'extra' spot to move money to if needed.
    return min(children - 1, count7)
