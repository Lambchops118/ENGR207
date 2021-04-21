//Liam Jackson
//Lab 3 Part C
//Theramin

int light = 0; //Light value
int SPKR = 8;
void setup() {
    pinMode(3, OUTPUT); //use arduino pin 3
}

void loop() {
    light = analogRead(A1); //reads light value from A1
 
    if(light > 50 && light < 500 ) {
        digitalWrite(3,LOW);
        tone(SPKR, light,  100); //3rd argument sets length for how long note plays
    }
    delay(1000);
}
