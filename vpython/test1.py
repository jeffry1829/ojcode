from vpython import *
import numpy as np
from histogram import *


N = 800
m, size = 28E-3/6E23, 0.1/90#20E-11 # He atom are 10 times bigger for easiear collision but not too big for accuracy
Tc=-100
L = 0.1#((24.4E-3/(6E23))*N)**(1/3.0)/2 + size # 2L is the cubic container's original length, width, and height
k, Tk = 1.38E-23, Tc+273# Boltzmann Constant and initial temperature
t, dt = 0,0.000005# 0.000005#3E-13
vrms = (2*k*1.5*Tk/m)**0.5 # the initial root mean square velocity
stage=0
counter=0

n=2
amplitude=0.1*L
#v=331+0.6*Tc
#delp,delpx,delpy,delpz=0,0,0,0

atoms = [] # list to store atoms

#initialization
scene = canvas(width=500, height=500, background=vector(0.2,0.2,0), align = 'left')
container = box(length = 0.25*L, height = 2.5*L, width = 0.25*L, opacity=0.2, color = color.yellow )
floor=box(length=container.length,height=0.025*L,width=container.width,color=color.red,pos=vec(0,container.height/2,0))
freq=2*594#n*v/(container.height)
freq_theo=n*v/(2*container.height)

# histogram setting
deltav = L/50. # slotwidth for v histogram
vdist = graph(x=800, y=0, ymax = 8,width=500, height=300, xtitle='y coordinate', ytitle='dN', align = 'left')

observation = ghistogram(graph = vdist, bins=arange(-container.height/2,container.height/2,deltav), color=color.red) # for the simulation speed distribution

def keyinput(evt):
    global n,freq,stage
    move={'a':100,'b':10,'c':1,'x':-100,'y':-10,'z':-1,'o':0}
    test={'m':1}
    resonance={'n':1}
    s=evt.key
    if s in move:
        freq=freq+move[s]
        print('frequency applied',freq)
#        observation.clear()
    if s in test:
        stage=stage+test[s]
    if s in resonance:
        n=n+move[s]
        print('n=',n)



scene.bind('keydown',keyinput)

p_a, v_a = np.zeros((N,3)), np.zeros((N,3)) # particle position array and particle velocity array, N particles and 3 for x, y, z
py_a=np.zeros(N)
for i in range(N):
    p_a[i] = [container.length*random() - container.length/2, container.height*random() - container.height/2, container.width*random() - container.width/2] # particle is initially random positioned in container
    atom = sphere(pos=vector(p_a[i, 0], p_a[i, 1], p_a[i, 2]), radius = size, color=vector(random(), random(), random()))
    ra = pi*random()
    rb = 2*pi*random()
    v_a[i] = [vrms*sin(ra)*cos(rb), vrms*sin(ra)*sin(rb), vrms*cos(ra)] # particle initially same speed but random direction
    atoms.append(atom)


def vcollision(a1p, a2p, a1v,a2v): # the function for handling velocity after collisions between two atoms
 v1prime = a1v - (a1p - a2p) * sum((a1v-a2v)*(a1p-a2p)) / sum((a1p-a2p)**2)
 v2prime = a2v - (a2p - a1p) * sum((a2v-a1v)*(a2p-a1p)) / sum((a2p-a1p)**2)
 return v1prime, v2prime
print('initial condition')
print('N=',N,'mass of atom=',m,'kg','size of atom=',size,'m','vrms=',vrms)
#print('n=',n)
#print('freq applied',freq)
#print('freq-theo',freq_theo)
#print('wave length',v/freq)
#print('number of atoms per m^3',N/(container.length*container.width*container.height))
#print('sound wave',v,'vrms',vrms)

while True:
   t += dt
   rate(1000000)
   p_a += v_a*dt # calculate new positions for all atoms
   if stage>=1:
       container.width=0.24*L
       container.length=0.24*L
#   if stage>=3:
#     floor.pos.y=container.height/2-amplitude+amplitude*sin(2*pi*freq*t)
#     floor_vy=2*pi*freq*amplitude*cos(2*pi*freq*t) 
   for i in range(N):
       atoms[i].pos = vector(p_a[i, 0], p_a[i, 1], p_a[i, 2]) # to display atoms at new positions
#       py_a[i]=p_a[i,1] 
#   observation.plot(data = py_a)
   
### find collisions between pairs of atoms, and handle their collisions
   r_array = p_a-p_a[:,np.newaxis] # array for vector from one atom to another atom for all pairs of atoms
   rmag = np.sqrt(np.sum(np.square(r_array),-1)) # distance array between atoms for all pairs of atoms
   hit = np.less_equal(rmag,2*size)-np.identity(N) # if smaller than 2*size meaning these two atoms might hit each other
   hitlist = np.sort(np.nonzero(hit.flat)[0]).tolist() # change hit to a list
   for ij in hitlist: # i,j encoded as i*Natoms+j
       i, j = divmod(ij,N) # atom pair, i-th and j-th atoms, hit each other
       hitlist.remove(j*N+i) # remove j,i pair from list to avoid handling the collision twice
       if sum((p_a[i]-p_a[j])*(v_a[i]-v_a[j])) < 0 : # only handling collision if two atoms are approaching each other
           v_a[i], v_a[j] = vcollision(p_a[i], p_a[j], v_a[i], v_a[j]) # handle collision
   
   if stage==0 or stage==1 or stage==2:
       for i in range(N): 
         if abs(p_a[i][0]) >= container.length/2 - size and p_a[i][0]*v_a[i][0] > 0 :
            v_a[i][0] = - v_a[i][0]
