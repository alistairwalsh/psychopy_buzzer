/*
  
*/

int ledPin1 = 11;
int ledPin2 = 12;
int firstTime = 0;
int secondTime = 0;
int waitTime = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  
  // initialize digital pin ledPin1 and ledPin2 as output.
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  establishContact();// send a byte to establish contact until receiver responds
}

// the loop function runs over and over again forever
void loop() {
  
  if (Serial.available() > 0) {
    // read the most recent string (which will be two values):
    firstTime = Serial.parseInt();
    Serial.println(firstTime);
    secondTime = Serial.parseInt();
    Serial.println(secondTime);
    waitTime = Serial.parseInt();
    Serial.println(waitTime);
    // flash leds:
    for (int i=0; i <= 4; i++){
      digitalWrite(ledPin1, HIGH);
      delay(50);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin1, LOW);
      delay(50);
      digitalWrite(ledPin2, LOW);
      }
  }
  else {
  digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(firstTime);                       // wait for a second
  digitalWrite(ledPin1, LOW);    // turn the LED off by making the voltage LOW
  delay(waitTime); 

  digitalWrite(ledPin2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(secondTime);                       // wait for a second
  digitalWrite(ledPin2, LOW);    // turn the LED off by making the voltage LOW
  delay(waitTime); // wait for a second
  

    
   }     
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
 
}
