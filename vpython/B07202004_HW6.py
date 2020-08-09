from vpython import *
class obj: pass
wall_left, ball, spring = obj(), obj(), obj()
size, m = 0.02, 0.2 # ball size = 0.02 m, ball mass = 0.2kg
L, k = 0.2, 20 # spring original length = 0.2m, force constant = 20 N/m
amplitude = 0.03
b = 0.05 * m * sqrt(k/m)

PTwd = graph(height = 400,width = 400, align = 'left', xtitle='w_d',ytitle='PT',background=vec(0.5,0.5,0))
PTwdx=gcurve(color=color.red,graph = PTwd)


omega = [0.1*i + 0.7*sqrt(k/m) for i in range(1, int(0.5*sqrt(k/m)/0.1))]
f_a=0.1
biggest_w=0
biggest_pt=0
for w_d in omega:
    ball.pos = vector(L, 0 , 0) # ball initial position
    ball.v = vector(0, 0, 0) # ball initial velocity
    ball.m = m
    spring.pos = vector(0, 0, 0)
    t, dt = 0, 0.001
    last_high_P_T=0
    interval=2*3.1415926/w_d
    P_T_t=0
    count=0
    while True:
        spring.axis = ball.pos - spring.pos # spring extended from spring endpoint A to ball
        spring_force = - k * (mag(spring.axis) - L) * norm(spring.axis) # spring force vector
        F=f_a*sin(w_d*t)*vec(1,0,0)
        ball.a = spring_force / ball.m # ball acceleration = spring force /m - damping
        ball.a+=-b*ball.v/ball.m
        ball.a+=F/ball.m
        ball.v += ball.a*dt
        ball.pos += ball.v*dt
        t += dt
        count+=1
        P_T_t+=F.dot(ball.v)
        if t%interval <0.001:
            if P_T_t/count > last_high_P_T:
                if P_T_t/count-last_high_P_T<0.01:
                    PTwdx.plot(pos=(w_d,P_T_t/count))
                    if P_T_t/count>biggest_pt:
                        biggest_w=w_d
                    break
                last_high_P_T=P_T_t/count
print("biggest w_d:%f"%biggest_w)