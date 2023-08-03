int val_2, val_4;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    val_2 = digitalRead(2);
    val_4 = digitalRead(4);
    if (val_2 == val_4){
        digitalWrite(13, LOW);
    } else {
        digitalWrite(13, HIGH);
    }
}
