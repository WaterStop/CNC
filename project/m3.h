
#ifndef M3_H
#define M3_H

#include <time.h>
#include "config.h"



#define    MON_APOS        0x00        /* Feedback position in the machine coordinate system */
#define    MON_MPOS        0x01        /* Reference position in the machine coordinate system */
#define    MON_PERR        0x02        /* Position error */
#define    MON_LPOS1        0x03        /* Feedback latch position in the machine coordinate system */
#define    MON_LPOS2        0x04

#define    MON_FSPD        0x05        /* Feedback speed */
#define    MON_CSPD        0x06        /* Reference speed */
#define    MON_TRQ         0x07        /* Reference torque */
#define    MON_ALARM     0x08        /* Detailed Information on the Current Alarm */

#define    MON_CMN1        0x0C        /* Selects the monitor data specified at common parameter 89. */
#define    MON_CMN2        0x0D        /* Selects the monitor data specified at common parameter 8A. */
#define    MON_OMN1        0x0E        /* Selects the monitor data specified by parameter */
#define    MON_OMN2        0x0F        /* Selects the monitor data specified by parameter */


enum
{
    cNOP = 0x00,                
    cPRM_RD,                 
    cPRM_WR,                   
    cID_RD=0x03,            
    cCONFIG,                   
    cALM_RD,                
    cALM_CLR,                 
    cSYNC_SET = 0x0d,            
    cCONNECT,                
    cDISCONNECT,            
    cPPRM_RD = 0x1b,        
    cPPRM_WR,                   
    cMEM_RD = 0x1d,                
    cMEM_WR,
    cPOS_SET = 0x20,            
    cBRK_ON,                
    cBRK_OFF,                
    cSENS_ON,                
    cSENS_OFF,                
    cSMON = 0x30,            
    cSV_ON,                    
    cSV_OFF,                    
    cINTERPOLATE = 0x34,    
    cPOSING,                
    cFEED,                    
    cEX_FEED,
    //cLATCH,                    
    cEX_POSING=0x39,        
    cZRET,                    
    cVELCTRL = 0x3C,            
    cTRQCTRL,                
    //cADJ,                        
    //cSVCTRL,                
    //cDATA_RWA = 0x50,            
    //cDATA_RWS            
    cSVPRM_RD=0x40,
    cSVPRM_WR=0x41,
    cZPOSING = 0xCA //LZ ADD 20211110 配合超同步做的CA快速定位指令
};

typedef enum E_MST_STATE
{
    MST_Start,
    MST_WaitSlaves,
    MST_Disconnect,
    MST_WaitDisconnect,
    MST_Connect,
    MST_WaitConnect,
    MST_ReadID,
    MST_WaitReadID,
    MST_EnterSync,
    MST_WaitEnterSync,
    MST_Synced,
    MST_Error,
    MST_ClrAlm,
    MST_WaitClrAlm
}MST_STATE;

typedef enum E_SLV_RUN_STATE
{
    SLVRUN_SensorOn,
    SLVRUN_WaitSensorOn,
    SLVRUN_WaitForSonReq,
    SLVRUN_ServoOn,
    SLVRUN_ClearAlm,
    SLVRUN_WaitServoOn,
    SLVRUN_WaitFeedBack,
    SLVRUN_ServoOff,
    SLVRUN_WaitServoOff,
    SLVRUN_Feeding,
    SLVRUN_WaitClearAlm,//LZ ADD 20210810
    SLVRUN_ServoCA,//LZ ADD 20211110 伺服快速定位CA指令
    LVRUN_WaitServoCA
}SLV_RUN_STATE;

