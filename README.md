# Kanaan_Lab3

#A. Introduction

In this lab we use the DE10-Lite's ADXL345 embedded accelerometer to display acceleration on the x, y, and z axis. The accelerometer communication was done through an I2C bus.

#B. System architecture

Here is a basic design of our Qsys design
![image](https://user-images.githubusercontent.com/114091388/213652878-2ad081a4-0730-4b2f-9866-5edc1aec10b1.png)

We also implement the ADXL345's design in our VHDL. We made sure to pull the CS bit and the ALT_ADDRESS to high according to the datasheet in order to enable the I2C mode and to use the default I2C address.

In addtion, We created our own I2C read and I2C write function in the main.c according to the ADXL345's I2C protocol.

Furthermore, we made sure to have our x, and z axis read variable as signed bits of width 16 because acceleration can be negative and the date of each axis is read on two register of 8 bits each. 

#C. Results

Due the lack of time, I was only able to program the basic design in C. The photo below shows data gathered from each axis and printed on the nios2 terminal. However, a calibration is still required to calibrate the offset values of each axis. 

![image](https://user-images.githubusercontent.com/114091388/213659178-69649d45-6536-4a36-b921-ff1a5532d30d.png)

#D. Conclusion

This lab taught us how to read data from the accelerometer and use the I2C protocol to do so. We also learned how to display the gather data in the nios2 terminal.
We were supposed to use the 7-segment display to show the value of the acceleration and use a push button to switch between each axis. However, this was not done due to the lack of time.

Note that in to be able to print in the terminal without overflowing the RAM, the memory should be set to around 100 000 bytes. 
