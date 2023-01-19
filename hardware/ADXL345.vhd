library ieee;
use ieee.std_logic_1164.all;

entity ADXL345 is
	port(
		CLOCK				:	in		std_logic;
		RESET				:	in		std_logic;
		GSENSOR_SDI		:	inout	std_logic;
		GSENSOR_SDO		:	out	std_logic;
		GSENSOR_CS_N	:	out	std_logic;
		GSENSOR_SCLK	:	inout	std_logic
		);
end entity;

architecture RTL of ADXL345 is
		component lab3_qsys is
			port (
					clk_clk                             : in    std_logic := 'X'; -- clk
					reset_reset_n                       : in    std_logic := 'X'; -- reset_n
					opencores_i2c_0_export_0_scl_pad_io : inout std_logic := 'X'; -- scl_pad_io
					opencores_i2c_0_export_0_sda_pad_io : inout std_logic := 'X'  -- sda_pad_io
			);
		end component lab3_qsys;
		
	begin
		GSENSOR_CS_N	<= '1';
		GSENSOR_SDO		<= '1';
		u0 : component lab3_qsys
			port map (
					clk_clk                             =>	CLOCK			,	-- clk.clk
					reset_reset_n                       => RESET			,  -- reset.reset_n
					opencores_i2c_0_export_0_scl_pad_io => GSENSOR_SCLK,	-- opencores_i2c_0_export_0.scl_pad_io
					opencores_i2c_0_export_0_sda_pad_io => GSENSOR_SDI		--                         .sda_pad_io
			);
end RTL;
