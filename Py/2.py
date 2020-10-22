import numpy as np
from numpy import sin,pi
import matplotlib.pyplot as plt
m=[[0],[2,2],[2,1],[1,2],[3,2],[3,4],[5,4],[5,6],[9,8]]# отношение круговых частот
for i in m:
                if i[0]==0:
                           a=1
                           x=[sin(a*t) for t in np.arange(0.,2*pi,0.01)]
                           y=[sin(a*t) for t in np.arange(0.,2*pi,0.01)]
                           plt.plot(x, y, 'r')# график для линии
                           plt.grid(True)
                           plt.show()
                else:
                                a=i[0]
                                b=i[1]
                                d=0.5*pi
                                x=[sin(a*t+d) for t in np.arange(0.,2*pi,0.01)]
                                y=[sin(b*t) for t in np.arange(0.,2*pi,0.01)]
                                plt.plot(x, y, 'r') # график для различных отношений  a/b
                                #круговых частот
                                plt.grid (True)
                                plt.show()