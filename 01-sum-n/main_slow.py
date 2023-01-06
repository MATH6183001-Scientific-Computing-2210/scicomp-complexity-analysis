

def sum_n(n):
    sum = 0
    while n > 0:
        sum += n 
        n -= 1

    return sum 

n = 10
print(f"n={n}, sum(n) = {sum_n(n)}")