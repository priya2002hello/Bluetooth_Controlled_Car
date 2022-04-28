#define M11 13
#define M12 12
#define M21 11
#define M22 10

char data;

void setup()
{
  Serial.begin(9600);
  Serial.println("Welcome to bluetooth controlled car");

  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);

  Stop();
}

void loop()
{
  if (Serial.available())
  {

    data = Serial.read();
    Serial.println(data);

    if (data == 'F' || data == 'f')
    {
      Serial.println("move forward");
      forward();
      delay(100);
    }
    else if (data == 'B' || data == 'b')
    {
      Serial.println("move backward");
      backward();
      delay(100);
    }
    else if (data == 'R' || data == 'r')
    {
      right();
      delay(100);
    }
    else if (data == 'L' || data == 'l')
    {
      left();
      delay(100);
    }
  }
  else
  {
    Stop();
    delay(100);
  }
}

void forward()
{
  digitalWrite(M11, HIGH);
  digitalWrite(M12, LOW);
  digitalWrite(M21, HIGH);
  digitalWrite(M22, LOW);
  //delay(1000);
}

void backward()
{
  digitalWrite(M11, LOW);
  digitalWrite(M12, HIGH);
  digitalWrite(M21, LOW);
  digitalWrite(M22, HIGH);
 //delay(1000);
}

void right()
{
  digitalWrite(M11, LOW);
  digitalWrite(M12, LOW);
  digitalWrite(M21, HIGH);
  digitalWrite(M22, LOW);
  //delay(1000);
}

void left()
{
  digitalWrite(M11, HIGH);
  digitalWrite(M12, LOW);
  digitalWrite(M21, LOW);
  digitalWrite(M22, LOW);
  //delay(1000);
}
void Stop()
{
  digitalWrite(M11, LOW);
  digitalWrite(M12, LOW);
  digitalWrite(M21, LOW);
  digitalWrite(M22, LOW);
  //delay(1000);
}
