int LED1 = 25;
int LED2 = 26;
int knap1=36;
int microfon =39;
int buzzer=19;

int speed = 400;
byte rythem[8] = {0,0,0,0,0,0,0,0};

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(knap1, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(microfon, INPUT);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:


}

void OS{
  
}


void aimGame() {
  digitalWrite(LED1,LOW);
  int pause = random(1000, 5000);
  int vindu = random(3000, 6000);

  for (int i = 1 ; i < pause; i++) {
    if (digitalRead(microfon)==HIGH) {SFX(1);}
    delay(1);
  }

  long tid = millis();
  while (millis()-tid < vindu) {
    if ((millis()-tid)%100 == 1) {digitalWrite(LED1,HIGH);} else if ((millis()-tid)%100 == 50) {digitalWrite(LED1,LOW);}
    if (digitalRead(microfon) == HIGH) { digitalWrite(LED2,HIGH); SFX(0); delay(500); {digitalWrite(LED2,LOW); break;}
  }
}
}

void rythemGame() {
  for (int i = 0;i<8;++i){
    if (i == 0){ digitalWrite(LED2, HIGH); tone(buzzer,400);}
    if ( i == 2 || i == 4 || i == 6){ digitalWrite(LED2, HIGH); tone(buzzer,600);}
    if (rythem[i] == 1 ){
      digitalWrite(LED1, HIGH);
      if (i == 2 || i == 4 || i == 6){ tone(buzzer,600); } else if(i == 0) {tone(buzzer,400);} else{ tone(buzzer,800); }

      for (int i = 0 ; i < speed; i++) {
        if (speed/2<i){ noTone(buzzer); digitalWrite(LED1, LOW); digitalWrite(LED2, LOW);}
        delay(1);
        }
    } else {
      for (int i = 0 ; i < speed; i++) {
        if (speed/2<i){ noTone(buzzer); digitalWrite(LED2, LOW);}
        delay(1);
        }
      }
  }
}

void SFX(int index){
  switch (index) {
    case 0: //win
    tone(buzzer,261);
    delay(100);
    tone(buzzer,349);
    delay(100);
    tone(buzzer,220);
    delay(100);
    tone(buzzer,174);
    delay(100);
    tone(buzzer,261);
    delay(400);
    noTone(buzzer);
    break;
    case 1: //lose
    tone(buzzer,261);
    delay(200);
    tone(buzzer,277);
    delay(200);
    tone(buzzer,220);
    delay(200);
    tone(buzzer,155);
    delay(200);
    tone(buzzer,138);
    delay(400);
    noTone(buzzer);

    break;

    default:
    break;
  }

}