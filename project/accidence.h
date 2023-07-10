#ifndef __ACCIDENCE_H__
#define __ACCIDENCE_H__

#include "decode.h"






extern struct accidence_data_s accidence_data;
extern struct accidence_status_s accidence_status;






extern int read_real_number(char* line_buf, int* line_pos, double* ret_num);
extern int read_real_value(char* line_buf, int* line_pos, double* value);
extern void init_accidence_status();
extern int accidence(void);
extern int out_accidence_queue(struct accidence_data_s* data);
extern int in_accidence_queue(struct accidence_data_s* data);

extern int accidence_q_item(struct accidence_data_s* data);
extern int accidence_q_size_add(void);

extern int clear_accidence_queue();

extern int init_accidence_queue();
extern void InitAccidenceData();



extern int accidence_q_is_empty(void) ;

extern void CNCWarning(int no);
extern int check_MST_done_flag(void);
extern int check_move_mode_queue_empty(void);
extern int decode_is_start(void);
extern int accidence_q_is_empty(void);
extern int is_MST_done(void);

extern int  GetIndexByLine(int iLine);


#endif //__ACCIDENCE_H__
