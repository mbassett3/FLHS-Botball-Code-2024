#include <kipr/wombat.h> 
// ryans not coding with his head

void start();
void shake1();
void shake2();
void raise();

int main()
{
    shut_down_in(119);
    // enable the servos and the code to connect to the roomba
    create_connect();
    enable_servos();
    msleep(1000);
    // set the distance and total angle to 0 every time the code runs
    set_create_distance(0);
    set_create_total_angle(0); 

    start(); // start program
    msleep(1000); // pause for a second

    //*************************************************************************
    // move to the drop
    while (get_create_distance() < 550) // drive set distance
    {
        create_drive_direct(175,200);
    }
    create_stop();
    msleep(500);
    while(digital(0) == 0){ // turn right until sensor is triggered by drop
        create_drive_direct(100,0);
    }
    create_stop();
    msleep(200);

    create_drive_direct(-100,-100); // back up
    msleep(100); // value to be adjusted for backing up
    create_stop();
    msleep(500);


//*****************************************************************************
    // catch pool noodles 
    msleep(5000); // pause for 5 seconds
    shake1(); // shake to make sure noodles are properly in place

    //*************************************************************************
    // move away from drop    
    create_drive_direct(0,100); // slightly turn
    msleep(500);
    create_drive_direct(100,100); // move forward
    msleep(3000);
    set_servo_position(2,1250); // slightly raise arm
    while (get_create_lbump() == 0 && get_create_rbump() == 0){ // turn left
        create_drive_direct(200,100);
    }
    create_stop();
    msleep(500);

    //*************************************************************************
    // move towards the lava tubes
    int x;
    for(x = 1250; x >= 1000; x--) // lower arm
    {
        set_servo_position(2,x);
        msleep(5);
    }
    msleep(500);
    create_drive_direct(-100,100); // turn right
    msleep(850);
    create_stop();
    create_drive_direct(125,100); // move away from wall
    msleep(300);
    while (get_create_lbump() == 0 && get_create_rbump() == 0){ // move to lava tube zone
        create_drive_direct(100,100);
    }
    create_stop();
    msleep(500);
    create_drive_direct(-100,-100); // back up
    msleep(100);
    create_stop();

    //*************************************************************************
    // drop first pool noodle
    set_servo_position(2,1300); // lower arm
    msleep(500);
    while (digital(0) == 0){
        create_drive_direct(50,-50); // turn left until sensor is tripped
    }
    create_stop();
    msleep(1000);
    raise(); // slowly raise arm
    msleep(500);
    set_servo_position(1,2047); // open mini servo to drop first noodle
    msleep(500);
    create_drive_direct(50,-50); // slightly adjust direction
    msleep(150);
    create_stop();
    msleep(1000);
    shake2(); // shake to make sure it drops properly
    msleep(500);
 
    //*************************************************************************
    // drop first pool noodle
    set_servo_position(1,500); // catch second noodle with mini servo
    msleep(700);
    set_servo_position(2,900); // raise arm
    msleep(500);
    create_drive_direct(-75,75); // turn right
    msleep(800);
    create_stop();
    set_servo_position(2,1200); // lower arm
    msleep(500);
    while (digital(0) == 0){
        create_drive_direct(30,-30); // turn left until sensor is tripped again
    }
    create_stop();
    msleep(500);
    raise(); // slowly raise arm
    msleep(500);
    create_drive_direct(-50,50); // slightly turn right
    msleep(100);
    create_stop();
    msleep(500); 
    set_servo_position(1,2047); // open mini servo to drop second noodle
    msleep(500);
    create_drive_direct(-100,-100); // back up to drop into lava tube
    msleep(300);
    create_stop();
    msleep(300);
    shake2(); // shake to make sure it drops properly
    msleep(500);
    set_servo_position(2,500); // raise arm
    msleep(500);

    create_stop();
    create_disconnect();
    return 0;
}

// starting sequence - preset servo positions and move out of starting box
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

    create_drive_direct(50,-50);
    msleep(1500);
    create_stop();
}

// moves the robot around to shake the pool noodles
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

// moves the arm up and down to shake the pool noodles
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

// slowly raises the arm
void raise(){
    int x;
    for (x = 1300; x > 1100; x--){
        set_servo_position(2,x);
        msleep(2);
    }
}
