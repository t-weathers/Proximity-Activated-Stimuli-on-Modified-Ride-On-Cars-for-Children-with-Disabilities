const int sensor_pin = 3;
const int loadPin = 13; 
float sensor1, pulse1;
void setup() {
  Serial.begin(9600);
}

void loop() {
  pulse1 = pulseIn(sensor_pin,HIGH);
  sensor1 =  pulse1/ 25.4; //convert to inches
  Serial.print("inches: ");
  Serial.println(sensor1);

  if(sensor1 <= 60 && sensor1 != 0){
    Serial.println("sensor tripped . :: distance below 60 inches");
    Serial.print("Sensor reading: ");
    Serial.println(sensor1);
    delay(5000);
  }
  else if(sensor1 == 0){
    Serial.println("error: sensor reading 0");
    delay(5000);
  }
  else{
    delay(1000);
  }
}

