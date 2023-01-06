#We will plot sin(x+t) in this gif animation
reset
set term gif animate
set output "animate.gif"
n=24    #n frames
dt=2*pi/n
set xrange [0:4*pi]
i=0
do for [i=0:10:1]{
plot sin(x+i*dt) w l lt 1 lw 1.5 title sprintf("t=%i",i)
}
set output