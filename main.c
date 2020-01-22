#include <stdio.h>
#include <stdlib.h>

#define uint unsigned
#define max_x_coord 8
#define max_y_coord 8
#define len_CB 16

typedef struct{
    uint x;
    uint y;
    uint amount_blocks;
    uint info;          // result function info()
} life;

void executor(life, uint);
void move(life, uint);
void drop(life, uint);
void info(life, uint);
void attack(life, uint);

int main(){
    uint place[max_y_coord][max_x_coord] = {[0 ... max_y_coord-1] = {[0 ... max_x_coord-1] = 0}}; // init zero array 8 * 8
    uint code_block[len_CB] = {[0 ... len_CB-1] = 0};
    register __uint16_t count;

    life lifes[5];
    lifes[0].x = 5;
    lifes[0].y = 5;
    lifes[0].amount_blocks = 0;
    lifes[0].info = 0;
    while(count < len_CB){
        executor(lifes[0], code_block[count]);
        count++;
    }
    return 0;
}
void executor(life life, uint num_code){
    switch (num_code){
        case 0 ... 7:{
            move(life, num_code);
            break;
        }
        case 8 ... 15:{
            drop(life, num_code%8);
            break;
        }
        case 16 ... 23:{
            info(life, num_code%8);
            break;
        }
        case 24 ... 32:{
            attack(life, num_code % 8);
            break;
        }
        default:{
            printf("Error code number");
            exit(1);
        }
    }
}
void move(life life, uint direction){

}
void drop(life life, uint direction){

}
void info(life life, uint direction){

}
void attack(life life, uint direction){

}