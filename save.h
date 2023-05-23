#ifndef __SAVE_H__
#define __SAVE_H__

extern int save_int;
extern double save_double;
extern int save_num;//一共存储了多少个数据bit

extern int init_save(void);
extern void get_save_val_func(int num );
extern void save_func(int num);

#endif //__SAVE_H__



