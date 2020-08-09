#https://youtu.be/JXR4Blt8Dc8
from vpython import *
T=0
L=0
g=9.8 # g = 9.8 m/s^2
size = 0.25 # ball radius = 0.25 m
height = 15.0 # ball center initial height = 15 m
scene = canvas(width=800, height=800, center=vec(0,height/2,0), background=vec(0.5,0.5,0)) # open a window
floor = box(pos=vec(0,0,0),length=100, height=0.01, width=100, color=color.blue) # the floor
ball = sphere(radius = size, color=color.red, make_trail = True, trail_radius = 0.05) # the ball
msg =text(text = 'Free Fall', pos = vec(-10, 10, 0))
ball.pos = vec( -15, 5, 0) # ball center initial position
ball.v = vec(6, 8, 10) # ball initial velocity
a1 = arrow(color = color.green, shaftwidth = 0.05)

a1.pos=ball.pos
a1.axis=ball.v
dt = 0.001 # time step
while ball.pos.y >= 0: # until the ball hit the ground
 rate(1000) # run 1000 times per real second
 ball.pos = ball.pos + ball.v*dt
 ball.v.y = ball.v.y - g*dt
 a1.pos=ball.pos
 a1.axis=ball.v
 T+=dt
 L+=mag(ball.v*dt)
msg.visible = False
text(text = "displacement: %s"%str(ball.pos-vec(-15,5,0)), pos = vec(-10, 10, 0))
text(text = "T: %f"%T, pos = vec(-10, 15, 0))
text(text = "L: %f"%L, pos = vec(-10, 5, 0))
