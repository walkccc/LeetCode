SELECT SalesPerson.name
FROM Orders
INNER JOIN Company
  ON (Orders.com_id = Company.com_id AND Company.name = 'RED')
RIGHT JOIN SalesPerson
  USING (sales_id)
WHERE Orders.sales_id IS NULL;