typedef struct
{
    int speed_base;
    int acc_base;
    int trq_base;
    unsigned short base_unit_flag;

    int target_pos;//command
    int target_s;//command
    int fback_pos;//反馈实际位置
    int cmd_pos;    //反馈指令位置    
    int pos_err;
    int latch_pos;
    int latch_incr;

    int fback_speed;
    int ref_speed;
    int tor_ref;
    int cur_alarm;
    int tar_speed;
    char comm_phase;
    char ctrl_mod;
    char cmd_code;

    int lastInvalid;
    int last_fback_pos;
    int last_ref_speed;
    int last_cmd_pos;

    unsigned short stFlag;
    unsigned char stType;

    unsigned char      SonReq;//cmd,使能请求，0:下使能;1:上使能
    unsigned char      FlgSon;//input flag使能状态
    unsigned char      FlgAlm;//input flag
    unsigned char      FlgPstRsp;//input flag
    unsigned char      Alarm;

    unsigned char      FlgPstReq;//output flag
    unsigned char      FlgGainReq;//output flag

    unsigned char      InitPosValid;//internal flag
    SLV_RUN_STATE SlvRunSt;
    int Event;

    int M3_Slave_Type;
    int output_mode;//hanwenye add 0:interp 1:rotate
    int io_out;

    int io_in;
    int isZSPD;//hanwenye add

    int target_torque;//LZ 20210511 增加扭矩功能
    int AlmResetFlag;//LZ MOD 原来使用的是全局变量，增加到结构体中，用来做伺服报竟复位的
    int befor_power_down_fback_pos;//LZ MOD 原来使用的是全局变量，增加到结构体中，用于增量编码器上电回复下电时保存的座标
} MLINK_MONITOR_STRUCT;


#define PANEL_LED_SIZE 8

typedef struct  
{
    unsigned char m_sbuff[16][FRAMESIZE];
    unsigned char m_rbuff[16][FRAMESIZE];
    //struct timespec motion_time;
    unsigned short LOCAL_DATA[100];
    char panel_led[PANEL_LED_SIZE];
}MIII_data_t;


typedef struct S_MIII_MST
{
    MST_STATE MstSt;
    unsigned int       MstTmr;
    unsigned int       ComErrCnt;
    unsigned int       SlvWdtErr;
    unsigned int       SlvRsp;                //从机返回    
    unsigned int       SlvExpected;            //主机向从机通讯的标志，初始化时把希望与从站通讯的从站位设置为1，例如想与从站1通讯，则需要把第二位置1
    unsigned int       SlvPresence;
    unsigned int       SlvDisconnect;
    unsigned int       SlvConnect;
    unsigned int       SlvIdRead;
    unsigned int       SlvSynced;
    unsigned int       SlvSensorOn;
    unsigned int       SlvServoOn;
    unsigned int       SlvServoOff;
    unsigned int       SlvGetInitPos;
    unsigned int       SlvPrmNop;
    unsigned int       SlvPrmRd;
    unsigned int       SlvPrmWr;
    unsigned int       SlvAdj;
    unsigned int       SlvClrAlM;
    //MIII_SLV   Slv[SLV_ST_MAX];
}* PMIII_MST, MIII_MST;


typedef struct
{
    unsigned short alm_mod;
    unsigned short alm_index;
} MLINK_ALM_STRUCT;

typedef struct
{
    char type;
    short size;
    int address;
    int data;
} MLINK_MEM_STRUCT;

typedef struct
{
    unsigned short no;
    char size;
    char mode;
    int parameter;
} MLINK_SVPRM_STRUCT;


typedef struct
{
    unsigned char cmd_seq;
    unsigned char alm_clr_bit;
    MLINK_ALM_STRUCT alm_cmd;
    MLINK_MEM_STRUCT mem_cmd;
    MLINK_SVPRM_STRUCT svprm_cmd;
} MLINK_SUB_CMD;



extern MIII_data_t m3_data;
extern MLINK_SUB_CMD sub_cmd_data[SLV_ST_MAX];
extern unsigned short m3Stat[SLV_ST_MAX];
extern unsigned char cmd_data[SLV_ST_MAX][FRAMESIZE];
extern unsigned char rsp_data[SLV_ST_MAX][FRAMESIZE];
extern MLINK_MONITOR_STRUCT mlinkMonitor[SLV_ST_MAX];
extern unsigned short inverse_t_mcyc;
extern int m3WDTErro;
extern unsigned short svcmdStat[SLV_ST_MAX];

extern MIII_MST MiiiMst;

extern int m3WDTError;


