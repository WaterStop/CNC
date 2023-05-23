#include "plc_plc_pic.h"
#include "ui_plc_plc_pic.h"

#define LadNode_Width       65//74//60
#define LadNode_Height      42//33
#define Node_TextHeight     20
#define MaxRow 50
#define MaxColumn 8
#define LadNode_Top 0//84

static bool bac_command = 0;//基本指令
static bool edit_command =0;//编辑指令
static int menu_lev = 0;//菜单级别
static int bac_com_page = 0;
static int cur_row =0;
static int cur_column =0;
static int cur_left =0;
static int cur_top =84;//84
int Notesign = 0;

QColor green(0,0xFF,0);
QColor black(0,0,0);
static int LadFileTopRow = 0;  //界面上第一行对应的梯图行号
static int Focus_row = 0,Focus_col = 0;//当前光标行列

struct PLC_Info
{
    int data_type[MaxRow][MaxColumn];//数据类型
    bool status[MaxRow][MaxColumn];//当前状态是否激活
    QString Name[MaxRow][MaxColumn];//名字
    QString command[MaxRow][MaxColumn];//注释
};

struct PLC_Info plc_info;
//struct LadArray_loc *PLadderArrayObj = NULL; //梯图信息数据结构LadArrayAddr_Array[][]
struct LadArrayplc *PLadderArrayObj = NULL; //梯图信息数据结构LadArrayAddr_Array[][]
struct LadArrayplc PLadderArrayObj1;
struct LadFileCell_loc *LadFileEdit = NULL;      //在编辑的文件

int functionnode[FuncTypeSize] = {ndCTR, ndROT, ndCOMP, ndMOVN, ndCALL, ndSP, ndSPE, ndDSCH, ndCOIN, ndTMR, ndADD, ndSUB, ndXMOV, ndEND1, ndEND2,
                                  ndDEC, ndCOD, ndDIFU, ndDIFD, ndEOR , ndANDF , ndORF, ndNOT, ndJMPB, ndLBL, ndRST, ndSET, ndSFT, ndCOM, ndCOME,
                                  ndCODT, ndTMRB, ndTMRC, ndCALLU, ndMOVB, ndMOVW, ndAXCTL
                                 };
bool IfDispNoVLink = false; //梯图信息数据结构LadArrayAddr_Array[][]
int SonMenuNo = -1; // -1:上层菜单  0:基本指令  1:功能指令  2:编辑指令
char LadRowMeanArray[LadFile_MaxRow][50];
bool CodTableFlag = false;
char LadLineStrArray[NodeStrSize];
char *LadLineStr;
unsigned short LadArrayFlag_Array[LadFile_MaxRow];


PLC_plc_pic::PLC_plc_pic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PLC_plc_pic)
{
    ui->setupUi(this);
    Deal_solt();
    //pNodeLine1=pNodeLine2[0];
    Share_To_Local();
    loc_plcNode=&loc_plcNode2;
    pNodeLine = &PLC_Node;
    PLadderArrayObj = &PLadderArrayObj1;
}

PLC_plc_pic::~PLC_plc_pic()
{
    delete ui;
}

void PLC_plc_pic::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    QImage image;
    QPalette palette;
    ui->frame->setAutoFillBackground(true);
    //image.load(":/new/blue_pic/plc_bk.png");
    palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size())));
    this->setPalette(palette);
}

void PLC_plc_pic::mousePressEvent(QMouseEvent* event)//鼠标事件获取坐标
{
    QPoint p = event->pos();
    QString str2 = QString::number(p.x()) + " , " + QString::number(p.y());
    qDebug()<<"pos:"<<str2;

    int tem_x,tem_y;
    tem_x = 4+0*LadNode_Width;
    tem_y = LadNode_Top+ 0*LadNode_Height;
    if(((p.x()>4+8*LadNode_Width)||(p.x()<0))||((p.y()>LadNode_Top+ 8*LadNode_Height)||(p.y()<0)))
    {
        return;
    }
    for (int i=0;i<8;i++)
    {
        if((p.x()>=4+i*LadNode_Width)&&(p.x()<4+(i+1)*LadNode_Width))
        {
            Focus_col = i;
            break;
        }
    }

    for (int j=0;j<8;j++)
    {
        if((p.y()>=LadNode_Top+ j*LadNode_Height)&&(p.y()<LadNode_Top+ (j+1)*LadNode_Height))
        {
            Focus_row = j;
            break;
        }
    }
    plc_shm->LadFileEdit.LadFileCurRow = Focus_row + LadFileTopRow;
    plc_shm->LadFileEdit.LadFileCurCol = Focus_col;
    qDebug()<<Focus_row<<","<<Focus_col;
    qDebug()<<"LadFileCurRow"<<","<<"LadFileCurCol"<<plc_shm->LadFileEdit.LadFileCurRow<<","<<plc_shm->LadFileEdit.LadFileCurCol;

    update();

}

void PLC_plc_pic::Timer_on_slot()
{

}

void PLC_plc_pic::Deal_solt()
{
    ui->bt_up->setText("up");
    ui->bt_down->setText("down");
    ui->bt_up->setFont(weiruanyahei4);
    ui->bt_down->setFont(weiruanyahei4);
    connect(ui->bt_up, SIGNAL(pressed()), this, SLOT(page_up_slot()));
    connect(ui->bt_down, SIGNAL(pressed()), this, SLOT(page_down_slot()));
    connect(ui->bt_u, SIGNAL(pressed()), this, SLOT(up_slot()));
    connect(ui->bt_d, SIGNAL(pressed()), this, SLOT(down_slot()));
    connect(ui->bt_l, SIGNAL(pressed()), this, SLOT(left_slot()));
    connect(ui->bt_r, SIGNAL(pressed()), this, SLOT(right_slot()));

}

void PLC_plc_pic::FUN_cmd()
{
//    plc_fun_cmd *dialog = new plc_fun_cmd(this);
//    dialog->setGeometry(600,480,225,157);
//    dialog->exec();
//    delete dialog;
}

void PLC_plc_pic::LadNodeDis_Rd(Ladder_Node *pNode,int left, int top, int fgcolor, int row, int col)//常开
{
    if(pNode->m_nDownLink)
    {
        LadNodeDis_DownLink(pNode,left, top, 0, row, col);
    }
    int xCent, yCent;
    int width = 8;
    QPen pen;
    QPainter painter(this);
    if(fgcolor==1)
    {
        pen.setColor(green);
    }
    else if(fgcolor==0)
    {
        pen.setColor(black);
    }
    painter.setFont(weiruanyahei4);
    painter.setPen(pen);
    pen.setWidth(5);
    row = row -LadFileTopRow;
    cur_left = 4+col*LadNode_Width;
    cur_top = LadNode_Top+ row*LadNode_Height;
    xCent = cur_left + LadNode_Width / 2;
    yCent = cur_top + Node_TextHeight + (LadNode_Height - Node_TextHeight) / 2;

    painter.drawLine(cur_left -1, yCent, xCent - width, yCent);
    painter.drawLine(xCent + width, yCent, cur_left + LadNode_Width - 2, yCent);
    painter.drawLine(xCent - width, yCent - 6, xCent - width, yCent + 7);
    painter.drawLine(xCent + width, yCent - 6, xCent + width, yCent + 7);

    //节点名字
    if(Notesign == 0)
    {
        painter.drawText(cur_left + 7, cur_top + 1+Node_TextHeight,pNode->m_strName);
    }
    else if(Notesign == 1)
    {
        if(pNode->m_strNote[0] == '\0')
        {
            painter.drawText( cur_left + 7, cur_top + 1+Node_TextHeight,  pNode->m_strName);
        }
        else
        {
            painter.drawText(cur_left + 7, cur_top + 1+Node_TextHeight,pNode->m_strNote);
        }
    }
    painter.end();
}

void PLC_plc_pic::LadNodeDis_RdNot(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col)//常闭
{
    if(pNode->m_nDownLink)
    {
        LadNodeDis_DownLink(pNode,left, top, 0, row, col);
    }
    int xCent, yCent;
    int width = 8;
    QPen pen;
    QPainter painter(this);
    if(fgcolor==1)
    {
        pen.setColor(green);
    }
    else if(fgcolor==0)
    {
        pen.setColor(black);
    }
    painter.setFont(weiruanyahei4);
    //pen.setColor(Qt::red);
    painter.setPen(pen);
    pen.setWidth(5);
    row = row -LadFileTopRow;
    cur_left = 2+col*LadNode_Width;
    cur_top = LadNode_Top+ row*LadNode_Height;
    xCent = cur_left + LadNode_Width / 2;
    yCent = cur_top + Node_TextHeight + (LadNode_Height - Node_TextHeight) / 2;

    painter.drawLine(cur_left + 1, yCent, xCent - width, yCent);//画左边横线
    painter.drawLine(xCent + width, yCent, cur_left + LadNode_Width - 2, yCent);//画右边横线
    painter.drawLine(xCent - width, yCent - 6, xCent - width, yCent + 7);//画两条竖线
    painter.drawLine(xCent + width, yCent - 6, xCent + width, yCent + 7);
    painter.drawLine(xCent + width - 4, yCent - 5, xCent - width + 4, yCent + 5);//画斜线
    painter.drawLine(xCent + width - 4, yCent - 4, xCent - width + 4, yCent + 6);
    painter.drawLine(xCent + width - 4, yCent - 3, xCent - width + 4, yCent + 7);

    //节点名字
    if(Notesign == 0)
    {
        painter.drawText(cur_left + 7, cur_top + 1+Node_TextHeight,pNode->m_strName);
    }
    else if(Notesign == 1)
    {
        if(pNode->m_strNote[0] == '\0')
        {
            painter.drawText( cur_left + 7, cur_top + 1+Node_TextHeight,  pNode->m_strName);
        }
        else
        {
            painter.drawText(cur_left + 7, cur_top + 1+Node_TextHeight,pNode->m_strNote);
        }
    }

}

