// 贡献者：路遥
#include <Servo.h>    //舵机控制库
#include <DistanceSRF04.h>
#include <SoftwareSerial.h>
SoftwareSerial swSer(13, 12);
DistanceSRF04 Dist;
int rx = 13;
int tx = 12;
int distance;
int EN2 = 14;  
int EN3 = 15;
int EN4 = 16;
int EN5 = 17;
int LED1 = 6; 
int LED2 = 7; 
int EA= 3; 
int EB= 5; 
int val,kkl,lkf,ctr;
int lx=90;
int trans,code,codex;
//2路舵机
Servo servoX; //云台X轴舵机 左右
Servo servoY; //云台Y轴舵机 上下
int mkk;
///////////////////////////////////////

void sense1(void) {
    while (swSer.available() > 0) {
        trans = swSer.read();
       //Serial.write(trans);
       code = trans;
       if(code == 'H' ){
        Serial.println("complete");
       servo_left();
     }
     
   }
}
void sense(void) {
    while (swSer.available() > 0) {
        trans = swSer.read();
       code = trans;
       if (code == 'X'){
       codex = 'X';
       }
       if (code == 'B' && codex == 'X'){        //前
        qian();
        codex == 0 ;
       }
       if (code == 'A' && codex == 'X'){        //后
        hou();
        codex == 0 ;
       }
       if (code == 'C' && codex == 'X'){        //左
        zuo();
        codex == 0 ;
       }
       if (code == 'E' && codex == 'X'){        //右
        you();
        codex == 0 ;
       }
       if (code == 'F' && codex == 'X'){        //停
        ting();  
        codex == 0 ;
       }
       if (code == 'G' && codex == 'X'){        //向上
        servo_up();            
        codex == 0 ;
       }
       if (code == 'H' && codex == 'X'){        //向下
        servo_down();             
        codex == 0 ;
       }
       if (code == 'J' && codex == 'X'){        //向左
        servo_left();              
        codex == 0 ;
       }
       if (code == 'K' && codex == 'X'){        //向右
        servo_right();             
        codex == 0 ;
       }   
   }
}


void ting(void)
        {
          analogWrite(EA,0);
          analogWrite(EB,0); 
          digitalWrite(EN2,LOW);   
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,LOW);   
          digitalWrite(EN5,LOW);       
          delay(500);
        }
        
void hou(void)
        { 
          analogWrite(EA,254);//调节参数可调速度（0-255）
          analogWrite(EB,255);//调节参数可调速度（0-255）    
          digitalWrite(EN2,LOW);
          digitalWrite(EN3,HIGH);
          digitalWrite(EN4,LOW);
          digitalWrite(EN5,HIGH);
          delay(500);
          analogWrite(EA,0);
          analogWrite(EB,0); 
          digitalWrite(EN2,LOW);   
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,LOW);   
          digitalWrite(EN5,LOW);     
        }
void qian(void)
        {  
          analogWrite(EA,255);//调节参数可调速度（0-255）
          analogWrite(EB,255); //调节参数可调速度（0-255）     
          digitalWrite(EN2,HIGH);
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,HIGH);
          digitalWrite(EN5,LOW);    
          delay(500);
          analogWrite(EA,0);
          analogWrite(EB,0); 
          digitalWrite(EN2,LOW);   
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,LOW);   
          digitalWrite(EN5,LOW);             
        }
void zuo(void)
        {  
          analogWrite(EA,180);//调节参数可调速度（0-255）
          analogWrite(EB,180); //调节参数可调速度（0-255）     
          digitalWrite(EN2,LOW);
          digitalWrite(EN3,HIGH);
          digitalWrite(EN4,HIGH);
          digitalWrite(EN5,LOW);    
          delay(500);
          analogWrite(EA,0);
          analogWrite(EB,0); 
          digitalWrite(EN2,LOW);   
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,LOW);   
          digitalWrite(EN5,LOW);      
        }        
void you(void)
        {  
          analogWrite(EA,180);//调节参数可调速度（0-255）
          analogWrite(EB,180); //调节参数可调速度（0-255）     
          digitalWrite(EN2,HIGH);
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,LOW);
          digitalWrite(EN5,HIGH);
          delay(500);
          analogWrite(EA,0);
          analogWrite(EB,0); 
          digitalWrite(EN2,LOW);   
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,LOW);   
          digitalWrite(EN5,LOW);     
          
        }  
//舵机左转
void servo_up()
{
  int servotemp=servoX.read();//获取舵机目前的角度值
  servotemp-=2;//舵机运动1度
  if(servotemp<170&&servotemp>10) //我定义的舵机旋转角度为10度到170度
  servoX.write(servotemp);
  else if (servotemp<=10)  servoX.write(10);
  else servoX.write(170);
}


//舵机右转
void servo_down()
{
  int servotemp=servoX.read();//获取舵机目前的角度值
  servotemp+=2;//舵机运动1度
  if(servotemp<170&&servotemp>10)//我定义的舵机旋转角度为10度到170度
  servoX.write(servotemp);
  else if (servotemp<=10)  servoX.write(10);
  else servoX.write(170);
}


//舵机上转
void servo_left()
{
  int servotemp1=servoY.read();//获取舵机目前的角度值
  servotemp1+=2;//舵机运动1度
  if(servotemp1<170&&servotemp1>10)//我定义的舵机旋转角度为10度到170度
  servoY.write(servotemp1);
  else if (servotemp1<=10)  servoY.write(10);
  else servoY.write(170);
}


//舵机下转
void servo_right()
{
  int servotemp1=servoY.read();//获取舵机目前的角度值
  servotemp1-=2;//舵机运动1度
  if(servotemp1<170&&servotemp1>10)//我定义的舵机旋转角度为10度到170度
  servoY.write(servotemp1);
  else if (servotemp1<=10)  servoY.write(10);
  else servoY.write(170);
}

void setup()
{ 
  Dist.begin(8,9);
  servoX.attach(10);//水平舵机接10脚
  servoY.attach(11);//上下舵机接11脚
  servoX.write(90);//输出舵机初始位置为90度
  servoY.write(90);//输出舵机初始位置为90度
  pinMode(EN2,OUTPUT);
  pinMode(EN3,OUTPUT);
  pinMode(EN4,OUTPUT);
  pinMode(EN5,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(EA,OUTPUT);
  pinMode(EB,OUTPUT);
  lkf=0;
  Serial.begin(115200);
  swSer.begin(115200);
}


void loop(){
  sense();
}
