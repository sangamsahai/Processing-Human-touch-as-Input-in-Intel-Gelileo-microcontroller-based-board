#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

char inData[80]; //This will hold the user input through touch
int inDataIndex=0;// This will have the next available position in the array

char outData[80]; //This will hold the user output
int outDataIndex=0;// This will have the next available position in the array



// Defines the pins to which the button is connected.
const int pinButton = 3;


void setup() {
  
  // Configure the button's pin for input signals.
    pinMode(pinButton, INPUT);
  
  // put your setup code here, to run once:
  Serial.begin(9600); //9600 bits of data per second being transfered
  
  // set up the LCD's number of columns and rows:
    lcd.begin(16, 2); 
     //Print a message to the LCD.
    lcd.print("Morse Code App !"); 


}


void loop() {

    Serial.println("");
  Serial.println("");
Serial.println("Do you want to enter a new letter ? If yes, then enter the number of morse characters it has");
  Serial.println("");

while(Serial.available()==0){}// busy wait for the user to input

char charLength;
 while(Serial.available() > 0)//while the user is entering the string
 {
   charLength = Serial.read(); 
   inData[0]='\0';
   inDataIndex=0;
 }
  int intLength=charLength-'0';//converting char to string
  //Serial.println("Value of charLength is ");
    //Serial.println(intLength);

 Serial.println("");
Serial.println("Start entering the touch input !!");
  Serial.println("");


  
  for(int i=0;i<intLength;i++)
  {
  
    //Serial.println("");
    //Serial.println("in loop");
  while(!digitalRead(pinButton))//busy waiting when no touch
  {
    //Serial.println("busy waiting when no touch");
  }
    
byte touch=0;   // 0 means no touch and 1 means touch

  
   if(digitalRead(pinButton))  //means when touch is there
    {
           // Serial.println("");
      //Serial.println("A touch cycle  starts");
      time_t seconds_initial;
      seconds_initial = time(NULL);
//       Serial.println("Initial Time is");
  //      Serial.println(seconds_initial);
      time_t seconds_final;
      
        // When the button is pressed
        //Serial.println("There is touch");
        touch=1;
        
        while(touch==1)  //While the user is maintaining the touch
        {

          if(!digitalRead(pinButton)) //when user removes touch
          {
        //    Serial.println("I sensed no touch");
            touch=0;
            seconds_final = time(NULL);
       //Serial.println("Final difference is");

        int difference=seconds_final-seconds_initial;
        //Serial.println(difference);
        if(difference <=2)   //less than equal to 2 seconds
        {
          //Serial.println("setting . on basis of  no touch");
          inData[inDataIndex]='.';
                    inData[inDataIndex+1]='\0';
          inDataIndex=inDataIndex+1;          
        }
        else
        {
          //Serial.println("setting - on basis of  touch");
          inData[inDataIndex]='-';
                    inData[inDataIndex+1]='\0';
          inDataIndex=inDataIndex+1;          
        
        }
        
          }//end of if - when user removes touch loop
          
          
        }//end of while - This is end of one touch cycle
        
        
        //Serial.println("Value of this touch counter is ");
          //      Serial.println(seconds_final-seconds_initial);

       Serial.println("");
        Serial.println("Input elements Array so far is ");                
        Serial.println("");

    for(int k=0;k<inDataIndex;k++)
    {
      
      Serial.print(inData[k]);
    }
            Serial.println("");
    
    
    
     }//end of if
    
    }//end of for loop
  
    
    //conditions start
    
    //CONVERSION TABLE STARTS
      
        //CONVERSION TABLE STARTS
         //case for a
         if(strcmp(inData,".-")==0)
         {

          outData[outDataIndex]='a';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
      
         }
         //case for b
         if(strcmp(inData,"-...")==0)
         {

           outData[outDataIndex]='b';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
     
         }
         //case for c
         if(strcmp(inData,"-.-.")==0)
         {

            outData[outDataIndex]='c';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
     
         }
         //case for d
         if(strcmp(inData,"-..")==0)
         {

         outData[outDataIndex]='d';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for e
         if(strcmp(inData,".")==0)
         {

                   outData[outDataIndex]='e';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
          }
         //case for f
         if(strcmp(inData,"..-.")==0)
         {

           outData[outDataIndex]='f';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for g
         if(strcmp(inData,"--.")==0)
         {
         outData[outDataIndex]='g';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
         }
    
        //case for h
         if(strcmp(inData,"....")==0)
         {
           outData[outDataIndex]='h';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
        //case for i
         if(strcmp(inData,"..")==0)
         {
            outData[outDataIndex]='i';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
        //case for j
         if(strcmp(inData,".---")==0)
         {
            outData[outDataIndex]='j';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
        //case for k
         if(strcmp(inData,"-.-")==0)
         {
            outData[outDataIndex]='k';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
        //case for l
         if(strcmp(inData,".-..")==0)
         {
           outData[outDataIndex]='l';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
        //case for m
         if(strcmp(inData,"--")==0)
         {
           outData[outDataIndex]='m';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for n
         if(strcmp(inData,"-.")==0)
         {
           outData[outDataIndex]='n';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for o
         if(strcmp(inData,"---")==0)
         {
           outData[outDataIndex]='o';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for p
         if(strcmp(inData,".--.")==0)
         {
            outData[outDataIndex]='p';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for q
         if(strcmp(inData,"--.-")==0)
         {
           outData[outDataIndex]='q';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for r
         if(strcmp(inData,".-.")==0)
         {
            outData[outDataIndex]='r';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for s
         if(strcmp(inData,"...")==0)
         {
            outData[outDataIndex]='s';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for t
         if(strcmp(inData,"-")==0)
         {
           outData[outDataIndex]='t';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for u
         if(strcmp(inData,"..-")==0)
         {
            outData[outDataIndex]='u';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for v
         if(strcmp(inData,"...-")==0)
         {
           outData[outDataIndex]='v';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for w
         if(strcmp(inData,".--")==0)
         {
           outData[outDataIndex]='w';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
        //case for x
         if(strcmp(inData,"-..-")==0)
         {
            outData[outDataIndex]='x';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for y
         if(strcmp(inData,"-.--")==0)
         {
            outData[outDataIndex]='y';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for z
         if(strcmp(inData,"--..")==0)
         {
           outData[outDataIndex]='z';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for 0
         if(strcmp(inData,"-----")==0)
         {
           outData[outDataIndex]='0';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for 1
         if(strcmp(inData,".----")==0)
         {
           outData[outDataIndex]='1';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for 2
         if(strcmp(inData,"..---")==0)
         {
            outData[outDataIndex]='2';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for 3
         if(strcmp(inData,"...--")==0)
         {
           outData[outDataIndex]='3';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for 4
         if(strcmp(inData,"....-")==0)
         {
            outData[outDataIndex]='4';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for 5
         if(strcmp(inData,".....")==0)
         {
           outData[outDataIndex]='5';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for 6
         if(strcmp(inData,"-....")==0)
         {
           outData[outDataIndex]='6';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for 7
         if(strcmp(inData,"--...")==0)
         {
           outData[outDataIndex]='7';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for 8
         if(strcmp(inData,"---..")==0)
         {
           outData[outDataIndex]='8';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
         //case for 9
         if(strcmp(inData,"----.")==0)
         {
            outData[outDataIndex]='9';
                    outData[outDataIndex+1]='\0';
          outDataIndex=outDataIndex+1;
       
    
         }
        
         
         //CONVERSION TABLE ENDS
         
         
    //conditions ends
    
    lcd.noDisplay();
      lcd.display();
      lcd.clear();  //clearing the old display on the table

    
    
       Serial.println("");
        Serial.println("Out Array so far is ");                
                for(int k=0;k<outDataIndex;k++)
    {
      
      Serial.print(outData[k]);
            lcd.print(outData[k]);
           
    }
          Serial.print("");
      //Serial.print("and the length of out data is ");
        //          Serial.print(outDataIndex);  
        
 
}//end of loop() function








