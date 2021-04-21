//Liam Jackson
//Lab 3 Part B
//Night Light

int light = 0; //variable to store current value for light
void setup() {
    pinMode(3, OUTPUT); //Pin 3 is being used
}

void loop() {
    light = analogRead(A1); //read from pin A1
 
    if(light > 450) {
        digitalWrite(3,LOW);
    }
    else if(light > 229 && light < 451) {
       digitalWrite(3, LOW);
    }
    else {
        digitalWrite(3,HIGH); //Turns on LED when certain darkness threshold is met
    }
    delay(1000);
}
