#include <Stepper.h>
char val;
const int stepsPerRevolution = 2048; // change this to fit the number of steps per revolution

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup()
{
    // set the speed at 10 rpm:
    myStepper.setSpeed(10);
    // initialize the serial port:
    Serial.begin(9600);
}

void loop()
{
    if(Serial.available() > 0) {
        val = Serial.read();
        Serial.println(val, DEC);
    }
    if (val == 'I') {
        myStepper.step(stepsPerRevolution / 12);
        delay(1000);
    }
    if (val == 'O') {
        myStepper.step(-stepsPerRevolution / 12);
        delay(1000);
    }
    val = "X";
}
