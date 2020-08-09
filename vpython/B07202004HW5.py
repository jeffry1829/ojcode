from vpython import *
G = 6.673E-11
mass	=	{'earth':	5.97E24,	'moon':	7.36E22,	'sun':1.99E30}
radius	=	{'earth':	6.371E6*10,	'moon':	1.317E6*10,	'sun':6.95E8*10}	#10	times	larger	for	better	view	
earth_orbit	=	{'r':	1.495E11,	'v':	2.9783E4}
moon_orbit	=	{'r':	3.84E8,	'v':	1.022E3}
theta	=	5.145*pi/180.0
def G_force(M,m, pos_vec):
    return G * M * m / mag2(pos_vec) * norm(pos_vec) #pos_vec:M->m
class as_obj(sphere):
    def kinetic_energy(self):
        return 0.5 * self.m * mag2(self.v)
def potential_energy(self):
    return -G * mass['sun'] * self.m / mag(self.pos)
scene = canvas(width = 800, height = 800, background = vector(0.5, 0.5, 0))
sun = as_obj(pos = vector(0, 0, 0), radius = radius['sun'], m = mass['sun'], texture = {
  'file': textures.sun
},v=vec(0,0,0))
earth = as_obj(pos = vector(earth_orbit['r'], 0, 0), radius = radius['earth'], m = mass['earth'], texture = {
  'file': textures.earth
},v=vec(0,12.599531,0))
moon = as_obj(pos = vector(earth_orbit['r']-moon_orbit['r']*sin(theta), 0, moon_orbit['r']*cos(theta)), radius = radius['moon'], m = mass['moon']
,v=vec(0,-moon_orbit['v'],0))
#scene.forward=vector(0,0,-1)

dt = 60 * 60 * 6
while True:
    rate(10)
    earth.a=G_force(earth.m,moon.m,moon.pos-earth.pos)/earth.m
    moon.a=G_force(earth.m,moon.m,earth.pos-moon.pos)/moon.m
    earth.v+=dt*earth.a
    moon.v+=dt*moon.a
    earth.pos+=dt*earth.v
    moon.pos+=dt*moon.v
