using DifferentialEquations
using Plots
gr()
function Run()
  α=3/2
  d=2.0 #ball 2×r
  E=207.0 #彈性模量
  ν=0.29 #柏松比
  k=(E*sqrt(d))/(3(1-ν^2))
  n::Integer ,m::Integer = 2,8 #n≝initial moveing ball number
  x₀=zeros(Float64,n+m)
  #v₀=[1.0,1.0,0.0,0.0,0.0]
  #mass=[1.0,1.0,1.0,1.0,1.0]
  v₀=[3.0,3.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]
  mass=[1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]
  u₀=vcat(v₀,x₀)
  tspan=(0.0,10.0)
  a=Array{Array{Float64}}(undef,0) #
  for i=1:n+m; push!(a,[]) end
  ts=Array{Float64}(undef,0) # these two are used to plot acceleration
  function δ(x::Float64) if x<0 0;else x end end
  function f(du,u,p,t)
    push!(ts,t)
    du[1]=(-k*(δ(u[n+m+1]-u[n+m+2])^α))/mass[1]
    push!(a[1],du[1])
    du[n+m]=(k*(δ(u[n+m+(n+m-1)]-u[n+m+(n+m)])^α))/mass[n+m]
    push!(a[n+m],du[n+m])
    for i=2:n+m-1
      du[i]=(k*(δ(u[n+m+(i-1)]-u[n+m+(i)])^α)-k*(δ(u[n+m+(i)]-u[n+m+(i+1)])^α))/mass[i]
      push!(a[i],du[i])
      #if i==5
      #  push!(a[i],du[i]*2)
      #else
      #  push!(a[i],du[i])
      #end
    end
    for i=n+m+(1):n+m+(n+m)
      du[i]=u[i-(n+m)]
    end
  end

  prob=ODEProblem(f,u₀,tspan)
  sol=solve(prob, dense=true)
  #arrVars=[((t,x)->(t,x),0,6),((t,x)->(t,x+d),0,7),((t,x)->(t,x+2d),0,8)
  #,((t,x)->(t,x+3d),0,9),((t,x)->(t,x+4d),0,10)]
  arrVars=[((t,x)->(t,x),0,11),((t,x)->(t,x+d),0,12),((t,x)->(t,x+2d),0,13)
  ,((t,x)->(t,x+3d),0,14),((t,x)->(t,x+4d),0,15),((t,x)->(t,x+5d),0,16),
  ((t,x)->(t,x+6d),0,17),((t,x)->(t,x+7d),0,18)
  ,((t,x)->(t,x+8d),0,19),((t,x)->(t,x+9d),0,20)]
  #pt=plot(xlabel="t in sec",ylabel="x coordinate",reuse=false)
  #for s ∈ arrVars
  #  plot!(pt,sol.t,t->s[1](t,sol(t)[s[3]])[2],label="ball $(s[3]-(n+m))")
  #end
  pt2=plot(xlabel="t in sec",ylabel="acceleration",reuse=false,xlims=(0.0,3.0))
  for i=1:n+m
    plot!(pt2,ts,a[i],label="$(i)")
  end
  #display(pt)
  display(pt2)
  for i=1:n+m
    println("x[",i,"]:",sol(10)[i+(n+m)]+(i-1)d)
    println("v[",i,"]:",sol(10)[i]/1.0*100.0,"%")
  end
end
Run()
