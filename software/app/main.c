#include <stdio.h>
#include "system.h"
#include "opencores_i2c.h"
#include "sys/alt_stdio.h"

#define ALT_ADDRESS 0x1D
#define I2C_CLK_SPEED 100000


alt_16	x_axis	= 0;
alt_16	y_axis	= 0;
alt_16	z_axis	= 0;
alt_u16 data	= 0;

// start -> read value -> set axis
void read_axis_values()
{
	I2C_start(OPENCORES_I2C_0_BASE, ALT_ADDRESS, 0);
	I2C_write(OPENCORES_I2C_0_BASE, 0x33, 0);
	
	data = I2C_read(OPENCORES_I2C_0_BASE, 1);
		
}

void display_axis()
{
	
	printf("x=%d\ty=%d\tz=%d\r\n", x_axis, y_axis, z_axis);
}

int main()
{
	I2C_init(OPENCORES_I2C_0_BASE, ALT_CPU_FREQ, I2C_CLK_SPEED);
	if( I2C_start(OPENCORES_I2C_0_BASE, ALT_ADDRESS, 0) == 0 )
	{
		printf("I2C success\r\n");

	}
	else
	{
		printf("I2C failure\r\n");
	}
		data = I2C_read(OPENCORES_I2C_0_BASE, 1);
	 I2C_write(OPENCORES_I2C_0_BASE, ALT_ADDRESS, 1);
	 alt_printf();
	while(1){
		display_axis();
	}
}
	