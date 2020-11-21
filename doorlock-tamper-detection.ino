const int trigPin =4 ;
const int echoPin =2 ;
const int led=13;
const int buzzer=11;
int ctr=0;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
pinMode(buzzer, OUTPUT);
Serial.begin(9600);
Serial.println("Timer");
//Serial.println("\n");
}
void loop()
{
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.41;
if (distance<=5)
{
ctr++;
delay(1000);
Serial.print(ctr);
Serial.println("\n");
if(ctr>10)
{
for(;;)
{
digitalWrite(buzzer,HIGH);
digitalWrite(led,HIGH);
delay(50);
digitalWrite(buzzer,LOW);
digitalWrite(led,LOW);
delay(50);
}
}
}
}
