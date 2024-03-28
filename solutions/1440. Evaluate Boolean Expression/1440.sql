SELECT Expressions.*,
  (
    CASE
      WHEN Expressions.operator = '<'
      AND LeftOperand.value < RightOperand.value THEN 'true'
      WHEN Expressions.operator = '>'
      AND LeftOperand.value > RightOperand.value THEN 'true'
      WHEN Expressions.operator = '='
      AND LeftOperand.value = RightOperand.value THEN 'true'
      ELSE 'false'
    END
  ) AS value
FROM Expressions
INNER JOIN VARIABLES AS LeftOperand
  ON (Expressions.left_operand = LeftOperand.name)
INNER JOIN VARIABLES AS RightOperand
  ON (Expressions.right_operand = RightOperand.name);
