import math, time
from functools import lru_cache

var1 = [1.21645100408832e+17, 120, 6, 51090942171709440000, 6402373705728000, 362880, 87178291200, 120, 2432902008176640000, 121645100408832000, 123, 6402373705728000, 51, 6, 51090942171709440000, 6402373705728000, 121645100408832000, 362880, 1307674368000, 87178291200, 95, 49, 1.21645100408832e+17, 95, 2, 51, 2432902008176640000, 2432902008176640000, 51, 6402373705728000, 95, 2.43290200817664e+18, 40320.0, 52, 87178291200.0, 95, 49, 2432902008176640000, 51, 6402373705728000, 1.0, 2.43290200817664e+18, 362880.0, 1307674368000.0, 87178291200, 125]

def f0(var2):
    var2 = var2.lower()
    if var2.isalpha():
        return ord(var2) - ord('a') + 1
    else:
        return None

@lru_cache(maxsize=None)
def f1(var2):
    if var2 <= 1:
        return 1
    return var2 * f1(var2 - 1)

def f2(var2):
    if var2 % 2 == 0:
        return f3(var2) + var2 * 2
    else:
        return f4(var2) - var2 // 3

def f3(var2):
    if var2 < 2:
        return f1(var2)
    else:
        return f5(var2 - 1) * f2(var2 - 2)

def f4(var2):
    if var2 > 10:
        return f5(var2 - 2) + var2 * var2
    else:
        return f2(var2 + 1) // 2

def f5(var2):
    if var2 == 1:
        return 1
    return f3(var2 - 1) + f4(var2 - 1)

def f6():
    var3 = input("Enter the password: ")
    var4 = []

    for var5 in var3:
        alphabetic_position = f0(var5)
        if alphabetic_position is not None:
            factorial_value = f1(alphabetic_position)
            if var5.isupper():
                var4.append(float(factorial_value))
            else:
                var4.append(factorial_value)
        else:
            var4.append(ord(var5))

    print("Checking password...")
    time.sleep(1)
    print(var4)
    if var4 == var1:
        print("<< UNLOCKED! >>")
    else:
        print("Wrong password!")

if __name__ == "__main__":
    print()
    time.sleep(1)
    print("== C U R S I V E ==")
    time.sleep(1)
    print("--  Author: jio  --")
    time.sleep(1)
    print()
    f6()
