#ifndef TC_H
#define TC_H

#include "tp.h"










extern double fmax(double __y, double __x) ;
extern double fmin(double __y, double __x) ;
extern int pos_sub(double *a,double *b,double *out);
extern int pos_add(double *a,double *b,double *out);
extern int pos_equ(double *a,double *b);
extern int pos_abs(double *a);
extern int pos_set_zeor(double *a);
extern double tc_get_target(struct tc_struct *  tc, int direction);
extern double tc_get_distance_to_go(struct tc_struct *  tc, int direction);
extern int tc_get_pos_real(struct tc_struct *  tc, int of_point,double * pos,int reverse);
extern int tc_pre_data_handle_g0(struct tp_struct *  tp, struct tc_struct *  tc);
extern int tc_pre_data_handle_g1(struct tp_struct *  tp, struct tc_struct *  tc);
extern int tc_pre_data_handle_g2g3(struct tp_struct *  tp, struct tc_struct *  tc);
extern int tc_pre_data_handle_rigidtap(struct tp_struct *  tp, struct tc_struct *  tc);
extern int tc_pre_data_handle_screw(struct tp_struct *  tp, struct tc_struct *  tc);
extern int tc_pre_data_handle_mac_home(struct tp_struct *  tp, struct tc_struct *  tc);
extern int tc_pre_data_handle_pro_home(struct tp_struct *  tp, struct tc_struct *  tc);
















#endif //TC_H
