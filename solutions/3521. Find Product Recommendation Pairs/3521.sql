SELECT
  P1.product_id AS product1_id,
  P2.product_id AS product2_id,
  PI1.category AS product1_category,
  PI2.category AS product2_category,
  COUNT(P1.user_id) AS customer_count
FROM ProductPurchases AS P1
INNER JOIN ProductPurchases AS P2
  USING (user_id)
LEFT JOIN ProductInfo AS PI1
  ON (P1.product_id = PI1.product_id)
LEFT JOIN ProductInfo AS PI2
  ON (P2.product_id = PI2.product_id)
WHERE P1.product_id < P2.product_id
GROUP BY 1, 2, 3, 4
HAVING COUNT(P1.user_id) >= 3
ORDER BY customer_count DESC, product1_id, product2_id;
