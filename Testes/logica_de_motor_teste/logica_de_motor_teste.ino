#define motor1A 13
#define motor2A 10
#define botao 1
#define botao2 0   


void setup(){

  pinMode (motor1A, OUTPUT);
  pinMode (motor2A, OUTPUT);
  pinMode (botao, INPUT);
  pinMode (botao2, INPUT);
  
 }


void loop(){
  estadoDobotao = digitalRead(botao);
  estadoDobotao2 = digitalRead(botao2);

  if(estadoDobotao==HIGH){
    digitalWrite (motor1A, HIGH);
    digitalWrite (motor2A, LOW);
  }

  else{
    digitalWrite(motor1A,LOW);
    digitalWrite (motor2A, LOW);
  }

  if(estadoDobotao2==HIGH){
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor1A, LOW);
  }
  else{
    digitalWrite(motor1A,LOW);
    digitalWrite (motor2A, LOW);
  }
}
