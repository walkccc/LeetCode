WITH
  Prime AS (
    SELECT SUM(square_footage) AS sum_square_footage
    FROM Inventory
    WHERE item_type = 'prime_eligible'
  )
SELECT
  'prime_eligible' AS item_type,
  COUNT(*) * FLOOR(500000 / Prime.sum_square_footage) AS item_count
FROM Inventory, Prime
WHERE item_type = 'prime_eligible'
UNION ALL
SELECT
  'not_prime',
  COUNT(*) * FLOOR(500000 % Prime.sum_square_footage / SUM(square_footage))
FROM Inventory, Prime
WHERE item_type = 'not_prime';
