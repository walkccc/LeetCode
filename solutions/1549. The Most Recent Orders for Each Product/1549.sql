WITH
  RankedProducts AS (
    SELECT
      Products.product_name,
      Products.product_id,
      Orders.order_id,
      Orders.order_date,
      RANK() OVER(
        PARTITION BY Products.product_name
        ORDER BY Orders.order_date DESC
      ) `rank`
    FROM Products
    INNER JOIN Orders
      USING (product_id)
  )
SELECT
  RankedProducts.product_name,
  RankedProducts.product_id,
  RankedProducts.order_id,
  RankedProducts.order_date
FROM RankedProducts
WHERE `rank` = 1
ORDER BY 1, 2, 3;
