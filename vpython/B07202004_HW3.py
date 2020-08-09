#https://youtu.be/imduy050d4g
from vpython import *
g = 9.8
size, m = 0.05, 0.2
L, k = 0.5, [15, 12, 17]
v = [1, 2, 2.2]
d = [-0.06, 0, -0.1]
T=0
dt=0.001
scene = canvas(width=400, height=400, center =vec(0.4, 0.2, 0), align = 'left', background=vec(0.5,0.5,0))
floor = box(pos = vec(0.4, 0, 0), length=0.8, height=0.005, width=0.8, color=color.blue)
wall = box(pos= vec(0, 0.05, 0), length = 0.01, height = 0.1, width =0.8)
balls = []
for i in range(3):
 ball = sphere(pos = vec(L+d[i], size, (i-1)*3*size), radius = size, color=color.red)
 ball.v = vec(v[i], 0, 0)
 balls.append(ball)
springs =[]
for i in range(3):
 spring = helix(pos = vec(0, size, (i-1)*3*size), radius=0.02, thickness =0.01)
 spring.axis = balls[i].pos-spring.pos
 spring.k = k[i]
 springs.append(spring)
i_kp=graph(width = 450, align = 'right')
ifk=gcurve(graph = i_kp, color=color.blue, width=4)
ifp=gcurve(graph = i_kp, color=color.red, width=4)
a_kp=graph(width = 450, align = 'right')
afk=gcurve(graph = a_kp, color=color.blue, width=4)
afp=gcurve(graph = a_kp, color=color.red, width=4)
K,P=0,0
sizes = [0.06, 0.04] # for balls’ sizes
ms = [0.2, 0.12] # for balls’ mass
LL,kk=0.5,15
bball1=sphere(pos = vec(-1, size+1, 0), radius = sizes[0], color=color.red,v=vec(0,0,0))
bball2=sphere(pos = vec(-1+1.1*LL, size+1, 0), radius = sizes[1], color=color.red,v=vec(0,0,0))
sspring=helix(pos = bball1.pos, radius=0.02, thickness =0.01)
sspring.axis=bball2.pos-sspring.pos
TT=0
while True:
    rate(1000)
    TT+=dt
    bball1.a=((kk*(mag(sspring.axis)-LL))/ms[0])*sspring.axis.norm()
    bball2.a=-((kk*(mag(sspring.axis)-LL))/ms[1])*sspring.axis.norm()
    bball1.v+=bball1.a*dt
    bball2.v+=bball2.a*dt
    bball1.pos+=bball1.v*dt
    bball2.pos+=bball2.v*dt
    sspring.pos=bball1.pos
    sspring.axis=bball2.pos-sspring.pos
    if mag(bball1.pos-vec(-1, size+1, 0))<0.000001 and TT!=dt:
        print("time-period:%f" % TT)
        TT=0

    T+=dt
    iK,iP=0,0
    for i in range(3):
        balls[i].a=-((k[i]*(mag(springs[i].axis)-L))/m)*springs[i].axis.norm()
        balls[i].v+=balls[i].a*dt
        balls[i].pos+=balls[i].v*dt
        springs[i].axis=balls[i].pos-springs[i].pos
        iK+=0.5*m*mag(balls[i].v)**2
        iP+=0.5*k[i]*(mag(springs[i].axis)-L)**2
        K+=iK
        P+=iP
    afk.plot(T,K/T)
    afp.plot(T,P/T)
    ifk.plot(T,iK)
    ifp.plot(T,iP)