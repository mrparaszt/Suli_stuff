def reszhalmazok(A):
    H = [""]
    for elem in A:
        A1 = []
        for x in H:
            A1 += [x + elem]
        H += A1
    return H

def fel4(A):
    rl = reszhalmazok(A)
    i = 0
    out = open("reszh.txt" , "wt")
    for r in rl:
        out.write(r + " ")
        i += 1
        if i == 5:
            out.write("\n")
            i = 0
    out.close()
