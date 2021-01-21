

/* 
 * rosserial Subscriber for dc motors
 * Runs an dc motors on callback
 */

#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

void messageCb(const std_msgs::UInt16& cmd_msg){
  
  if (cmd_msg.data == 1) {
    goForward();
    }
  if (cmd_msg.data == 2) {
    Stop();
    }
  if (cmd_msg.data == 3) {
    goRight();
    }
  if (cmd_msg.data == 4) {
    goLeft();
    }
  
}

ros::Subscriber<std_msgs::UInt16> sub("dc_motors", &messageCb );


void goForward(){
  digitalWrite(2, HIGH-digitalRead(2));
  digitalWrite(5, HIGH-digitalRead(5));
}

void Stop(){
  digitalWrite(13, HIGH-digitalRead(13));

  digitalWrite(2, LOW-digitalRead(2));
  digitalWrite(5, LOW-digitalRead(5));
  digitalWrite(4, LOW-digitalRead(2));
  digitalWrite(3, LOW-digitalRead(5));
}

void goRight(){
  digitalWrite(2, HIGH-digitalRead(2));
  
}

void goLeft(){
  digitalWrite(5, HIGH-digitalRead(5));
  
}





void setup()
{ 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
