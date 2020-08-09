from vpython import *
g = 9.8
size, m = 0.02, 0.5
L, k = 0.5, 15000
dt=0.001
N=5 ##
NN=2 ##
scene = canvas(width=500, height=500, center=vec(0, 0, 0), background=vec(0.5,0.5,0))
ceiling = box(pos=vec(0,L,0), length=0.8, height=0.005, width=0.8, color=color.blue)
dt = 0.001
def af_col_v(m1, m2, v1, v2, x1, x2): # function after collision velocity
    v1_prime = v1 + 2*(m2/(m1+m2))*(x1-x2) * dot (v2-v1, x1-x2) / dot (x1-x2, x1-x2)
    v2_prime = v2 + 2*(m1/(m1+m2))*(x2-x1) * dot (v1-v2, x2-x1) / dot (x2-x1, x2-x1)
    return (v1_prime, v2_prime)
balls=[]
for i in range(N):
    balls.append(sphere(pos = vec(i*size*2,0,0), radius = size, color=color.yellow))
    balls[i].v = vec(0,0,0)
    balls[i].m = m
    balls[i].a=vec(0,0,0)
for i in range(NN):
    balls[i].v=vec(1,0,0)
springs=[]
for i in range(N):
    springs.append(cylinder(radius=0.005))
    springs[i].pos=balls[i].pos
    springs[i].pos.y+=L
    springs[i].axis=balls[i].pos-springs[i].pos
    
while True:
    rate(1000)
    for i in range(N):
        if i-1 >= 0:
            if mag(balls[i-1].pos-balls[i].pos)<2*size and dot(balls[i-1].pos-balls[i].pos,balls[i-1].v-balls[i].v)<=0:
                (balls[i-1].v,balls[i].v)=af_col_v(m,m,balls[i-1].v,balls[i].v,balls[i-1].pos,balls[i].pos)
        if i+1 < N:
            if mag(balls[i+1].pos-balls[i].pos)<2*size and dot(balls[i+1].pos-balls[i].pos,balls[i+1].v-balls[i].v)<=0:
                (balls[i+1].v,balls[i].v)=af_col_v(m,m,balls[i+1].v,balls[i].v,balls[i+1].pos,balls[i].pos)
        balls[i].a=vec(0,0,0)
        balls[i].a.y-=g
        balls[i].a+=-((k*(mag(springs[i].axis)-L))/m)*springs[i].axis.norm()
        balls[i].v+=balls[i].a*dt
        balls[i].pos+=balls[i].v*dt
        springs[i].axis=balls[i].pos-springs[i].pos
