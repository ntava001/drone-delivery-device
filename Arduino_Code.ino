#include <Stepper.h>

const int trigPin = 6;
const int echoPin = 5;

long duration;
int distance;

const int stepsPerRevolution = 200; // Change this to fit the number steps per revolution for motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup( ) {
    // set the speed at 60rpm:
    myStepper.setSpeed(300);
    // initialize the serial port:
    // put your setup code here, to run once:
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    delay(1000);
    // step three revolution in the ohter direction:
    // put your main code here, to run repeatedly:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    digitalWrite(trigPin, LOW);

    delayMicroseconds(10);
    duration = pulseIn(echoPin, HIGH);
    distance = duration* 0.034/2; 

    Serial.print("Distance: ");
    Serial.println(distance);
    delay(1);


if(distance <=10)
    for (int i =0; i<3; i++) // number of steps the motor takes for one revolution
    
    // step one revolution in one direction:
    // Serial.printIn("clockwise");
    myStepper.step(stepsPerRevolution);
    delay(1); } //Delay in milliseconds for each step in the clockwise direction
    
