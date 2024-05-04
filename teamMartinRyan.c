#include <kipr/wombat.h> 

void start();
void shake1();
void shake2();

int main()
{
    shut_down_in(119);
    //this enables the servos and the code to connect to the roomba
    create_connect();
    enable_servos();
    msleep(1000);
    //this sets the distance and total angle to 0 every time the code runs
    set_create_distance(0);
    set_create_total_angle(0); 

    start(); // start program
    msleep(1000); // pause for a second

    //shake2();
    while (get_create_distance() < 550) // move to drop
    {
        create_drive_direct(175,200);
    }
    create_stop();
    
    msleep(500);
    
    while(digital(0) == 0){
        create_drive_direct(100,0);
    }
    create_stop();
    
    msleep(200);
    
    create_drive_direct(-100,-100); // back up
    msleep(200);
    create_stop();
    msleep(500);

    msleep(5000); // pause for 5 seconds

    shake1(); // shake to make sure noodles are properly in place
    
    create_drive_direct(0,100);
    msleep(800);
    
    create_drive_direct(100,100);
    msleep(3000);
    
    set_servo_position(2,1250);
    
    while (get_create_lbump() == 0 && get_create_rbump() == 0){ // turn left
        create_drive_direct(200,100);
    }
    create_stop();
    msleep(500);
    
    int x;
    for(x = 1250; x >= 1000; x--)
    {
        set_servo_position(2,x);
        msleep(5);
    }
    
    msleep(500);
    
    create_drive_direct(-100,100); // turn right
    msleep(900);
    create_stop();
    
    create_drive_direct(125,100); // move away from wall
    msleep(400);
    
    while (get_create_lbump() == 0 && get_create_rbump() == 0){ // move to lava tube zone
        create_drive_direct(100,100);
    }
    create_stop();
    msleep(500);
    
    create_drive_direct(-100,-100); // back up
    msleep(100);
    create_stop();
    
    set_servo_position(2,1300);
    msleep(500);
    
    while (digital(0) == 0){
    	create_drive_direct(50,-50); // turn left
    }
    create_stop();
	msleep(500);
    
    set_servo_position(2,1000);
    msleep(500);
    
    create_drive_direct(50,-50);
    msleep(200);
    create_stop();
    
    msleep(500);
    
    set_servo_position(1,2047); // drop first noodle
    msleep(500);
    create_drive_direct(50,-50);
    msleep(150);
    create_stop();
    msleep(1000);
    
    shake2(); // shake to make sure it drops properly
    msleep(500);
    
    set_servo_position(1,500); // catch second noodle
    msleep(700);
    
    set_servo_position(2,900);
    msleep(500);

    create_drive_direct(-75,75); // turn right
    msleep(800);
    create_stop();
    
    set_servo_position(2,1200);
    msleep(500);
    
    while (digital(0) == 0){
    	create_drive_direct(50,-50); // turn left
    }
    create_stop();
    msleep(500);
   	
    set_servo_position(2,1000);
    msleep(500);
    
    create_drive_direct(50,-50);
    msleep(100);
    create_stop();
   	msleep(500); 
   
    set_servo_position(2,1100);
    msleep(500);
    set_servo_position(1,2047); // drop second noodle
    msleep(500);
    create_drive_direct(-100,-100);
    msleep(300);
    create_stop();
    msleep(300);
    shake2();
    msleep(500);
    
    set_servo_position(2,500);
    msleep(500);

    create_stop();
    create_disconnect();
    return 0;
}

void start()
{   
    int x;
    set_servo_position(3,1841);
    for (x = 0; x < 1250; x++)
    {
        set_servo_position(2,x);
        msleep(2);
    }
    set_servo_position(1,1000);
    
    msleep(500);
    /*while (get_create_rbump() == 0){
        create_drive_direct(100,-100);
    }*/
    create_drive_direct(100,-100);
    msleep(1000);
    create_stop();
}

//this function makes it so that the robot shakes so that the purple pool noodle goes in
void shake1(){ 
    int x;
    for (x = 0; x < 5; x++){
        create_drive_direct(300,-300);
        msleep(30);
        create_drive_direct(-300,-300);
        msleep(30);
        create_drive_direct(-300,300);
        msleep(30);
        create_drive_direct(300,300);
        msleep(30);
        create_stop();
        msleep(50);
    }
}

void shake2(){
    int x, y;
    for (x = 0; x < 5; x++){
        for (y = 1000; y > 900; y--){
        	set_servo_position(2,y);
        	msleep(1);
    	}
        for (y = 900; y < 1000; y++){
        	set_servo_position(2,y);
        	msleep(1);
    	}
        msleep(10);
    }
}
