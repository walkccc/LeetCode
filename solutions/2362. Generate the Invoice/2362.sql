WITH
  HighestPriceInvoice AS (
    SELECT
      Purchases.invoice_id,
      SUM(Purchases.quantity * Products.price) AS price
    FROM Purchases
    INNER JOIN Products
      USING (product_id)
    GROUP BY 1
    ORDER BY 2 DESC, 1
    LIMIT 1
  )
SELECT
  Products.product_id,
  Purchases.quantity,
  Purchases.quantity * Products.price AS price
FROM HighestPriceInvoice
INNER JOIN Purchases
  USING (invoice_id)
INNER JOIN Products
  USING (product_id);