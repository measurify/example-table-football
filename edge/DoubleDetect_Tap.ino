#include <SparkFun_ADXL345.h>         

ADXL345 adxl = ADXL345(0x53);             
ADXL345 adxl2 = ADXL345(0x1D);

int interruptPin = 2;  
int interruptPin2 = 3;     
int trigger = 0;
int trigger2 = 0;


void setup(){

  Serial.begin(9600);                 
  Serial.println("Start simulation:");
  Serial.println();
  

  adxl.powerOn();                   
  adxl.setRangeSetting(16);        
  adxl.setTapDetectionOnXYZ(1, 1, 1); 
  adxl.setTapThreshold(230);           
  adxl.setTapDuration(15);  
	adxl.setInterrupt(ADXL345_INT_SINGLE_TAP_BIT, ADXL345_INT1_PIN);  
  adxl.singleTapINT(1);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), ADXL_ISR, RISING); 

  adxl2.powerOn();
  adxl2.setRangeSetting(16);   
  adxl2.setTapDetectionOnXYZ(1, 1, 1);
  adxl2.setTapThreshold(230);         
  adxl2.setTapDuration(15); 
  adxl2.setInterrupt(ADXL345_INT_SINGLE_TAP_BIT, ADXL345_INT1_PIN);   
  adxl2.singleTapINT(1);
  attachInterrupt(digitalPinToInterrupt(interruptPin), ADXL_ISR2, RISING);
  
  //Serial.println(trigger);
  //Serial.println(trigger2);
 
  adxl.getInterruptSource();

  adxl2.getInterruptSource();


  if(adxl.isTapDetectionOnY()){
     Serial.println("tap detection on for sensor one");
  }

  if(adxl2.isTapDetectionOnY()){
     Serial.println("tap detection on for sensor two");
  }

}


void loop(){
  delay(50);
  
  if(trigger)
  { 
    if(adxl.getInterruptSource(ADXL345_INT_SINGLE_TAP_BIT)){
      Serial.println("*** ASTA BLU DIFESA ***");  
    } 
    trigger = 0;
  }
  if(trigger2)
  {
    if(adxl2.getInterruptSource(ADXL345_INT_SINGLE_TAP_BIT)){
     Serial.println("*** ASTA ROSSA ATTACCO ***");
    }
    trigger2 = 0;
  }
}
void ADXL_ISR() {
  trigger = 1;
}

void ADXL_ISR2() {
  trigger2 = 1;
}
