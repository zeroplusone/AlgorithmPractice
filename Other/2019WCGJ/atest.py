#!/usr/bin/python

import random

T = random.randint(1, 100)
print(T)

for i in range(T):
    K = random.randint(4, 10)
    print(K)
    for j in range(K+1):
        M = random.randint(0, 1000)
        print(M, end=' ')
    print()