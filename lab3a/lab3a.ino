//Liam Jackson
//Lab 3 Part A
//Dimmable LED Light

const int analogPin = 1;
const int ledPin = 3;
int inputValue = 0;
int outputValue = 0;
void setup()
{
  Serial.begin(9600);
}
void
loop()
{
inputValue = analogRead(analogPin);
Serial.print("Input: ");
Serial.println(inputValue);
outputValue = map(inputValue, 0, 1023, 0,
255);
Serial.print("Output: ");
Serial.println(outputValue);
analogWrite(ledPin, outputValue);
}
