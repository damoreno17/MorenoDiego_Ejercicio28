import matplotlib.pyplot as plt
import numpy as np

data = np.genfromtxt("datos.dat")

t,x,y,vx,vy=data.T

plt.figure()
plt.plot(x, y)
plt.ylim([0,10])
plt.savefig("proyectil.png")