#define MLINK_STATION_DISCONNECT_BIT        0x0001
#define MLINK_STATION_CONNECT_BIT        0x0002
#define MLINK_STATION_PARAINIT_BIT        0x0004
#define MLINK_STATION_ABSENC_INIT_BIT    0x0008
#define MLINK_STATION_CONFIG_BIT            0x0010
//#define MLINK_STATION_SUBCMD_BIT            0x0020
#define MLINK_STATION_START_ALMCLR_BIT    0x0020
#define MLINK_STATION_SYNC_BIT            0x0040
#define MLINK_STATION_SENS_ON_BIT        0x0080
#define MLINK_STATION_SPEED_BASE_BIT        0x0100
#define MLINK_STATION_ACC_BASE_BIT        0x0200
#define MLINK_STATION_TRQ_BASE_BIT        0x0400

#define MLINK_STATION_D_ALM_BIT                0x0001
#define MLINK_STATION_D_WAR_BIT                0x0002
#define MLINK_STATION_CMDRDY_BIT                   0x0004
#define MLINK_STATION_ALM_CLR_CMP_BIT        0x0008

#define MLINK_STATION_CMD_PAUSE_CMP_BIT        0x0001
#define MLINK_STATION_CMD_CANCEL_CMP_BIT    0x0002
#define MLINK_STATION_ACCFIL                    0x0030
#define MLINK_STATION_L_CMP1_BIT                0x0100
#define MLINK_STATION_L_CMP2_BIT                0x0200
#define MLINK_STATION_POS_RDY_BIT                0x0400
#define MLINK_STATION_PON_BIT                    0x0800
#define MLINK_STATION_M_RDY_BIT                0x1000
#define MLINK_STATION_SV_ON_BIT                0x2000



#define GET_STATION_DISCONNECT_FLAG(st) (m3Stat[st] & MLINK_STATION_DISCONNECT_BIT ? 1 : 0)
#define SET_STATION_DISCONNECT_FLAG(st, fl) if (fl) m3Stat[st] |= MLINK_STATION_DISCONNECT_BIT; else m3Stat[st] &= ~MLINK_STATION_DISCONNECT_BIT;
#define GET_STATION_CONNECT_FLAG(st) (m3Stat[st] & MLINK_STATION_CONNECT_BIT ? 1 : 0)
#define SET_STATION_CONNECT_FLAG(st, fl) if (fl) m3Stat[st] |= MLINK_STATION_CONNECT_BIT; else m3Stat[st] &= ~MLINK_STATION_CONNECT_BIT;
#define GET_STATION_PARAINIT_FLAG(st) (m3Stat[st] & MLINK_STATION_PARAINIT_BIT ? 1 : 0)
#define SET_STATION_PARAINIT_FLAG(st, fl) if (fl) m3Stat[st] |= MLINK_STATION_PARAINIT_BIT; else m3Stat[st] &= ~MLINK_STATION_PARAINIT_BIT;
#define GET_STATION_ABSENC_INIT_FLAG(st) (m3Stat[st] & MLINK_STATION_ABSENC_INIT_BIT ? 1 : 0)
#define SET_STATION_ABSENC_INIT_FLAG(st, fl) if (fl) m3Stat[st] |= MLINK_STATION_ABSENC_INIT_BIT; else m3Stat[st] &= ~MLINK_STATION_ABSENC_INIT_BIT;
#define GET_STATION_CONFIG_FLAG(st) (m3Stat[st] & MLINK_STATION_CONFIG_BIT ? 1 : 0)
#define SET_STATION_CONFIG_FLAG(st, fl) if (fl) m3Stat[st] |= MLINK_STATION_CONFIG_BIT; else m3Stat[st] &= ~MLINK_STATION_CONFIG_BIT;
#define GET_STATION_START_ALMCLR_FLAG(st) (m3Stat[st] & MLINK_STATION_START_ALMCLR_BIT ? 1 : 0)
#define SET_STATION_START_ALMCLR_FLAG(st, fl) if (fl) m3Stat[st] |= MLINK_STATION_START_ALMCLR_BIT; else m3Stat[st] &= ~MLINK_STATION_START_ALMCLR_BIT;
#define GET_STATION_SYNC_FLAG(st) (m3Stat[st] & MLINK_STATION_SYNC_BIT ? 1 : 0)
#define SET_STATION_SYNC_FLAG(st, fl) if (fl) m3Stat[st] |= MLINK_STATION_SYNC_BIT; else m3Stat[st] &= ~MLINK_STATION_SYNC_BIT;
#define GET_STATION_SENS_ON_FLAG(st) (m3Stat[st] & MLINK_STATION_SENS_ON_BIT ? 1 : 0)
#define SET_STATION_SENS_ON_FLAG(st, fl) if (fl) m3Stat[st] |= MLINK_STATION_SENS_ON_BIT; else m3Stat[st] &= ~MLINK_STATION_SENS_ON_BIT;
#define GET_STATION_SPEED_BASE_FLAG(st) (m3Stat[st] & MLINK_STATION_SPEED_BASE_BIT ? 1 : 0)
#define SET_STATION_SPEED_BASE_FLAG(st, fl) if (fl) m3Stat[st] |= MLINK_STATION_SPEED_BASE_BIT; else m3Stat[st] &= ~MLINK_STATION_SPEED_BASE_BIT;
#define GET_STATION_ACC_BASE_FLAG(st) (m3Stat[st] & MLINK_STATION_ACC_BASE_BIT ? 1 : 0)
#define SET_STATION_ACC_BASE_FLAG(st, fl) if (fl) m3Stat[st] |= MLINK_STATION_ACC_BASE_BIT; else m3Stat[st] &= ~MLINK_STATION_ACC_BASE_BIT;
#define GET_STATION_TRQ_BASE_FLAG(st) (m3Stat[st] & MLINK_STATION_TRQ_BASE_BIT ? 1 : 0)
#define SET_STATION_TRQ_BASE_FLAG(st, fl) if (fl) m3Stat[st] |= MLINK_STATION_TRQ_BASE_BIT; else m3Stat[st] &= ~MLINK_STATION_TRQ_BASE_BIT;



