//Liam Jackson
//Lab 4 B
//Serial Input for DC Motor direction control

int bin = 0; //for all data coming in

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available())
{
  char direction = Serial.read();
  
  if (direction == 'W' || direction == 'w')
  {
    // Whatever code makes it go one direction
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    //delay(5000);
  }
  else if (direction == 'S' || direction == 's')
  {
    // Whatever code makes it go the other direction
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    //delay(5000);
  }

  else if (direction == 'X' || direction == 'x')
  {
    // Whatever code makes it go the other direction
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    //delay(5000);
  }
}
}
