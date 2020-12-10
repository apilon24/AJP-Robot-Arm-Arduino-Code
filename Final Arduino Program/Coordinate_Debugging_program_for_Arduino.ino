#include <Servo.h>
const int magnetPin = 13;
const byte buffSize = 40;
unsigned int inputBuffer[buffSize];
const char startMarker = '<';
const char endMarker = '>';
byte bytesRecvd = 0;
boolean readInProgress = false;
boolean newDataFromPC = false;
byte robotZone[2];
//Create the Variables that are coming in from Emgu
int incomingZone;
char incomingShape;
//Assign the starting position for the Robot
int baseServoPos = 60;
int shoulderServoPos = 0;
int elbowServoPos = 0;
int wristServoPos = 140;
//Assign Servo names
Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo wristServo;
void setup() {
// put your setup code here, to run once:

pinMode(magnetPin, OUTPUT); // set LED pin mode
Serial.begin(115200); // set serial baud rate
//Assign servo ports
baseServo.attach(9);
shoulderServo.attach(10);
elbowServo.attach(3);
wristServo.attach(5);
//Send robot arm to the starting position
baseServo.write(60);
shoulderServo.write(0);
elbowServo.write(0);
wristServo.write(140);



}
void loop() 
{
// put your main code here, to run repeatedly:

getDataFromPC();//Get the Array from the Emgu
if(newDataFromPC)
  {
    sendSuspendCmd();
    
    delay(1000);
    MotorMove();
    sendEnableCmd();
    newDataFromPC = false;
  }
}
void sendSuspendCmd()
  {
    // send the suspend-true command
    Serial.println("<S1>");
  }
void sendEnableCmd()
  {
    // send the suspend-false command
    Serial.println("<S0>");
  }



void getDataFromPC() 
  {
    // receive data from PC and save it into inputBuffer
    if(Serial.available() > 0) 
      {
        int x = Serial.read();
        // the order of these IF clauses is significant
        if (x == endMarker) {
        readInProgress = false;
        newDataFromPC = true;
        inputBuffer[bytesRecvd] = 0;
        //assign the variables
        robotZone[0] = inputBuffer[0];
        robotZone[1] = inputBuffer[1];
      }
   if(readInProgress) 
      {
        inputBuffer[bytesRecvd] = x;
        bytesRecvd ++;
        if (bytesRecvd == buffSize) 
          {
            bytesRecvd = buffSize - 1;
          }
      }
   if (x == startMarker) 
      {
        bytesRecvd = 0;
        readInProgress = true;
      }
    }
  }
