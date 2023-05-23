#ifndef GLOBAL_VARIABLE_H
#define GLOBAL_VARIABLE_H

#endif // GLOBAL_VARIABLE_H

#include<math.h>

#define G2 0
#define G3 1
#define PI2        6.2831853071795864 // 2*PI
#define PI         3.1415926535897932
#define PI1_5	   4.7123889803846899
#define PI0_5	   1.5707963267948966

#define OUTER_CIRCLE_ONE_X      305
#define OUTER_CIRCLE_ONE_Y      328

#define OUTER_CIRCLE_TWO_X      322
#define OUTER_CIRCLE_TWO_Y      335

#define OUTER_CIRCLE_THREE_X    302
#define OUTER_CIRCLE_THREE_Y    323

#define END_FACE_ONE_X          254
#define END_FACE_ONE_Y          325

#define END_FACE_TWO_X          205
#define END_FACE_TWO_Y          330

#define END_FACE_THREE_X        295
#define END_FACE_THREE_Y        215

#define INNER_HOLE_ONE_X        305
#define INNER_HOLE_ONE_Y        240

#define INNER_HOLE_TWO_X        306
#define INNER_HOLE_TWO_Y        240

#define INNER_HOLE_THREE_X      315
#define INNER_HOLE_THREE_Y      240

#define INNER_HOLE_FOUR_X       305
#define INNER_HOLE_FOUR_Y       240

#define INNER_HOLE_FIVE_X       320
#define INNER_HOLE_FIVE_Y       210

#define CONE_FACE_ONE_X         322
#define CONE_FACE_ONE_Y         355

#define CONE_FACE_TWO_X         320
#define CONE_FACE_TWO_Y         335

#define CONE_FACE_THREE_X       320
#define CONE_FACE_THREE_Y       295

#define CONE_FACE_FOUR_X        320
#define CONE_FACE_FOUR_Y        350

#define SCREW_THREAD_ONE_X      293
#define SCREW_THREAD_ONE_Y      308

#define SCREW_THREAD_TWO_X      317
#define SCREW_THREAD_TWO_Y      292

#define SCREW_THREAD_THREE_X    316
#define SCREW_THREAD_THREE_Y    215

#define SCREW_THREAD_FOUR_X     336
#define SCREW_THREAD_FOUR_Y     255

#define CHAMFER_ONE_X           295
#define CHAMFER_ONE_Y           326

#define CHAMFER_TWO_X           295
#define CHAMFER_TWO_Y           326

#define CHAMFER_THREE_X         305
#define CHAMFER_THREE_Y         235

#define CHAMFER_FOUR_X          305
#define CHAMFER_FOUR_Y          240



enum WOKE_TYPE
{
    OUTER_CIRCLE_ONE=1,//外圆
    OUTER_CIRCLE_TWO,
    OUTER_CIRCLE_THREE,
    END_FACE_ONE,
    END_FACE_TWO,
    END_FACE_THREE,
    INNER_HOLE_ONE,
    INNER_HOLE_TWO,
    INNER_HOLE_THREE,
    INNER_HOLE_FOUR,
    INNER_HOLE_FIVE,
    CONE_FACE_ONE,
    CONE_FACE_TWO,
    CONE_FACE_THREE,
    CONE_FACE_FOUR,
    SCREW_THREAD_ONE,
    SCREW_THREAD_TWO,
    SCREW_THREAD_THREE,
    SCREW_THREAD_FOUR,
    CHAMFER_ONE,
    CHAMFER_TWO,
    CHAMFER_THREE,
    CHAMFER_FOUR,
};
