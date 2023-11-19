#include <SoftwareSerial.h>

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define EN1 9
#define EN2 10
#define R_S A0                 // ir sensor Right
#define L_S A1                 // ir sensor Left
SoftwareSerial mySerial(2, 3); // RX, TX

String data;
int btVal;
char t;
void setup()
{
    // Serial.begin(115200);
    pinMode(A0, INPUT); // declare if sensor as input
    pinMode(A1, INPUT); // declare ir sensor as input
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(EN1, OUTPUT);
    pinMode(EN2, OUTPUT);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(EN1, 200);
    digitalWrite(EN2, 200);
    mySerial.begin(9600);
}

void loop()
{
    while (mySerial.available())
    {
        {
            data = mySerial.readStringUntil('\n');
            // Serial.print(str);
        }

        btVal = (data.toInt());
        Serial.print("BlueTooth Value ");
        Serial.println(btVal);

        switch (btVal)
        {
        case 1:
            Serial.println("Forward");
            t='c';
            forward();
            break;

        case 2:
            Serial.println("Reverse");
            t='c';
            reverse();
            break;

        case 3:
            Serial.println("Left");
            t='c';
            left();
            break;

        case 4:
            Serial.println("Right");
            t='c';
            right();
            break;

        case 5:
            Serial.println("Stop");
            t='c';
            stoprobot();
            break;

        case 6:
            while (t!='F')
            {
                t= mySerial.read();
                
            
                Serial.println("Auto Mode");
                if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0))
                {
                    //forward();
                    forward_control();
                } // if Right Sensor and Left Sensor are at White color then it will call forword function
                if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0))
                {
                    
                    //left();
                    left_control();
                } // if Right Sensor is Black and Left Sensor is White then it will call turn Right function
                if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1))
                {
                    
                    //right();
                    right_control();
                } // if Right Sensor is White and Left Sensor is Black then it will call turn Left function
                if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1))
                {
                    //stoprobot();
                    stop_robot();
                } // if Right Sensor and Left Sensor are at Black color then it will call Stop function
                // }

                delay(10);
                // break;
            }
        }
    }

    if (mySerial.available() < 0)
    {
        // Serial.println("No Bluetooth Data ");
    }
}

// void autoMode(int btVal)
//{
//     if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0))
//     {
//         forward(btVal);
//     } // if Right Sensor and Left Sensor are at White color then it will call forword function
//     if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0))
//     {
//         right(btVal);
//     } // if Right Sensor is Black and Left Sensor is White then it will call turn Right function
//     if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1))
//     {
//         left(btVal);
//     } // if Right Sensor is White and Left Sensor is Black then it will call turn Left function
//     if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1))
//     {
//         stoprobot(btVal);
//     } // if Right Sensor and Left Sensor are at Black color then it will call Stop function
//     // }
//
//     delay(10);
//
//     // }
// }

void reverse()
{
    //    if (btVal == 6)
    //    {
    //        digitalWrite(IN1, HIGH);
    //        digitalWrite(IN2, LOW);
    //        digitalWrite(IN3, HIGH);
    //        digitalWrite(IN4, LOW);
    //        autoMode(btVal);
    //    }
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
//    analogWrite(EN1,200);
//    analogWrite(EN2,200);
}

void forward()
{
    //    if (btVal == 6)
    //    {
    //        digitalWrite(IN1, LOW);
    //        digitalWrite(IN2, HIGH);
    //        digitalWrite(IN3, LOW);
    //        digitalWrite(IN4, HIGH);
    //        autoMode(btVal);
    //    }
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
//    analogWrite(EN1,200);
//    analogWrite(EN2,200);
}

//void left()
//{
//    //    if (btVal == 6)
//    //    {
//    //        digitalWrite(IN1, LOW);
//    //        digitalWrite(IN2, LOW);
//    //        digitalWrite(IN3, HIGH);
//    //        digitalWrite(IN4, LOW);
//    //        autoMode(btVal);
//    //    }
//    digitalWrite(IN1, LOW);
//    digitalWrite(IN2, LOW);
//    digitalWrite(IN3, HIGH);
//    digitalWrite(IN4, LOW);
////    analogWrite(EN1,200);
////    analogWrite(EN2,200);
//}
void left()
{
    //    if (btVal == 6)
    //    {
    //        digitalWrite(IN1, LOW);
    //        digitalWrite(IN2, LOW);
    //        digitalWrite(IN3, HIGH);
    //        digitalWrite(IN4, LOW);
    //        autoMode(btVal);
    //    }
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
//    analogWrite(EN1,200);
//    analogWrite(EN2,200);
}

//void right()
//{
//    //    if (btVal == 6)
//    //    {
//    //        digitalWrite(IN1, HIGH);
//    //        digitalWrite(IN2, LOW);
//    //        digitalWrite(IN3, LOW);
//    //        digitalWrite(IN4, LOW);
//    //        autoMode(btVal);
//    //    }
//    digitalWrite(IN1, HIGH);
//    digitalWrite(IN2, LOW);
//    digitalWrite(IN3, LOW);
//    digitalWrite(IN4, LOW);
////    analogWrite(EN1,200);
////    analogWrite(EN2,200);
//}
void right()
{
    //    if (btVal == 6)
    //    {
    //        digitalWrite(IN1, HIGH);
    //        digitalWrite(IN2, LOW);
    //        digitalWrite(IN3, LOW);
    //        digitalWrite(IN4, LOW);
    //        autoMode(btVal);
    //    }
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
//    analogWrite(EN1,200);
//    analogWrite(EN2,200);
}
void stoprobot()
{
    //    if (btVal == 6)
    //    {
    //        digitalWrite(IN1, LOW);
    //        digitalWrite(IN2, LOW);
    //        digitalWrite(IN3, LOW);
    //        digitalWrite(IN4, LOW);
    //        autoMode(btVal);
    //    }
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
//    analogWrite(EN1,180);
//    analogWrite(EN2,180);
}

void forward_control(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN1,120);
    analogWrite(EN2,120);
    //delay(1000);
}
void reverse_control(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(EN1,120);
    analogWrite(EN2,120);
    //delay(1000);
}
void right_control(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN1,120);
    analogWrite(EN2,120);
    //delay(1000);
}
void left_control(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(EN1,120);
    analogWrite(EN2,120);
    //delay(1000);
    //stoprobot();
}
void stop_robot(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(EN1,120);
    analogWrite(EN2,120);
    //delay(1000); 
}
