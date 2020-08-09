import numpy as np
from vpython import *
A, omega = 0.10, 2*pi/1.0
N = 50
size, m, k, d = 0.06, 0.1, 10.0, 0.4
Ang_Wave = graph(title='Phonon dispersion relationship', width=400, align='left',background=vec(0.5,0.5,0))
x = gcurve(color=color.red, graph=Ang_Wave)

for n in range(1, 25):
    Unit_K = 2 * pi/(N*d)
    Wavevector = n * Unit_K
    phase = Wavevector * arange(N) * d
    ball_pos, ball_orig, ball_v, spring_len = np.arange(N)*d + A*np.sin(phase), np.arange(N)*d, np.zeros(N), np.ones(N)*d
    ball_disp = ball_pos - ball_orig
    t, dt = 0, 0.001
    count, timecount = -1, 0
    while True:
        rate(1000)
        t += dt
        temp = ball_disp[1]
        spring_len[-1] = ball_pos[0] - ball_pos[-1] + N * d
        spring_len[:-1] = ball_pos[1:] - ball_pos[:-1]
        ball_v[0] = (k * ((spring_len[0] - d) - (spring_len[-1] - d))) / m
        ball_v[1:] = (k * ((spring_len[1:] - d) - (spring_len[:-1] - d))) / m
        ball_pos += ball_v*dt
        ball_disp = ball_pos - ball_orig
        if (ball_disp[1]>=0 and temp<=0) or (ball_disp[1]<=0 and temp>=0):
            count += 1
        if count==-1:
            continue
        else:
            timecount += 1
        if count==2:
            x.plot(pos=(1/(timecount/1000),n))
            break