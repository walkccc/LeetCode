WITH
  RankedSpending AS (
    SELECT
      Sales.user_id,
      Sales.product_id,
      RANK() OVER(
        PARTITION by user_id
        ORDER BY SUM(Sales.quantity * Product.price) DESC
      ) AS `rank`
    FROM Sales
    INNER JOIN Product
      USING (product_id)
    GROUP BY 1, 2
  )
SELECT user_id, product_id
FROM RankedSpending
WHERE `rank` = 1;