void MotorMove()
{
//assign the variabes to better names
  incomingZone = inputBuffer[0];
  incomingShape = inputBuffer[1];
    
    //Read the Zone number and assign the Servo positions to the corresponding Zone.
   switch(incomingZone)
   {
    case 1:
      baseServoPos = 75;
      shoulderServoPos = 91;
      elbowServoPos = 56;
      wristServoPos = 130;
      break;
    case 2:
      baseServoPos = 74;
      shoulderServoPos = 88;
      elbowServoPos = 50;
      wristServoPos = 130;
      break;
    case 3:
      baseServoPos = 73;
      shoulderServoPos = 86;
      elbowServoPos = 46;
      wristServoPos = 124;
      break;  
    case 4:
      baseServoPos = 72;
      shoulderServoPos = 83;
      elbowServoPos = 41;
      wristServoPos = 120;
      break;
    case 5:
      baseServoPos = 72;
      shoulderServoPos = 81;
      elbowServoPos = 37;
      wristServoPos = 115;
      break;
    case 6:
      baseServoPos = 70;
      shoulderServoPos = 78;
      elbowServoPos = 32;
      wristServoPos = 110;
      break; 
    case 7:
      baseServoPos = 68;
      shoulderServoPos = 76;
      elbowServoPos = 28;
      wristServoPos = 105;
      break; 
    case 8:
      baseServoPos = 67;
      shoulderServoPos = 74;
      elbowServoPos = 24;
      wristServoPos = 103;
      break;  
    case 9:
      baseServoPos = 66;
      shoulderServoPos = 73;
      elbowServoPos = 21;
      wristServoPos = 103;
      break;   
    case 10:
      baseServoPos = 66;
      shoulderServoPos = 72;
      elbowServoPos = 17;
      wristServoPos = 98;
      break; 
    case 11:
      baseServoPos = 62;
      shoulderServoPos = 70;
      elbowServoPos = 13;
      wristServoPos = 98;
      break;            
    case 12:
      baseServoPos = 78;
      shoulderServoPos = 89;
      elbowServoPos = 52;
      wristServoPos = 123;
      break;     
    case 13:
      baseServoPos = 78;
      shoulderServoPos = 87;
      elbowServoPos = 47;
      wristServoPos = 119;
      break;   
    case 14:
      baseServoPos = 76;
      shoulderServoPos = 84;
      elbowServoPos = 44;
      wristServoPos = 115;
      break;       
    case 15:
      baseServoPos = 75;
      shoulderServoPos = 81;
      elbowServoPos = 38;
      wristServoPos = 112;
      break; 
    case 16:
      baseServoPos = 75;
      shoulderServoPos = 79;
      elbowServoPos = 34;
      wristServoPos = 111;
      break;
    case 17:
      baseServoPos = 74;
      shoulderServoPos = 78;
      elbowServoPos = 30;
      wristServoPos = 109;
      break;
    case 18:
      baseServoPos = 73;
      shoulderServoPos = 75;
      elbowServoPos = 26;
      wristServoPos = 103;
      break;
    case 19:
      baseServoPos = 71;
      shoulderServoPos = 74;
      elbowServoPos = 23;
      wristServoPos = 105;
      break;
    case 20:
      baseServoPos = 70;
      shoulderServoPos = 73;
      elbowServoPos = 20;
      wristServoPos = 102;
      break;
    case 21:
      baseServoPos = 69;
      shoulderServoPos = 71;
      elbowServoPos = 18;
      wristServoPos = 100;
      break;
    case 22:
      baseServoPos = 68;
      shoulderServoPos = 70;
      elbowServoPos = 12;
      wristServoPos = 98;
      break;
    case 23:
      baseServoPos = 81;
      shoulderServoPos = 90;
      elbowServoPos = 51;
      wristServoPos = 125;
      break;
    case 24:
      baseServoPos = 80;
      shoulderServoPos = 86;
      elbowServoPos = 46;
      wristServoPos = 121;
      break;
    case 25:
      baseServoPos = 80;
      shoulderServoPos = 83;
      elbowServoPos = 42;
      wristServoPos = 119;
      break;
    case 26:
      baseServoPos = 79;
      shoulderServoPos = 81;
      elbowServoPos = 38;
      wristServoPos = 114;
      break;
    case 27:
      baseServoPos = 78;
      shoulderServoPos = 79;
      elbowServoPos = 33;
      wristServoPos = 111;
      break;
    case 28:
      baseServoPos = 77;
      shoulderServoPos = 77;
      elbowServoPos = 29;
      wristServoPos = 108;
      break;
    case 29:
      baseServoPos = 76;
      shoulderServoPos = 75;
      elbowServoPos = 25;
      wristServoPos = 105;
      break;
    case 30:
      baseServoPos = 75;
      shoulderServoPos = 73;
      elbowServoPos = 21;
      wristServoPos = 101;
      break;
    case 31:
      baseServoPos = 74;
      shoulderServoPos = 71;
      elbowServoPos = 18;
      wristServoPos = 98;
      break;
    case 32:
      baseServoPos = 72;
      shoulderServoPos = 69;
      elbowServoPos = 14;
      wristServoPos = 96;
      break;
    case 33:
      baseServoPos = 70;
      shoulderServoPos = 68;
      elbowServoPos = 10;
      wristServoPos = 99;
      break;
    case 34:
      baseServoPos = 84;
      shoulderServoPos = 87;
      elbowServoPos = 49;
      wristServoPos = 124;
      break;
    case 35:
      baseServoPos = 83;
      shoulderServoPos = 85;
      elbowServoPos = 46;
      wristServoPos = 124;
      break;
    case 36:
      baseServoPos = 83;
      shoulderServoPos = 82;
      elbowServoPos = 40;
      wristServoPos = 113;
      break;
    case 37:
      baseServoPos = 82;
      shoulderServoPos = 80;
      elbowServoPos = 36;
      wristServoPos = 111;
      break;
    case 38:
      baseServoPos = 81;
      shoulderServoPos = 78;
      elbowServoPos = 32;
      wristServoPos = 109;
      break;
    case 39:
      baseServoPos = 81;
      shoulderServoPos = 77;
      elbowServoPos = 28;
      wristServoPos = 106;
      break;
    case 40:
      baseServoPos = 80;
      shoulderServoPos = 75;
      elbowServoPos = 24;
      wristServoPos = 103;
      break;
    case 41:
      baseServoPos = 79;
      shoulderServoPos = 73;
      elbowServoPos = 21;
      wristServoPos = 101;
      break;
    case 42:
      baseServoPos = 78;
      shoulderServoPos = 71;
      elbowServoPos = 17;
      wristServoPos = 100;
      break;
    case 43:
      baseServoPos = 77;
      shoulderServoPos = 69;
      elbowServoPos = 12;
      wristServoPos = 95;
      break;
    case 44:
      baseServoPos = 76;
      shoulderServoPos = 68;
      elbowServoPos = 10;
      wristServoPos = 99;
      break;
    case 45:
      baseServoPos = 86;
      shoulderServoPos = 87;
      elbowServoPos = 49;
      wristServoPos = 122;
      break;
    case 46:
      baseServoPos = 86;
      shoulderServoPos = 84;
      elbowServoPos = 44;
      wristServoPos = 117;
      break;
    case 47:
      baseServoPos = 85;
      shoulderServoPos = 81;
      elbowServoPos = 39;
      wristServoPos = 113;
      break;
    case 48:
      baseServoPos = 85;
      shoulderServoPos = 79;
      elbowServoPos = 36;
      wristServoPos = 110;
      break;
    case 49:
      baseServoPos = 84;
      shoulderServoPos = 78;
      elbowServoPos = 31;
      wristServoPos = 108;
      break;
    case 50:
      baseServoPos = 84;
      shoulderServoPos = 76;
      elbowServoPos = 27;
      wristServoPos = 106;
      break;
    case 51:
      baseServoPos = 83;
      shoulderServoPos = 74;
      elbowServoPos = 23;
      wristServoPos = 103;
      break;
    case 52:
      baseServoPos = 82;
      shoulderServoPos = 72;
      elbowServoPos = 20;
      wristServoPos = 82;
      break;
    case 53:
      baseServoPos = 81;
      shoulderServoPos = 70;
      elbowServoPos = 16;
      wristServoPos = 97;
      break;
    case 54:
      baseServoPos = 81;
      shoulderServoPos = 69;
      elbowServoPos = 12;
      wristServoPos = 95;
      break;
    case 55:
      baseServoPos = 79;
      shoulderServoPos = 66;
      elbowServoPos = 9;
      wristServoPos = 99;
      break;
    case 56:
      baseServoPos = 89;
      shoulderServoPos = 87;
      elbowServoPos = 49;
      wristServoPos = 125;
      break;
    case 57:
      baseServoPos = 89;
      shoulderServoPos = 84;
      elbowServoPos = 44;
      wristServoPos = 120;
      break;
    case 58:
      baseServoPos = 89;
      shoulderServoPos = 81;
      elbowServoPos = 39;
      wristServoPos = 115;
      break;
    case 59:
      baseServoPos = 88;
      shoulderServoPos = 79;
      elbowServoPos = 35;
      wristServoPos = 112;
      break;
    case 60:
      baseServoPos = 88;
      shoulderServoPos = 78;
      elbowServoPos = 31;
      wristServoPos = 110;
      break;
    case 61:
      baseServoPos = 88;
      shoulderServoPos = 75;
      elbowServoPos = 29;
      wristServoPos = 107;
      break;
    case 62:
      baseServoPos = 87;
      shoulderServoPos = 73;
      elbowServoPos = 23;
      wristServoPos = 104;
      break;
    case 63:
      baseServoPos = 87;
      shoulderServoPos = 72;
      elbowServoPos = 20;
      wristServoPos = 102;
      break;
    case 64:
      baseServoPos = 87;
      shoulderServoPos = 70;
      elbowServoPos = 16;
      wristServoPos = 99;
      break;
    case 65:
      baseServoPos = 86;
      shoulderServoPos = 68;
      elbowServoPos = 12;
      wristServoPos = 98;
      break;
    case 66:
      baseServoPos = 86;
      shoulderServoPos = 66;
      elbowServoPos = 9;
      wristServoPos = 99;
      break;
    case 67:
      baseServoPos = 91;
      shoulderServoPos = 86;
      elbowServoPos = 48;
      wristServoPos = 118;
      break;
    case 68:
      baseServoPos = 91;
      shoulderServoPos = 84;
      elbowServoPos = 44;
      wristServoPos = 118;
      break;
    case 69:
      baseServoPos = 91;
      shoulderServoPos = 82;
      elbowServoPos = 40;
      wristServoPos = 118;
      break;
    case 70:
      baseServoPos = 90;
      shoulderServoPos = 80;
      elbowServoPos = 36;
      wristServoPos = 118;
      break;
    case 71:
      baseServoPos = 90;
      shoulderServoPos = 77;
      elbowServoPos = 31;
      wristServoPos = 111;
      break;
    case 72:
      baseServoPos = 90;
      shoulderServoPos = 75;
      elbowServoPos = 27;
      wristServoPos = 108;
      break;
    case 73:
      baseServoPos = 90;
      shoulderServoPos = 73;
      elbowServoPos = 23;
      wristServoPos = 104;
      break;
    case 74:
      baseServoPos = 90;
      shoulderServoPos = 71;
      elbowServoPos = 19;
      wristServoPos = 99;
      break;
    case 75:
      baseServoPos = 90;
      shoulderServoPos = 69;
      elbowServoPos = 15;
      wristServoPos = 96;
      break;
    case 76:
      baseServoPos = 90;
      shoulderServoPos = 68;
      elbowServoPos = 11;
      wristServoPos = 94;
      break;
    case 77:
      baseServoPos = 90;
      shoulderServoPos = 66;
      elbowServoPos = 8;
      wristServoPos = 97;
      break;
    case 78:
      baseServoPos = 94;
      shoulderServoPos = 87;
      elbowServoPos = 49;
      wristServoPos = 125;
      break;
    case 79:
      baseServoPos = 95;
      shoulderServoPos = 84;
      elbowServoPos = 44;
      wristServoPos = 120;
      break;
    case 80:
      baseServoPos = 94;
      shoulderServoPos = 81;
      elbowServoPos = 39;
      wristServoPos = 115;
      break;
    case 81:
      baseServoPos = 93;
      shoulderServoPos = 79;
      elbowServoPos = 35;
      wristServoPos = 112;
      break;
    case 82:
      baseServoPos = 94;
      shoulderServoPos = 77;
      elbowServoPos = 31;
      wristServoPos = 111;
      break;
    case 83:
      baseServoPos = 94;
      shoulderServoPos = 75;
      elbowServoPos = 27;
      wristServoPos = 109;
      break;
    case 84:
      baseServoPos = 94;
      shoulderServoPos = 73;
      elbowServoPos = 23;
      wristServoPos = 105;
      break;
    case 85:
      baseServoPos = 94;
      shoulderServoPos = 71;
      elbowServoPos = 19;
      wristServoPos = 103;
      break;
    case 86:
      baseServoPos = 94;
      shoulderServoPos = 69;
      elbowServoPos = 15;
      wristServoPos = 99;
      break;
    case 87:
      baseServoPos = 95;
      shoulderServoPos = 67;
      elbowServoPos = 11;
      wristServoPos = 97;
      break;
    case 88:
      baseServoPos = 95;
      shoulderServoPos = 65;
      elbowServoPos = 7;
      wristServoPos = 96;
      break;
    case 89:
      baseServoPos = 96;
      shoulderServoPos = 87;
      elbowServoPos = 50;
      wristServoPos = 127;
      break;
    case 90:
      baseServoPos = 97;
      shoulderServoPos = 85;
      elbowServoPos = 45;
      wristServoPos = 123;
      break;
    case 91:
      baseServoPos = 97;
      shoulderServoPos = 82;
      elbowServoPos = 40;
      wristServoPos = 120;
      break;
    case 92:
      baseServoPos = 97;
      shoulderServoPos = 80;
      elbowServoPos = 36;
      wristServoPos = 117;
      break;
    case 93:
      baseServoPos = 97;
      shoulderServoPos = 78;
      elbowServoPos = 32;
      wristServoPos = 115;
      break;
    case 94:
      baseServoPos = 97;
      shoulderServoPos = 76;
      elbowServoPos = 28;
      wristServoPos = 111;
      break;
    case 95:
      baseServoPos = 98;
      shoulderServoPos = 74;
      elbowServoPos = 24;
      wristServoPos = 108;
      break;
    case 96:
      baseServoPos = 98;
      shoulderServoPos = 72;
      elbowServoPos = 20;
      wristServoPos = 103;
      break;
    case 97:
      baseServoPos = 99;
      shoulderServoPos = 69;
      elbowServoPos = 16;
      wristServoPos = 100;
      break;
    case 98:
      baseServoPos = 101;
      shoulderServoPos = 68;
      elbowServoPos = 12;
      wristServoPos = 97;
      break;
    case 99:
      baseServoPos = 101;
      shoulderServoPos = 65;
      elbowServoPos = 7;
      wristServoPos = 93;
      break;
    case 100:
      baseServoPos = 98;
      shoulderServoPos = 87;
      elbowServoPos = 50;
      wristServoPos = 125;
      break;
    case 101:
      baseServoPos = 98;
      shoulderServoPos = 85;
      elbowServoPos = 45;
      wristServoPos = 122;
      break;
    case 102:
      baseServoPos = 98;
      shoulderServoPos = 82;
      elbowServoPos = 40;
      wristServoPos = 119;
      break;
    case 103:
      baseServoPos = 99;
      shoulderServoPos = 80;
      elbowServoPos = 36;
      wristServoPos = 116;
      break;
    case 104:
      baseServoPos = 99;
      shoulderServoPos = 78;
      elbowServoPos = 32;
      wristServoPos = 114;
      break;
    case 105:
      baseServoPos = 100;
      shoulderServoPos = 76;
      elbowServoPos = 28;
      wristServoPos = 110;
      break;
    case 106:
      baseServoPos = 101;
      shoulderServoPos = 74;
      elbowServoPos = 24;
      wristServoPos = 106;
      break;
    case 107:
      baseServoPos = 102;
      shoulderServoPos = 71;
      elbowServoPos = 20;
      wristServoPos = 103;
      break;
    case 108:
      baseServoPos = 103;
      shoulderServoPos = 69;
      elbowServoPos = 16;
      wristServoPos = 100;
      break;
    case 109:
      baseServoPos = 105;
      shoulderServoPos = 66;
      elbowServoPos = 9;
      wristServoPos = 93;
      break;
    case 110:
      baseServoPos = 105;
      shoulderServoPos = 66;
      elbowServoPos = 40;
      wristServoPos = 119;
      break;
    case 111:
      baseServoPos = 100;
      shoulderServoPos = 88;
      elbowServoPos = 51;
      wristServoPos = 128;
      break;
    case 112:
      baseServoPos = 100;
      shoulderServoPos = 86;
      elbowServoPos = 46;
      wristServoPos = 125;
      break;
    case 113:
      baseServoPos = 101;
      shoulderServoPos = 83;
      elbowServoPos = 42;
      wristServoPos = 122;
      break;
    case 114:
      baseServoPos = 102;
      shoulderServoPos = 80;
      elbowServoPos = 37;
      wristServoPos = 120;
      break;
    case 115:
      baseServoPos = 103;
      shoulderServoPos = 78;
      elbowServoPos = 33;
      wristServoPos = 118;
      break;
    case 116:
      baseServoPos = 103;
      shoulderServoPos = 77;
      elbowServoPos = 29;
      wristServoPos = 115;
      break;
    case 117:
      baseServoPos = 104;
      shoulderServoPos = 74;
      elbowServoPos = 25;
      wristServoPos = 111;
      break;
    case 118:
      baseServoPos = 105;
      shoulderServoPos = 73;
      elbowServoPos = 22;
      wristServoPos = 108;
      break;
    case 119:
      baseServoPos = 107;
      shoulderServoPos = 71;
      elbowServoPos = 18;
      wristServoPos = 105;
      break;
    case 120:
      baseServoPos = 108;
      shoulderServoPos = 70;
      elbowServoPos = 14;
      wristServoPos = 103;
      break;
    case 121:
      baseServoPos = 109;
      shoulderServoPos = 67;
      elbowServoPos = 10;
      wristServoPos = 99;
      break;
    case 122:
      baseServoPos = 104;
      shoulderServoPos = 88;
      elbowServoPos = 51;
      wristServoPos = 125;
      break;
    case 123:
      baseServoPos = 105;
      shoulderServoPos = 85;
      elbowServoPos = 46;
      wristServoPos = 121;
      break;
    case 124:
      baseServoPos = 105;
      shoulderServoPos = 83;
      elbowServoPos = 41;
      wristServoPos = 119;
      break;
    case 125:
      baseServoPos = 106;
      shoulderServoPos = 80;
      elbowServoPos = 37;
      wristServoPos = 115;
      break;
    case 126:
      baseServoPos = 107;
      shoulderServoPos = 78;
      elbowServoPos = 33;
      wristServoPos = 112;
      break;
    case 127:
      baseServoPos = 107;
      shoulderServoPos = 77;
      elbowServoPos = 29;
      wristServoPos = 110;
      break;
    case 128:
      baseServoPos = 108;
      shoulderServoPos = 74;
      elbowServoPos = 25;
      wristServoPos = 108;
      break;
    case 129:
      baseServoPos = 109;
      shoulderServoPos = 73;
      elbowServoPos = 22;
      wristServoPos = 105;
      break;
    case 130:
      baseServoPos = 111;
      shoulderServoPos = 71;
      elbowServoPos = 19;
      wristServoPos = 103;
      break;
    case 131:
      baseServoPos = 113;
      shoulderServoPos = 69;
      elbowServoPos = 15;
      wristServoPos = 101;
      break;
    case 132:
      baseServoPos = 115;
      shoulderServoPos = 67;
      elbowServoPos = 11;
      wristServoPos = 99;
      break;
    case 133:
      baseServoPos = 106;
      shoulderServoPos = 89;
      elbowServoPos = 54;
      wristServoPos = 129;
      break;
    case 134:
      baseServoPos = 107;
      shoulderServoPos = 86;
      elbowServoPos = 48;
      wristServoPos = 125;
      break;
    case 135:
      baseServoPos = 108;
      shoulderServoPos = 84;
      elbowServoPos = 43;
      wristServoPos = 122;
      break;
    case 136:
      baseServoPos = 109;
      shoulderServoPos = 81;
      elbowServoPos = 39;
      wristServoPos = 120;
      break;
    case 137:
      baseServoPos = 110;
      shoulderServoPos = 79;
      elbowServoPos = 35;
      wristServoPos = 117;
      break;
    case 138:
      baseServoPos = 111;
      shoulderServoPos = 77;
      elbowServoPos = 31;
      wristServoPos = 114;
      break;
    case 139:
      baseServoPos = 112;
      shoulderServoPos = 75;
      elbowServoPos = 27;
      wristServoPos = 110;
      break;
    case 140:
      baseServoPos = 114;
      shoulderServoPos = 74;
      elbowServoPos = 24;
      wristServoPos = 106;
      break;
    case 141:
      baseServoPos = 116;
      shoulderServoPos = 72;
      elbowServoPos = 20;
      wristServoPos = 103;
      break;
    case 142:
      baseServoPos = 118;
      shoulderServoPos = 70;
      elbowServoPos = 17;
      wristServoPos = 103;
      break;
    case 143:
      baseServoPos = 120;
      shoulderServoPos = 68;
      elbowServoPos = 13;
      wristServoPos = 100;
      break;
    case 144:
      baseServoPos = 109;
      shoulderServoPos = 90;
      elbowServoPos = 57;
      wristServoPos = 129;
      break;
    case 145:
      baseServoPos = 110;
      shoulderServoPos = 87;
      elbowServoPos = 49;
      wristServoPos = 125;
      break;
    case 146:
      baseServoPos = 111;
      shoulderServoPos = 84;
      elbowServoPos = 45;
      wristServoPos = 124;
      break;
    case 147:
      baseServoPos = 112;
      shoulderServoPos = 82;
      elbowServoPos = 41;
      wristServoPos = 120;
      break;
    case 148:
      baseServoPos = 114;
      shoulderServoPos = 80;
      elbowServoPos = 37;
      wristServoPos = 117;
      break;
    case 149:
      baseServoPos = 115;
      shoulderServoPos = 78;
      elbowServoPos = 33;
      wristServoPos = 115;
      break;
    case 150:
      baseServoPos = 116;
      shoulderServoPos = 76;
      elbowServoPos = 29;
      wristServoPos = 111;
      break;
    case 151:
      baseServoPos = 118;
      shoulderServoPos = 74;
      elbowServoPos = 26;
      wristServoPos = 108;
      break;
    case 152:
      baseServoPos = 120;
      shoulderServoPos = 72;
      elbowServoPos = 21;
      wristServoPos = 104;
      break;
    case 153:
      baseServoPos = 122;
      shoulderServoPos = 70;
      elbowServoPos = 18;
      wristServoPos = 102;
      break;
    case 154:
      baseServoPos = 125;
      shoulderServoPos = 69;
      elbowServoPos = 15;
      wristServoPos = 99;
      break;
   }
   // set counters to move to position
   int baseServoCount = 60;
   int shoulderServoCount = 0;
   int elbowServoCount = 0;
   int wristServoCount = 140;
   
    while(shoulderServoCount < (shoulderServoPos - 2))
    {
      if(baseServoCount < baseServoPos)
        baseServoCount++;
      if(shoulderServoCount < shoulderServoPos)
        shoulderServoCount++;
      if(elbowServoCount < elbowServoPos)
        elbowServoCount++;
      if(wristServoCount > wristServoPos)                   //Move the Servos
        wristServoCount--;

        baseServo.write(baseServoCount);
        shoulderServo.write(shoulderServoCount);
        elbowServo.write(elbowServoCount);
        wristServo.write(wristServoCount);
        delay(100);
    }
    shoulderServoCount++;
    shoulderServo.write(shoulderServoCount);
    delay(100);
    shoulderServoCount++;
    shoulderServo.write(shoulderServoCount);
    delay(100);
    shoulderServoCount++;
    shoulderServo.write(shoulderServoCount);
    delay(100);
    shoulderServoCount++;
    shoulderServo.write(shoulderServoCount);
    delay(100);
    shoulderServoCount++;
    shoulderServo.write(shoulderServoCount);
    delay(100);
    shoulderServoCount++;
    shoulderServo.write(shoulderServoCount);
    delay(100);
    shoulderServoCount++;
    shoulderServo.write(shoulderServoCount);
    delay(100);

    digitalWrite(magnetPin, HIGH);        //Turn on Magnet
    delay(2000);
   wristServoCount++;
   wristServo.write(wristServoCount);
   delay(400);
   wristServoCount++;
   wristServo.write(wristServoCount);
   delay(400);

    
    while(shoulderServoCount > 50)
    {
      shoulderServoCount--;
      shoulderServo.write(shoulderServoCount);      //Move shoulder to sort position
      delay(100);
    }
    while(elbowServoCount > 8)
    {
      elbowServoCount--;
      elbowServo.write(elbowServoCount);            //Move elbow to sort position
      delay(100);
    }
    while(elbowServoCount < 8)
    {
      elbowServoCount++;
      elbowServo.write(elbowServoCount);            //Move elbow to sort position
      delay(100);
    }
    while(wristServoCount > 125)
    {
      wristServoCount--;
      wristServo.write(wristServoCount);            //Move wrist to sort position
      delay(100);
    }
    while(wristServoCount < 125)
    {
      wristServoCount++;
      wristServo.write(wristServoCount);            //Move wrist to sort position
      delay(100);
    }
    
    

    delay(1000);
    //Drop to the Square Zone
    if(incomingShape == 'S')
    {
      while(baseServoCount < 180)
      {
        baseServoCount++;
        baseServo.write(baseServoCount);
        delay(100);
      }
      delay(3000);
      digitalWrite(magnetPin, LOW);
      delay(1000);
      while(baseServoCount> 60)
      {
        //go back to home position
        if(shoulderServoCount > 0)
          shoulderServoCount--;
        if(elbowServoCount > 0)
          elbowServoCount--;
        if(wristServoCount < 140)
          wristServoCount++;

          baseServoCount--;
          baseServo.write(baseServoCount);
          shoulderServo.write(shoulderServoCount);
          elbowServo.write(elbowServoCount);
          wristServo.write(wristServoCount);
          delay(100);
      }
    }
    //drop to the Triangle Zone
    else
    {
      while(baseServoCount > 0)
      {
        baseServoCount--;
        baseServo.write(baseServoCount);
        delay(100);
      }
      delay(3000);
      digitalWrite(magnetPin, LOW);
      delay(1000);
      while(baseServoCount< 60)
      {
        //go back to staring position
        if(shoulderServoCount > 0)
          shoulderServoCount--;
        if(elbowServoCount > 0)
          elbowServoCount--;
        if(wristServoCount < 140)
          wristServoCount++;

          baseServoCount++;
          baseServo.write(baseServoCount);
          shoulderServo.write(shoulderServoCount);
          elbowServo.write(elbowServoCount);
          wristServo.write(wristServoCount);
          delay(100);
      }
      
    }
    // release Magnet
    digitalWrite(magnetPin, LOW);
    delay(1000);

    
    shoulderServo.write(0);
    delay(1000);
    wristServo.write(140);
    elbowServo.write(0);
    delay(2000);
    baseServo.write(60);  
}
