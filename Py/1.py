import dash
import plotly
import plotly.graph_objs as go
import plotly.express as px
from plotly.subplots import make_subplots
import dash_core_components as dcc
import dash_html_components as html
from dash.dependencies import Input, Output, State


import numpy as np
import pandas as pd

external_stylesheets = ['https://codepen.io/chriddyp/pen/bWLwgP.css']

app = dash.Dash(__name__, external_stylesheets=external_stylesheets)

app.layout = html.Div(style = {'textAlign': 'center'},children = [
    html.Div('y0'),
    dcc.Input(id='input-1', type='number',value= 1,style = {'textAlign': 'center'} ),
    html.Div('x0'),
    dcc.Input(id='input-2', type='number',value= 1 ,style = {'textAlign': 'center'}),
    html.Div('Wx'),
    dcc.Input(id='input-3', type='number',value= 1,style = {'textAlign': 'center'} ),
    html.Div('Wy'),
    dcc.Input(id='input-4', type='number',value= 1,style = {'textAlign': 'center'} ),
    html.Div('delta phi(коэффицент перед Pi)'),
    dcc.Input(id='input-6', type='number',value= 0,style = {'textAlign': 'center'}),
    html.Br(),
    html.Button(id='submit-button-state', n_clicks=0, children='Смоделировать'),
    dcc.Graph(id='my-graph')
])


@app.callback(Output('my-graph', 'figure'),
              [Input('submit-button-state', 'n_clicks')],
              [State('input-1', 'value'),
                State('input-2', 'value'),
                State('input-3', 'value'),
                State('input-4', 'value'),
                State('input-6', 'value'),
               ])

def update_figure(n_clicks, y0,x0,wx,wy,delta2):
    try:
        x0 = float(x0)
        y0 = float(y0)
        wx = float(wx)
        wy = float(wy)
        delta2 = float(delta2)
    except TypeError:
        return go.Figure()

    fi = np.pi * delta2
    fig = go.Figure()
    t = np.arange(0, 2 * np.pi, 0.0001)
    fig.add_trace(go.Scatter(line=dict(width = 5),x=(x0 * np.cos(wx * t)), y=(y0 * np.cos(wy * t + fi))))
    fig.update_layout(height = 500,width = 500)
    return fig


if __name__ == '__main__':
    app.run_server(debug=True)