void PLC_plc_pic::LadNodeDis_Wrt(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col)//输出
{
    int xCent,yCent;
    int left2, top2;
    int width = 8;
    QPen pen;
    QPainter painter(this);
    if(fgcolor==1)
    {
        pen.setColor(green);
    }
    else if(fgcolor==0)
    {
        pen.setColor(black);
    }
    painter.setFont(weiruanyahei4);
    //pen.setColor(Qt::red);
    painter.setPen(pen);
    pen.setWidth(5);
    row = row -LadFileTopRow;
    cur_left = 2+col*LadNode_Width;
    cur_top = LadNode_Top+ row*LadNode_Height;
    xCent = cur_left + LadNode_Width/2;
    yCent = cur_top + Node_TextHeight + (LadNode_Height - Node_TextHeight) / 2;

    painter.drawLine(cur_left + 1, yCent, xCent-width, yCent);//画左边横线
    painter.drawLine(xCent + width, yCent, cur_left + LadNode_Width - 2, yCent);//画右边横线
    QRectF rectangle(xCent-width, cur_top + Node_TextHeight+3, 15, LadNode_Height - Node_TextHeight-5);//给定的矩形，我们会直接用正方形来绘制正圆弧
    int startAngle = 135 * 16;    //起始角，以3点方向为0°，逆时针为整,起始角度是点到圆心与右侧水平线夹角
    int spanAngle = 90 * 16;    //偏移角，就是起始角和终止角的差值。绘制整个圆就输入360 * 16
    painter.drawArc(rectangle, startAngle, spanAngle);//画圆弧
    QRectF rectangle2(xCent-width+2, cur_top + Node_TextHeight+3, 15, LadNode_Height - Node_TextHeight-5);//给定的矩形，我们会直接用正方形来绘制正圆弧
    int startAngle2 = 45 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = -90 * 16;    //偏移角，就是起始角和终止角的差值。绘制整个圆就输入360 * 16
    painter.drawArc(rectangle2, startAngle2, spanAngle2);//画圆弧

    //节点名字
    if(Notesign == 0)
    {
        //painter.drawText(left + 7, top + 1+Node_TextHeight,pNode->m_strName);
        painter.drawText(cur_left + 7, cur_top + 1+Node_TextHeight,pNode->m_strName);
    }
    else if(Notesign == 1)
    {
        if(pNode->m_strNote[0] == '\0')
        {
            //painter.drawText( left + 7, top + 1+Node_TextHeight,  pNode->m_strName);
            painter.drawText(cur_left + 7, cur_top + 1+Node_TextHeight,pNode->m_strName);
        }
        else
        {
            //painter.drawText(left + 7, top + 1+Node_TextHeight,pNode->m_strNote);
            painter.drawText(cur_left + 7, cur_top + 1+Node_TextHeight,pNode->m_strName);
        }
    }

}

void PLC_plc_pic::LadNodeDis_WrtNot(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col)//反向输出
{
    int xCent,yCent;
    int left2, top2;
    int width = 8;
    int cycle_r =6;
    QPen pen;
    QPainter painter(this);
    if(fgcolor==1)
    {
        pen.setColor(green);
    }
    else if(fgcolor==0)
    {
        pen.setColor(black);
    }
    painter.setFont(weiruanyahei4);
    //pen.setColor(Qt::red);
    painter.setPen(pen);
    pen.setWidth(5);
    row = row -LadFileTopRow;
    cur_left = 2+col*LadNode_Width;
    cur_top = LadNode_Top+ row*LadNode_Height;
    xCent = cur_left + LadNode_Width/2;
    yCent = cur_top + Node_TextHeight + (LadNode_Height - Node_TextHeight) / 2;

    painter.drawLine(cur_left + 1, yCent, xCent-width-cycle_r, yCent);//画左边横线
    painter.drawLine(xCent + width, yCent, cur_left + LadNode_Width - 2, yCent);//画右边横线
    QRectF rectangle(xCent-width, cur_top + Node_TextHeight+3, 15, LadNode_Height - Node_TextHeight-5);//给定的矩形，我们会直接用正方形来绘制正圆弧
    int startAngle = 135 * 16;    //起始角，以3点方向为0°，逆时针为整,起始角度是点到圆心与右侧水平线夹角
    int spanAngle = 90 * 16;    //偏移角，就是起始角和终止角的差值。绘制整个圆就输入360 * 16
    painter.drawArc(rectangle, startAngle, spanAngle);//画圆弧
    QRectF rectangle2(xCent-width+2, cur_top + Node_TextHeight+3, 15, LadNode_Height - Node_TextHeight-5);//给定的矩形，我们会直接用正方形来绘制正圆弧
    int startAngle2 = 45 * 16;    //起始角，以3点方向为0°，逆时针为整。
    int spanAngle2 = -90 * 16;    //偏移角，就是起始角和终止角的差值。绘制整个圆就输入360 * 16
    painter.drawArc(rectangle2, startAngle2, spanAngle2);//画圆弧
    QRectF rectangle3(xCent-width-cycle_r, yCent-(cycle_r/2), cycle_r,cycle_r);//给定的矩形，我们会直接用正方形来绘制正圆弧
    int startAngle3 = 180 * 16;    //起始角，以3点方向为0°，逆时针为整,起始角度是点到圆心与右侧水平线夹角
    int spanAngle3 = 360 * 16;    //偏移角，就是起始角和终止角的差值。绘制整个圆就输入360 * 16
    painter.drawArc(rectangle3, startAngle3, spanAngle3);//画圆

    //节点名字
    if(Notesign == 0)
    {
        painter.drawText(left + 7, top + 1+Node_TextHeight,pNode->m_strName);
    }
    else if(Notesign == 1)
    {
        if(pNode->m_strNote[0] == '\0')
        {
            painter.drawText( left + 7, top + 1+Node_TextHeight,  pNode->m_strName);
        }
        else
        {
            painter.drawText(left + 7, top + 1+Node_TextHeight,pNode->m_strNote);
        }
    }

}

//直线
void PLC_plc_pic::LadNodeDis_Horizon(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col)//直线
{
    if(pNode->m_nDownLink)
    {
        LadNodeDis_DownLink(pNode,left, top, 0, row, col);
    }
    QPen pen;
    QPainter painter(this);
    pen.setColor(green);
    painter.setPen(pen);
    pen.setWidth(5);

    int xCent,yCent;
    row = row -LadFileTopRow;
    cur_left = 2+col*LadNode_Width;
    cur_top = LadNode_Top+ row*LadNode_Height;
    yCent = cur_top + Node_TextHeight + (LadNode_Height - Node_TextHeight) / 2;
    //painter.drawLine(left, yCent, cur_left + LadNode_Width - 1, yCent);
    painter.drawLine(cur_left, yCent, cur_left + LadNode_Width - 1, yCent);
}

//竖线
void PLC_plc_pic::LadNodeDis_DownLink(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col)//竖线
{
    int y;
    int xCent,yCent;
    bool vLinkUp = false;
    bool vLinkDown = false;
    int IsNode0 = 2;
    int IsNode1 = 2;
    QPen pen;
    QPainter painter(this);
    pen.setColor(green);
    painter.setPen(pen);
    pen.setWidth(5);
    row = row -LadFileTopRow;
    cur_left = 2+col*LadNode_Width;
    cur_top = LadNode_Top+ row*LadNode_Height;
    xCent = cur_left + LadNode_Width/2;
    yCent = cur_top + Node_TextHeight + (LadNode_Height - Node_TextHeight) / 2; //横线位置

//    if(color == COLOR_TBACK)
//    {
//            if(row > 0)
//            {
//                vLinkUp =  LadRangeIsHaveVLink(PLadderArrayObj->m_pIndex[row - 1], col, col);
//            }

//            vLinkDown =  LadRangeIsHaveVLink(PLadderArrayObj->m_pIndex[row + 1], col, col);

//            if(LadRangeIsNull(PLadderArrayObj->m_pIndex[row], col, col) && vLinkUp == false)
//            {
//                IsNode0 = 0;
//            }

//            if((LadFileEdit->LadFileCurRow == (LadFileEdit->LadFileUpRow + LadWnd_RowNum))) {
//                IsNode1 = 0;
//            }

//            if(LadRangeIsNull(PLadderArrayObj->m_pIndex[row + 1], col, col) && vLinkDown == false) {
//                IsNode1 = 0;
//            }
//     } else
//    {
//            if(LadRangeIsNull(PLadderArrayObj->m_pIndex[row], col, col)) 3
//            {
//                IsNode0 = 0;
//            }

//            if((LadFileEdit->LadFileCurRow == (LadFileEdit->LadFileUpRow + LadWnd_RowNum)) || LadRangeIsNull(PLadderArrayObj->m_pIndex[row + 1], col, col))
//            {
//                IsNode1 = 0;
//            }
//     }
    painter.drawLine(cur_left + LadNode_Width - 1, yCent + IsNode0, cur_left + LadNode_Width - 1, yCent + LadNode_Height + 1 - IsNode1);

}

void PLC_plc_pic::LadNodeDis_FuncAll(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col)
{
        qDebug()<<"LadNodeDis_FuncAll";
        short int type, floor;
        int width, height;
        type  = (short int)(pNode->m_nType & 0xff00);
        qDebug()<<"type ="<<type;
        QPainter painter(this);
        painter.begin(this);
        painter.setFont(weiruanyahei4);

        if(type == 0)
        {
            return;
        }

        if(type != ndCODT)
        {
            LadFuncGetShowSize(type, &width, &height);
        }
        else
        {
            height = pNode->m_CodtHeight;
        }

        floor = (short int)((pNode->m_nType & 0x00f0) >> 4);
        qDebug()<<"floor="<<floor;
        if(height == 1)
        {
            LadNodeDis_FunOut(pNode,  left, top, fgcolor, 'C', row, col);
        }
        else if(floor == 0)
        {
            LadNodeDis_FunOut(pNode, left, top, fgcolor, 'T', row, col);
        }
        else if(floor == (height - 1))
        {
            LadNodeDis_FunOut(pNode, left, top, fgcolor, 'B', row, col);
        }
        else
        {
            LadNodeDis_FunIn(pNode, left, top, fgcolor, row, col);
        }
        QString str = QString::fromUtf8(pNode->m_strName);
        LadNodeDis_FuncAll1(pNode,left, top);
        painter.end();
}

void PLC_plc_pic::LadNodeDis_FuncAll1(Ladder_Node *pNode, int left, int top)
{
    QPainter painter(this);
    painter.setFont(weiruanyahei4);

    painter.drawText(left + 15, top + 10+Node_TextHeight,pNode->m_strName);

}

