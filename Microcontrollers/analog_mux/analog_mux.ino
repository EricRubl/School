

int A_PIN = 10;
int B_PIN = 9;
int C_PIN = 8;

int pot_value, magn_value, temp_value, light_value;

void setup() 
{
pinMode(A_PIN, OUTPUT);
pinMode(B_PIN, OUTPUT);
pinMode(C_PIN, OUTPUT);

Serial.begin(9600);
}

void loop() 
{
  
digitalWrite(C_PIN,0);
digitalWrite(B_PIN,0);
digitalWrite(A_PIN,0);
delay(50);
pot_value = analogRead(A0);

digitalWrite(C_PIN,0);
digitalWrite(B_PIN,0);
digitalWrite(A_PIN,1);
delay(50);
magn_value = analogRead(A0);

digitalWrite(C_PIN,0);
digitalWrite(B_PIN,1);
digitalWrite(A_PIN,0);
delay(50);
temp_value = analogRead(A0);

digitalWrite(C_PIN,0);
digitalWrite(B_PIN,1);
digitalWrite(A_PIN,1);
delay(50);
light_value = analogRead(A0);

Serial.print(pot_value);
Serial.print(",");
Serial.print(magn_value);
Serial.print(",");
Serial.print(temp_value);
Serial.print(",");
Serial.println(light_value);

}
