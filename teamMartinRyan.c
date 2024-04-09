#include <kipr/wombat.h>

void start();
void shake();

int main()
{
    create_connect();
    enable_servos();

    set_create_distance(0);
    set_create_total_angle(0);

    start();
    msleep(1000);

    while (get_create_distance() < 593)
    {
        create_drive_direct(200,200);
    }
    create_stop();

    msleep(5000);

    shake();

    while (get_create_lbump() == 0 && get_create_rbump() == 0){
        create_drive_direct(100,100);
    }

    int x;
    for(x = 850; x <= 1200; x++)
    {
        set_servo_position(2,x);
        msleep(5);
    }

    set_servo_position(1,2047);
    shake();
    set_servo_position(1,0);

    create_drive_direct(-100,100);
    msleep(100);
    
    set_servo_position(1,2047);
    shake();

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