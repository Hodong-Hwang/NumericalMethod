import numpy as np
import matplotlib.pyplot as plt

# Define the problem domain and parameters
Lx = 1.0  # Length of the domain in x direction
Ly = 1.0  # Length of the domain in y direction
nx = 50  # Number of grid cells in x direction
ny = 50  # Number of grid cells in y direction
dx = Lx / nx  # Grid cell size in x direction
dy = Ly / ny  # Grid cell size in y direction
k = 1.0  # Thermal conductivity
rho = 1.0  # Density
c = 1.0  # Specific heat
alpha = k / (rho * c)  # Thermal diffusivity
dt = 0.001  # Time step size
nt = 1000  # Number of time steps
x = np.linspace(dx/2, Lx-dx/2, nx)  # Cell centers in x direction
y = np.linspace(dy/2, Ly-dy/2, ny)  # Cell centers in y direction
X, Y = np.meshgrid(x, y)  # Meshgrid of cell centers

# Define the initial condition
T0 = np.zeros((ny, nx))
T0[ny//4:3*ny//4, nx//4:3*nx//4] = 1.0

# Initialize the solution array
T = T0.copy()

# Apply the finite volume method
for n in range(nt):
    # Calculate the fluxes at the cell boundaries
    Fx = -k * (T[:, 1:] - T[:, :-1]) / dx  # Flux in x direction
    Fy = -k * (T[1:, :] - T[:-1, :]) / dy  # Flux in y direction
    Fx_left = np.concatenate((Fx[:, [-1]], Fx[:, :-1]), axis=1)  # Periodic boundary condition
    Fx_right = np.concatenate((Fx[:, 1:], Fx[:, [0]]), axis=1)  # Periodic boundary condition
    Fy_top = np.concatenate((Fy[[-1], :], Fy[:-1, :]), axis=0)  # Periodic boundary condition
    Fy_bottom = np.concatenate((Fy[1:, :], Fy[[0], :]), axis=0)  # Periodic boundary condition
    
    # Update the solution using the unsteady-state finite volume method
    T += alpha * dt * ((Fx_right - Fx_left) / dx + (Fy_top - Fy_bottom) / dy)
    
# Plot the solution
plt.imshow(T, cmap='jet', origin='lower', extent=[0, Lx, 0, Ly])
plt.colorbar()
plt.xlabel('x')
plt.ylabel('y')
plt.show()