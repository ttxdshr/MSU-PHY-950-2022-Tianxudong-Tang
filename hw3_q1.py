import numpy as np
import matplotlib.pyplot as plt
import math

#Declear useful variables
exp = 6
nTrials = int(math.pow(10,6))
event8 = 0
x = []
y = []
sum1 = []
x2 = []
Sample_var = []
for t in range(10,nTrials+1):
    t1 = np.random.randint(1,7)
    t2 = np.random.randint(1,7)
    sum1.append(t1 + t2)
    if((t1+t2) == 8):
        event8 += 1
    prob = event8 / t
    y.append(prob)
    x.append(t)
    for i in range(1,exp+1):
        if(t==math.pow(10,i)):
            print("yes",t)
            x2.append(t)
            Sample_var.append(np.var(sum1))

sum2 = []
for i in range(1,exp+1):
    for j in range(1,exp+1):
        sum2.append(i+j)
Expected_var = np.var(sum2)    

plt.subplot(3,1,1)
plt.plot(x,y,c="red", label='The prob to get 8')
plt.xlabel("The number of trails")
plt.ylabel("The probability")
plt.xscale("log")
plt.title("(a)The prob of rolling a sum of 8")

plt.subplot(3,1,3)
plt.hlines(Expected_var,0,nTrials, color="red", label='The Expected variance')
plt.plot(x2,Sample_var,c="blue", label='The Sample variance')
plt.xlabel("The number of trails")
plt.ylabel("The Expected variance")
plt.xscale("log")
plt.title("(b)The Variance")

plt.show()