#ifndef PLC_PLC_PIC_H
#define PLC_PLC_PIC_H

#include <QWidget>
#include <plc.h>
#include "baseset.h"

#define  ndCTR       0x1000   //counter
#define ndROT       0x1100
#define ndCOMP      0x1200
#define ndMOVN      0x1300
#define  ndCALL     0x1400
#define  ndSP        0x1500
#define ndSPE       0x1600
#define  ndDSCH      0x1700
#define ndCOIN      0x1800
#define ndTMR       0x1900
#define ndADD      0x2000
#define ndSUB       0x2100
#define ndXMOV     0x2200
#define ndEND1      0x7100
#define ndEND2      0x7200
#define ndDEC        0X2500
#define ndCOD        0X2600
#define ndDIFU      0X2700
#define ndDIFD      0X2800
#define ndEOR        0X2900
#define ndANDF      0X3000
#define ndORF        0X3100
#define ndNOT        0X3200
#define ndJMPB      0X3300
#define ndLBL        0X3400
#define ndRST       0X3500
#define ndSET       0X3600
#define ndSFT        0X3700
#define ndCOM      0X3800
#define ndCOME      0X3900
#define ndCODT     0X4000           //COD data Table
#define ndTMRB     0X4100
#define ndTMRC     0X4200
#define ndCALLU    0X4300
#define ndMOVB     0X4400
#define ndMOVW    0X4500
#define ndAXCTL    0X4600

#define FuncTypeSize 37

//ladder file
#define LadFile_MaxRow 4500
#define LadFile_MaxStep 9000
#define LadFile_Col 8
#define LadWnd_RowNum 8
//---------------
#define NodeType_None         0x0000   //empty node
#define NodeType_HLink        0x0100   //horizontal link
#define NodeType_RdNot             0x0200   //common OFF node
#define NodeType_Rd        0x0300  //common ON node
#define NodeType_Wrt            0x0400   //coil node
#define NodeType_WrtNot       0x0500   //NOT coil

#define LadWnd_Left 4
#define LadWnd_Top 0//85

#define SoftFuncKey0    0xFF6
#define SoftFuncKey1    0xFF7
#define SoftFuncKey2    0xFF8
#define SoftFuncKey3    0xFF9
#define SoftFuncKey4    0xFFA
#define SoftFuncKey5    0xFFB
#define SoftFuncKey6    0xFFC
#define SoftFuncKey7    0xFFD

#define NodeStrSize 50

extern int SonMenuNo;// -1:上层菜单  0:基本指令  1:功能指令  2:编辑指令

typedef struct
{
    int m_nVal;
    int m_nType;
    bool m_nDownLink;
    int m_nAddr;
    char m_strName[20];
    int m_CodtHeight;
    char m_strNote[34];
} Ladder_Node_loc;


namespace Ui {
class PLC_plc_pic;
}

class PLC_plc_pic : public QWidget
{
    Q_OBJECT

public:
    explicit PLC_plc_pic(QWidget *parent = nullptr);
    ~PLC_plc_pic();
    int LadViewMenuKeyDeal(int key);
private:
    Ui::PLC_plc_pic *ui;
    void Deal_solt();
    void menu_show();
    void bottom_menu_show();
    //绘制梯图函数
    void LadNodeDis_Rd(Ladder_Node *pNode,int left, int top, int fgcolor, int row, int col);//常开
    void LadNodeDis_RdNot(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col);//常闭
    void LadNodeDis_Wrt(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col);//输出
    void LadNodeDis_WrtNot(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col);//取反输出
    void LadNodeDis_Horizon(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col);//横线
    void LadNodeDis_DownLink(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col);//竖线
    void LadNodeDis_FuncAll(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col);//功能块
    void LadNodeDis_FuncAll1(Ladder_Node *pNode, int left, int top);
    void LadNodeDis_FunOut(Ladder_Node *pNode,int left, int top, int fgcolor, char type, int row, int col);
    void LadNodeDis_FunIn(Ladder_Node *pNode,  int left, int top, int fgcolor, int row, int col);
    void LadDraw_Rectangle(int x, int y, int x1, int y1);
    void LadFuncGetShowSize(int nType, int *width, int *height);
    void LadNodeDis_Empty(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col);//空白区域
    void LadNodeDispDeal(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col);
    void LadderViewShowRow(int row);
    void LadderPageRedraw(void);
    //******************************//
    int Get_Node_Status(Ladder_Node *pNode);
    int calculate_Node_val(int node,int bit);
    void FUN_cmd();
    void PLC_Data_Share(Ladder_Node *pNode,int row,int col);
    void Share_To_Local();
    void set_Focus(int row,int col);
    int LadNode_IsFunc(int nType);
    bool LadFuncEnterKeyDeal(Ladder_Node *pNode);
    bool LadBaseMenuKeyDeal(int key);
    bool LadEditMenuKeyDeal(int key);
    void LadMenuDown_Base(short int nType);
    int LadLineIsHaveFunc( int nLine, int *RetFuncCol);
    bool LadEditFlagPermit(int isWarn);
    bool LadFileRunOrStopPermit(int  isWarn);
    void GetFCmdInputRow(int nType, int *height);
    bool LadFuncIsHaveOut(int recFuncType);
    Ladder_Node *LadArray_GetRowAdr(void);
    Ladder_Node LadArray_GetRow(int Row);
    int LadLineIsHaveVLink( int nLine, int from, int to);
    void LadNode_SetType(Ladder_Node *pNode, int type);
    void LadNode_ClearAll(Ladder_Node *pNode);
    void LadArray_AddRow(Ladder_Node *pItem);
    void LadNode_SetName(Ladder_Node *pNode, char *pName);
    void LadNodeDraw_VLink(int select, int setDownLink, int row, int col);
    bool LadViewInsertLine(void);
    bool LadViewDelLine(void);
    void LadArray_DelIndex(int lIndx);
    int IsFCmdInRow(int row);
    bool LadMenuFileSaveDeal(void);
    int adFileConvertDeal(bool download);
    int LadFileConvertDeal(bool download);
    void LadArray_InsertIndex(int lIndx, Ladder_Node *pItem);
    void LadValueChange(Ladder_Node *pNode);
    void LadToLad(Ladder_Node *pItem);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent* event);
    QDir *m_dir;
    Ladder_Node  PLC_Node;
    Ladder_Node *pNodeLine;
    plc_shm_s *loc_plcNode;
    plc_shm_s loc_plcNode2;
   // Ladder_Node_loc *pNodeLine;
    Ladder_Node *pNodeLine1;
    Ladder_Node pNodeLine2[LadFile_MaxRow][LadFile_Col];
    Ladder_Node LadArrayAddr_Array[LadFile_MaxRow][LadFile_Col];

    //QLabel *lab;
private slots:
//    void RIGHT_FUN0_slot();
//    void RIGHT_FUN1_slot();
//    void RIGHT_FUN2_slot();
//    void RIGHT_FUN3_slot();
//    void RIGHT_FUN4_slot();
//    void RIGHT_FUN5_slot();
//    void RIGHT_FUN6_slot();
//    void RIGHT_FUN7_slot();
//    void FUN0_slot();
//    void FUN1_slot();
//    void FUN2_slot();
//    void FUN3_slot();
//    void FUN4_slot();
//    void FUN5_slot();
//    void FUN6_slot();
//    void FUN7_slot();
    void Timer_on_slot();
    void page_up_slot();
    void page_down_slot();
    void up_slot();
    void down_slot();
    void left_slot();
    void right_slot();
};

#endif // PLC_PLC_PIC_H
