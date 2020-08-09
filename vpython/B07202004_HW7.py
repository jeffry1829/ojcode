import numpy as np
from vpython import *
A, N, omega = 0.10, 50, 2*pi/1.0
size, m, k, d = 0.06, 0.1, 10.0, 0.4
#scene = canvas(title='Spring Wave', width=800, height=300, background=vec(0.5,0.5,0), center = vec((N-1)*d/2, 0, 0))
#balls = [sphere(radius=size, color=color.red, pos=vector(i*d, 0, 0), v=vector(0,0,0)) for i in range(N)] #3
#springs = [helix(radius = size/2.0, thickness = d/15.0, pos=vector(i*d, 0, 0), axis=vector(d,0,0)) for i in range(N-1)] #3
#c = curve([vector(i*d, 1.0, 0) for i in range(N)], color=color.black)

w_k = graph(width = 400, align = 'left', xtitle='Wavevector',ytitle='omega',background=vec(0.5,0.5,0))
w_k_p=gdots(color=color.red,graph=w_k)
for n in range(25):
    n=n+1
    Unit_K = 2 * pi/(N*d)
    Wavevector = n * Unit_K
    phase = Wavevector * arange(N) * d
    ball_pos, ball_orig, ball_v, spring_len = np.arange(N)*d + A*np.sin(phase), np.arange(N)*d, np.zeros(N), np.ones(N)*d
    t, dt = 0, 0.0003
    init_N2=ball_pos[23]
    count=0
    while True:
        t += dt
        for i in range(N-1):
            spring_len[i]=ball_pos[i+1]-ball_pos[i]
        for i in range(N-1):
            if i!=0:
                ball_v[i]+=-k*(d-spring_len[i])/m*dt
                ball_v[i]+=k*(d-spring_len[i-1])/m*dt
        ball_v[N-1]+=k*(d-spring_len[N-2])/m*dt
        ball_v[N-1]+=-k*(-(N-1)*d+ball_pos[N-1]+ball_pos[0])/m*dt
        for i in range(N):
            if i!=0:
                ball_pos[i]+=ball_v[i]*dt
        ball_v[0]+=-k*(-(N-1)*d+ball_pos[N-1]+ball_pos[0])/m*dt
        #for i in range(N): 
        #    balls[i].pos.x = ball_pos[i] #3
        #for i in range(N-1): #3
        #    springs[i].pos = balls[i].pos #3
        #    springs[i].axis = balls[i+1].pos - balls[i].pos #3
        #ball_disp = ball_pos - ball_orig
        #for i in range(N):
        #    c.modify(i, y = ball_disp[i]*4+1)
        if abs(init_N2-ball_pos[23]) < 0.001 and t>0.3:
            w_k_p.plot(pos=(Wavevector,2*pi/t))
            break