#define GET_SUB_NOP_FLAG(st) (sub_cmd_data[st].cmd_seq & MLINK_SUB_NOP ? 1 : 0)
#define SET_SUB_NOP_FLAG(st, fl) if (fl) sub_cmd_data[st].cmd_seq |= MLINK_SUB_NOP; else sub_cmd_data[st].cmd_seq &= ~MLINK_SUB_NOP;
#define GET_SUB_SMON_FLAG(st) (sub_cmd_data[st].cmd_seq & MLINK_SUB_SMON ? 1 : 0)
#define SET_SUB_SMON_FLAG(st, fl) if (fl) sub_cmd_data[st].cmd_seq |= MLINK_SUB_SMON; else sub_cmd_data[st].cmd_seq &= ~MLINK_SUB_SMON;
#define GET_SUB_ALM_RD_FLAG(st) (sub_cmd_data[st].cmd_seq & MLINK_SUB_ALM_RD ? 1 : 0)
#define SET_SUB_ALM_RD_FLAG(st, fl) if (fl) sub_cmd_data[st].cmd_seq |= MLINK_SUB_ALM_RD; else sub_cmd_data[st].cmd_seq &= ~MLINK_SUB_ALM_RD;
#define GET_SUB_ALM_CLR_FLAG(st) (sub_cmd_data[st].cmd_seq & MLINK_SUB_ALM_CLR ? 1 : 0)
#define SET_SUB_ALM_CLR_FLAG(st, fl) if (fl) sub_cmd_data[st].cmd_seq |= MLINK_SUB_ALM_CLR; else sub_cmd_data[st].cmd_seq &= ~MLINK_SUB_ALM_CLR;
#define GET_SUB_MEM_RD_FLAG(st) (sub_cmd_data[st].cmd_seq & MLINK_SUB_MEM_RD ? 1 : 0)
#define SET_SUB_MEM_RD_FLAG(st, fl) if (fl) sub_cmd_data[st].cmd_seq |= MLINK_SUB_MEM_RD; else sub_cmd_data[st].cmd_seq &= ~MLINK_SUB_MEM_RD;
#define GET_SUB_MEM_WR_FLAG(st) (sub_cmd_data[st].cmd_seq & MLINK_SUB_MEM_WR ? 1 : 0)
#define SET_SUB_MEM_WR_FLAG(st, fl) if (fl) sub_cmd_data[st].cmd_seq |= MLINK_SUB_MEM_WR; else sub_cmd_data[st].cmd_seq &= ~MLINK_SUB_MEM_WR;
#define GET_SUB_SVPRM_RD_FLAG(st) (sub_cmd_data[st].cmd_seq & MLINK_SUB_SVPRM_RD ? 1 : 0)
#define SET_SUB_SVPRM_RD_FLAG(st, fl) if (fl) sub_cmd_data[st].cmd_seq |= MLINK_SUB_SVPRM_RD; else sub_cmd_data[st].cmd_seq &= ~MLINK_SUB_SVPRM_RD;
#define GET_SUB_SVPRM_WR_FLAG(st) (sub_cmd_data[st].cmd_seq & MLINK_SUB_SVPRM_WR ? 1 : 0)
#define SET_SUB_SVPRM_WR_FLAG(st, fl) if (fl) sub_cmd_data[st].cmd_seq |= MLINK_SUB_SVPRM_WR; else sub_cmd_data[st].cmd_seq &= ~MLINK_SUB_SVPRM_WR;

