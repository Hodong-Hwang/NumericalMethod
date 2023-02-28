#include <stdio.h>
int main ()
{
    int x=0,y=0;
    FILE *gnupipe =nullptr;
    char* GNuCommands[]={"set output 'test.png'", 
    "set title \"Demo\"",
    "set autoscale xfix",
    "set autoscale yfix",
    "set autoscale cbfix",
    "set pm3d map",
    "splot 'data.dat' matrix"};
    gnupipe = _popen("gnuplot -persistent","w");
    for (int i=0; i<7; i++){
        fprintf(gnupipe,"%s\n",GNuCommands[i]);
    }
    return 0;
}