#            delpx=delpx+abs(2*m*v_a[i][0])
         if abs(p_a[i][1]) >= container.height/2 - size and p_a[i][1]*v_a[i][1] > 0 :
            v_a[i][1] = - v_a[i][1]
#            delpy=delpy+abs(2*m*v_a[i][1])
         if abs(p_a[i][2]) >= container.width/2 - size and p_a[i][2]*v_a[i][2] > 0 :
            v_a[i][2] = - v_a[i][2]
#            delpz=delpz+abs(2*m*v_a[i][2])
#         delp=delp+delpx+delpy+delpz
        
         if t>1000*dt*counter:
            if stage==0:
              Ek0=0
              for i in range(N) :
                Ek0=Ek0+0.5*m*(v_a[i][0]**2+v_a[i][1]**2+v_a[i][2]**2)
              T0=Ek0/((3/2)*N*k)
              V0=container.width*container.length*container.height
              P0=N*k*T0/V0#(delp/(1000*dt*10000))/(2*container.width*container.length+2*container.length*container.height+2*container.height*container.width)
#              print('stage=',stage,'T=''%8.2f'%T0,'P=''%.3g'%P0,'V=''%.3g'%V0,'PV=''%.3g'%(P0*V0),'NkT=''%.3g'%(N*k*T0),'P_theo=''%.3g'%(N*k*T0/V0))
              print('stage=',stage,'T(K)=''%8.2f'%T0,'Pressure of gas(Pa)=''%.3g'%P0,'Volume of container(m^3)=''%.3g'%V0)
              print('press m to get to the next stage')
#              delp,delpx,delpy,delpz=0,0,0,0
              counter=counter+1
            if stage==1:
              Ek1=0
              for i in range(N) :
                Ek1=Ek1+0.5*m*(v_a[i][0]**2+v_a[i][1]**2+v_a[i][2]**2)
              T1=Ek1/((3/2)*N*k)
              V1=container.width*container.length*container.height
              P1=N*k*T1/V1#(delp/(1000*dt*10000))/(2*container.width*container.length+2*container.length*container.height+2*container.height*container.width)
              print('stage=',stage,'T(K)=''%8.2f'%T1,'Pressure of gas(Pa)=''%.3g'%P1,'Volume of container(m^3)=''%.3g'%V1)
              print('press m to get to the next stage')
#              delp,delpx,delpy,delpz=0,0,0,0
              counter=counter+1
            if stage==2:
                bulk_modulus= -(P1-P0)*V0/(V1-V0)
                print('bulk_modulus(Pa)=','%.3g'%(bulk_modulus))
                density=N*m/V1
                print('density(kg/m^3)=''%.3g'%(density))
                sound_speed=sqrt(bulk_modulus/density)
                print('sound_speed(m/s)=',(sound_speed))
                freq=n*sound_speed/(2*container.height)
                print('thoery frequency for the',n,'harmonic''%.3g'%(n*sound_speed/(2*container.height)),'Hz')
                print('press o to show freqency applied')
                print('to adjust applied frequency:press a:+100 b:+10 c:+1 x:-100 y:-10 z:-1')
                print('press m to get to the final stage')
                counter=counter+1
                
#find collisions between the atoms and the walls, and handle their elastic collisions
   if stage>=3:
      floor.pos.y=container.height/2-amplitude+amplitude*sin(2*pi*freq*t)
      floor_vy=2*pi*freq*amplitude*cos(2*pi*freq*t)
      for i in range(N):
       py_a[i]=p_a[i,1] 
      observation.plot(data = py_a)
      if t>1000*dt*counter:print('thoery frequency for the ',n,' harmonic''%.3g'%(n*sound_speed/(2*container.height)))
      for i in range(N):
        if abs(p_a[i][0]) >= container.length/2 - size and p_a[i][0]*v_a[i][0] > 0 :
           v_a[i][0] = - v_a[i][0]
        if p_a[i][1] >= floor.pos.y - size and p_a[i][1]*v_a[i][1] > 0 :
           v_a[i][1] = - v_a[i][1]+2*floor_vy
        if p_a[i][1] <= size-container.height/2 and p_a[i][1]*v_a[i][1] > 0 :
           v_a[i][1] = - v_a[i][1]
        if abs(p_a[i][2]) >= container.width/2 - size and p_a[i][2]*v_a[i][2] > 0 :
           v_a[i][2] = - v_a[i][2]
        counter=counter+1




  












           