#define GET_STATION_CMD_PAUSE_CMP_FLAG(st) (svcmdStat[st] & MLINK_STATION_CMD_PAUSE_CMP_BIT ? 1 : 0)
#define SET_STATION_CMD_PAUSE_CMP_FLAG(st, fl) if (fl) svcmdStat[st] |= MLINK_STATION_CMD_PAUSE_CMP_BIT; else svcmdStat[st] &= ~MLINK_STATION_CMD_PAUSE_CMP_BIT;
#define GET_STATION_CMD_CANCEL_CMP_FLAG(st) (svcmdStat[st] & MLINK_STATION_CMD_CANCEL_CMP_BIT ? 1 : 0)
#define SET_STATION_CMD_CANCEL_CMP_FLAG(st, fl) if (fl) svcmdStat[st] |= MLINK_STATION_CMD_CANCEL_CMP_BIT; else svcmdStat[st] &= ~MLINK_STATION_CMD_CANCEL_CMP_BIT;
#define GET_STATION_ACCFIL(st) (svcmdStat[st] & MLINK_STATION_ACCFIL)
#define SET_STATION_ACCFIL(st, fl) svcmdStat[st] = (svcmdStat[st] & ~MLINK_STATION_ACCFIL) | (fl);
#define GET_STATION_L_CMP1_FLAG(st) (svcmdStat[st] & MLINK_STATION_L_CMP1_BIT ? 1 : 0)
#define SET_STATION_L_CMP1_FLAG(st, fl) if (fl) svcmdStat[st] |= MLINK_STATION_L_CMP1_BIT; else svcmdStat[st] &= ~MLINK_STATION_L_CMP1_BIT;
#define GET_STATION_L_CMP2_FLAG(st) (svcmdStat[st] & MLINK_STATION_L_CMP2_BIT ? 1 : 0)
#define SET_STATION_L_CMP2_FLAG(st, fl) if (fl) svcmdStat[st] |= MLINK_STATION_L_CMP2_BIT; else svcmdStat[st] &= ~MLINK_STATION_L_CMP2_BIT;
#define GET_STATION_POS_RDY_FLAG(st) (svcmdStat[st] & MLINK_STATION_POS_RDY_BIT ? 1 : 0)
#define SET_STATION_POS_RDY_FLAG(st, fl) if (fl) svcmdStat[st] |= MLINK_STATION_POS_RDY_BIT; else svcmdStat[st] &= ~MLINK_STATION_POS_RDY_BIT;
#define GET_STATION_PON_FLAG(st) (svcmdStat[st] & MLINK_STATION_PON_BIT ? 1 : 0)
#define SET_STATION_PON_FLAG(st, fl) if (fl) svcmdStat[st] |= MLINK_STATION_PON_BIT; else svcmdStat[st] &= ~MLINK_STATION_PON_BIT;
#define GET_STATION_M_RDY_FLAG(st) (svcmdStat[st] & MLINK_STATION_M_RDY_BIT ? 1 : 0)
#define SET_STATION_M_RDY_FLAG(st, fl) if (fl) svcmdStat[st] |= MLINK_STATION_M_RDY_BIT; else svcmdStat[st] &= ~MLINK_STATION_M_RDY_BIT;
#define GET_STATION_SV_ON_FLAG(st) (svcmdStat[st] & MLINK_STATION_SV_ON_BIT ? 1 : 0)
#define SET_STATION_SV_ON_FLAG(st, fl) if (fl) svcmdStat[st] |= MLINK_STATION_SV_ON_BIT; else svcmdStat[st] &= ~MLINK_STATION_SV_ON_BIT;


