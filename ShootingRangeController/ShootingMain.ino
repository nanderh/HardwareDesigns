

int goButton1 = 2;
int stopButton1 = 3;
int forwardDrive1 = 9;
int backwardDrive1 = 8;
int targetFront1 = 4;
int targetBack1 = 5;

int goButton1Check = 0;
int stopButton1Check = 0;
int targetFront1Check = 1;
int targetBack1Check = 0;
int forwardDrive1Check = 0;
int backwardDrive1Check = 0;

int stopped = 0;


void setup() {
  pinMode(goButton1, INPUT);
  pinMode(stopButton1, INPUT);
  pinMode(targetFront1, INPUT);
  pinMode(targetBack1, INPUT);
  pinMode(forwardDrive1, OUTPUT);
  pinMode(backwardDrive1, OUTPUT);

}

void loop() {
  
  goButton1Check = digitalRead(goButton1);
  if (goButton1Check == 1) {
    //If target is in the front move it back
    if (targetFront1Check == 1) {
      digitalWrite(backwardDrive1, HIGH);
      backwardDrive1Check = 1;
      targetFront1Check = 0;
    }
    //If target is in back move in front
    if (targetBack1Check == 1) {
      digitalWrite(forwardDrive1, HIGH);
      forwardDrive1Check = 1;
      targetBack1Check = 0;
    }
    if (stopped == 1) {
      digitalWrite(forwardDrive1, HIGH);
      forwardDrive1Check = 1;
      stopped = 0;
    }
  }
  
  
  
  
  if (backwardDrive1Check == 1) {
    targetBack1Check = digitalRead(targetBack1);
    if (targetBack1Check == 1) {
      digitalWrite(backwardDrive1, LOW);
      backwardDrive1Check = 0;
    }
  }
  
  if (forwardDrive1Check == 1) {
    targetFront1Check = digitalRead(targetFront1);
    if (targetFront1Check == 1) {
      digitalWrite(forwardDrive1, LOW);
      forwardDrive1Check = 0;
    }
  }
  
  stopButton1Check = digitalRead(stopButton1);
  if (stopButton1Check == 1) {
    digitalWrite(forwardDrive1, LOW);
    digitalWrite(backwardDrive1, LOW);
    forwardDrive1Check = 0;
    backwardDrive1Check = 0;
    stopped = 1;
  }
  
}
