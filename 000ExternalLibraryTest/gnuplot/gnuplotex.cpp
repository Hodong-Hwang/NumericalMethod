#include <stdio.h>
int main ()
{
    int x=0,y=0;
    FILE *fp=nullptr;
    fp=fopen("data.tmp","w");
    FILE *gnupipe =nullptr;
    char* GNuCommands[]={"set output 'test.gif'","set title \"Demo\"","plot 'data.tmp'"};
    gnupipe = _popen("gnuplot -persistent","w");
    for (int i=0; i<11;i++){
        fprintf(fp,"%d %d\n",x,y);
        x=x+1;
        y=y+1;
    }
    for (int i=0; i<2; i++){
        fprintf(gnupipe,"%s\n",GNuCommands[i]);
    }
    return 0;
}