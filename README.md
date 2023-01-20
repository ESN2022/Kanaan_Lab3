# Kanaan_Lab3

#A. Introduction
In this lab we use the DE10-Lite's ADXL345 embedded accelerometer to display acceleration on the x, y, and z axis. The acceleormeter communication was done through an I2C bus.

#B. System architecture
Here is a basic design of our Qsys design
![image](https://user-images.githubusercontent.com/114091388/213652878-2ad081a4-0730-4b2f-9866-5edc1aec10b1.png)

We also implement the ADXL345's design in our VHDL. We made sure to pull the CS bit and the ALT_ADDRESS to high according to the datasheet in order to enable the I2C mode and to use the default I2C address.

We also created our own I2C read and I2C write function in the main.c according to the ADXL345's I2C protocol.

#C. Results
Due the lack of time, I was only able to program the basic design in C. The photo below shows data gathered from each axis and printed on the nios2 terminal. However, a calibration is still required to calibrate the offset values of each axis. 

![image](https://user-images.githubusercontent.com/114091388/213657386-d533d2f3-0e63-4663-b005-2ed561e2201c.png)

#D. Conclusion
This lab taught us how to read data from the accelerometer and use the I2C protocol to do so. We also learned how to display the gather data in the nios2 terminal.
We were supposed to use the 7 segment display to show the value of the acceleration and use a button to switch between each axis. However, this wqs not done due to the lack of time.