extern void NOP(int st, int subflag, int CMD_CTRL);
extern void ID_RD(int st, int subflag, int CMD_CTRL, char ID_CODE, char OFFSET , int SIZE);
extern void CONFIG(int st, int subflag, int CMD_CTRL, char CONFIG_MOD);
extern void ALM_RD(int st, int subflag, int CMD_CTRL, int ALM_RD_MODE, int ALM_INDEX);
extern void ALM_CLR(int st, int subflag, int CMD_CTRL, int ALM_CLR_MOD);
extern void SYNC_SET(int st, int subflag, int CMD_CTRL);
extern void CONNECT(int st, int subflag, int CMD_CTRL, char VER, char COM_MODE, char COM_TIM, char PROFILE_TYPE );
extern void DISCONNECT(int st, int subflag);
extern void MEM_RD(int st, int subflag, int CMD_CTRL, char TYPE, short SIZE, int ADDRESS);
extern void MEM_WR(int st, int subflag, int CMD_CTRL, char TYPE, short SIZE, int ADDRESS, int DATA);
extern void  POS_SET(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO, int POS_SET_MOD, int POS_DATA);
extern void BRK_ON(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO);
extern void BRK_OFF(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO);
extern void SENS_ON(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO);
extern void SENS_OFF(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO);
extern void SMON(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO);
extern void SV_ON(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO);
extern void SV_OFF(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO);
extern void INTERPOLATE(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO , int TPOS, int VFF, int TFF, int TLIM);
extern void POSING(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO, int TPOS, int TSPD, int ACCR, int DECR, int TLIM);
extern void FEED(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO, int TSPD, int ACCR, int DECR, int TLIM);
extern void EX_FEED(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO, int TSPD, int ACCR, int DECR, int TLIM);
extern void EX_POSING(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO, int TPOS, int TSPD, int ACCR, int DECR, int TLIM);
extern void ZRET(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO, int MODE, int TSPD, int ACCR, int DECR, int TLIM);
extern void VELCTRL(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO, int TFF, int VREF, int ACCR, int DECR, int TLIM);
extern void TRQCTRL(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO, int VLIM, int TQREF);
extern void  SVPRM_RD(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO, int NO, char SIZE, char MODE);
extern void  SVPRM_WR(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL, int SVCMD_IO, int NO, char SIZE, char MODE, unsigned int PARAMETER);
extern void IO_DATA_RWA(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL,int IO_OUT);
extern void SUB_NOP(int st, int SUB_CTRL);
extern void SUB_ALM_RD(int st, int SUB_CTRL, int ALM_RD_MOD, int ALM_INDEX);
extern void SUB_ALM_CLR(int st, int SUB_CTRL, int ALM_CLR_MOD);
extern void SUB_MEM_RD(int st, int SUB_CTRL, char TYPE, short SIZE, int ADDRESS);
extern void SUB_MEM_WR(int st, int SUB_CTRL, char TYPE, short SIZE, int ADDRESS, int DATA);
extern void SUB_SMON(int st, int SUB_CTRL);
extern void SUB_SVPRM_RD(int st, int SUB_CTRL, unsigned short NO, char SIZE, char MODE);
extern void SUB_SVPRM_WR(int st, int SUB_CTRL, unsigned short NO, char SIZE, char MODE, int PARAMETER);
extern void SET_SUB_CMD(int st);
extern void ZPOSING(int st, int subflag, int CMD_CTRL, int SVCMD_CTRL,int SVCMD_IO,int TPOS, int TSPD, int ACCR, int DECR, int TLIM);

extern void mlinkSpinSetLatchFlag(int spin, int flag);

extern int spinEncoderReadLatch(int spin, int type, int *flag); //读取主轴Z 信号与锁存位置脉冲数
extern void spinEncoderMarkZenable(int spin); //主轴Z 信号使能




extern void init_m3(void);
void star_communication(void);

extern int rspSVCMD(int st);

extern void m3_reset(void);

#endif

