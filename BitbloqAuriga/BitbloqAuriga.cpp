#include "Arduino.h"
#include "BitbloqAuriga.h"

//setting Auriga ports values
const Port BitbloqAuriga::ports[11] = {Port(-1,-1),Port(4,5),Port(2,3),Port(6,7),Port(8,9),Port(17,16), Port(A15,A10),Port(A14,A9),Port(A13,A8),Port(A12,A7),Port(A11,A6)};

BitbloqAuriga::BitbloqAuriga():
        powerSensorPin(A4),
        lightSensor1Pin(A3),
        lightSensor2Pin(A2),
        soundSensorPin(A1),
        temperatureSensorPin(A0),
        RGBLedsPin(44),
        buzzerPin(45)
{
}

BitbloqAuriga::~BitbloqAuriga(){	
	//check that all of them are not NULL pointers, delete and set to NULL

}

void BitbloqAuriga::setup(){
    
    pinMode(powerSensorPin,INPUT);
    pinMode(lightSensor1Pin,INPUT);
    pinMode(lightSensor2Pin,INPUT);
    pinMode(soundSensorPin,INPUT);
    pinMode(temperatureSensorPin,INPUT);
    pinMode(buzzerPin,OUTPUT);
    boardLeds.setup(RGBLedsPin,12);
}

int BitbloqAuriga::readPowerStatus() const{
    return analogRead(powerSensorPin);
    //TODO
}

void BitbloqAuriga::setLed(int led, int red, int green, int blue){
	boardLeds.setColor(led, red, green, blue);
	boardLeds.show();
}

void BitbloqAuriga::playTone(int note, int beat){
	tone(buzzerPin, note, beat);
}

int BitbloqAuriga::readTemperature(){
    return analogRead(temperatureSensorPin);
    //TODO
}

int BitbloqAuriga::readSoundLevel() const{
    return analogRead(soundSensorPin);
    //TODO
}
    
int BitbloqAuriga::readLightSensor(int number) const{
    if (number==1)
        return analogRead(lightSensor1Pin);
    if (number==2)
        return analogRead(lightSensor2Pin);
        
    return 0;
}
