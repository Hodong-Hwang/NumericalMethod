import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation

    
class FDM1D:
    def __init__(self,xinfo:tuple,node:int,runtime:float):
        """_summary_
        It is Test code for 1D FDM according to MIT course
        Args:
            xinfo (tuple): x0, xend
            node (int): number of nodes
        """
        self.x=np.linspace(xinfo[0],xinfo[1],node+2) # with out init and end
        self.node =node
        self.timestep= 0.001 # default value 
        self.tend = runtime
        self.mu=0.001 #default value 
        self. u = 2.5
    def setInitialCondition(self,U0:np.array):
        self.U0=U0
    
    def make_SimpleCentralDiff(self):
        
        dx=self.x[1]-self.x[0]
        dx2=dx*dx
        mu=self.mu
        u=self.u
        self.A=np.array([0.5*u/dx+mu/(dx2),-2*mu/(dx2),-0.5*u/dx+mu/(dx2)])
 
    def animate(self,i):
        U=self.U
        prevU=self.U
        dt=self.timestep
        xnode =self.node+2
        A=self.A
        self.U[1]=prevU[1]-dt*A[1:3].dot(prevU[1:3])
        for i in range(2,self.node+1):  
            U[i]=prevU[i]+dt*A.dot(prevU[i-1:i+2])                                
        U[xnode-1]=prevU[xnode-1]-dt*A[0:2].dot(prevU[xnode-2:xnode+1])
        self.line.set_data(self.x, self.U)
        self.U=U
        return self.line,
    
    def animationrun(self):
        t=0
        dt=self.timestep
        Tstep = int(self.tend/dt)
        xnode =self.node+2
        self.U=self.U0
        self.make_SimpleCentralDiff()
        A=self.A
        A.reshape(1,3)
        self.fig = plt.figure()
        self.ax = plt.axes(xlim=(0, 1), ylim=(-2,2))
        self.line, = self.ax.plot(self.x, self.U, lw=3)
        self.anim = FuncAnimation(self.fig, self.animate, frames=200, interval=1)
        self.anim.save('FTCS results.gif')


    def run(self):
        t=0
        dt=self.timestep
        Tstep = int(self.tend/dt)
        xnode =self.node+2
        U=np.zeros((Tstep,xnode))
        U[0,:]=self.U0
        self.make_SimpleCentralDiff()
        A=self.A
        A.reshape(1,3)
        curstep = 0 
        prevstep = curstep

        while (t<self.tend):
            # Forward Euler step
            curstep+=1
            U[curstep,1]=U[prevstep,1]-dt*A[1:3].dot(U[prevstep,1:3])
            for i in range(2,self.node+1):  
                U[curstep,i]=U[prevstep,i]-dt*A.dot(U[prevstep,i-1:i+2])                
                
            U[curstep,xnode-1]=U[prevstep,xnode-1]-dt*A[0:2].dot(U[prevstep,xnode-2:xnode+1])
            U[curstep,0]=U[curstep,xnode-1]
            prevstep=curstep
            t+=dt
            




  
def ex01():
    
    fdm1d=FDM1D((0,1),20,2)
    U0=0.75*np.exp(-(np.power((fdm1d.x-0.5)/0.1,2 )))
    fdm1d.setInitialCondition(U0)
    fdm1d.animationrun()
def main():
    ex01()




if __name__ == '__main__':
    main()
