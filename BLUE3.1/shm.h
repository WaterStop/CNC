
#ifndef SHM_H
#define SHM_H

#ifdef __cplusplus
extern "C" {
#endif
/* 未使用这种形式的共享内存
extern char * shm_mbuff_alloc(char * name,int size,int flag);
extern void shm_mbuff_free(char * name, void * shm_p,  int flag);
*/

/*
运动共享内存
*/
extern int share_motion_status(int need_init);
extern int share_motion_internal(int need_init);

/*
PLC共享内存    
*/
extern int share_plc_shm(int need_init);

/*
解释器共享内存
*/
int share_decode_status(int need_init);

/*
公用共享内存    
*/
extern int share_command(int need_init);
extern int share_motion_err(int need_init);
extern int share_warn(int need_init);


extern int shm_init(void);

#ifdef __cplusplus
}
#endif


#endif //SHM_H

