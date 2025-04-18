SELECT
  A.symbol AS metal,
  B.symbol AS nonmetal
FROM Elements AS A, Elements AS B
WHERE
  A.type = 'Metal'
  AND B.type = 'Nonmetal'
