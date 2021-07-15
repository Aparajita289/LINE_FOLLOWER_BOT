int A[6]={A5,A4,A3,A2,A1,A0};
String s;
int i;
int flag=0;
void setup() {
 Serial.begin(9600);
 pinMode(13,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 for(i=0;i<6;i++)
 {
    pinMode(A[i],INPUT);
 }
  // put your setup code here, to run once:

}void loop()
{
  // put your main code here, to run repeatedly:
 s="";
  SensorRead();
  Serial.println(s);
 if((flag==0)&&((s[0]!=s[5])||(s=="BBBBBB")||(s=="WWWWWW")))
    EdgeFollower();
 else
  LineFollower();
}
void SensorRead()
{
  int B[6];
  for(i=0;i<6;i++)
  {
    B[i]=analogRead(A[i]);
    if(B[i]<500)
    s+="W";
    else
    s+="B";
  }
}
void EdgeFollower()
{
  if(s=="BBBWWW")
     forward();
  else if(s=="BBBBWW")
     slowright();
  else if(s=="BBBBBW")
     slowright();
  else if(s=="WWWWBB")
     slowleft();
   else if(s=="WWWWWB"||s=="WWWWWW")
      slowleft_e();
     else if(s=="BBBBBW"||s=="BBBBBB")
      slowright_e();
}
void LineFollower()
{ flag=1;

  if(s=="BBWWBB")
    forward();
    
 else if(s=="BBBWWB"||s=="BBBBWW")
    slowright();
 else if(s=="WWWWBB"||s=="WWWWWB"||s=="WWWBBB")
 {  
    
   sharpleft();
 }
 else if(s=="BBBWWW"||s=="BBBBWW"||s=="BBBBBW")
   {
     
    sharpright();
   }
 else if(s=="BWWBBB"||s=="WWBBBB")
      slowleft();
 //else if(s=="BBBBBB")
   //backward();
else if(s=="WWWWWW")
   {
    stopbot();
    digitalWrite(13,1);
    }
 //else if(s=="BBBBWW")
    //slowright();
//else if(s=="BBBBBB")
 //backward();
// else if(s=="BBWWWW")
//  sharpright();

   
  //else if(s=="BWWBBB")
    //slowright();
 
      
 // else if(s=="WBBBBB")
      //slowright();

 }

void forward()
{
  //rotate right clockwise
  analogWrite(3,200);
  digitalWrite(5,0);
  digitalWrite(6,1);
  //rotate  left clockwise
  analogWrite(9,200);
  digitalWrite(7,0);
  digitalWrite(8,1);
}

  void slowleft()
{
  //halt left
  analogWrite(9,0);
  //rotate right clockwise
  analogWrite(3,150);
  digitalWrite(5,0);
  digitalWrite(6,1);
}
void backward()
{
 
  //rotate left anticlockwise
  analogWrite(9,200);
  digitalWrite(7,1);
  digitalWrite(8,0);
   Serial.println("done");
   //rotate right anticlockwise
  analogWrite(3,200);
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(13,1);

  
  
}
void slowright()
{
  //halt right
  analogWrite(3,0);
  //rotate left clockwise
  analogWrite(9,150);
  digitalWrite(7,0);
  digitalWrite(8,1);
}
void sharpright()
{//rotate left clockwise
  analogWrite(9,70);
  digitalWrite(7,0);
  digitalWrite(8,1);
  //rotate right anticlockwise
  analogWrite(3,70);
  digitalWrite(5,1);
  digitalWrite(6,0);
}
void sharpleft()
{
  //rotate right clockwise
  analogWrite(3,70);
  digitalWrite(5,0);
  digitalWrite(6,1);
  //rotate left anticlockwise
  analogWrite(9,70);
  digitalWrite(7,1);
  digitalWrite(8,0);
}
void doright()
{
  delay(70);
  sharpright();
}
void doleft()
{
  delay(70);
  sharpleft();
}
void slowleft_e()
{
  //halt left
  analogWrite(9,0);
  //rotate right clockwise
  analogWrite(3,50);
  digitalWrite(5,0);
  digitalWrite(6,1);
}
void slowright_e()
{
   //halt right
   analogWrite(3,0);
 
  //rotate left clockwise
  analogWrite(9,50);
  digitalWrite(7,0);
  digitalWrite(8,1);
}
void stopbot()
{ 
  analogWrite(3,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
   analogWrite(9,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
}
