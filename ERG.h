#ifndef ERG_H
#define ERG_H

#include "Arduino.h"  // Чтобы работали типы вроде String и функции Arduino

void controlLine(int line);
void autoControl(String state, String inertionState, int step);
void manualControl(float settingData);
int outputERG(float inputData);

#endif