void PLC_plc_pic::set_Focus(int row,int col)//当前焦点颜色
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::yellow);
    painter.setPen(pen);

    QPolygon t0;
    painter.setBrush(Qt::yellow);

    int tem_x,tem_y,tem_x1,tem_y1;
//    tem_x = 4+col*LadNode_Width;
//    tem_y = LadNode_Top+ row*LadNode_Height;
    tem_x = 4+col*LadNode_Width;
    tem_y = LadNode_Top+ row*LadNode_Height;


    QPoint p0_1(tem_x,tem_y);
    QPoint p0_2(tem_x+LadNode_Width,tem_y);
    QPoint p0_3(tem_x+LadNode_Width,tem_y+LadNode_Height);
    QPoint p0_4(tem_x,tem_y+LadNode_Height);
    t0<<p0_1<<p0_2<<p0_3<<p0_4;
    painter.drawPolygon(t0);
    painter.drawConvexPolygon(t0);//填充颜色
}

void PLC_plc_pic::LadFuncGetShowSize(int nType, int *width, int *height)
{
    nType &= 0xFF00;

    switch(nType) {
        case ndCTR :
            *width = 2;
            *height = 4;
            break;

        case ndTMR :
            *width = 2;
            *height = 2;
            break;

        case ndCALL:
            *width = 2;
            *height = 1;
            break;

        case ndDSCH:
            *width = 6;
            *height = 3;
            break;

        case ndCOIN:
            *width = 4;
            *height = 2;
            break;

        case ndROT :
            *width = 5;
            *height = 5;
            break;

        case ndCOMP:
            *width = 4;
            *height = 2;
            break;

        case ndMOVN:
            *width = 4;
            *height = 2;
            break;

        case ndSP  :
            *width = 2;
            *height = 1;
            break;

        case ndSPE :
            *width = 1;
            *height = 1;
            break;

        case ndADD:
            *width = 5;
            *height = 2;
            break;

        case ndSUB:
            *width = 5;
            *height = 2;
            break;

        case ndXMOV:
            *width = 6;
            *height = 3;
            break;

        case ndEND1:
            *width = 1;
            *height = 1;
            break;

        case ndEND2:
            *width = 1;
            *height = 1;
            break;

        case ndDEC:
            *width = 5;
            *height = 2;
            break;

        case ndCOD:
            *width = 5;
            *height = 2;
            break;

        case ndCODT:
            *width = LadFile_Col;
            *height = 0;
            break;

        case ndDIFU:
            *width = 2;
            *height = 1;
            break;

        case ndDIFD:
            *width = 2;
            *height = 1;
            break;

        case ndEOR:
            *width = 5;
            *height = 2;
            break;

        case ndANDF:
            *width = 5;
            *height = 2;
            break;

        case ndORF:
            *width = 5;
            *height = 2;
            break;

        case ndNOT:
            *width = 4;
            *height = 2;
            break;

        case ndJMPB:
            *width = 2;
            *height = 1;
            break;

        case ndLBL:
            *width = 2;
            *height = 1;
            break;

        case ndRST:
            *width = 2;
            *height = 1;
            break;

        case ndSET:
            *width = 2;
            *height = 1;
            break;

        case ndSFT:
            *width = 3;
            *height = 4;
            break;

        case ndCOM:
            *width = 1;
            *height = 1;
            break;

        case ndCOME:
            *width = 1;
            *height = 1;
            break;

        case ndTMRB:
            *width = 4;
            *height = 2;
            break;

        case ndTMRC:
            *width = 3;
            *height = 2;
            break;

        case ndCALLU:
            *width = 2;
            *height = 1;
            break;

        case ndMOVB:
            *width = 3;
            *height = 2;
            break;

        case ndMOVW:
            *width = 3;
            *height = 2;
            break;

        case ndAXCTL:
            *width = 3;
            *height = 2;
            break;

        default:
            break;
        }
}

void PLC_plc_pic::LadNodeDis_FunOut(Ladder_Node *pNode, int left, int top, int fgcolor, char type, int row, int col)
{
    QPen pen;
    QPainter painter(this);
    painter.setFont(weiruanyahei4);
    //pen.setColor(Qt::red);
    painter.setPen(pen);
    pen.setWidth(5);
    qDebug()<<"LadNodeDis_FunOut";
    int right;
    right = left + LadNode_Width - 1;

    if((pNode->m_nType & 0x000f) != 0)
    {
        left -= 2;
    }
    qDebug()<<"LadNodeDis_FunOut1";
    //SetPenColor(pdc, COLOR_TOFF);

    if(type == 'T') //top side
    {
        qDebug()<<"left="<<left<<"top="<<top;
        painter.drawLine(left + 1, top + LadNode_Height, left + 1, top + 10);
        painter.drawLine(left + 1, top + 10, right, top + 10);
        painter.drawLine(right, top + 10, right, top + LadNode_Height);
    }
    else if(type == 'B') //bottom side
    {
        painter.drawLine(left + 1, top, left + 1, top + LadNode_Height - 1);
        painter.drawLine(left + 1, top + LadNode_Height - 2, right, top + LadNode_Height - 2);
        painter.drawLine(right, top + LadNode_Height - 1, right, top);
    }
    else if(type == 'C') //closed
    {
        LadDraw_Rectangle(left + 1, top + 10, right, top + LadNode_Height - 1);
        //painter.drawRect(left + 1, top + 10, right, top + LadNode_Height - 1);
    }

    //painter.drawText(left + 7, top + 1+Node_TextHeight,pNode->m_strName);

}

void PLC_plc_pic::LadDraw_Rectangle(int x, int y, int x1, int y1)
{
    QPen pen;
    QPainter painter(this);
    painter.setFont(weiruanyahei4);
    //pen.setColor(Qt::red);
    painter.setPen(pen);
    pen.setWidth(5);

    painter.drawLine(x, y, x1, y);
    painter.drawLine(x, y1, x1, y1);
    painter.drawLine(x, y, x, y1 + 1);
    painter.drawLine(x1, y, x1, y1);
}

void PLC_plc_pic::LadNodeDis_FunIn(Ladder_Node *pNode,  int left, int top, int fgcolor, int row, int col)
{
    QPen pen;
    QPainter painter(this);
    painter.setFont(weiruanyahei4);
    //pen.setColor(Qt::red);
    painter.setPen(pen);
    pen.setWidth(5);

    int right;
    //SetPenColor(pdc, COLOR_TOFF);
    right = left + LadNode_Width - 1;

    if((pNode->m_nType & 0x000f) != 0) {
        left -= 2;
    }

    painter.drawLine(left + 1, top, left + 1, top + LadNode_Height);
    painter.drawLine(right, top, right, top + LadNode_Height);
    //SetPenColor(pdc, fgcolor);
    //PDC_StrOut16(pdc, left + 6, top + 15,  fgcolor, pNode->m_strName);
    if(pNode->m_strName[0]=='\0')
    {
        painter.drawText(left + 7, top + 1+Node_TextHeight,"");
    }
    else
    {
        painter.drawText(left + 7, top + 1+Node_TextHeight,pNode->m_strName);
    }

}

void PLC_plc_pic::LadNodeDis_Empty(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col)//空白区域
{
    if(pNode->m_nDownLink)
    {
        LadNodeDis_DownLink(pNode,left, top, 0, row, col);
    }
}

void PLC_plc_pic::LadderViewShowRow(int row)
{
    //Ladder_Node *pNodeLine;

    QPen pen;
    QPainter painter(this);
    //pen.setColor(Qt::red);
    pen.setWidth(4);
    painter.setPen(pen);

    int left = 0, top = 0, i;
    int color;
    //int color[2] = {COLOR_TOFF, COLOR_TON};
    char str[50], str2[50];
    int yCent = 0;

    //界面上第一行与上一行之间是否有竖连线
    if(row == plc_shm->LadFileEdit.LadFileUpRow && row > 0)
    {
        PLC_Node = LadArray_GetRow(row - 1);
        pNodeLine = &PLC_Node;

        for(i = 0; i < LadFile_Col; i++)
        {
            if(pNodeLine[i].m_nDownLink) //是否有向下连线
            {
                //LadNodeDis_FirstDown(LadWnd_Left + (i)*LadNode_Width, LadWnd_Top);
            }
        }
    }
    if(row < 0 || row > PLadderArrayObj->m_lSize - 1)
    {
        return;
    }
    PLC_Node = LadArray_GetRow(row);
    pNodeLine = &PLC_Node;

    left = LadWnd_Left;
    //top = LadWnd_Top + (row - LadFileEdit->LadFileUpRow) * LadNode_Height;
    top = LadWnd_Top + (row - LadFileTopRow) * LadNode_Height;
//    pdc = CreateDC();
//    SetBackColor(pdc, COLOR_TBACK);

    painter.drawLine(LadWnd_Left, top, LadWnd_Left, LadNode_Top+8*LadNode_Height);
    painter.drawLine(LadWnd_Left+8*LadNode_Width, top, LadWnd_Left+8*LadNode_Width, LadNode_Top+8*LadNode_Height);
    for(i = 0; i < LadFile_Col; i++)
    {
        PLC_Data_Share(pNodeLine,row,i);
        //LadNodeDispDeal(&pNodeLine1[i], left, top,1, row, i);
        color = Get_Node_Status(pNodeLine);
        LadNodeDispDeal(pNodeLine, left, top,color, row, i);
        left += LadNode_Width;
        //qDebug()<<"/******/";
    }
}

//行内容刷新
void PLC_plc_pic::LadNodeDispDeal(Ladder_Node *pNode, int left, int top, int fgcolor, int row, int col)
{
    //qDebug()<<"pNode->m_nType"<<pNode->m_nType;
    switch(pNode->m_nType)
    {
        case NodeType_None:
            LadNodeDis_Empty(pNode, left, top, fgcolor, row, col);
            memset(pNode->m_strName,0,sizeof(pNode->m_strName));
            break;

        case NodeType_HLink:
            LadNodeDis_Horizon(pNode,left, top, fgcolor, row, col);
            memset(pNode->m_strName,0,sizeof(pNode->m_strName));
            break;

        case NodeType_Rd:
            LadNodeDis_Rd(pNode, left, top, fgcolor, row, col);
            memset(pNode->m_strName,0,sizeof(pNode->m_strName));
            break;

        case NodeType_RdNot:
            LadNodeDis_RdNot(pNode, left, top, fgcolor, row, col);
            memset(pNode->m_strName,0,sizeof(pNode->m_strName));
            break;

        case NodeType_Wrt:
            LadNodeDis_Wrt(pNode, left, top, fgcolor, row, col);
            memset(pNode->m_strName,0,sizeof(pNode->m_strName));
            break;

        case NodeType_WrtNot:
            LadNodeDis_WrtNot(pNode, left, top, fgcolor, row, col);
            memset(pNode->m_strName,0,sizeof(pNode->m_strName));
            break;

        default:
            LadNodeDis_FuncAll(pNode, left, top, fgcolor, row, col);
            memset(pNode->m_strName,0,sizeof(pNode->m_strName));
            break;
        }
}

