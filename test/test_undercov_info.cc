#include "undercov.h"
#include<iostream>

int main(){
    init_bitmap();
    std::cerr<<get_bb_cnt()<<"\n";
}