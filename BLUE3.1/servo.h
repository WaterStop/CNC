#ifndef SERVO_H
#define SERVO_H

#include "motion.h"

//#include "miii_def.h"

//#include "miii_glb.h"

#define SERVO_Q_SIZE 12


extern struct servo_q_s servo_q;

struct servo_data_s
{
    int axis[MAX_AXIS_NUM];  // 各个轴的脉冲输出 轴顺序0-X 1-Z 2-Y 3-4TH 4-5TH
    int s[MAX_SPIND_NUM];    //主轴的位置
};


struct servo_q_s
{
    struct servo_data_s data[SERVO_Q_SIZE];   
    int start;        
    int end;            
    int num;            
};

extern void init_servo_q(void);

extern int cheek_servo_ready(void);
extern void servo_out(void);
extern int servo_data_IsFull(struct servo_q_s *mydata);
extern void servo_data_put(struct servo_q_s *mydata, struct servo_data_s *msg);
extern int servo_data_get(struct servo_q_s *mydata, struct servo_data_s *msg);
extern void fill_axis_motor_data(int pulse,int type,int addr);
extern void fill_spind_motor_data(int pulse,int type,int addr,int mode);

extern int get_axis_station(int axis_id);
extern int getM3SpindleStation(int num);
extern void spindleStop(int st);
extern void spindleRun(int st, long refSpeed);





#endif //SERVO_H
