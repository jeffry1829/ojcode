from vpython import *
import numpy as np
import math
from histogram import *

 
N=500
m = 4E-3/6E23,#31E-12*10
L2=0.15/2#((24.4E-3/(6E23))*N)**(1/3.0)/2 + size
L1=L2#0.5*L2
size=L1/25
freq=7238
amplitude=3*L1
t=0
dt=0.000001
#bondlen_N2=145E-3
k, T = 1.38E-23, 298.0
vrms = 550#(2*k*1.5*T/m)**0.5

#bondlen_N2,bondlen_O2=0.001,0.001  
scene = canvas(width=500, height=500, background=vector(0.2,0.2,0), align = 'left')
container1 = box(length = 2*L1, height = 2*L1, width = 2*L1, opacity=0.2, color = color.yellow,
                 pos=vec(0,L1,0))
container2 = box(length = 2*L2, height = 2*L2, width = 2*L2, opacity=0.2, color = color.yellow,
                 pos=vec(0,-L2,0))
floor=box(length=2*L1,height=L2/10,width=2*L1,opacity=0.8,color=color.red,pos=vec(0,2*L1,0))
N2s=[]

# histogram setting
deltav = 0.005 # slotwidth for v histogram
vdist = graph(x=800, y=0, ymax = 0.3,width=500, height=300, xtitle='x', ytitle='density(N)', align = 'left')
theory_low_T = gcurve(color=color.cyan) # for plot of the curve for the atom speed distribution
observation = ghistogram(graph = vdist, bins=arange(0.,4.*L1,deltav), color=color.red)
 
c = curve()
graphAxis = curve(color = color.red)
graphLabel = label(text = 'Density', box = False, height = 11)
 
running = True
 
graphAxis.clear()
graphAxis.append( pos = vec(-1.5*L2, 2*L1, 0) )
graphAxis.append( pos = vec(-1.5*L2, -2*L2, 0) )
graphLabel.pos = vec(-1.5*L2, ((2*L1+2*L2)/2) + floor.height, 0)
 
def flipRunning():
  global running
  if (running == True):
    running = False
    pause.text = 'Resume'
  else:
    running = True
    pause.text = 'Pause'
pause = button(text = 'Pause', bind = flipRunning)
 
def setFrequency(freq):
  freq = freqSlider.value
 
scene.append_to_caption('\n\nPiston frequency\n')
 
freqSlider = slider(min=0, max=15000, value=917, bind=setFrequency)
 
def setAmplitude(amplitude):
  amplitude = amplitudeSlider.value
 
scene.append_to_caption('\n\nPiston amplitude\n')    
amplitudeSlider = slider(min=0, max=L1, value=0.01, bind=setAmplitude)
 
scene.append_to_caption('\n\nGraph bins\n')  
binSlider = slider(min = 2, max = 100, value = 100, bind = bin)
def bin(numBins):
  numBins = binSlider.value
 
freqText = label(text = 'Freq: ' + str(freq) + " Hz", pos = vec(1.2*L1,L1, 0), box = False, align = 'left' )
ampText = label(text = 'Amplitude: ' + str(amplitude*100) + ' cm', pos = vec(1.2*L1, -L1,0), box = False, align = 'left' )

c = curve()
numBins = int(binSlider.value)
seg = (2*L1+2*L2) / numBins
for i in range(numBins):
    c.append(pos=(0,0,0))
positionBin=np.zeros(numBins)
 
p_N2, v_N2 = np.zeros((N,3)), np.zeros((N,3))
for i in range(N):
    p_N2[i] = [2 * L2*random() - L2, 2 * L2*random() - 2*L2, 2 * L2*random() - L2] # particle is initially random positioned in container
    N2 = sphere(pos=vector(p_N2[i, 0], p_N2[i, 1], p_N2[i, 2]), radius = size, color=color.red)
    ra = pi*random()
    rb = 2*pi*random()
    v_N2[i] = [vrms*sin(ra)*cos(rb), vrms*sin(ra)*sin(rb), vrms*cos(ra)] # particle initially same speed but random direction
    N2s.append(N2)
 
#N2s[0].make_trail=True
 
def vcollision(a1p, a2p, a1v,a2v): # the function for handling velocity after collisions between two atoms
 v1prime = a1v - (a1p - a2p) * sum((a1v-a2v)*(a1p-a2p)) / sum((a1p-a2p)**2)
 v2prime = a2v - (a2p - a1p) * sum((a2v-a1v)*(a2p-a1p)) / sum((a2p-a1p)**2)
 return v1prime, v2prime
counter=0
 
zeta0=5
delta0=2*L1/zeta0
origin0=np.array([-L1,0,L1])
grid0=np.empty((zeta0,zeta0,zeta0),dtype=object)
#sphere(color=color.blue,pos=vec(origin0[0],origin0[1],origin0[2]),radius=size)
 
