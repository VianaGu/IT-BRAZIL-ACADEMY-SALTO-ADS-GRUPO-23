#define motor1A 12
#define motor2A 10
#define botao 7
#define botao2 8   
int estadoDobotao = 0; 
int estadoDobotao2 = 0;

void setup(){
  Serial.begin(115200); 

  pinMode (motor1A, OUTPUT);
  pinMode (motor2A, OUTPUT);
  pinMode (botao, INPUT);
  pinMode (botao2, INPUT);
  
 }


void loop(){
  estadoDobotao = digitalRead(botao);
  estadoDobotao2 = digitalRead(botao2);
  //Serial.println(estadoDobotao);
  Serial.println(estadoDobotao2);
  if(estadoDobotao == LOW){
    digitalWrite (motor1A, HIGH);
    digitalWrite (motor2A, LOW);
    
  }
  else{
    digitalWrite(motor1A,LOW);
    digitalWrite (motor2A, LOW);
  }

  if(estadoDobotao2 == LOW){
    digitalWrite(motor1A, LOW);
    digitalWrite(motor2A, HIGH);
  }
  else{
    digitalWrite(motor1A,LOW);
    digitalWrite (motor2A, LOW);
  }
}
