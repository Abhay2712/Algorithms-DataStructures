SELECT Name  as Customers from Customers A
WHERE A.Id NOT IN (SELECT B.CustomerId from Orders B)