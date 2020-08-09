#Gas.py
from vpython import*

size_N,size_O,size_C,size_H=65E-12,60E-12,70E-12,25E-12
m_N,m_O,m_C,m_H=14/(6E23),16/(6E23),12/(6E23),1/(6E23)

bondlen_N2,bondlen_O2,bondlen_CO2,bondlen_H2=145E-12,148E-12,116E-12,74E-12
dN2=2.5*size_N   #
#k_N2,k_O2,k_CO2,k_H2=
k_bond=18600
dt=1E-16

class N2_molecule:
    def __init__(self,pos,axis):
        self.Na=sphere(pos=pos,radius=size_N,color=color.red)
        self.Nb=sphere(pos=pos+axis,radius=size_N,color=color.red)
        self.bond=cylinder(pos=pos,axis=axis,radius=size_N/2.0,color=color.white)
        self.Na.m=m_N
        self.Nb.m=m_N
        self.Na.v=vector(0,0,0)
        self.Nb.v=vector(0,0,0)
        self.bond.k=k_bond

    def bond_force_on_Nb(self):
        return self.bond.k*(mag(self.bond.axis)-bondlen_N2)*norm(self.bond.axis)

    def N2time_lapse(self,dt):
        self.Na.a=-self.bond_force_on_Nb()/self.Na.m
        self.Nb.a=self.bond_force_on_Nb()/self.Nb.m
        self.Na.v=self.Na.v+self.Na.a*dt
        self.Nb.v=self.Nb.v+self.Nb.a*dt
        self.Na.pos=self.Na.pos+self.Na.v*dt
        self.Nb.pos=self.Nb.pos+self.Nb.v*dt
        self.bond.axis=self.Nb.pos-self.Na.pos
        self.bond.pos=self.Na.pos

class O2_molecule:
    def __init__(self,pos,axis):
        self.Oa=sphere(pos=pos,radius=size_O,color=color.blue)
        self.Ob=sphere(pos=pos+axis,radius=size_O,color=color.blue)
        self.bond=cylinder(pos=pos,axis=axis,radius=size_O/2.0,color=color.white)
        self.Oa.m=m_O
        self.Ob.m=m_O
        self.Oa.v=vector(0,0,0)
        self.Ob.v=vector(0,0,0)
        self.bond.k=k_bond

    def bond_force_on_Ob(self):
        return self.bond.k*(mag(self.bond.axis)-bondlen_O2)*norm(self.bond.axis)

    def O2time_lapse(self,dt):
        self.Oa.a=-self.bond_force_on_Ob()/self.Oa.m
        self.Ob.a=self.bond_force_on_Ob()/self.Ob.m
        self.Oa.v=self.Oa.v+self.Oa.a*dt
        self.Ob.v=self.Ob.v+self.Ob.a*dt
        self.Oa.pos=self.Oa.pos+self.Oa.v*dt
        self.Ob.pos=self.Ob.pos+self.Ob.v*dt
        self.bond.axis=self.Ob.pos-self.Oa.pos
        self.bond.pos=self.Oa.pos

def collision(a1,a2):
        v1prime=a1.v-2*a2.m/(a1.m+a2.m)*(a1.pos-a2.pos)*dot(a1.v-a2.v,a1.pos-a2.pos)/mag(a1.pos-a2.pos)**2
        v2prime=a2.v-2*a1.m/(a1.m+a2.m)*(a2.pos-a1.pos)*dot(a2.v-a1.v,a2.pos-a1.pos)/mag(a2.pos-a1.pos)**2
        return v1prime,v2prime

if __name__=='__main__':
        a=N2_molecule(pos=vector(0,0,0),axis=vector(0.5*bondlen_N2,0,0))
        a.Na.v=vector(1.0,1.0,0)
        a.Nb.v=vector(2.0,-1.0,0)
        a.N2time_lapse(dt)

        b=O2_molecule(pos=vector(0,2*size_N,0),axis=vector(bondlen_O2,0,0))
        b.Oa.v=vector(1.0,1.0,0)
        b.Ob.v=vector(2.0,-1.0,0)
        b.O2time_lapse(dt)
        print(a.bond_force_on_Nb(),b.bond_force_on_Ob())


