SELECT
  Salesperson.salesperson_id,
  Salesperson.name,
  SUM(IFNULL(Sales.price, 0)) AS total
FROM Salesperson
LEFT JOIN Customer
  USING (salesperson_id)
LEFT JOIN Sales
  USING (customer_id)
GROUP BY 1;