zeta=18
delta=4*L1/zeta
origin=np.array([-2*L1,-4*L1,2*L1])
grid=np.empty((zeta,zeta,zeta),dtype=object)
#sphere(color=color.blue,pos=vec(origin[0],origin[1],origin[2]),radius=size)
def colli(zeta_,delta_,origin_,grid_):
    for i in range(zeta_):
        for j in range(zeta_):
            for k in range(zeta_):
                grid_[i,j,k]=[]
    for i in range(N):
        if p_N2[i][1]+size>=origin_[1] and p_N2[i][1]-size<=origin[1]+zeta_*delta_:
            _pos=p_N2[i]-origin_
            _pos[0]=math.floor(_pos[0]/delta_)
            _pos[1]=math.floor(_pos[1]/delta_)
            _pos[2]=math.floor(-_pos[2]/delta_) #change sign to positive
            _pos=_pos.astype(int)
            for j in range(3):
                if _pos[j]>=zeta_:
                    _pos[j]=zeta_-1
            grid_[_pos[0],_pos[1],_pos[2]].append(i)
    for i in range(zeta_):
        for j in range(zeta_):
            for k in range(zeta_):
                length=len(grid_[i,j,k])
                #if length!=0: print(length)
                for l in range(length-1):
                    _l=grid_[i,j,k][l]
                    for m in range(l+1, length):
                        _m=grid_[i,j,k][m]
                        if math.sqrt((p_N2[_l][0]-p_N2[_m][0])**2+(p_N2[_l][1]-p_N2[_m][1])**2+(p_N2[_l][2]-p_N2[_m][2])**2)<2*size:
                            if sum((p_N2[_l]-p_N2[_m])*(v_N2[_l]-v_N2[_m]))<0:
                                v_N2[_l], v_N2[_m] = vcollision(p_N2[_l], p_N2[_m], v_N2[_l], v_N2[_m])
 
while True:
    t=t+dt
    counter+=1
    if (not running): continue
 
    freqText.text = 'Freq: ' + str(freq) + ' Hz'
    ampText.text = 'Amplitude: ' + str(round(1000*amplitude)/10) + ' cm'
    amplitude = amplitudeSlider.value
    freq = freqSlider.value
#   rate(10000)
    floor.pos.y=2*L1+amplitude*sin(2*pi*freq*t)
    floor_vy=2*pi*freq*amplitude*cos(2*pi*freq*t)
    p_N2=p_N2+ v_N2*dt # calculate new positions for all atoms
    for i in range(N): N2s[i].pos = vector(p_N2[i, 0], p_N2[i, 1], p_N2[i, 2])
 
    #colli(zeta0,delta0,origin0,grid0)
    #colli(zeta,delta,origin,grid)
 
    r_array = p_N2-p_N2[:,np.newaxis] # array for vector from one atom to another atom for all pairs of atoms
    rmag = np.sqrt(np.sum(np.square(r_array),-1)) # distance array between atoms for all pairs of atoms
    hit = np.less_equal(rmag,2*size)-np.identity(N) # if smaller than 2*size meaning these two atoms might hit each other
    hitlist = np.sort(np.nonzero(hit.flat)[0]).tolist() # change hit to a list
    for ij in hitlist: # i,j encoded as i*Natoms+j
        i, j = divmod(ij,N) # atom pair, i-th and j-th atoms, hit each other
        hitlist.remove(j*N+i) # remove j,i pair from list to avoid handling the collision twice
        if sum((p_N2[i]-p_N2[j])*(v_N2[i]-v_N2[j])) < 0 : # only handling collision if two atoms are approaching each other
            v_N2[i], v_N2[j] = vcollision(p_N2[i], p_N2[j], v_N2[i], v_N2[j]) # handle collision
   
   
    for i in range(N):
        if p_N2[i][1]>=0:
            if abs(p_N2[i][0]) >= L1 - size and p_N2[i][0]*v_N2[i][0] > 0 :
                v_N2[i][0] = - v_N2[i][0]
            if abs(p_N2[i][2]) >= L1 - size and p_N2[i][2]*v_N2[i][2] > 0 :
                v_N2[i][2] = - v_N2[i][2]
            if p_N2[i][1]>=floor.pos.y-floor.height/2-size and (v_N2[i][1]-floor_vy) > 0:
                v_N2[i][1] = - v_N2[i][1]+2*floor_vy
        if p_N2[i][1]<0:
            if abs(p_N2[i][0]) >= L2 - size and p_N2[i][0]*v_N2[i][0] > 0 :
                v_N2[i][0] = - v_N2[i][0]
            if abs(p_N2[i][2]) >= L2 - size and p_N2[i][2]*v_N2[i][2] > 0 :
                v_N2[i][2] = - v_N2[i][2]
            if p_N2[i][1] >= - size and p_N2[i][1]<0 and v_N2[i][1] > 0 and (abs(p_N2[i][0])>L1 or abs(p_N2[i][2])>L1):
                v_N2[i][1] = - v_N2[i][1]
            if p_N2[i][1] <= -2*L2 + size and p_N2[i][1]*v_N2[i][1] > 0 :
                v_N2[i][1] = - v_N2[i][1]
    
    newnumBins = int(binSlider.value)
    if numBins!=newnumBins:
        numBins=newnumBins
        c.clear()
        seg = (2*L1+2*L2) / numBins
        for i in range(numBins):
            c.append(pos=(0,0,0))
        positionBin=np.zeros(numBins)
    avgNinBin=N/numBins
    positionBin.fill(0)
    for i in range(N):
        j=0
        if p_N2[i][1]>0:
            j=math.floor((2*L1-p_N2[i][1])/seg)
        elif p_N2[i][1]<=0:
            j=math.floor((-p_N2[i][1]+2*L1)/seg)
        if j>=numBins:
            j=numBins-1
        positionBin[j]+=1
    #for j in range(math.floor(2*L1/seg)):
        #positionBin[j]*=4
    for j in range(numBins):
        c.modify(j,pos = vec(-1.5*L2 - ((positionBin[j])/N), 2*L1 - j*seg, 0))
        observation.plot(data=np.full(int(abs(avgNinBin-positionBin[j])),j*seg,dtype=float))