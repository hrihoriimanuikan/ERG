# ERG Library for Arduino

ERG is a lightweight library for controlling a sensor input or line input with automatic or manual gain adjustment.

## Installation

1. Download or clone the repository.
2. Place the `ERG` folder into your Arduino `libraries/` directory.
3. Restart the Arduino IDE.

## Basic Example

```cpp
#include "ERG.h"

void setup() {
    Serial.begin(9600);
    controlLine(500); // Set the desired line value
    manualControl(1.5); // Manually set the gain factor
}

void loop() {
    float sensorValue = analogRead(A0);
    int output = outputERG(sensorValue);

    Serial.println(output);
    delay(100);
}
More examples are available in the examples/ folder.

Available Functions
controlLine(int line) — Sets the desired line value.

autoControl(String state, String inertionState, int step) — Enables automatic gain adjustment.

manualControl(float settingData) — Manually sets the gain value.

outputERG(float inputData) — Calculates the output control signal based on the input data.

Author
Created with ❤️ for Arduino projects.