void PLC_plc_pic::LadderPageRedraw(void)
{
    int i ;
//    FilledRect(LadWnd_Left - 1 - BaseLine_Width, LadWnd_Top, LadWnd_Left - 1, LadWnd_Bot, COLOR_TBUS); //左边竖线
//    FilledRect(LadWnd_SecLine, LadWnd_Top, LadWnd_SecLine + BaseLine_Width, LadWnd_Bot, COLOR_TBUS); //右边竖线
//    FilledRect(LadWnd_Left, LadWnd_Top /*- 9*/, LadWnd_SecLine - 1, LadWnd_Bot, COLOR_TBACK); //梯图显示区域
//    FilledRect(LadWnd_SecLine + BaseLine_Width + 1, LadWnd_Top /*- 9*/, LadWnd_Right, LadWnd_Bot, COLOR_TBACK);//右边竖线的右侧区域

//        if(LadFileEdit->LadFileCurRow >= LadFileEdit->LadFileUpRow + LadWnd_RowNum)
//        {
//            LadFileEdit->LadFileUpRow += LadFileEdit->LadFileCurRow - (LadFileEdit->LadFileUpRow + LadWnd_RowNum) + 1;
//        }

//        if(LadFileEdit->LadFileCurRow < LadFileEdit->LadFileUpRow)
//        {
//            LadFileEdit->LadFileUpRow =  LadFileEdit->LadFileCurRow;
//        }

//        if(LadFileEdit->LadFileCurRow > PLadderArrayObj->m_lSize - 1)
//        {
//            LadFileEdit->LadFileCurRow = PLadderArrayObj->m_lSize - 1;
//        }

//        if(LadFileEdit->LadFileCurRow < 0)
//        {
//            LadFileEdit->LadFileCurRow = 0;
//            LadFileEdit->LadFileUpRow = 0;
//        }
        //绘制梯图内容
    set_Focus(Focus_row,Focus_col);
    //if(Subsignal == 0)
    //{
        //for(i = LadFileEdit->LadFileUpRow; i < (LadFileEdit->LadFileUpRow + LadWnd_RowNum); i++)
        for(i = LadFileTopRow; i < (LadFileTopRow + LadWnd_RowNum); i++)
        {
            LadderViewShowRow(i);
        }
    //}
//       if(Subsignal == 1)
//       {
//         for(i = LadFileEdit->LadFileUpRow; i < LadFileEdit->LadFileUpRow + LadWnd_RowNum; i++)
//         {
//           if( i >= (block_node[iNode].Start-1) && i < block_node[iNode].End)
//           {
//             LadderViewShowRow(i);
//            }
//         }
//       }
}

bool PLC_plc_pic::LadFuncEnterKeyDeal(Ladder_Node *pNode)
{
    char strText[35];
//    Ladder_Node *pNodeLine;
//    Ladder_Node *pNode;
    int nPosParam;
    int nType;
    int addr;
//    pNodeLine1 = LadArray_GetRow(plc_shm->LadFileEdit.LadFileCurRow);
//    pNode = &pNodeLine1[plc_shm->LadFileEdit.LadFileCurCol];
    //pNode = plc_shm->LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol];
    PLC_Data_Share(pNode,plc_shm->LadFileEdit.LadFileCurRow,plc_shm->LadFileEdit.LadFileCurCol);
    nPosParam = (short int)((pNode->m_nType) & 0x00ff);

    if((!(nPosParam & 0x0f) || (nPosParam & 0xf0)) && (pNode->m_nType & 0xff00) != ndCODT) {
        return false;
    }

//    PlcTextInputGetStr(strText);

//    if(strText[1] == 0 && strText[0] >= 'A' && strText[0] <= 'Z') {
//        strText[1] = '0';
//    }

//    nType = (short int) pNode->m_nType;
//    addr = LadFuncInputErrCheck   (nType, nPosParam, strText);

//    if(addr < 0) {
//        CNCWarning(1013 + addr, LadFileEdit->LadFileCurRow);
//        CodTableFlag = false;
//        return false;
//    } else if(nType == (ndCTR | 0x01) || nType == (ndTMR | 0x01) || nType == (ndTMRC | 0x02) || nType == (ndTMRB | 0x02) || nType == (ndLBL | 0x01) || nType == (ndSP | 0x01) || nType == (ndDIFU | 0x01) || nType == (ndDIFD | 0x01)) {
//        if(PlcParaRangeIsCheck(pNode, addr, plc_shm->LadFileEdit.LadFileCurRow, 0)) {
//            return false;
//        }
//    }

//    LadNode_SetName(pNode, strText);
//    LadNode_SetAddr(pNode, addr);
//    LadderRowShowSel(1, false);
    return true;
}

//处理基本指令菜单
bool PLC_plc_pic::LadBaseMenuKeyDeal(int key)
{
    int col = 0;
    int type = 0;
qDebug()<<"基本指令";
    //if(LadFuncPageShowFlag == 1) {
    //    return FALSE;
    //}
//    if(key == EditKey_O)
//    {
//        MenuGetKeyDown(MenuHead, 7);
//        MenuHead = CurrentMenu->Father;
//        CurrentMenu = MenuHead;
//        ShowRightMenu(MenuHead, CurrentMenu);
//        return TRUE;
//    }
qDebug()<<"基本指令1";
    if(LadEditFlagPermit(true) == false)
    {
        return false;
    }
qDebug()<<"基本指令2";
    type = LadLineIsHaveFunc(plc_shm->LadFileEdit.LadFileCurRow, &col);

    if(type == ndCODT)
    {
        qDebug()<<"type == ndCODT";
        return false;
    }
qDebug()<<"基本指令3";
    switch(key)
    {
    case SoftFuncKey0: //常开
        LadMenuDown_Base(NodeType_Rd);
        break;

    case SoftFuncKey1: //常闭
        LadMenuDown_Base(NodeType_RdNot);
        break;

    case SoftFuncKey2: //输出
        LadMenuDown_Base(NodeType_Wrt);
        break;

    case SoftFuncKey3: //取反输出
        LadMenuDown_Base(NodeType_WrtNot);
        break;

    case SoftFuncKey4: //横线
        LadMenuDown_Base(NodeType_HLink);
        break;

    case SoftFuncKey5: //竖线
        LadNodeDraw_VLink(1, 1, plc_shm->LadFileEdit.LadFileCurRow, plc_shm->LadFileEdit.LadFileCurCol);
        break;

    case SoftFuncKey6: //删除竖线
        LadNodeDraw_VLink(0, 1, plc_shm->LadFileEdit.LadFileCurRow, plc_shm->LadFileEdit.LadFileCurCol);
        break;

    default :
        break;
    }

    return 1;
}

//处理编辑指令菜单
bool PLC_plc_pic::LadEditMenuKeyDeal(int key)
{
    int col = 0;
    int type = 0;

    /*if(LadFuncPageShowFlag == 1) {
        return FALSE;
    }
    if(key == EditKey_O) {
        MenuGetKeyDown(MenuHead, 7);
        MenuHead = CurrentMenu->Father;
        CurrentMenu = MenuHead;
        ShowRightMenu(MenuHead, CurrentMenu);
        return TRUE;
    }*/

    if(LadEditFlagPermit(true) == false)
    {
        return false;
    }

    type = LadLineIsHaveFunc(plc_shm->LadFileEdit.LadFileCurRow, &col);

    if(type == ndCODT)
    {
        return false;
    }

    switch(key)
    {
    case SoftFuncKey0: //插入一行
        plc_shm->LadFileEdit.LadFileIsModify = LadViewInsertLine();
        break;

    case SoftFuncKey1: //删除一行
        plc_shm->LadFileEdit.LadFileIsModify = LadViewDelLine();
        break;

    case SoftFuncKey2: //保存梯形图
        LadMenuFileSaveDeal();
        break;

    case SoftFuncKey3:
        //SearchState = Label_Note;
        //LadSearchSetDataType(); //左下角显示"序号"
        break;

    default :
        break;
    }

    return 1;
}

