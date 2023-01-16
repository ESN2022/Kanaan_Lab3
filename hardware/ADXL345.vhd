library ieee;
use ieee.std_logic_1164.all;

entity ADXL345 is
	port(
		CS_bar				: out 	std_logic;
		SDA					: inout	std_logic;
		ALT_ADDRESS 		: out 	std_logic;
		reset					: in		std_logic;
		SCL					: in 		std_logic;
		);
end entity;



architecture RTL of ADXL345 is

 component lab3_qsys is
        port (
            clk_clk       				: in		std_logic := 'X'; -- clk
            reset_reset_n 				: in		std_logic := 'X'; -- reset_n
			output_i2c_scl_pad_io		: inout	std_logic := 'X'; -- scl_pad_io
            output_i2c_sda_pad_io	: inout	std_logic := 'X'  -- sda_pad_io
        );
 end component lab3_qsys;
	 
begin
u0 : component lab3_qsys
    port map (
		clk_clk						=> SCL,				-- clk.clk
        reset_reset_n			=> reset,	-- reset.reset_n
		output_i2c_scl_pad_io	=> SCL,					-- output_i2c.scl_pad_io
        output_i2c_sda_pad_io => SDA					-- output_i2c.sda_pad_io
    );

	CS_bar		<= '1';
	ALT_ADDRESS <= '1';
end RTL;
