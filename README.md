# ERG Library

The **ERG** library is designed to control a system based on a feedback loop, offering automatic and manual control modes. It allows for fine-grained control of input values with user-defined parameters.

## Features

- **Automatic Control Mode**: Adjusts the gain and feedback values based on predefined parameters.
- **Manual Control Mode**: Allows direct setting of the gain factor.
- **Flexible Parameters**: Set desired input values, control modes, and step sizes.

## Installation

To use the `ERG` library, you need to include it in your Arduino project. You can add it to your project by following these steps:

1. Download the `ERG.h` file from this repository.
2. Place the `ERG.h` file in the `src` folder of your Arduino project.
3. Include the library in your Arduino sketch:
   ```cpp
   #include "ERG.h"
Functions
controlLine(int line)
Sets the desired line (target value) for the feedback system.

Parameters:
line - The desired line value (e.g., 500).

autoControl(String state, String inertionState, int step)
Enables or disables automatic control and sets the inertia mode.

Parameters:

state - Turns the automatic control on ("ON") or off ("OFF").

inertionState - Sets the inertia mode ("ON" or "OFF").

step - Step value for control adjustment.

manualControl(float settingData)
Sets the manual control gain factor.

Parameters:
settingData - The value of the gain factor to apply.

outputERG(float inputData)
Calculates the output based on the input data and control parameters.

Parameters:
inputData - The input value for which the output will be calculated.

Returns:
The calculated output value.

Example
cpp
Копировать
Редактировать
#include "ERG.h"

void setup() {
  Serial.begin(9600);
  
  controlLine(500);  // Set the desired line value

  // Enable automatic control with no inertia mode
  autoControl("ON", "OFF", 100);
}

void loop() {
  float sensorValue = analogRead(A0);  // Read a sensor value
  int output = outputERG(sensorValue); // Get the output based on input

  Serial.println(output); // Output the result
  delay(1000); // Wait for a second
}
License
This library is licensed under the MIT License - see the LICENSE file for details.