void PLC_plc_pic::LadMenuDown_Base(short int nType)
{
    //Ladder_Node *pNodeLine;
    int thistype, j, left, top, k, fCmdInRow;
    bool upLineIsDown = false;
    //PDC pdc;
    qDebug()<<"基本处理0";
    qDebug()<<"m_lSize="<<PLadderArrayObj->m_lSize;
    qDebug()<<"LadFileCurRow="<<plc_shm->LadFileEdit.LadFileCurRow<<"LadFileCurCol="<<plc_shm->LadFileEdit.LadFileCurCol;

    if(plc_shm->LadFileEdit.LadFileCurRow < PLadderArrayObj->m_lSize - 1)
    {
        qDebug()<<"分支1:LadFileCurRow="<<plc_shm->LadFileEdit.LadFileCurRow;
        PLC_Node = LadArray_GetRow(plc_shm->LadFileEdit.LadFileCurRow);
        pNodeLine = &PLC_Node;
        thistype = pNodeLine[plc_shm->LadFileEdit.LadFileCurCol].m_nType;
        //thistype = pNodeLine->m_nVal;

        for(k = 0, j = 0; j < LadFile_Col - 1; j++)
        {
            if(LadNode_IsFunc(pNodeLine[j].m_nType))
            {
                GetFCmdInputRow(pNodeLine[j].m_nType, &fCmdInRow);

                if((pNodeLine[j].m_nType & 0x00f0) / 0x10 >= fCmdInRow)
                {
                    return;
                }

                k = j;

                if(!LadFuncIsHaveOut(pNodeLine[j].m_nType))
                {
                    j = LadFile_Col;
                }

                break;
            }
        }
qDebug()<<"基本处理1";
        if(k)
        {
            if(!(k > plc_shm->LadFileEdit.LadFileCurCol) &&
            !(nType == NodeType_HLink && !LadNode_IsFunc(thistype)) &&
            !((nType == NodeType_Wrt || nType == NodeType_WrtNot) && j != LadFile_Col /*&& (CtrlkeyState % 2 || plc_shm->LadFileEdit.LadFileCurCol == LadFile_Col - 1)*/))//缺CtrlkeyState
            {
                return;
            }
        }
    }
    else
    {
        qDebug()<<"分支2";
        if(plc_shm->LadFileEdit.LadFileCurRow == LadFile_MaxRow - 1)
        {
            return;
        }
        pNodeLine = LadArray_GetRowAdr();
        LadArray_AddRow(pNodeLine);
        PLC_Node=LadArray_GetRow(plc_shm->LadFileEdit.LadFileCurRow);
        pNodeLine = &PLC_Node;
    }
qDebug()<<"基本处理2";
    if(nType == NodeType_Wrt || nType == NodeType_WrtNot)
    {
        qDebug()<<"分支3";
        if(LadNode_IsFunc(pNodeLine[j].m_nType))
        {
            if((pNodeLine[j].m_nType & 0x00f0) / 0x10 >= 1)
            {
                return;
            }
        }

        if(j == LadFile_Col)
        {
            return;
        }
        if(plc_shm->LadFileEdit.LadFileCurRow > 0)
        {
            upLineIsDown = LadLineIsHaveVLink(plc_shm->LadFileEdit.LadFileCurRow - 1, 0, LadFile_Col - 1);
        }

        if(plc_shm->LadFileEdit.LadFileCurRow == 0 || (plc_shm->LadFileEdit.LadFileCurRow > 0 && upLineIsDown == 0))
        {
            for(j = LadFile_Col - 1; j >= 0; j--)
            {
                if(pNodeLine[j].m_nType == NodeType_None)
                {
                    LadNode_SetType(&pNodeLine[j], NodeType_HLink);
                    LadNode_SetName(&pNodeLine[j], (char*)"");
                }
                else
                {
                    break;
                }
            }
        }
        if(plc_shm->LadFileEdit.LadFileCurCol != LadFile_Col - 1)
        {
            qDebug()<<"分支3.1";
            //LadderRowShowSel(0, false);//重绘界面
            plc_shm->LadFileEdit.LadFileCurCol = LadFile_Col - 1;
        }

        //LadderViewShowRow(plc_shm->LadFileEdit.LadFileCurRow);
    }
    else if(plc_shm->LadFileEdit.LadFileCurCol == LadFile_Col - 1)
    {
        if(!(j == LadFile_Col && nType == NodeType_HLink))
        {
            return;
        }
    }
qDebug()<<"基本处理5";
    IfDispNoVLink = pNodeLine[plc_shm->LadFileEdit.LadFileCurCol].m_nDownLink;
    qDebug()<<"基本处理5.1";
    //LadNode_ClearAll(&pNodeLine[plc_shm->LadFileEdit.LadFileCurCol]);
    qDebug()<<"基本处理5.2";
    LadNode_SetType(&pNodeLine[plc_shm->LadFileEdit.LadFileCurCol], nType);
    qDebug()<<"基本处理5.3";
    LadValueChange(&pNodeLine[plc_shm->LadFileEdit.LadFileCurCol]);
    qDebug()<<"基本处理5.4";
    left = LadWnd_Left + plc_shm->LadFileEdit.LadFileCurCol * LadNode_Width;
    qDebug()<<"基本处理5.5";
    top = LadWnd_Top + (plc_shm->LadFileEdit.LadFileCurRow - plc_shm->LadFileEdit.LadFileUpRow) * LadNode_Height;
    qDebug()<<"基本处理5.6";
    //LadderViewShowRow(plc_shm->LadFileEdit.LadFileCurRow);
    //LadderRowShowSel(1, false);

qDebug()<<"基本处理6";
    if(IfDispNoVLink)
    {
        //pdc = CreateDC();
        //LadNodeDis_DownLink(&pNodeLine[LadFileEdit->LadFileCurCol], pdc, left, top, COLOR_TBACK, LadFileEdit->LadFileCurRow, LadFileEdit->LadFileCurCol);
        //DestoryDC(pdc);
        //plc_shm->LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_nDownLink = IfDispNoVLink;
    }

    IfDispNoVLink = false;
    plc_shm->LadFileEdit.LadFileIsModify = true;
    update();
}

void PLC_plc_pic::LadValueChange(Ladder_Node *pNode)
{
    LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_nVal = pNode->m_nVal;
    LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_nAddr = pNode->m_nAddr;
    LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_nType = pNode->m_nType;
    memcpy(LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_strName,pNode->m_strName,strlen(pNode->m_strName));
    LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_CodtHeight = pNode->m_CodtHeight;
    memcpy(LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_strNote,pNode->m_strNote,strlen(pNode->m_strNote));


    //pNodeLine2[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_nVal = pNodeLine->m_nVal;
    //pNodeLine2[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_nAddr = pNodeLine->m_nAddr;
    //pNodeLine2[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_nType = pNodeLine->m_nType;
    //memcpy(pNodeLine2[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_strName,plc_shm->LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_strName,strlen(plc_shm->LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_strName));
    //pNodeLine2[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_CodtHeight = pNodeLine->m_CodtHeight;
    //memcpy(pNodeLine2[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_strNote,plc_shm->LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_strNote,strlen(plc_shm->LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_strNote));
}

bool  PLC_plc_pic::LadMenuFileSaveDeal(void)
{
    //Ladder_Node *pNodeLine;
//    if(LadFileConvertDeal(false) > 0 && LadderFileSaveDeal())//检查、保存
//    {
//        if (!PlcLadFileSaveOk)
//        {
//            PlcLadFileSaveOk = TRUE;
//            isLadModified = 1;
//        }
//        ShowLadderStatus();
//        DispHintInfo(g_ViewLadEditText[UIVLadEditInfo_5]);
//    }
//    else
//    {
//        DispHintInfo(g_ViewLadEditText[UIVLadEditInfo_6]);
//    }

//    LadViewPromptClear();
//    PMCRecord();
    for (int i= 0;i<LadFile_MaxRow;i++)
    {
        for (int j=0;j<LadFile_Col;j++)
        {
            //plc_shm->LadArrayAddr_Array[i][j] = pNodeLine2[i][j];
            plc_shm->LadArrayAddr_Array[i][j].m_nVal = pNodeLine->m_nVal;
            plc_shm->LadArrayAddr_Array[i][j].m_nAddr = pNodeLine->m_nAddr;
            plc_shm->LadArrayAddr_Array[i][j].m_nType = pNodeLine->m_nType;
            memcpy(plc_shm->LadArrayAddr_Array[i][j].m_strName,LadArrayAddr_Array[i][j].m_strName,strlen(LadArrayAddr_Array[i][j].m_strName));
            plc_shm->LadArrayAddr_Array[i][j].m_CodtHeight = pNodeLine->m_CodtHeight;
            memcpy(plc_shm->LadArrayAddr_Array[i][j].m_strNote,LadArrayAddr_Array[i][j].m_strNote,strlen(LadArrayAddr_Array[i][j].m_strNote));
        }
    }
    return true;
}

int PLC_plc_pic::LadFileConvertDeal(bool download)
{
    //botLine是增加功能块大小之后的行号，找到了功能块下沿的行号
//    int botLine, fn1stCol, i, midLine;
//    int error;
//    LadLineStr = LadLineStrArray;
//    memset(&StringArrayObjSave, 0, sizeof(StringArrayObjSave));

//    if(!if_plc_init) {//初始化时不进入。保存pLadStringArrayObj到StringArrayObjSave
//        for(i = 0; i < pLadStringArrayObj->m_lSize; i++) {
//            CNCStrCpy(StringArrayObjSave.m_pIndex[i], pLadStringArrayObj->m_pIndex[i], NodeStrSize);
//        }

//        StringArrayObjSave.m_lSize = pLadStringArrayObj->m_lSize;
//    }

//    Destroy_String();//清空pLadStringArrayObj。
//    //begin

//    for(i = 0, error = 0; error >= 0 && i <= (PLadderArrayObj->m_lSize - 1) && !IsHavePLCWarnNo();) { //暂时将i理解为节点号//mark debug
//        error = LadConIsEmptyLine( i, 0, LadFile_Col - 1);//判断是不是空行，不是空行返回0，超过最大的程序行数返回1，是空行返回1，是竖线返回2
//        if(error == 1) {
//            if(LadLineIsHaveVLink(i, 0, LadFile_Col - 1)) {
//                CNCWarning(1030, i);//1030	网络中有不正确的垂直线.
//                error = -3;
//                break;
//            }

//            i++;
//            continue;
//        } else if(error == 2) {//1009	网络水平线未连上或短路.
//            CNCWarning(1009, i);
//            error = -3;
//            break;
//        }//以上判断程序格式问题

//        botLine = 0; //相关联的最后一个节点

//        //如果是此行有功能块，botLine是增加功能块大小之后的行号，找到了功能块下沿的行号
//        //如果是基本指令，没有功能块，botLine不变，是0
//        fn1stCol = LadConFindBlockRange( i, &botLine); //分块程序，找到一个程序块占用的行数，判断是功能行还是基本指令行

//        switch(fn1stCol) {
//        case -2://网络块太大
//            error = -1; //return -1;
//            break;

//        case -1://不是功能指令,只有基本指令
//            if(!LadConvertBasicLines( i, botLine)) {
//                error = -3; //return -3;
//            }

//            break;

//        case 0: //功能指令CODT
//            if(!ConvertCodtFuncLine( i, botLine)) {
//                error = -4; //return -4;
//            }

//            break;

//        default: //是功能指令

//            // 在这里 把节点命令 变为字符串 ， 填充 pLadStringArrayObj->m_pIndex
//            if(!LadConvertFuncLines( i, botLine, fn1stCol)) {
//                error = -2; //return -2;
//            }

//            break;
//        }

//        for(midLine = i; midLine <= botLine; midLine++) {
//            if(IsBreakDownLink(midLine, 0, LadFile_Col - 1)) { //是否有悬空的垂直线
//                CNCWarning(1030, midLine);
//                error = -3;
//                break;
//            }
//        }

//        i = botLine + 1;
//    }

//    if(!IsHavePLCWarnNo()) {//如果没有报警
//        TextConvertToBinCode(download);
//    }

//    if(!IsHavePLCWarnNo()) {
//        return true;//SaveLadRepertoFile();
//    } else if(!if_plc_init) {//恢复函数最开始保存的备份
//        for(i = 0; i < StringArrayObjSave.m_lSize; i++) {
//            CNCStrCpy(pLadStringArrayObj->m_pIndex[i], StringArrayObjSave.m_pIndex[i], NodeStrSize);
//        }

//        pLadStringArrayObj->m_lSize = StringArrayObjSave.m_lSize;
//    }

//    return 0;
}

