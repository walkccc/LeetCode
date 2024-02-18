WITH
  OrdersNeighbors AS (
    SELECT
      product_id,
      YEAR(purchase_date) AS curr_year,
      LEAD(YEAR(purchase_date)) OVER(
        PARTITION BY product_id
        ORDER BY YEAR(purchase_date)
      ) AS next_year
    FROM orders
    GROUP BY 1, 2
    HAVING COUNT(order_id) >= 3
  )
SELECT DISTINCT product_id
FROM OrdersNeighbors
WHERE curr_year + 1 = next_year;
