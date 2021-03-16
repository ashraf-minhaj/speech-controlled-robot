/**** Arduino Speech/voice Controlled robot ***/

/* Arduino Rolling robot
 *  by Ashraf Minhaj
 *  mail me at ashraf_minhaj@yahoo.com
 *  tutorial- ashrafminhajfb.blogspot.com
 */

//Declare the arduino pins

int lm1 = 4;     //declare 1st motor pins
int lm2 = 5;

int rm1 = 2;    //right motor pins
int rm2 = 3;

char val;

void setup()
{
  //initlize the mode of the pins
   pinMode(lm1,OUTPUT);
   pinMode(lm2,OUTPUT);
   pinMode(rm1,OUTPUT);
   pinMode(rm2,OUTPUT);

   //set the serial communication rate
   Serial.begin(9600);


}

void loop()
{
  //check whether arduino is reciving signal or not 
  while(Serial.available() == 0);
  val = Serial.read() ;           //reads the signal
  //Serial.print(val);

  /*********For Forward motion*********/
  if (val == 'F')
  {
    //Serial.println("FORWARD");
    digitalWrite(lm1,HIGH);  
    digitalWrite(rm1,HIGH);
    digitalWrite(lm2,LOW);       
    digitalWrite(rm2,LOW);
  }

 
   /*********For Backward Motion*********/
  else if(val == 'B')
  {
    digitalWrite(lm2,HIGH);    
    digitalWrite(rm2,HIGH);
    digitalWrite(lm1,LOW);      
    digitalWrite(rm1,LOW);
  }
  
   /*********Right*********/
  else if(val == 'R')
  {
    digitalWrite(lm1,HIGH);  
    digitalWrite(rm2,HIGH);
    digitalWrite(lm2,LOW);       
    digitalWrite(rm1,LOW);
  }
  
   /*********Left*********/
  else if(val == 'L')
  {
    digitalWrite(lm2,HIGH);  
    digitalWrite(rm1,HIGH);
    digitalWrite(lm1,LOW);       
    digitalWrite(rm2,LOW);
  }

  /*********STOP*********/
  else
  {
    digitalWrite(lm1,LOW);  
    digitalWrite(rm1,LOW);
    digitalWrite(lm2,LOW);       
    digitalWrite(rm2,LOW);
  }

 delay(10);
  
}