bool PLC_plc_pic::LadViewDelLine(void)
{
    //Ladder_Node *pNodeLine;
    int i;

    if(plc_shm->LadFileEdit.LadFileCurRow >= PLadderArrayObj->m_lSize - 1)
    {
        return false;
    }

    PLC_Node = LadArray_GetRow(plc_shm->LadFileEdit.LadFileCurRow);
    pNodeLine = &PLC_Node;


    if(plc_shm->LadFileEdit.LadFileCurRow > PLadderArrayObj->m_lSize - 1)
    {
        return false;
    }

    for( i = 0; i < LadFile_Col; i++)
    {
        LadNode_ClearAll(&pNodeLine[i]);
    }

    LadArray_DelIndex(plc_shm->LadFileEdit.LadFileCurRow);

    if(plc_shm->LadFileEdit.LadFileCurRow >= PLadderArrayObj->m_lSize - 1)
    {
        plc_shm->LadFileEdit.LadFileCurRow = PLadderArrayObj->m_lSize - 1;
    }

    if(!CodTableFlag)
    {
        //LadderRowShowSel(1, true);
    }
    update();
    return true;
}

bool PLC_plc_pic::LadViewInsertLine(void)
{
    //Ladder_Node *pNodeLine;
    int col, i;

    if(PLadderArrayObj->m_lSize >= LadFile_MaxRow)
    {
        //CNCWarning(1004, PLadderArrayObj->m_lSize);
        return false;
    }

    col = IsFCmdInRow(plc_shm->LadFileEdit.LadFileCurRow);

    if(col != USERERR)
    {
        PLC_Node =  LadArray_GetRow(plc_shm->LadFileEdit.LadFileCurRow);
        pNodeLine = &PLC_Node;

        if(((pNodeLine[col].m_nType) & 0x00ff) >= 0x10)
        {
            return false;
        }

        if((pNodeLine[plc_shm->LadFileEdit.LadFileCurCol].m_nType & 0xff00) == ndCODT)
        {
            return false;
        }
    }

    pNodeLine = LadArray_GetRowAdr();

    for(i = 0; i < LadFile_Col; i++)
    {
        LadNode_ClearAll(&pNodeLine[i]);
    }

    LadArray_InsertIndex(plc_shm->LadFileEdit.LadFileCurRow, pNodeLine);
    //LadderRowShowSel(1, true);
    update();
    return true;
}

void PLC_plc_pic::LadArray_DelIndex(int lIndx)
{
    int i;

    if(lIndx < 0)
    {
        return;
    }

    if(lIndx > PLadderArrayObj->m_lSize - 1)
    {
        return;
    }

    for (i=lIndx; i<(PLadderArrayObj->m_lSize-1); i++)
    {
        PLadderArrayObj->m_pIndex[i] = PLadderArrayObj->m_pIndex[i + 1];
    }

    PLadderArrayObj->m_lSize--;
}


void PLC_plc_pic::LadArray_InsertIndex(int lIndx, Ladder_Node *pItem)
{
    int i;
    //char str[50];

    if(lIndx < 0) {
        return;
    }

    if(lIndx > PLadderArrayObj->m_lSize - 1) {
        LadArray_AddRow(pItem);
        return;
    }

    for(i = PLadderArrayObj->m_lSize - 1; i >= lIndx; i--)
    {
        PLadderArrayObj->m_pIndex[i + 1] = PLadderArrayObj->m_pIndex[i];
        strcpy(LadRowMeanArray[i + 1], LadRowMeanArray[i]);
         strcpy(LadRowMeanArray[i], "");
    }

    PLadderArrayObj->m_pIndex[lIndx] = *pItem;
    PLadderArrayObj->m_lSize++;
}

int PLC_plc_pic::IsFCmdInRow(int row)
{
    int nType;
    int j;
    //Ladder_Node *pNodeLine;
    PLC_Node = LadArray_GetRow(row);
    pNodeLine = &PLC_Node;

    for(j = 0; j < LadFile_Col - 1; j++)
    {
        nType = pNodeLine[j].m_nType;

        if(LadNode_IsFunc(nType))
        {
            return j;
        }
    }

    return USERERR;
}


void PLC_plc_pic::LadNodeDraw_VLink(int select, int setDownLink, int row, int col)
{
    //PDC pdc;
    int left, top, nextRow;
    int funCol = 0 , inputNum = 0;
    //Ladder_Node *pNodeLine;

    if(setDownLink)
    {
        PLC_Node = LadArray_GetRow(row);
        pNodeLine = &PLC_Node;

        if(col == LadFile_Col - 1)
        {
            return;
        }

        if(row + 1 < PLadderArrayObj->m_lSize)
        {
            if(LadLineIsHaveFunc(row + 1, &funCol) != 0)
            {
                return;
            }
        }

        if(LadLineIsHaveFunc(row, &funCol) != 0)
        {
            GetFCmdInputRow(pNodeLine[funCol].m_nType, &inputNum);

            if(inputNum != 1)
            {
                return;
            }
            else if(inputNum == 1 && col >= funCol - 1)
            {
                return;
            }
        }
    }

    //pdc = CreateDC();
    left = LadWnd_Left + col * LadNode_Width;
    nextRow = row - plc_shm->LadFileEdit.LadFileUpRow;
    top = LadWnd_Top + nextRow * LadNode_Height;
    pNodeLine[col].m_nDownLink = select;
    IfDispNoVLink = true;

    if(pNodeLine[col].m_nDownLink)
    {
        //LadNodeDis_DownLink(&pNodeLine[col], pdc, left, top, COLOR_TON, row, col);
        plc_shm->LadArrayAddr_Array[row][col].m_nDownLink = select;
    }
    else
    {
        //LadNodeDis_DownLink(&pNodeLine[col], pdc, left, top, COLOR_TBACK, row, col);
        plc_shm->LadArrayAddr_Array[row][col].m_nDownLink = select;
    }

    IfDispNoVLink = false;
    //DestoryDC(pdc);
    plc_shm->LadFileEdit.LadFileIsModify = true;
    update();
}

void PLC_plc_pic::LadNode_SetName(Ladder_Node *pNode, char *pName)
{
    if(strlen(pName) > 7)
    {
        return;
    }

    CNCStrCpy(pNode->m_strName, pName, 7);
    //strcpy(pNode->m_strName,pName);
}

void PLC_plc_pic::LadNode_SetType(Ladder_Node *pNode, int type)
{    
    qDebug()<<"SetType";
    LadNode_ClearAll(pNode);
    qDebug()<<"SetType1";
    pNode->m_nType = type;
    qDebug()<<"SetType2 type="<<pNode->m_nType;
    LadArrayAddr_Array[plc_shm->LadFileEdit.LadFileCurRow][plc_shm->LadFileEdit.LadFileCurCol].m_nType = pNode->m_nType;
    qDebug()<<"SetType3";
}

void PLC_plc_pic::LadNode_ClearAll(Ladder_Node *pNode)
{
    qDebug()<<"ClearAll";
    if(pNode == NULL)
    {
        return;
    }
    qDebug()<<"ClearAll1";

    pNode->m_nVal = 0;
    qDebug()<<"ClearAll2";
    pNode->m_nType = NodeType_None;
    qDebug()<<"ClearAll3";
    pNode->m_nDownLink = false;
    qDebug()<<"ClearAll4";
    pNode->m_nAddr      = -1;
    qDebug()<<"ClearAll5";
    pNode->m_strName[0] = '\0';
    qDebug()<<"ClearAll6";
    pNode->m_CodtHeight = 0;
    qDebug()<<"ClearAll7";
    //	pNode->m_strNote[0] = '\0';
}

Ladder_Node PLC_plc_pic::LadArray_GetRow(int Row)//返回梯图对应行的指针
{
    if(Row > PLadderArrayObj->m_lSize - 1)
    {
        Row = PLadderArrayObj->m_lSize - 1;
    }

    if(Row < 0)
    {
        Row = 0;
    }

    if(PLadderArrayObj->m_lSize == 0)
    {
    }

    return  PLadderArrayObj->m_pIndex[Row];
}

Ladder_Node *PLC_plc_pic::LadArray_GetRowAdr(void)
{
    int i;

    for(i = 0; i < LadFile_MaxRow; i++)
    {
        if(!LadArrayFlag_Array[i])
        {
            LadArrayFlag_Array[i] = 0xAA;
            break;
        }
    }

    if(i > LadFile_MaxRow - 1)
    {
        //CNCWarning(1004, LadFile_MaxRow - 1);
        return LadArrayAddr_Array[LadFile_MaxRow - 1];
    }

    return LadArrayAddr_Array[i];
}

int PLC_plc_pic::LadLineIsHaveVLink( int nLine, int from, int to)
{
    int col;
    int downLinkCol = 0;
    //Ladder_Node *pNodeLine;

    if(nLine >= 0 && nLine < PLadderArrayObj->m_lSize )
    {
        //pNodeLine = LadArray_GetRow(nLine);

        for( col = from; col < to; col++)
        {
            if(pNodeLine[col].m_nDownLink)
            {
                downLinkCol = col + 1;
            }
        }
    }

    return downLinkCol;
}

void PLC_plc_pic::LadArray_AddRow(Ladder_Node *pItem)//添加到最后面
{
    if(PLadderArrayObj->m_lSize >= LadFile_MaxRow)
    {
        return;
    }

    //PLadderArrayObj->m_pIndex[PLadderArrayObj->m_lSize] = *pItem;
    LadToLad(pItem);
    PLadderArrayObj->m_lSize++;
}

