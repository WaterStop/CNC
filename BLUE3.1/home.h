


#ifndef HOME_H
#define HOME_H

#define MACHINE_ZERO_HIGH_SPEED_TYPE 0
#define MACHINE_ZERO_LOW_SPEED_TYPE 1





typedef enum 
{
  HOME_IDLE = 0,
  HOME_START,//判断回零状态
  HOME_G0_ZERO,//直接G0走到0位置
  HOME_HIGH_SPEED_SEARCH,//高速搜索回零开关
  HOME_FINISHED,//完成

  HOME_BEFORE,//档块前
  HOME_BEFORE_HIGH_STOP,//找到档块后立即停止
  HOME_BEFORE_REVERSE,//反向移动
  HOME_BEFORE_THROUGH_REVERSE,//穿越档块后的反向移动
  
  HOME_AFTER,//档块后
  HOME_AFTER_LOW_SPEED_SEARCH,//档块后低速模式


  
  HOME_SEARCH_MARK,//档块后找MARK点
  HOME_SEARCH_OFFSET//找偏移
} home_state_t;



extern int do_machine_zero(void);
extern int check_all_home_done(void);
extern void init_home(void);



#endif //HOME_H


