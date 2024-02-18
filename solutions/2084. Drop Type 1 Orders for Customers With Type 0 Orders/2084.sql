WITH
  RankedOrders AS (
    SELECT
      *,
      RANK() OVER(PARTITION BY customer_id ORDER BY order_type) AS `rank`
    FROM Orders
  )
SELECT
  order_id,
  customer_id,
  order_type
FROM RankedOrders
WHERE `rank` = 1;
