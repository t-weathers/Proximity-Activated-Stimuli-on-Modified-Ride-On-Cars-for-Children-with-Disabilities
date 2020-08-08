const int sensor_pin = 3; //LW
const int sensor2_pin = 5; //LF
const int sensor3_pin = 6; //RF
const int sensor4_pin = 7; //RW
const int loadPin = 13; 
float sensor1, pulse1, sensor2, pulse2, sensor3, pulse3,sensor4, pulse4;
void setup() {
  Serial.begin(9600);
}

void loop() {
  pulse1 = pulseIn(sensor_pin,HIGH);
  Serial.print("pulse1: ");
  Serial.println(pulse1);
  sensor1 =  pulse1/ 25.4;
  Serial.print("inches: ");
  Serial.println(sensor1);

  Serial.println ();
  
  pulse2 = pulseIn(sensor2_pin,HIGH);
  Serial.print("pulse1: ");
  Serial.println(pulse2);
  sensor2 =  pulse2/ 25.4;
  Serial.print("inches: ");
  Serial.println(sensor2);

  Serial.println ();

  pulse3 = pulseIn(sensor3_pin,HIGH);
  Serial.print("pulse1: ");
  Serial.println(pulse2);
  sensor3 =  pulse3/ 25.4;
  Serial.print("inches: ");
  Serial.println(sensor3);
  
  Serial.println ();
  
  pulse4 = pulseIn(sensor4_pin,HIGH);
  Serial.print("pulse1: ");
  Serial.println(pulse2);
  sensor4 =  pulse4/ 25.4;
  Serial.print("inches: ");
  Serial.println(sensor4);

  Serial.println ();

  if(sensor1 <= 30 && sensor1 != 0){
    Serial.println("sensor LW tripped . :: distance below 30 inches");
    delay(5000);
  }
  else if(sensor1 == 0){
    Serial.println("error: sensor LW reading 0");
    delay(5000);
  }
  else if(sensor2 <= 30 && sensor2 != 0){
    Serial.println("sensor LF tripped . :: distance below 30 inches");
    delay(5000);
  }
  else if(sensor2 == 0){
    Serial.println("error: sensor LF reading 0");
    delay(5000);
  }
  else if(sensor3 <= 30 && sensor3 != 0){
    Serial.println("sensor RF tripped . :: distance below 30 inches");
    delay(5000);
  }
  else if(sensor3 == 0){
    Serial.println("error: sensor RF reading 0");
    delay(5000);
  }
  else if(sensor4 <= 30 && sensor4 != 0){
    Serial.println("sensor RW tripped . :: distance below 30 inches");
    delay(5000);
  }
  else if(sensor4 == 0){
    Serial.println("error: sensor RW reading 0");
    delay(5000);
  }
}

