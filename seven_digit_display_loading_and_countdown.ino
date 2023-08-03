void setup() {
  for (int i = 2; i < 8; i++){
    pinMode(i, OUTPUT);
  }


}

void loop() {
  for (int i = 0; i < 5; i++){
    for (int j = 3; j < 8; j++){
        digitalWrite(j, HIGH);
        delay(50);
        digitalWrite(j, LOW);
        delay(50);
    }
  }
  for (int i = 0; i < 8; i++){
    digitalWrite(i, LOW);  
  }
  for (int i = 0; i < 10; i++){
    if (i == 0){
      for (int j = 2; j < 8; j++){
        digitalWrite(j, HIGH);  
      }  
    }
    else if (i == 1){
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);  
    }
    else if (i == 2){
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(7, HIGH);
    }
    else if (i == 3){
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);  
    }
    else if (i == 4){
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(6, HIGH);  
    }
    else if (i == 5){
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);  
    }
    else if (i == 6){
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);  
    }
    else if (i == 7){
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);  
    }
    else if (i == 8){
      for (int j = 3; j < 8; j++){
        digitalWrite(j, HIGH);  
      } 
    }
    else if (i == 9){
      for (int j = 2; j < 8; j++){
        digitalWrite(j, HIGH);  
      }  
    }
    delay(1000);
    for (int j = 2; j < 8; j++){
     digitalWrite(j, LOW); 
     }
  }
}
