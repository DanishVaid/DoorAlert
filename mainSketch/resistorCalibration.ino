//Calibration Info for Laser

/*
 * Danish Vaid
 * DoorAlert Project
 * Summer 2016
 */

int cal_laser = 4;

void setup() {
  pinMode(cal_laser, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(cal_laser, HIGH);
  Serial.println(analogRead(0));
}


