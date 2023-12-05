
// Modify Code
// Cotinuity Equation
void Cotinuity_Equation()
{
	bool boundp2;
	if (boundp2)
	{
		arp1+=shepardCorr*(dvx*boundNormal[p2].x*+dvy*boundNormal[p2].y+dvz*boundNormal[p2].z)*wab*area; 
	}
	else
	{
		arp1 += shepardCorr*(USE_FLOATING ? ftmassp2 : massp2) * (dvx * frx + dvy * fry + dvz * frz) * (rhop1 / rhop2);
	}
}

// Pressure Term


void cacl_pressure()
{
	bool boundp2;
	if (boundp2)
	{
		arp1+=shepardCorr*(dvx*boundNormal[p2].x*+dvy*boundNormal[p2].y+dvz*boundNormal[p2].z)*wab*area; 
	}
	else
	{
		const float prs = (pressp1 + pressp2) / (rhop1 * rhop2)
							+ (tker == KERNEL_Cubic ? cufsph::GetKernelCubic_Tensil(rr2, rhop1, pressp1, rhop2, pressp2) : 0);
		const float p_vpm = -prs * (USE_FLOATING ? ftmassp2 : massp2);
		acep1.x += p_vpm * frx; acep1.y += p_vpm * fry; acep1.z += p_vpm * frz;	}
}