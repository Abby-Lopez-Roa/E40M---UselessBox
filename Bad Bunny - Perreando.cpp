int IN1 = 2;
int IN2 = 4;
int TOGGLE = 9;   // toggle switch 
int LIMIT  = 6;   // limit switch  

void forward() {          // arm OUT 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void back() {             // arm IN 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void stopM() {            // motor OFF
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(TOGGLE, INPUT_PULLUP);
  pinMode(LIMIT, INPUT_PULLUP);
  stopM();
}

void perreo() {

  for (int i = 0; i < 4; i++) {
    forward();
    delay(300);                      
    stopM();
    back();
    delay(200);
    stopM();

    forward();
    delay(200);                      
    stopM();
    back();
    delay(300);
    stopM();
  }

  forward();
  delay(500);                       
  stopM();
}

void loop() {
  // 1) Waits for user to flip toggle ON 
  if (digitalRead(TOGGLE) == HIGH) {
    delay(40);                       
  if (digitalRead(TOGGLE) != HIGH) return;
  //  2) Perrea (aka dances reggeaton) to Bad Bunny's "Eeo" song
  perreo();
  // 3) Goes down until limit switch is PRESSED, then stops
  while (digitalRead(LIMIT) == LOW) { 
      back();
  }
  stopM();
  }
}
