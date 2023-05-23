
#ifndef TCQ_H
#define TCQ_H

#include "tp.h"










extern int tcq_create(struct tcq_struct *  tcq, int _size);
extern int tcq_init(struct tcq_struct  *  tcq);
extern int tcq_put(struct tcq_struct  *  tcq, struct tc_struct  *  tc);
extern struct tc_struct * tcq_item(struct tcq_struct  *  tcq, int n);

extern int tcq_pop(struct tcq_struct *  tcq);
extern int tcq_full(struct tcq_struct *  tcq);
extern int tcq_back_step(struct tcq_struct *  tcq);








#endif //TCQ_H

