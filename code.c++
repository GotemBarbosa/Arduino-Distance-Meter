//desenvolvido por Gabriel Barbosa

//Ultrassonico
int trig = 12;
int echo = 11;

//controle
int a;
int b;
int c;
int d;
int parteInteira;
int parteFracionaria;
int displayshow;
int i = 0;

//distancia e tempo
float dist;
float distM;
double temp;


void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
  Serial.begin(9600);
}

void pulso (){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  
  temp = pulseIn(echo, HIGH);
}

void v0(){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
}
void v1(){
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
}
void v2(){
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
}
void v3(){
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
}
void v4(){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
}
void v5(){
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
}
void v6(){
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
}
void v7(){
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
}
void v8(){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
}
void v9(){
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
}
void display1Config(){
    a = 10;
    b = 9;
    c = 0;
    d = 0;
}

void display2Config(){
    a = 8;
    b = 7;
    c = 6;
    d = 5;
}

void selectDisplay(){
    if (i == 0){
        displayshow = parteInteira;
        display1Config();
        i++;
        delayMicroseconds(10);
    }else {
        if ( i == 1){
            displayshow = parteFracionaria;
            display2Config();
            i = i - 1;
        }
    }
}


void display(){

    selectDisplay();
    
    switch (displayshow){
        

        case 0:
            v0();
        break;

        case 1:
            v1();
        break;

        case 2:
            v2();
        break;

        case 3:
            v3();
        break;

        case 4:
            v4();
        break;

        case 5:
            v5();
        break;

        case 6:
            v6();
        break;

        case 7:
            v7();
        break;

        case 8:
            v8();
        break;
        case 9:
            v8();
        break;

    }
}


void distancia(){
  
  pulso();
  
  dist = temp * 0.0347/2;
  distM = dist /100; 

  parteInteira = (int)distM; 
  parteFracionaria = (distM - parteInteira) * 10;
  
  Serial.print("Distancia:");
  Serial.println(distM);
}

void loop()
{
  distancia();
  display();
}




/*

0 0 0 1
0 0 1 0
0 0 1 0

*/

