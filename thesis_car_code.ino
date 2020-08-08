#include <Servo.h>
Servo servo;
const int off_position = 0;
const int on_position = 90;

const int snsr1pin = 3;
const int snsr2pin = 5;
const int snsr3pin = 6;
const int snsr4pin = 7;

const int servopin = 10;
const int TARGET_DISTANCE = 60; //this is the distance we want to trip off the sensors in inches
const int MILLISECONDS_ON = 5000;  //time that the bubble gun stays on   TIME IN MILLISECONDS
const int REFRESH_TIME = 10000;   //time delay before sensing begins again  TIME IN MILLISECONDS

long range1,range2,range3,range4,pulse,distance; //this declaration avoids the recreation of variables, saving memory

void setup() {
  servo.attach(servopin);
  if(!initialize_all()){    //if one of the sensors faults initializing
    stop_arduino();         //kill the process before the sensors begin looping
  }
  else{
    Serial.println("ARDUINO TESTED AND BEGINNING SCRIPT");
  }
}

void loop() {
  range1 = collect_range(snsr1pin);
  if(check_in_range(range1, snsr1pin)){
    activate_servo(MILLISECONDS_ON, REFRESH_TIME);
  }
  range2 = collect_range(snsr2pin);
  if(check_in_range(range2, snsr2pin)){
    activate_servo(MILLISECONDS_ON, REFRESH_TIME);
  }
  range3 = collect_range(snsr3pin);
  if(check_in_range(range3, snsr3pin)){
    activate_servo(MILLISECONDS_ON, REFRESH_TIME);
  }
  range4 = collect_range(snsr4pin);
  if(check_in_range(range4, snsr4pin)){
    activate_servo(MILLISECONDS_ON, REFRESH_TIME);
  }
}


//***********************************
//collect_range()
//description:  this function reads in distance by activating the sensor pin argument
//              then converts this number to inches and returns this number
//return:       integer distance in inches
//***********************************
   long collect_range(int sensor_pin){
      pulse = pulseIn(sensor_pin,HIGH);   //collect reading
      Serial.print("pin: ");
      Serial.println(sensor_pin);
      distance =  pulse/ 25.4;            //convert to inches
      Serial.print("inches: ");
      Serial.println(distance);
      Serial.println();
      return distance;
   }
   
   //***********************************
  //check_in_range()
  //description:  checks if the distance is less than the target distance
  //return:       boolean value true if less than global constant target_distance, else returns false
  //***********************************
   bool check_in_range(long distance,int sensor_pin){
      if(distance < TARGET_DISTANCE){
          Serial.print(sensor_pin);
          Serial.println(" within range");
          return true;
      }
      return false;
   }
 
  //***********************************
  //verify_sensor()
  //description:  runs the sensor once initially, and verify's that the reading is not faulting
  //return:       boolean value true if a reading is given, else returns false: error in wiring
  //***********************************
   bool verify_sensor(int sensor_pin){
      Serial.println("INITIAL SENSOR TEST");    //start sensor validation testing
      int test = collect_range(sensor_pin);
      if(test == 0){
        Serial.print("SENSOR FAULT: ");     //error reading, check wire connections for sensor
        Serial.println(sensor_pin);
        return false;
      }
      return true;
   }
   
  //***********************************
  //activate-servo()
  //description:  this will activate the global object servo, with given time and refresh time
  //return:       n/a
  //post: servo activated for given time, then return to off_position
  //***********************************
   void activate_servo(int milliseconds, int refresh_time){
      servo.write(on_position);
      Serial.print("SERVO SET TO ON-POSITION: DISPENSING BUBBLES");
      delay(milliseconds);            //keep the servo in the on position and shooting bubbles for this time
      servo.write(off_position);
      Serial.print("SERVO SET TO OFF-POSITION");
      delay(refresh_time);            //have a delay period before sensing again immediately
   }

  //***********************************
  //stop_arduino()
  //description:  end arduino functionality in endless loop
  //return:       n/a
  //post: arduino is deemed inactive from error
  //***********************************
   void stop_arduino(){
    Serial.println("ARDUINO END LOOP INITIATED");
    while(1);
   }

  //***********************************
  //initialize_all()
  //description:  runs the sensor once initially, and verify's that the reading is not faulting
  //return:       boolean value true if a reading is given, else returns false: error in wiring
  //***********************************
  bool initialize_all(){
      servo.write(off_position);
      Serial.begin(9600);
      if(verify_sensor(snsr1pin) && verify_sensor(snsr2pin) && verify_sensor(snsr3pin) && verify_sensor(snsr4pin)){
        Serial.println("all sensors initialized successfully");
        return true;
      }
     return false;
  }
