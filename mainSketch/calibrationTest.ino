//Calibration Test for Laser

/*
 * Danish Vaid
 * DoorAlert Project
 * Summer 2016
 */


int photoRes = 0; 
int cal_laser = 4;
int ledControl = 13;

void setup() {
  pinMode(cal_laser, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(cal_laser, HIGH);
  Serial.println(analogRead(0));

  if (analogRead(photoRes) < 400){
    digitalWrite(ledControl, HIGH);
  }
  else {
    digitalWrite(ledControl, LOW);
  }
}
