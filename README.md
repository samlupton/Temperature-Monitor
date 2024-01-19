# Temperature Monitor with LPC1768 mbed Microcontroller

## Overview and Demo GIF

This repository contains the code for a simple temperature monitor implemented on the mbed microcontroller board. The program reads data from the MCP9701 temperature sensor and displays the temperature on a 7-segment LED display. The user can switch between Celsius and Fahrenheit modes using pushbutton switches.

<img src="ezgif.com-optimize.gif" width=600><br>

## Features

- **Temperature Sensing:** Utilizes the MCP9701 temperature sensor to measure ambient temperature.
- **LED Display:** Displays the temperature on a 7-segment LED display with controlled digit intervals.
- **Mode Switching:** Users can switch between Celsius and Fahrenheit modes using dedicated pushbutton switches.
- **Stability:** Implements mean average voltage calculation over 1000 samples for stable temperature readings.
- **Interrupt Handling:** Uses InterruptIn to handle mode switches, allowing users to change modes at any time.

## How to Use

1. **Hardware Setup:**
   - Connect the MCP9701 temperature sensor and pushbutton switches to the specified mbed pins.
   - Ensure proper connections and resistor placement for the 7-segment LED display.

2. **Compilation:**
   - Compile the "main.cpp" file using the mbed development environment.

3. **Upload to mbed Board:**
   - Upload the compiled binary to the mbed microcontroller board.

4. **Operation:**
   - Power on the system.
   - Use the pushbutton switches to toggle between Celsius and Fahrenheit modes.
   - The LED display will show the current temperature in the selected unit.
