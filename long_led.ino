int rst=7;
int bt=12;
//int led=13;
char val;
char val2;
char a[1200];
int flag=0;
void setup() {
  // put your setup code here, to run once:
digitalWrite(rst,HIGH);
delay(200);
pinMode(bt,OUTPUT);
pinMode(rst,OUTPUT);
//pinMode(led,OUTPUT);
digitalWrite(bt,HIGH);
pinMode(LED_BUILTIN,OUTPUT);
digitalWrite(LED_BUILTIN,LOW);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(bt,HIGH);
  while(Serial.available()>0){
    val = Serial.read();
    
//    a[flag]=char(val);
//    Serial.println(flag);
    Serial.println(val);
    
    }

    
    if(val=='F'){
      Serial.println(flag);
      digitalWrite(bt,LOW);
      delay(1000);
      arr(a,flag);
//      rep(a, flag);
      exit(0);
    }
    else if(val=='B'){
      flag++;
      digitalWrite(LED_BUILTIN,HIGH);
      a[flag]='B';
      
      
    }

    else if(val=='S'){
      flag++;
       digitalWrite(LED_BUILTIN,LOW);
       a[flag]='S';
       
      }

}

void rep(char b[],int x){
      for(int i=0; i<x; i++){
        val2=a[i];
        if(val2=='B'){
          digitalWrite(LED_BUILTIN,HIGH);
          }
        if(val2=='S'){
          digitalWrite(LED_BUILTIN,LOW);
          }
        }
//        digitalWrite(bt,HIGH);
      
      }

int arr(char b[],int x){

  for(int i=0;i<x;i++){
    delay(23);
      Serial.println(b[i]);
    if(b[i]=='B'){
        digitalWrite(LED_BUILTIN,HIGH);
      }
    else if(b[i]=='S'){
        digitalWrite(LED_BUILTIN,LOW);
      }
    }
//    flag=0;
digitalWrite(LED_BUILTIN,HIGH);
digitalWrite(rst,LOW);
return 0;
  }
