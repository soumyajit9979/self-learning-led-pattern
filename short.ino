
int rst=7;
int bt=12;
char mov[400];
int num[400];
int scount=0;
int bcount=0;
//int led=13;
char val;
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
    
    Serial.println(val);
    
    }

    
    if(val=='F'){
      digitalWrite(bt,LOW);
//      if(bcount>10){
//          num[flag]=bcount;
//          mov[flag]='B';
//          flag++;
//          bcount=0;
//        }
        if(scount>10){
            num[flag]=scount;
            mov[flag]='S';
            flag++;
            scount=0;
          }
      delay(1000);
      arr(mov,num);
      exit(0);
    }
    else if(val=='B'){
      bcount++;
      digitalWrite(LED_BUILTIN,HIGH);
      if(scount>10)
      {
        num[flag]=scount;
        mov[flag]='S';
        flag++;
        scount=0;
      }
      
    }

    else if(val=='S'){
      scount++;
       digitalWrite(LED_BUILTIN,LOW);
       if(bcount>10){
          num[flag]=bcount;
          mov[flag]='B';
          flag++;
          bcount=0;
        }
      }

}


int arr(char b[],int c[]){
int x=sizeof(c)/sizeof(c[0]);
  for(int i=0;i<x;i++){
    if(b[i]=='B'){
      for(int j=0;j<c[i];j++){
        delay(23);
        digitalWrite(LED_BUILTIN,HIGH);
        Serial.println(b[i]);
      } 
      }
    else if(b[i]=='S'){
      for(int j=0;j<c[i];j++){
        delay(23);
        digitalWrite(LED_BUILTIN,LOW);
        Serial.println(b[i]);
      } 
      }
    }
digitalWrite(rst,LOW);
return 0;
  }
