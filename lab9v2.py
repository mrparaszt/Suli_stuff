

def fel1():
    inf = open("szamok.txt", "rt")
    while True:
        tmp = inf.readline()
        if not tmp: break
        tmp = tmp.strip("\n")
        tmp = tmp.split(" ")
        a, b = int(tmp[0]), int(tmp[1])
        r = inverz(a, b)
        if r != -1:
            e = (a * r) % b
            print(a, b,"Inverz: ", r, "check", e, "\n")
        else:
            print(a, b, "Nincs Inverz\n")
    inf.close()

def inverz(a, b):
    d, r = extEuclid(a, b)
    if d == 1:
        return r % b
    return -1

def extEuclid(a, b):
    x0, x1 = 1, 0
    while True:
        r = a % b
        q = a // b
        if r == 0:
            return b, x1
        a = b
        b = r
        x = x0 -  q * x1
        x0, x1 = x1, x

def fel2():
    inf = open("szamok2.txt", "rt")
    while True:
        tmp = inf.readline()
        if not tmp: break
        tmp = tmp.strip("\n")
        tmp = tmp.split(" ")
        a, b, c = int(tmp[0]), int(tmp[1]), int(tmp[2])
        r1 = inverzF(a, b)
        if r1 != -1:
            r = (r1 * c) % b
            e = (a * r) % b
            print(a, b, c, "Megoldas: ", r, " check: ", e)
        else:
            print(a, b, c, "Nincs megoldas")
    inf.close()

## 7 * x = 9 mod 13
## 7 * x1 = 1 mod 13
##   x1 = 2
## x =  9 * x1 = 1 mod 13
##    x = 2 * 9 = 5 mod 13
## x = 11


def inverzF(a, b):
    if primeTest(b):
        return pow(a, b-2, b)
    else: return -1

def primeTest(b):
    if b == 2: return True
    if b % 2 == 0: return False
    i = 3
    while i*i <=b:
        if b % i == 0: return False
        i += 2
    return True



from random import randint
def miller_rabinT(m, t= 10):
    s, r = 0, m - 1
    while r % 2 == 0:
        s, r = s + 1, r // 2
    for i in range (0, t):
        x = randint(2, m - 1)
        y = pow(x, r, m)
        if y == 1 or y == (m - 1): continue
        for j in range (1, s):
            y = (y * y) % m
            if y == 1: return False
            if y == m - 1: break
    if y != (m - 1): return False
return True





        
