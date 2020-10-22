import plotly
import plotly.graph_objs as go
import plotly.express as px
from plotly.subplots import make_subplots

import numpy as np
import pandas as pd

def kek():
    print("Введите необходимые значения:x0,y0,wx,wy")
    x0,y0,wx,wy = map(float,input().split())
    fi = np.pi / 2
    fig = go.Figure()
    t = np.arange(0, 2 * np.pi, 0.01)
    fig.add_trace(go.Scatter(x=x0 * np.sin(wx * t), y=y0 * np.sin(wy * t + fi)))
    fig.show()

flag = True
while flag == True:
    kek()
    print("Want to continue?? 1 - yes,0 - no")
    flag = bool(input())

