#include <kipr/wombat.h>

void start();
void shake();

int main()
{
    //this enables the servos and the code to connect to the roomba
    create_connect();
    enable_servos();

    //this sets the distance and total angle to 0 every time the code runs
    set_create_distance(0);
    set_create_total_angle(0);

    start(); // start program
    msleep(1000); // pause for a second

    while (get_create_distance() < 593) // move to drop
    {
        create_drive_direct(200,200);
    }
    create_stop();

    msleep(5000); // pause for 5 seconds

    shake(); // shake to make sure noodles are properly in place

    while (get_create_lbump() == 0 && get_create_rbump() == 0){ // move to lava tube zone
        create_drive_direct(100,100);
    }

    // lower arm
    int x;
    for(x = 850; x <= 1200; x++)
    {
        set_servo_position(2,x);
        msleep(5);
    }

    // drop first noodle
    set_servo_position(1,2047);
    shake();
    set_servo_position(1,0);

    create_drive_direct(-100,100);
    msleep(100);
	//this turns to the one next to the tube in the corner
    
    set_servo_position(1,2047);
    shake();
    //this allows it so that it properly drops it into the tube

    create_stop();
    create_disconnect();
    return 0;
}

void start()
{
    int x;
    set_servo_position(3,1841);
    for (x = 0; x < 1400; x++)
    {
        set_servo_position(2,x);
        msleep(2);
    }
}
//this function sets the servo starting positions

void shake(){ 
    int x;
    for (x = 0; x < 5; x++){
        create_drive_direct(300,-300);
        msleep(20);
        create_drive_direct(-300,300);
        msleep(20);
        create_stop();
        msleep(50);
    }
}
//this function makes it so that the robot shakes so that the purple pool noodle goes in