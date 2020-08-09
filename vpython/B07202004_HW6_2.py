from vpython import *
size, m = 0.02, 0.2 # ball size = 0.02 m, ball mass = 0.2kg
L, k = 0.2, 20 # spring original length = 0.2m, force constant = 20 N/m
amplitude = 0.03
b1 = 0.05 * m * sqrt(k/m)
b2 = 0.0025 * m * sqrt(k/m)
K=5.0
scene = canvas(width=600, height=400, fov = 0.03, align = 'left', center=vec(0.3, 0, 0), background=vec(0.5,0.5,0))
wall_left = box(length=0.005, height=0.3, width=0.3, color=color.blue) # left wall
wall_right = box(length=0.005, height=0.3, width=0.3, color=color.blue, pos=vec(3*L,0,0)) # right wall
ball1 = sphere(radius = size, color=color.red) # ball
ball2 = sphere(radius = size, color=color.red) # ball
spring1 = helix(radius=0.015, thickness =0.01)
spring2 = helix(radius=0.015, thickness =0.01)
spring3 = helix(radius=0.015, thickness =0.01)
oscillation = graph(width = 400, align = 'left', xtitle='t',ytitle='x',background=vec(0.5,0.5,0))
x1=gcurve(color=color.red,graph = oscillation)
x2=gcurve(color=color.blue,graph = oscillation)
PT = graph(width = 400, align = 'left', xtitle='t',ytitle='x',background=vec(0.5,0.5,0))
PTx=gdots(color=color.red,graph = PT)
ball1.pos = vector(L, 0 , 0) # ball initial position
ball2.pos=vector(2*L, 0 , 0)
ball1.v = vector(0, 0, 0) # ball initial velocity
ball2.v = vector(0, 0, 0)
ball1.m = m
ball2.m = m
spring1.pos = vector(0, 0, 0)
spring2.pos = vector(L, 0, 0)
spring3.pos = vector(2*L, 0, 0)
t, dt = 0, 0.001
f_a=0.1
w_d=sqrt((k+K)/m)
sumPT=0
count=0
interval=2*3.1415926/w_d
while True:
    rate(1000)
    spring1.axis = ball1.pos - spring1.pos # spring extended from spring endpoint A to ball
    spring2.axis = ball2.pos - spring2.pos # spring extended from spring endpoint A to ball
    spring3.axis = vec(3*L,0,0) - spring3.pos # spring extended from spring endpoint A to ball
    spring_force1 = - k * (mag(spring1.axis) - L) * norm(spring1.axis) # spring force vector
    spring_force2 = - K * (mag(spring2.axis) - L) * norm(spring2.axis) # spring force vector
    spring_force3 = - k * (mag(spring3.axis) - L) * norm(spring3.axis) # spring force vector
    ball1.a = spring_force1 / m # ball acceleration = spring force /m - damping
    F=f_a*sin(w_d*t)*vec(1,0,0)
    ball1.a+=-b1*ball1.v/m
    ball1.a+=F/m
    ball1.a+=-spring_force2/m
    ball1.v += ball1.a*dt
    ball1.pos += ball1.v*dt

    ball2.a = spring_force2 / m # ball acceleration = spring force /m - damping
    ball2.a+=-b2*ball1.v/m
    ball2.a+=-spring_force3/m
    ball2.v += ball2.a*dt
    ball2.pos += ball2.v*dt
    sumPT+=F.dot(ball1.v)
    count+=1
    t += dt
    x1.plot(pos=(t,ball1.pos.x - L))
    x2.plot(pos=(t,ball2.pos.x - 2*L))
    if t%interval<0.001:
        PTx.plot(pos=(t,sumPT/count))
    spring2.pos=ball1.pos
    spring3.pos=ball2.pos
