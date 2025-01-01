from abc import ABC, abstractmethod

"""
This is the interface for the expression tree Node.
You should not remove it, and you can define some classes to implement it.
"""


class Node(ABC):
  @abstractmethod
  # define your fields here
  def evaluate(self) -> int:
    pass


class ExpNode(Node):
  op = {
      '+': lambda a, b: a + b,
      '-': lambda a, b: a - b,
      '*': lambda a, b: a * b,
      '/': lambda a, b: int(a / b),
  }

  def __init__(
      self,
      val: str,
      left: Optional['ExpNode'],
      right: Optional['ExpNode'],
  ):
    self.val = val
    self.left = left
    self.right = right

  def evaluate(self) -> int:
    if not self.left and not self.right:
      return int(self.val)
    return ExpNode.op[self.val](self.left.evaluate(), self.right.evaluate())


"""
This is the TreeBuilder class.
You can treat it as the driver code that takes the postinfix input
and returns the expression tree represnting it as a Node.
"""


class TreeBuilder(object):
  def buildTree(self, postfix: list[str]) -> 'Node':
    stack: list[ExpNode | None] = []

    for val in postfix:
      if val in '+-*/':
        right = stack.pop()
        left = stack.pop()
        stack.append(ExpNode(val, left, right))
      else:
        stack.append(ExpNode(val, None, None))

    return stack.pop()
