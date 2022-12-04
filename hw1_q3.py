import numpy as np

N = 121
x = []
for i in np.linspace(0,12,N):
    x.append(format(i, '.2f'))
print(x)
u = 0
sigma = 0
for i in range(N):
    u = u + float(x[i])
u = u/N
print(u)
sum = 0
for i in range(N):
    sum = sum + (float(x[i])-u)**2
sigma = np.sqrt(sum/N)
print(sum, sigma)

print(np.sqrt(3)/6*12)