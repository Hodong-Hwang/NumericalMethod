import numpy as np

def gauss_elimination(A, b):
    n = len(A)
    for i in range(n):
        pivot = A[i][i]
        for j in range(i+1, n):
            ratio = A[j][i]/pivot
            A[j] -= ratio * A[i]
            b[j] -= ratio * b[i]
    x = np.zeros(n)
    for i in range(n-1, -1, -1):
        x[i] = (b[i] - np.dot(A[i][i+1:], x[i+1:])) / A[i][i]
    return x