from time import time
from decimal import Decimal, getcontext
from math import gcd

def fel2():
    L = [117909607, 21261237198254169127801 ,149063950693785473206387643 ,6416626799448849184299219222997152546843712511308822463778262756071903295686583190313754050072639159072918419909621481540760781304636463845632523179 ,11379881602713805813074408600393657498808359221180270219583433367270200091282805603668259467898750049483687125365056837556555463733092892411265612455581727940831 ,10264762919188799324017198473653676357077973949714005441630872637584674644086006446077930626500755999282238632213530271489005199300521704739285262210696019]
##    i = 1
##    print("Trial div:")
##    for nr in L:
##        r1 = trialDiv(nr)
##        if r1 == -1:
##            print("Time Limit")
##        else:
##            print(i, r1)
##        i += 1
##    print("Fermat:")
##    for nr in L:
##        r1 = fermat(nr)
##        if r1 == -1:
##            print("Time Limit")
##        else:
##            print(i, r1)
##        i += 1
    i = 1
    print("Polar:")
    for nr in L:
        r1 = polar(nr)
        if r1 == -1:
            print(i, "Time Limit")
        else:
            print(i, r1)
        i += 1

def trialDiv(nr):
    if nr % 2 == 0: return 2
    i = 3
    st = time()
    while i * i <= nr:
        fs = time()
        if fs - st > 10: return -1
        if nr % i == 0: return i
        i += 2
        
def fermat(nr):
    st = time()
    getcontext().prec = 200
    a = int(Decimal(nr).sqrt()) + 1
    while True:
        fs = time()
        if fs - st > 10: return -1
        b1 = a*a - nr
        b = negyzetszam(b1)
        if b != -1:
            return (a-b, a+b)
        a += 1

def negyzetszam(b1):
    b = int(Decimal(b1).sqrt())
    if b*b == b1:
        return b
    return -1
    

def polar(nr):
    a = 1
    b = 2
    st = time()
    while True:
        fs = time()
        if fs - st > 10: return -1
        a = (a*a + 1) % nr
        b = (b*b + 1) % nr
        b = (b*b + 1) % nr
        r = gcd(nr, a-b)
        #print(a, b, a-b, r)
        if r != 1: return r










    
