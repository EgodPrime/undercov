#ifndef _UNDERCOV_H_
#define _UNDERCOV_H_
const int shm_key = 4399;
const unsigned int bitmap_size = 1<<28;
const unsigned int bytemap_size = bitmap_size/8;

extern "C" void on_bb_hit(unsigned int bb_idx);

extern "C" void init_bitmap();
extern "C" void close_bitmap();
extern "C" unsigned int get_bb_cnt();
#endif