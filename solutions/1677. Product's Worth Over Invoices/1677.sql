SELECT
  Product.name,
  IFNULL(SUM(Invoice.rest), 0) AS rest,
  IFNULL(SUM(Invoice.paid), 0) AS paid,
  IFNULL(SUM(Invoice.canceled), 0) AS canceled,
  IFNULL(SUM(Invoice.refunded), 0) AS refunded
FROM Product
LEFT JOIN Invoice
  USING (product_id)
GROUP BY 1
ORDER BY 1;
