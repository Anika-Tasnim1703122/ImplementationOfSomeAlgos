def karatsuba(x, y):
    
    if x < 100 or y < 100:
        return x * y
    
    sx, sy = str(x), str(y)
    m2 = max(len(sx), len(sy)) // 2
    
    ix, iy = len(sx) - m2, len(sy) - m2
        
    a, b = int(sx[:ix]), int(sx[ix:])
    c, d = int(sy[:iy]), int(sy[iy:])
    
    A = karatsuba(a, c)
    C = karatsuba(b, d)
    D = karatsuba(a + b, c + d)
    return A * 10 ** (2 * m2) + (D - A - C) * 10 ** m2 + C


test = karatsuba(3141592653589793238462643383279502884197169399375105820974944592,2718281828459045235360287471352662497757247093699959574966967627)
print(test)