void PLC_plc_pic::LadToLad(Ladder_Node *pItem)
{
    PLadderArrayObj->m_pIndex[PLadderArrayObj->m_lSize].m_nVal = pItem->m_nVal;
    PLadderArrayObj->m_pIndex[PLadderArrayObj->m_lSize].m_nAddr = pItem->m_nAddr;
    PLadderArrayObj->m_pIndex[PLadderArrayObj->m_lSize].m_nType = pItem->m_nType;
    PLadderArrayObj->m_pIndex[PLadderArrayObj->m_lSize].m_nDownLink = pItem->m_nDownLink;
    PLadderArrayObj->m_pIndex[PLadderArrayObj->m_lSize].m_CodtHeight = pItem->m_CodtHeight;
    memcpy(PLadderArrayObj->m_pIndex[PLadderArrayObj->m_lSize].m_strName,pItem->m_strName,strlen(pItem->m_strName));
    memcpy(PLadderArrayObj->m_pIndex[PLadderArrayObj->m_lSize].m_strNote,pItem->m_strNote,strlen(pItem->m_strNote));

}

Ladder_Node PLC_plc_pic::*LadArray_GetRowAdr(void)
{
    int i;

    for(i = 0; i < LadFile_MaxRow; i++)
    {
//        if(!LadArrayFlag_Array[i]) //缺LadArrayFlag_Array
//        {
//            LadArrayFlag_Array[i] = 0xAA;
//            break;
//        }
    }

    if(i > LadFile_MaxRow - 1)
    {
        //CNCWarning(1004, LadFile_MaxRow - 1);
        //return LadArrayAddr_Array[LadFile_MaxRow - 1];
    }

    //return LadArrayAddr_Array[i];
}

bool PLC_plc_pic::LadFuncIsHaveOut(int recFuncType)
{
    bool haveOutput;
    recFuncType &= 0xff00;

    switch(recFuncType) {
    case ndCTR:
        haveOutput = true;
        break; //counter

    case ndROT:
        haveOutput = true;
        break; //counter

    case ndCOMP:
        haveOutput = true;
        break; //counter

    case ndMOVN:
        haveOutput = true;
        break; //counter

    case ndMOVB:
        haveOutput = true;
        break; //counter

    case ndMOVW:
        haveOutput = true;
        break; //counter

    case ndCALL:
        haveOutput = false;
        break; //counter

    case ndCALLU:
        haveOutput = false;
        break;

    case ndSP:
        haveOutput = false;
        break; //counter

    case ndSPE:
        haveOutput = false;
        break; //counter

    case ndJMPB:
        haveOutput = false;
        break; //counter

    case ndLBL:
        haveOutput = false;
        break; //counter

    case ndDSCH:
        haveOutput = true;
        break; //counter

    case ndCOIN:
        haveOutput = true;
        break; //counter

    case ndTMR:
        haveOutput = true;
        break; //counter

    case ndTMRB:
        haveOutput = true;
        break; //counter

    case ndTMRC:
        haveOutput = true;
        break; //counter

    case ndADD:
        haveOutput = true;
        break; //counter

    case ndSUB:
        haveOutput = true;
        break; //counter

    case ndXMOV:
        haveOutput = true;
        break; //counter

    case ndEND1:
        haveOutput = false;
        break; //counter

    case ndEND2:
        haveOutput = false;
        break; //counter

    case ndDEC:
        haveOutput = false;
        break; //counter

    case ndCOD:
        haveOutput = true;
        break; //counter

    case ndCODT:
        haveOutput = false;
        break; //counter

    case ndDIFU:
        haveOutput = true;
        break; //counter

    case ndDIFD:
        haveOutput = true;
        break; //counter

    case ndEOR:
        haveOutput = false;
        break; //counter

    case ndANDF:
        haveOutput = false;
        break; //counter

    case ndORF:
        haveOutput = false;
        break; //counter

    case ndNOT:
        haveOutput = false;
        break; //counter

    case ndRST:
        haveOutput = false;
        break; //counter

    case ndSET:
        haveOutput = false;
        break; //counter

    case ndSFT:
        haveOutput = true;
        break; //counter

    case ndCOM:
        haveOutput = false;
        break; //counter

    case ndCOME:
        haveOutput = false;
        break; //counter

    case ndAXCTL:
        haveOutput = true;
        break;

    default:
        haveOutput = false;
    }

    return haveOutput;
}

void PLC_plc_pic::GetFCmdInputRow(int nType, int *height)
{
    nType &= 0xFF00;

    switch(nType) {
    case ndCTR :
        *height = 4;
        break;

    case ndTMR :
        *height = 1;
        break;

    case ndCALL:
        *height = 1;
        break;

    case ndDSCH:
        *height = 3;
        break;

    case ndCOIN:
        *height = 1;
        break;

    case ndROT :
        *height = 5;
        break;

    case ndCOMP:
        *height = 1;
        break;

    case ndMOVN:
        *height = 1;
        break;

    case ndSP  :
        *height = 1;
        break;

    case ndSPE :
        *height = 1;
        break;

    case ndADD:
        *height = 2;
        break;

    case ndSUB:
        *height = 2;
        break;

    case ndXMOV:
        *height = 3;
        break;

    case ndEND1:
        *height = 1;
        break;

    case ndEND2:
        *height = 1;
        break;

    case ndDEC:
        *height = 1;
        break;

    case ndCOD:
        *height = 2;
        break;

    case ndCODT:
        *height = 0;
        break;

    case ndDIFU:
        *height = 1;
        break;

    case ndDIFD:
        *height = 1;
        break;

    case ndEOR:
        *height = 1;
        break;

    case ndANDF:
        *height = 1;
        break;

    case ndORF:
        *height = 1;
        break;

    case ndNOT:
        *height = 1;
        break;

    case ndJMPB:
        *height = 1;
        break;

    case ndLBL:
        *height = 1;
        break;

    case ndRST:
        *height = 1;
        break;

    case ndSET:
        *height = 1;
        break;

    case ndSFT:
        *height = 4;
        break;

    case ndCOM:
        *height = 1;
        break;

    case ndCOME:
        *height = 1;
        break;

    case ndTMRB:
        *height = 1;
        break;

    case ndTMRC:
        *height = 1;
        break;

    case ndCALLU:
        *height = 1;
        break;

    case ndMOVB:
        *height = 1;
        break;

    case ndMOVW:
        *height = 1;
        break;

    case ndAXCTL:
        *height = 2;
        break;

    default:
        break;
    }
}

//nLine 梯图所在的行，等同于PLadderArrayObj的节点号
//RetFuncCol 《参数返回值》保存功能块所在的行的位置
//返回值是功能块号，如果没有功能块返回0
int PLC_plc_pic::LadLineIsHaveFunc( int nLine, int *RetFuncCol)//这一行有功能指令，返回功能指令，设置RetFuncCol为功能指令所在行中的位置
{
    //Ladder_Node *pNodeLine;
    int col;
    int i;
    //pNodeLine = LadArray_GetRow(nLine);

    for( col = 0; col < LadFile_Col - 1; col++)
    {
        for(i = 0; i < FuncTypeSize; i++)
        {
            if((pNodeLine[col].m_nType & 0xff00) == functionnode[i]) //是功能指令
            {
                *RetFuncCol = col;
                return functionnode[i];
            }
        }
    }

    return 0;
}

bool PLC_plc_pic::LadEditFlagPermit(int isWarn)
{
    bool ret = 0;
    if (LadFileRunOrStopPermit(true) /*&& SearchState != Label_Note*/ /*&& SearchReplay != 1  && PlcRunOrStopFlag != 1 && pLadFileList.CurOpenFileNum != -1*/)//缺少标志位
    {
        ret = 1;
    }

    return ret;
}

bool PLC_plc_pic::LadFileRunOrStopPermit(int  isWarn)
{
    int ret = 0;
    //if ((InputManner==CNC_RunStyle) && (ViewSet.URight>=MachineRight)) //缺系统运行状态和密码等级
    {
        ret = 1;
    }

    return ret;
}

void PLC_plc_pic::Share_To_Local()
{
    int i,j;
    for (i=0;i<LadFile_MaxRow;i++)
    {
        for (j=0;j<LadFile_Col;j++)
        {
            LadArrayAddr_Array[i][j].m_nVal = plc_shm->LadArrayAddr_Array[i][j].m_nVal;
            LadArrayAddr_Array[i][j].m_nType = plc_shm->LadArrayAddr_Array[i][j].m_nType;
            LadArrayAddr_Array[i][j].m_nDownLink = plc_shm->LadArrayAddr_Array[i][j].m_nDownLink;
            LadArrayAddr_Array[i][j].m_nAddr = plc_shm->LadArrayAddr_Array[i][j].m_nAddr;
            memcpy(LadArrayAddr_Array[i][j].m_strName,plc_shm->LadArrayAddr_Array[i][j].m_strName,strlen(plc_shm->LadArrayAddr_Array[i][j].m_strName));
            LadArrayAddr_Array[i][j].m_CodtHeight =plc_shm->LadArrayAddr_Array[i][j].m_CodtHeight;
            memcpy(LadArrayAddr_Array[i][j].m_strName,plc_shm->LadArrayAddr_Array[i][j].m_strNote,strlen(plc_shm->LadArrayAddr_Array[i][j].m_strNote));
        }
    }
}

