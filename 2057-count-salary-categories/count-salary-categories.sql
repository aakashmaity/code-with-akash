# Write your MySQL query statement below
select 'Low Salary' as category, SUM(IF(income<20000,1,0)) as accounts_count from Accounts
UNION
select 'Average Salary' as category, SUM(IF(income between 20000 and 50000,1,0)) as accounts_count from Accounts
UNION
select 'High Salary' as category, SUM(IF(income>50000,1,0)) as accounts_count from Accounts
