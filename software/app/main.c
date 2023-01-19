#include <stdio.h>
#include "system.h"
#include "alt_types.h"
#include "opencores_i2c.h"

#define ADXL345_I2C_ADDRESS 0x1D
#define I2C_CLK_SPEED 100000u
#define DATAX0 0X32 //	X-Axis Data 0 (LSB)
#define DATAX1 0X33 //	X-Axis Data 1 (MSB)
#define DATAY0 0X34 //	Y-Axis Data 0 (LSB)
#define DATAY1 0X35 //	Y-Axis Data 1 (MSB)
#define DATAZ0 0X36 //	Z-Axis Data 0 (LSB)
#define DATAZ1 0X37 //	Z-Axis Data 1 (MSB)

alt_16 x_axis = 0;
alt_16 y_axis = 0;
alt_16 z_axis = 0;
alt_16 x_axis_offset = 0;
alt_16 y_axis_offset = 0;
alt_16 z_axis_offset = 0;
int ack = 1;

alt_u32 I2C_READ_ADXL345(alt_u8 reg);
void I2C_WRITE_ADXL345(alt_u8 reg, alt_u8 data);

int main()
{
	
	printf("Hello world\r\n");
	I2C_init(ADXL345_I2C_ADDRESS, ALT_CPU_CPU_FREQ, I2C_CLK_SPEED);
	// while (1)
	// {
		// x_axis = (alt_16)((I2C_READ_ADXL345(DATAX1) << 8) | I2C_READ_ADXL345(DATAX0));
		// printf("%d\t", x_axis);
		// y_axis = (alt_16)((I2C_READ_ADXL345(DATAY1) << 8) | I2C_READ_ADXL345(DATAY0));
		// printf("%d\t", y_axis);
		// z_axis = (alt_16)((I2C_READ_ADXL345(DATAZ1) << 8) | I2C_READ_ADXL345(DATAZ0));
		// printf("%d\n", z_axis);

		// usleep(1000000);
	// }
}

alt_u32 I2C_READ_ADXL345(alt_u8 reg)
{
	alt_u32 read_byte;

	ack = I2C_start(ADXL345_I2C_ADDRESS, ADXL345_I2C_ADDRESS, 0);
	if (ack == 0)
	{
		I2C_write(OPENCORES_I2C_0_BASE, reg, 0);
	}
	
	ack = I2C_start(ADXL345_I2C_ADDRESS, ADXL345_I2C_ADDRESS, 1);
	if (ack == 0)
	{
		read_byte = I2C_read(OPENCORES_I2C_0_BASE, 1);
	}

	return read_byte;
}

void I2C_WRITE_ADXL345(alt_u8 reg, alt_u8 data)
{
	ack = I2C_start(ADXL345_I2C_ADDRESS, ADXL345_I2C_ADDRESS, 0);
	if (ack == 0)
	{
		I2C_write(OPENCORES_I2C_0_BASE, reg, 0);
		I2C_write(OPENCORES_I2C_0_BASE, data, 1);
	}
}
