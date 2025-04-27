#include "ERG.h"

float desiredLine = 500;    // Желаемая линия
float input = 0;            // Значение с пина
float difference = 0;       // Разница
float result = 0;
float gain = 1.0;           // Управляющий сигнал
int automode = 0;
int var = 0;
int var1 = 0;
int var2 = 0;
int automodevar = 1;
int inertionmode = 0;

void controlLine(int line) {
    desiredLine = line;
}

void autoControl(String state, String inertionState, int step) {
    var2 = step;

    if (state == "ON") {
        automode = 1;
        if (inertionState == "ON") {
            inertionmode = 1;
        } else if (inertionState == "OFF") {
            inertionmode = 0;
        }
    } else if (state == "OFF") {
        automode = 0;
        inertionmode = 0;
    }
}

void manualControl(float settingData) {
    gain = settingData;
}

int outputERG(float inputData) {
    input = inputData;

    switch (automodevar) {
    case 1:
        var = input;
        break;

    case 2:
        var1 = input;
        if (automode == 1) {
            if (inertionmode == 0) {
                if ((var1 - var) != 0) {
                    gain = (float)var2 / (var1 - var);
                }
            } else if (inertionmode == 1) {
                if ((var1 - var) != 0) {
                    gain = (float)var2 / (var1 - var) / 10.0;
                }
            }
        }
        break;
    }

    if (input <= desiredLine) {
        difference = ((desiredLine - input) * gain) + var2;
        result += difference;
    } else {
        difference = ((input - desiredLine) * gain) + var2;
        result -= difference;
    }

    return (int)result;
}