void PLC_plc_pic::PLC_Data_Share(Ladder_Node *pNode,int row,int col)
{
    pNode->m_nVal = LadArrayAddr_Array[row][col].m_nVal;
    pNode->m_nType = LadArrayAddr_Array[row][col].m_nType;
    pNode->m_nDownLink = LadArrayAddr_Array[row][col].m_nDownLink;
    pNode->m_nAddr = LadArrayAddr_Array[row][col].m_nAddr;
    memcpy(pNode->m_strName,LadArrayAddr_Array[row][col].m_strName,strlen(LadArrayAddr_Array[row][col].m_strName));
    //memcpy(pNode->m_strName,pNode1->m_CodtHeight,strlen());
    pNode->m_CodtHeight =LadArrayAddr_Array[row][col].m_CodtHeight;
    memcpy(pNode->m_strName,LadArrayAddr_Array[row][col].m_strNote,strlen(LadArrayAddr_Array[row][col].m_strNote));
    //plc_shm->Lad_Editobj_LadWnd.m_pIndex[0]->m_nVal;


    //plc_shm->Lad_Editobj_LadWnd.m_pIndex[0]->m_nVal;
    //qDebug()<<"PLC_Node.m_nVal="<<plc_shm->LadArrayAddr_Array[row][col].m_nVal<<" "<<row<<" "<<col;
    //qDebug()<<"PLC_Node.m_nType"<<plc_shm->LadArrayAddr_Array[row][col].m_nType<<" "<<row<<" "<<col;
    //qDebug()<<"PLC_Node.m_nDownLink="<<plc_shm->LadArrayAddr_Array[row][col].m_nDownLink;
//    qDebug()<<"PLC_Node.m_nAddr="<<plc_shm->LadArrayAddr_Array[row][col].m_nAddr;
    //qDebug()<<"PLC_Node.m_strName="<<plc_shm->LadArrayAddr_Array[row][col].m_strName;
    //qDebug()<<"PLC_Node.m_CodtHeight="<<plc_shm->LadArrayAddr_Array[row][col].m_CodtHeight;
//    qDebug()<<"PLC_Node.m_strNote="<<plc_shm->LadArrayAddr_Array[row][col].m_strNote;
//    qDebug()<<"LoadLadderNumber="<<plc_shm->LoadLadderNumber;
    //qDebug()<<"name="<<plc_shm->LadFileEdit.name;
    //qDebug()<<"size="<<plc_shm->LadFileEdit.size;
    //qDebug()<<"names="<<plc_shm->LadFileEdit.names;
    // qDebug()<<"m_lSize="<<plc_shm->LadArrayAddr_Array;
    //qDebug()<<"xl="<<plc_shm->xl[7];
    //qDebug()<<"m_lSize="<<plc_shm->m_lSize;
}

int PLC_plc_pic::Get_Node_Status(Ladder_Node *pNode)
{
    char tmp_char[7];
    double tmp_d;
    int a,b;
    int end_val;
    if(pNode->m_strName[0]=='X')
    {
        if((pNode->m_strName[1]>='0')&&(pNode->m_strName[1]<='9'))
        {
            memcpy(tmp_char,pNode->m_strName,strlen(pNode->m_strName));
            tmp_char[0]='0';
            tmp_d=strtod(tmp_char,NULL);
            a = (int)tmp_d;
            b = (int)((tmp_d-a)*10);
            end_val = calculate_Node_val(int(plc_shm->xl[a]),b);
            return end_val;
        }
    }
    else if(pNode->m_strName[0]=='Y')
    {
        if((pNode->m_strName[1]>='0')&&(pNode->m_strName[1]<='9'))
        {
            memcpy(tmp_char,pNode->m_strName,strlen(pNode->m_strName));
            tmp_char[0]='0';
            tmp_d=strtod(tmp_char,NULL);
            a = (int)tmp_d;
            b = (int)((tmp_d-a)*10);
            end_val = calculate_Node_val(int(plc_shm->y[a]),b);
            return end_val;
        }
    }
    else if(pNode->m_strName[0]=='F')
    {
        if((pNode->m_strName[1]>='0')&&(pNode->m_strName[1]<='9'))
        {
            memcpy(tmp_char,pNode->m_strName,strlen(pNode->m_strName));
            tmp_char[0]='0';
            tmp_d=strtod(tmp_char,NULL);
            a = (int)tmp_d;
            b = (int)((tmp_d-a)*10);
            end_val = calculate_Node_val(int(plc_shm->f[a]),b);
            return end_val;
        }
    }
    else if(pNode->m_strName[0]=='G')
    {
        if((pNode->m_strName[1]>='0')&&(pNode->m_strName[1]<='9'))
        {
            memcpy(tmp_char,pNode->m_strName,strlen(pNode->m_strName));
            tmp_char[0]='0';
            tmp_d=strtod(tmp_char,NULL);
            a = (int)tmp_d;
            b = (int)((tmp_d-a)*10);
            end_val = calculate_Node_val(int(plc_shm->g[a]),b);
            return end_val;
        }
    }
    else if(pNode->m_strName[0]=='A')
    {
        if((pNode->m_strName[1]>='0')&&(pNode->m_strName[1]<='9'))
        {
            memcpy(tmp_char,pNode->m_strName,strlen(pNode->m_strName));
            tmp_char[0]='0';
            tmp_d=strtod(tmp_char,NULL);
            a = (int)tmp_d;
            b = (int)((tmp_d-a)*10);
            end_val = calculate_Node_val(int(plc_shm->a[a]),b);
            return end_val;
        }
    }
    else if(pNode->m_strName[0]=='R')
    {
        if((pNode->m_strName[1]>='0')&&(pNode->m_strName[1]<='9'))
        {
            memcpy(tmp_char,pNode->m_strName,strlen(pNode->m_strName));
            tmp_char[0]='0';
            tmp_d=strtod(tmp_char,NULL);
            a = (int)tmp_d;
            b = (int)((tmp_d-a)*10);
            end_val = calculate_Node_val(int(plc_shm->r[a]),b);
            return end_val;
        }
    }
    else if(pNode->m_strName[0]=='K')
    {
        if((pNode->m_strName[1]>='0')&&(pNode->m_strName[1]<='9'))
        {
            memcpy(tmp_char,pNode->m_strName,strlen(pNode->m_strName));
            tmp_char[0]='0';
            tmp_d=strtod(tmp_char,NULL);
            a = (int)tmp_d;
            b = (int)((tmp_d-a)*10);
            end_val = calculate_Node_val(int(plc_shm->k[a]),b);
            return end_val;
        }
    }
    return 0;
}

int PLC_plc_pic::calculate_Node_val(int node,int bit)
{
    switch (bit)
    {
        case 0:
        {
            if((node&1)==1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        case 1:
        {
            if((node&2)==1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        case 2:
        {
            if((node&4)==1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        case 3:
        {
            if((node&8)==1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        case 4:
        {
            if((node&16)==1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        case 5:
        {
            if((node&32)==1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        case 6:
        {
            if((node&64)==1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        case 7:
        {
            if((node&128)==1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        default:
        return -1;
    }
}

void PLC_plc_pic::page_up_slot()
{
    LadFileTopRow = LadFileTopRow-8;
    if(LadFileTopRow<0)
    {
        LadFileTopRow =0;
    }
    update();
}
void PLC_plc_pic::page_down_slot()
{
    LadFileTopRow = LadFileTopRow+8;
    if(LadFileTopRow>4500)
    {
        LadFileTopRow =4500;
    }
    update();
}


void PLC_plc_pic::up_slot()
{
    Focus_col--;
    if(Focus_col<0)
    {
        //页面第一行行数-1
        Focus_col = 0;
    }
    update();
}

void PLC_plc_pic::down_slot()
{
    Focus_col++;
    if(Focus_col>7)
    {
        //页面第一行行数+1
        Focus_col = 7;
    }
    update();
}

void PLC_plc_pic::left_slot()
{
    Focus_row--;
    if(Focus_row<0)
    {
        //小于总行数
        //
        if(Focus_col>0)
        {
            Focus_col--;
        }
        else
        {
            Focus_col=0;
        }
        Focus_row=7;
    }
    update();
}

void PLC_plc_pic::right_slot()
{
    Focus_row++;
    if(Focus_row>7)
    {
        //大于总行数
        //
        if(Focus_col<7)
        {
            Focus_col++;
        }
        else
        {
            Focus_col=7;
        }
        Focus_row=0;
    }
    update();
}

int PLC_plc_pic::LadNode_IsFunc(int nType)
{
    int i = 0;
    nType &= 0xff00;

    for(i = 0; i < FuncTypeSize; i++) {
        if(nType == functionnode[i]) {
            return true;
        }
    }

    return false;
}

int PLC_plc_pic::LadViewMenuKeyDeal(int key)
{
//    if(CurrentHostView != VIEW_PLC || CurrentSonView[CurrentHostView] != VIEW_PLC_Graph) //缺标志位
//    {
//        return 0;
//    }
qDebug()<<"指令处理";
qDebug()<<"SonMenuNo="<<SonMenuNo;
    if (0 == SonMenuNo)//基本指令
    {
        LadBaseMenuKeyDeal(key);
    }
    else if (2 == SonMenuNo) //编辑指令
    {
        //LadEditMenuKeyDeal(key);
    }

    return 1;
}

void PLC_plc_pic::paintEvent(QPaintEvent *)
{
    QPainter painter;

    QPixmap pixmap(":/new/blue_pic/plc_bk.png");

    painter.begin(this);
    painter.drawPixmap(rect(),pixmap,QRect());
    //Ladder_Node_loc *pNodeLine;
    //Ladder_Node *plc_Node;
    //QPainter painter(this);
    //PLC_Data_Share(pNodeLine);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 0, 0);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 0, 1);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 0, 2);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 0, 3);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 0, 4);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 0, 5);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 0, 6);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 0, 7);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 7, 0);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 7, 1);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 7, 2);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 7, 3);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 7, 4);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 7, 5);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 7, 6);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 7, 7);
//    test();
    //LadNodeDis_RdNot(pNodeLine,cur_left, cur_top, 0, 0, 1);
//    LadNodeDis_Wrt(pNodeLine,cur_left, cur_top, 0, 0, 2);
//    LadNodeDis_WrtNot(pNodeLine,cur_left, cur_top, 0, 0, 3);
//    LadNodeDis_Horizon(pNodeLine,cur_left, cur_top, 0, 0, 4);
//    LadNodeDis_DownLink(pNodeLine,cur_left, cur_top, 0, 0, 5);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 0, 6);
//    LadNodeDis_Rd(pNodeLine,cur_left, cur_top, 0, 0, 7);
//    LadNodeDis_FunOut(pNodeLine, 0, cur_top+LadNode_Height+1, 0, 'C', 1, 0);
//    LadNodeDis_FunOut(pNodeLine, 0+LadNode_Width, cur_top+LadNode_Height+1, 0, 'T', 1, 0);
//    LadNodeDis_FunOut(pNodeLine, 0+LadNode_Width*2, cur_top+LadNode_Height+1, 0, 'B', 1, 0);
    LadderPageRedraw();
    painter.end();
}
