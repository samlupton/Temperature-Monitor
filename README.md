# Temperature-Monitor

Temperature moniter with LPC1768 and C++ code

# Temperature Monitor with mbed Microcontroller

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

## Customization

Feel free to customize the code to suit your specific requirements. You can adjust display timings, add additional features, or enhance the user interface.

## Dependencies

- This project relies on the mbed development environment.
- Make sure to refer to the provided textbook sections (6.2 and 6.4) for additional insights.

## Contribution

Contributions are welcome! Feel free to open issues, submit pull requests, or suggest improvements.

## License

This project is licensed under the [MIT License](LICENSE).

---

Feel free to adapt and expand upon this overview based on your specific implementation and any additional information you'd like to include in your README.
