#include <stdio.h>
#include <stdlib.h>

#define uint unsigned int

const uint max_x_coord = 8;
const uint max_y_coord = 8;
const uint len_CB = 16;
uint** place[max_x_coord][max_y_coord] = {[0 ... max_y_coord-1] = {[0 ... max_x_coord-1] = 0}}; // init zero array 8 * 8
uint* code_block[len_CB];
__uint16_t count;
typedef struct{
    uint x_pos;
    uint y_pos;
    uint amount_blocks;
    uint info;
} life;

void executor(life, uint);
void move(life, uint);
void drop(life, uint);
void info(life, uint);
void attack(life, uint);

int main(){
    life life;
    life.x_pos = 5;
    life.y_pos = 5;
    life.amount_blocks = 0;
    life.info = 0;
    while(count < len_CB){
        executor(life, code_block[count]);
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
void move(life life, uint way){

}