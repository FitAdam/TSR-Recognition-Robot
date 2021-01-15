

/* 
 * rosserial Subscriber for dc motors
 * Runs an dc motors on callback
 */

#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

void messageCb(const std_msgs::UInt16& cmd_msg){
  
  if (cmd_msg.data == 1) {
    goForward();
    }
  if (cmd_msg.data == 2) {
    goBack();
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

void goBack(){
  digitalWrite(3, HIGH-digitalRead(3));
  digitalWrite(4, HIGH-digitalRead(4));
}

void goRight(){
  digitalWrite(2, HIGH-digitalRead(2));
  digitalWrite(4, HIGH-digitalRead(4));
}

void goLeft(){
  digitalWrite(5, HIGH-digitalRead(5));
  digitalWrite(4, HIGH-digitalRead(4));
}





void setup()
{ 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
