#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>

int main (int argc, char **argv)
{
    
    double b = 0.35;
    double r = 0.1;
    double v=1, w=0;
  
    // Start ROS within this mode
    ros::init(argc, argv, "controller");
    // Declaring node
    ros::NodeHandle node;
    // Declare topic to be published
    ros::Publisher pub_right = node.advertise<std_msgs::Float64>("/vrep/vehicle/motorRightSpeed", 1);
    
    ros::Publisher pub_left = node.advertise<std_msgs::Float64>("/vrep/vehicle/motorLeftSpeed", 1);
    
    //Define ROS loop_rate
    ros::Rate loop_rate(60);
    
    //Define Messages
    std_msgs::Float64 wl,wr;
    
    //ROS LOOP
    while(ros::ok())
    {
        //Computer wr and wl
        
        //Publish
          double Vr = v + (b/2)*w;
          double Vl = v - (b/2)*w;
         wr.data = Vr/r;
         wl.data = Vl/r;
            
         pub_right.publish(wr);
         pub_left.publish(wl);
         ros::spinOnce();
         loop_rate.sleep();
             
        
            
            /* msg.data = "Hello World!";
            ROS_INFO("Publishing...");*/
            
        }
        //ROS routines
        
   
        
        
    }