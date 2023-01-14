//include the library code:
#include<NewPing.h>           
#include<Servo.h>                        

int motor_dp_kn_mj = 9;
int motor_dp_kn_md = 8;

int motor_dp_kr_mj = 7;
int motor_dp_kr_md = 6;

int motor_bk_kn_mj = 5;
int motor_bk_kn_md = 4;

int motor_bk_kr_mj = 3;
int motor_bk_kr_md = 2;

int kn = 10;
int kr = 11;

unsigned int jarak = 0;    //Variable to store ultrasonic sensor distance:
unsigned int ir_kn_Value = 0; //Variable to store Right IR sensor value:
unsigned int ir_kr_Value = 0;  //Variable to store Left IR sensor value:
  
#define trig_pin A0    
#define echo_pin A1  
#define ir_kn A2            
#define ir_kr A3                     
#define maximum_distance 300  

NewPing sonar(trig_pin, echo_pin, maximum_distance);  //NewPing setup of pins and maximum distance:

 Servo myservo; //create servo object to control the servo:
 int pos=0;     //pos = posisi

void setup(){ 
   //SERIAL COMUNICASI
  Serial.begin(9600);
  //depan
  pinMode(motor_dp_kn_mj, OUTPUT);
  pinMode(motor_dp_kn_md, OUTPUT);
  pinMode(motor_dp_kr_mj, OUTPUT);
  pinMode(motor_dp_kr_md, OUTPUT);
  //blakang
  pinMode(motor_bk_kn_mj, OUTPUT);
  pinMode(motor_bk_kn_md, OUTPUT);
  pinMode(motor_bk_kr_mj, OUTPUT);
  pinMode(motor_bk_kr_md, OUTPUT);
  //kecepatan
  pinMode(kn, OUTPUT); 
  pinMode(kr, OUTPUT);

  pinMode(ir_kn, INPUT); 
  pinMode(ir_kr, INPUT);

  myservo.attach(12); 
}

// the lope function runs forever
void loop() {                             
analogWrite(kn, 255);
analogWrite(kr, 255);

ir_kn_Value = digitalRead(ir_kn) ;            
ir_kr_Value = digitalRead(ir_kr) ;   

delay(50);                                        //wait 50ms between pings:
jarak = sonar.ping_cm();                       //send ping, get distance in cm and store it in 'distance' variable:
Serial.print("jarak");                   
Serial.println(jarak);    

Serial.print("kanan");                      
Serial.println(ir_kn_Value);                      
Serial.print("kiri");                       
Serial.println(ir_kr_Value);                                 
 
if((jarak > 5) && (jarak < 20)){      

  digitalWrite(motor_dp_kn_mj, HIGH);//MAJU
  digitalWrite(motor_dp_kn_md, LOW);
  
  digitalWrite(motor_dp_kr_mj, HIGH);
  digitalWrite(motor_dp_kr_md, LOW);

  digitalWrite(motor_bk_kn_mj, HIGH);
  digitalWrite(motor_bk_kn_md, LOW);
  
  digitalWrite(motor_bk_kr_mj, HIGH);
  digitalWrite(motor_bk_kr_md, LOW);
 
}else if((ir_kn_Value == 0) && (ir_kr_Value ==1)) { 
  
  digitalWrite(motor_dp_kn_mj, HIGH);//Kiri
  digitalWrite(motor_dp_kn_md, LOW);
  
  digitalWrite(motor_dp_kr_mj, LOW);
  digitalWrite(motor_dp_kr_md, HIGH);

  digitalWrite(motor_bk_kn_mj, HIGH);
  digitalWrite(motor_bk_kn_md, LOW);
  
  digitalWrite(motor_bk_kr_mj, LOW);
  digitalWrite(motor_bk_kr_md, HIGH);
  delay(500);
  
}else if((ir_kn_Value == 1)&&(ir_kr_Value == 0)) {
  
  digitalWrite(motor_dp_kn_mj, LOW);//kanan
  digitalWrite(motor_dp_kn_md, HIGH);
  
  digitalWrite(motor_dp_kr_mj, HIGH);
  digitalWrite(motor_dp_kr_md, LOW);

  digitalWrite(motor_bk_kn_mj, LOW);
  digitalWrite(motor_bk_kn_md, HIGH);
  
  digitalWrite(motor_bk_kr_mj, HIGH);
  digitalWrite(motor_bk_kr_md, LOW);
  delay(500);
/*}else if( jarak < 10){ 
  digitalWrite(motor_dp_kn_mj, LOW);//MUNDUR
  digitalWrite(motor_dp_kn_md, HIGH);
  
  digitalWrite(motor_dp_kr_mj, LOW);
  digitalWrite(motor_dp_kr_md, HIGH);

  digitalWrite(motor_bk_kn_mj, LOW);
  digitalWrite(motor_bk_kn_md, HIGH);
  
  digitalWrite(motor_bk_kr_mj, LOW);
  digitalWrite(motor_bk_kr_md, HIGH);
*/
}else if(jarak > 20 ){                         
  
  digitalWrite(motor_dp_kn_mj, LOW);//STOP
  digitalWrite(motor_dp_kn_md, LOW);
  
  digitalWrite(motor_dp_kr_mj, LOW);
  digitalWrite(motor_dp_kr_md, LOW);

  digitalWrite(motor_bk_kn_mj, LOW);
  digitalWrite(motor_bk_kn_md, LOW);
  
  digitalWrite(motor_bk_kr_mj, LOW);
  digitalWrite(motor_bk_kr_md, LOW);
  delay(1000); 
}
}