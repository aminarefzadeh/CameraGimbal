
int UD = 0;
int LR = 0;
int button = 0;

/*Arduino Micro Input Pins */ 
#define VRX A0
#define VRY A1
#define SW 8    // broken :(


#define enA 9
#define in1 6
#define in2 7


int rotDirection = 0;
int motorSpeed = 0;


void setup(){
  pinMode(VRX,INPUT);
  pinMode(VRY,INPUT);
  pinMode(SW,INPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  Serial.begin(115200);
}
void loop(){
UD = analogRead(VRX); 
LR = analogRead(VRY); 
button = digitalRead(SW);

//Serial.print(UD);
//Serial.print("\t");
//Serial.print(LR);
//Serial.print("\t");
//
//if (button == LOW){
//  Serial.print("button");
//}
//
//Serial.println("");

if(UD > 511){
  motorSpeed = (UD - 512)/2;
  rotDirection = 1;
  
}else{
  motorSpeed = (512 - UD)/2;
  rotDirection = 0;
}

if(motorSpeed > 255){
  motorSpeed = 255;
}

Serial.println(motorSpeed);
//Serial.print("\t");

analogWrite(enA,motorSpeed);
if(rotDirection){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}else{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
}
