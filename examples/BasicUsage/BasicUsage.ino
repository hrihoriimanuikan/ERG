#include "ERG.h"

void setup() {
    Serial.begin(9600);
    controlLine(500); // Установить целевую линию 500
}

void loop() {
    float sensorValue = analogRead(A0); // Читаем сенсор
    int controlSignal = outputERG(sensorValue); // Выход управления

    Serial.print("Sensor: ");
    Serial.print(sensorValue);
    Serial.print(" | Control: ");
    Serial.println(controlSignal);

    delay(100);
}
