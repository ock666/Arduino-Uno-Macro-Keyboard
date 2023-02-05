//Define the pins you have assigned to your buttons.
#define BUTTON_1 13
#define BUTTON_2 12
#define BUTTON_3 11
#define BUTTON_4 10
#define BUTTON_5 9

// define keys you will use for your shortcuts
// Note from ock666: in the keyboard sheet which lays out the number codes for all the different keys, it states ctrl is 227
// however when I used that config with a linux machine the functions did not work, in the original project that this one is based off
// the author also used 1 instead of 227. If you have problems getting functions that use KEY_LEFT_CTRL to work try changing this variable to either 1 or 227.

#define KEY_LEFT_CTRL 1   //left ctrl
#define KEY_ESC 41        //escape
#define KEY_F9 66         //F9 key
#define KEY_F11 68        //F11 key
#define KEY_T 23          //t key
#define KEY_V 25          //letter V
#define KEY_C 6           //letter c

// define your rgb LED pins
const int PIN_RED = 5;
const int PIN_GREEN = 6;
const int PIN_BLUE = 7;

//buffer to store the keypress
uint8_t buf[8] = { 0 };


void setup() {

  Serial.begin(9600);
  //Define the pinMode for each pin.
  pinMode(13, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  //Define RGB pinMode
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);

  //Sets the value of the pin on start up.
  digitalWrite(BUTTON_1, HIGH);
  digitalWrite(BUTTON_2, HIGH);
  digitalWrite(BUTTON_3, HIGH);
  digitalWrite(BUTTON_4, HIGH);
  digitalWrite(BUTTON_5, HIGH);

  delay(200);  //Wait before continuing on with the code.
  setColor(52, 168, 83); //once the LED lights up you know setup has completed
}

void loop() {
  byte button1_State = digitalRead(BUTTON_1);
  if (button1_State == LOW) {
    //Serial.println("Button 1 is pressed"); //serial printin to debug buttons, comment this out once you've confirmed your buttons work
    setColor(85, 155, 76);
    buf[0] = KEY_LEFT_CTRL;  //Presses ctrl key.
    buf[2] = KEY_C;          //Presses C key.
    Serial.write(buf, 8);    //Sends Keypress.
    releaseKey();            //Calls the releaseKey method.
  }

  byte button2_State = digitalRead(BUTTON_2);
  if (button2_State == LOW) {
    //Serial.println("Button 2 is pressed"); //serial printin to debug buttons, comment this out once you've confirmed your buttons work
    setColor(145, 212, 138);
    buf[0] = KEY_LEFT_CTRL;  //Presses ctrl key.
    buf[2] = KEY_V;          //Presses V key.
    Serial.write(buf, 8);    //Sends Keypress.
    releaseKey();            //Calls the releaseKey method.
  }

  byte button3_State = digitalRead(BUTTON_3);
  if (button3_State == LOW) {
    //Serial.println("Button 3 is pressed"); //serial printin to debug buttons, comment this out once you've confirmed your buttons work
    setColor(247, 120, 138);
    buf[0] = KEY_LEFT_CTRL;  //Presses ctrl key.
    buf[2] = KEY_F9;         //Presses F9 key.
    Serial.write(buf, 8);    //Sends Keypress.
    releaseKey();            //Calls the releaseKey method.
  }

  byte button4_State = digitalRead(BUTTON_4);
  if (button4_State == LOW) {
    //Serial.println("Button 4 is pressed"); //serial printin to debug buttons, comment this out once you've confirmed your buttons work
    setColor(0, 201, 204);
    buf[0] = KEY_LEFT_CTRL;  //Presses ctrl key.
    buf[2] = KEY_ESC;        //Presses ESC key.
    Serial.write(buf, 8);    //Sends Keypress.
    releaseKey();            //Calls the releaseKey method.
  }

  byte button5_State = digitalRead(BUTTON_5);
  if (button5_State == LOW) {
    //Serial.println("Button 5 is pressed"); //serial printin to debug buttons, comment this out once you've confirmed your buttons work
    setColor(52, 168, 83);
    buf[0] = KEY_LEFT_CTRL;  //Presses ctrl key.
    buf[2] = KEY_F11;          //Presses f11 key.
    Serial.write(buf, 8);    //Sends Keypress.
    releaseKey();            //Calls the releaseKey method.
  }
}

// function to set the led rgb values
void setColor(int R, int G, int B) {
  analogWrite(PIN_RED, R);
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE, B);
}

//Function used to release keys.
void releaseKey() {
  buf[0] = 0;            //Resets number.
  buf[2] = 0;            //Resets number.
  Serial.write(buf, 8);  //Release key.
  delay(200);
}