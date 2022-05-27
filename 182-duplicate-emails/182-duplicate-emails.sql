/* Write your PL/SQL query statement below */
Select email
From Person
Group By email
Having Count(email)>1;