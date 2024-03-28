WITH
  RECURSIVE Ids AS (
    SELECT 1 AS id
    UNION
    SELECT id + 1
    FROM Ids
    WHERE id < (
        SELECT MAX(customer_id)
        FROM Customers
      )
  )
SELECT Ids.id AS ids
FROM Ids
LEFT JOIN Customers
  ON (Ids.id = Customers.customer_id)
WHERE Customers.customer_id IS NULL
ORDER BY 1;
