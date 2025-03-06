int LED1 = 25;
int LED2 = 26;
int knap1=33;
int microfon =39;
int buzzer=19;

int gamemode = 0;

int speed = 100;
byte rythem[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

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
 OS();

}

void OS() {
  if (touchRead(knap1) < 36) {gamemode++;}
  switch (gamemode%2){
    case 0:
    aimGame();
    break;

    case 1:
    rythemGame();
    break;

    default:
    break;
  }
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
for (int m = 0; m<2;m++){
  for (int i = 0;i<32;++i){
    if (i == 0){ digitalWrite(LED2, HIGH); tone(buzzer,400);}
    if (i == 0 && m==0){ digitalWrite(LED2, HIGH); tone(buzzer,1600);}
    if ( i == 8 || i == 16 || i == 24){ digitalWrite(LED2, HIGH); tone(buzzer,100);}
    if (rythem[i] == 1 ){
      digitalWrite(LED1, HIGH);
      tone(buzzer,800);

      for (int n = 0 ; n < speed; n++) {
        if (speed/2<n){ noTone(buzzer); digitalWrite(LED1, LOW); digitalWrite(LED2, LOW);}
        if (digitalRead(microfon)==HIGH) {rythem[i]=1; digitalWrite(LED1,HIGH);} else {digitalWrite(LED1,LOW);}
        delay(1);
        }
    } else {
      for (int n = 0 ; n < speed; n++) {
        if (speed/2<n){ noTone(buzzer); digitalWrite(LED2, LOW);}
        if (digitalRead(microfon)==HIGH) {rythem[i]=1; digitalWrite(LED1,HIGH);} else {digitalWrite(LED1,LOW);}
        delay(1);
        }
      }
    }
    if (m==1) {  for(int b = 0; b<32;++b){rythem[b]=0;}  }
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
