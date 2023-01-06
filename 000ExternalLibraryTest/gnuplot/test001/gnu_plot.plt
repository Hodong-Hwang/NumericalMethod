
set terminal gif animate delay 100
set output "foobar.gif"
stats "data.tmp" name "A" noutput
set xrange[A_min_x:A_max_x]
set yrange[A_min_y:A_min_y]
set term wxt
plot "data.tmp" index 0 w lines
set output