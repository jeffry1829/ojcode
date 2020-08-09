#https://youtu.be/NVqsGq_d4pI
from vpython import *
g=9.8 # g = 9.8 m/s^2
size = 0.25 # ball radius = 0.25 m
height = 15.0 # ball center initial height = 15 m
C_drag = 1.2
C_drag2 = 0.3
scene = canvas(width=600, height=600, center =vec(0,height/2,0), background=vec(0.5,0.5,0))
floor = box(length=30, height=0.01, width=10, color=color.blue)
ball = sphere(radius = size, color=color.red, make_trail = True)
ball.pos = vec(-15, size, 0)
ball2 = sphere(radius = size, color=color.red, make_trail = True)
ball2.pos = vec(0, 100, 0)
theta=pi/4
ball.v = vec(20*cos(theta), 20*sin(theta), 0) # ball initial velocity
ball2.v=vec(0,0,0)
dt = 0.001 # time step
hit_ground=0
highest_height=0
v_t=graph(width = 450, align = 'right')
f1=gcurve(graph = v_t, color=color.blue, width=4)
v_t2=graph(width = 450, align = 'right')
f2=gcurve(graph = v_t2, color=color.blue, width=4)
t=0
ball2.move=True
while hit_ground<3 or ball2.move: # until the ball hit the ground
    rate(1000) # run 1000 times per real second
    if hit_ground<3:
        ball.v += vec(0, -g, 0) * dt - C_drag*ball.v*dt
        f1.plot(t,mag(ball.v))
        ball.pos += ball.v*dt
    if ball2.move:
        ball2.v += vec(0, -g, 0) * dt - C_drag2*ball2.v*dt
        f2.plot(t,mag(ball2.v))
        ball2.pos += ball2.v*dt
    if ball.pos.y>=highest_height:
        highest_height=ball.pos.y
    if ball.pos.y<=size:
        hit_ground+=1
        ball.v.y*=-1
    if abs(mag(vec(0, -g, 0) * dt - C_drag2*ball2.v*dt))<0.0001:
        print("Terminal velocity:%f" % mag(ball2.v))
        ball2.move=False
    t+=dt
text(text="displacement: %f"%mag(ball.pos-vec(-15,size,0)), pos = vec(-10,15,0))
msg = text(text = 'highest height: %f'%highest_height, pos = vec(-10, 20, 0))
