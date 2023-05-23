#ifndef __PARSE_SYNTAX_H__
#define __PARSE_SYNTAX_H__

#include "decode.h"
#define PI0_5       1.5707963267948966

extern int parse_syntax(struct parse_s* data2,struct accidence_data_s* data1);

extern void InitSyntaxData(struct parse_s *data) ;
extern void InitCutterData(struct CNC_CodeSegMent *data);

extern int ParseCutter(struct parse_s *data1,struct CNC_CodeSegMent *data2,struct temp_save_s *data3);


extern int GetCompensateLVal(struct temp_save_s *data3) ;

#endif //__PARSE_SYNTAX_H__
