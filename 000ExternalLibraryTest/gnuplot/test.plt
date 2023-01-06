reset
set term gif animate 20
set output 'test.gif'
stats "temp.dat" name "A"

set xrange[0:1024]
set yrange[-5:5]



 do for[i=0:1000:1] {
    plot "temp.dat" u 1:2 w circles lt 1 lw 1.5
 }
set output