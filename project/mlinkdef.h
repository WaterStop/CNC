/*file************ MELNK_DRV :    *****************************************/
/*                                                                    */
/*    MLINKDEF.H : JL-080 real constants  for C1 Master                        */
/*                                                                    */
/********** Copyright(C) 2008 SICT NC BUSLAB    *****************************/
/*                                                                    */
/*    Ver 1.00    2008.02.28    Initial coding    YZ.liu                            */
/*                                                                    */
/********************************************************************/

#ifndef        MLINKDEF_H_
#define        MLINKDEF_H_


#define DEF_TMCYC                200000

#define DEF_MAX_RTRY            1                /* Max retry setting */
#define DEF_PROT_SEL            0                /* Protocol select (0:sync, 1:async) */
#define DEF_WDT                    16384            /* WDT setting */

/* mark bit of using subcommand whether or not*/

#define STATION_TRANS_BYTES_BITS             0x0030
#define STATION_SYNCMODE_BIT                 0x0002
#define STATION_DTMODE_BIT                     0x0004
#define STATION_SUBCMD_BIT                     0x0080
#define STATION_PROFILE_TYPE_BITS             0x0700

#define STATION_TRANS_16_BYTES_FLAG         0x0020
#define STATION_TRANS_32_BYTES_FLAG         0x0010
#define STATION_TRANS_48_BYTES_FLAG         0x0000
#define STATION_TRANS_64_BYTES_FLAG         0x0030

#define STATION_SERVO_PROFILE_FLAG             0x0000
#define STATION_SMPIO_PROFILE_FLAG             0x0100
#define STATION_IO_PROFILE_FLAG                 0x0200

/* defines */

#define DEF_MOD_REGS                0x8002            /* MOD register setting (default : INT_FR = 1, C1master) */
#define DEF_DLY_CNT                1                /* DLY_CNT setting */
#define DEF_PROT_SEL                0                /* Protocol select (0:sync, 1:async) */
/* Sync. communication parameter */
#define DEF_INT_OFFSET            25000            /* INT_OFFSET setting (time unit : 10nsec) */
#define DEF_C2_DLY                49500            /* C2_DLY setting     (time unit : 10nsec) */
#define DEF_TRSP                    2000                /* T_RSP  setting     (time unit : 10nsec) */
#define DEF_CD_LEN                48                /* Command data length (unit : byte) */
#define DEF_RD_LEN                48                /* Response data length (unit : byte) */

/* C1/C2 message communication parameter */
#define DEF_C1MSG_SIZE            64                /* C1 message data length (unit : byte) */
#define DEF_C2MSG_SIZE            64                /* C2 message data length (unit : byte) */
#define DEF_PKT_SZ                64                /* Message packet size */
#define C1MSG_PEER_ADR            0x0021            /* Destination address of C1 message communication */
#define C2MSG_PEER_ADR            0x0002          /* Destination address of C2 message communication */

/* Async. communication parameter */
#define DEF_ASYNC_PEER_ADR        0x21            /* Destination address of Async. communication */
#define DEF_ASYNC_FTYPE            0x02            /* Frame type of async communication(0x02 or 0x0C) */
#define DEF_ASYNC_DATA_SIZE        64                /* Async. communication data size (unit : byte) */
#define DEF_ASYNC_RCV_TOUT_TIME 0xFFFF            /* Async. communication receive time-out setting */

#define        VERSION                0x30                /* MECHATROLINK-II Application Layer Version */
#define        COM_SYNCMODE        0x02                /* Synchronous communication command type */
#define        COM_ASYNCMODE        0x00                /* Asynchronous communication command type */
#define        COM_TIME            1                /* Communication Cycle/ transmission cycle] */
#define        PROFILE_TYP            0x10                /* set the standard servo profile command*/
//#define        CONFIG_MODE    1

//#define     DEF_MA_MAX                10

#ifndef        OK
#define        OK                    0x00
#endif
#define        NG                    0xff
#define        ON                    0x01
#define        OFF                    0x00

/* MECHATROLINK MONITOR */

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
/*
typedef struct
{
    int speed_base;
    int acc_base;
    int trq_base;
    unsigned short base_unit_flag;
    
    int fback_pos;
    int cmd_pos;        
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
    int io_in;                //zzy
} MLINK_MONITOR_STRUCT;

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
*/
#define MLINK_SUB_NOP        0x01
#define MLINK_SUB_SMON        0x02
#define MLINK_SUB_ALM_RD    0x04
#define MLINK_SUB_ALM_CLR    0x08
#define MLINK_SUB_MEM_RD    0x10
#define MLINK_SUB_MEM_WR    0x20
#define MLINK_SUB_SVPRM_RD    0x40
#define MLINK_SUB_SVPRM_WR    0x80
/*
typedef struct
{
    unsigned char cmd_seq;
    unsigned char alm_clr_bit;
    MLINK_ALM_STRUCT alm_cmd;
    MLINK_MEM_STRUCT mem_cmd;
    MLINK_SVPRM_STRUCT svprm_cmd;
} MLINK_SUB_CMD;
*/
#define MLINK_WARNING_START    0x900
#define MLINK_WARNING_MAX        0x00ff
#define MLINK_ALARM_MAX            0x0fff
#define MLINK_ERROR_MAX            12
#define MLINK_ALARM_EXISTED_BIT        0x01
#define MLINK_WARNING_EXISTED_BIT    MLINK_ALARM_EXISTED_BIT
#define MLINK_ALARM_NOTCLR_BIT        0x02
#define MLINK_WARNING_AUTOCLR_BIT    MLINK_ALARM_NOTCLR_BIT
#define MLINK_ALARM_OCCUR_BIT        0x04
#define MLINK_WARNING_OCCUR_BIT    MLINK_ALARM_OCCUR_BIT
/*
typedef struct
{
    int num;    //number of warning and alarm info
    unsigned char warnFlag[MLINK_WARNING_MAX];    //warning info
    unsigned char almFlag[MLINK_ALARM_MAX];    //alarm info
    unsigned short errInfo[MLINK_ERROR_MAX];        //warning and alarm number info 
    unsigned short errFlag;    //which bits are alarm or warning
    unsigned short isAlmFlag;    //bit: 0-warning, 1-alarm
} MLINK_ALARM_STRUCT;

typedef struct
{
    unsigned char m_sbuff[SLV_ST_MAX][FRAMESIZE];
    unsigned char m_rbuff[SLV_ST_MAX][FRAMESIZE];
    struct timespec motion_time;
    unsigned short LOCAL_DATA[100];
}MIII_data_t;
*/

#endif /* _MLINKDEF_H */
