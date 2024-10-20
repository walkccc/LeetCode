WITH
  RankedOrders AS (
    SELECT
      Orders.customer_id,
      Orders.product_id,
      Products.product_name,
      RANK() OVER(
        PARTITION BY Orders.customer_id
        ORDER BY COUNT(Orders.product_id) DESC
      ) AS `rank`
    FROM Orders
    INNER JOIN Products
      USING (product_id)
    GROUP BY 1, 2
  )
SELECT
  customer_id,
  product_id,
  product_name
FROM RankedOrders
WHERE `rank` = 1;
