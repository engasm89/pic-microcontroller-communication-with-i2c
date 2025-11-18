/*
 * Course: Pic Microcontroller Communication With I2c
 * Platform: PIC Microcontroller
 * Author: Ashraf S A AlMadhoun
 * Purpose: Auto-generated metadata block to document the learning goals.
 * Notes: Auto-generated metadata block (2025-11-18)
 */

/*
 * Course: Pic Microcontroller Communication With I2c
 * Platform: PIC Microcontroller
 * Author: Ashraf S A AlMadhoun
 * Purpose: Auto-generated metadata block to document the learning goals.
 * Notes: Auto-generated metadata block (2025-11-18)
 */

#include <stdio.h> // Include I/O for I2C logs
#include <unistd.h> // Include POSIX sleep for timing

// Simulated PIC I2C state
static int pic_i2c_on = 0; // Track I2C state

// Initialize PIC I2C master (stub)
int pic_i2c_init(long freq_hz) { // Function to initialize I2C
  (void)freq_hz; // Suppress unused warning
  pic_i2c_on = 1; // Enable I2C
  printf("PIC I2C Master init\n"); // Log init
  return pic_i2c_on; // Return status
} // End pic_i2c_init

// Write register on I2C device (stub)
int pic_i2c_write(unsigned char addr, unsigned char reg, unsigned char val) { // I2C write
  if (!pic_i2c_on) return 0; // Fail if disabled
  printf("PIC I2C WRITE addr=0x%02X reg=0x%02X val=0x%02X\n", addr, reg, val); // Log
  return 1; // Success
} // End pic_i2c_write

// Read register from I2C device (stub)
int pic_i2c_read(unsigned char addr, unsigned char reg, unsigned char *val) { // I2C read
  if (!pic_i2c_on) return 0; // Fail if disabled
  *val = (unsigned char)(reg ^ 0x33); // Simulate value
  printf("PIC I2C READ addr=0x%02X reg=0x%02X val=0x%02X\n", addr, reg, *val); // Log
  return 1; // Success
} // End pic_i2c_read

// Entry demonstrating PIC I2C communication
// Main routine: orchestrates the pic microcontroller communication with i2c scenario
int main(void) { // Begin main
  printf("PIC Microcontroller Communication with I2C\n"); // Title
  pic_i2c_init(100000); // Initialize PIC I2C
  unsigned char value = 0; // Prepare value var
  pic_i2c_write(0x68, 0x10, 0x5A); // Write register
  pic_i2c_read(0x68, 0x10, &value); // Read back
  for (int i = 0; i < 3; ++i) { // Emit frames
    printf("{\"i2c_on\":%d,\"last_val\":0x%02X}\n", pic_i2c_on, value); // Print status
    usleep(300000); // Delay 300 ms
  } // End loop
  return 0; // Exit success
} // End main

