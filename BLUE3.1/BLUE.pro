QT       += core gui
QT += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QMAKE_CXXFLAGS += -g

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bar.cpp \
    MachineFusion.cpp \
    MachineProcess.cpp \
    MachineSequence.cpp \
    MachineTrace.cpp \
    baseset.cpp \
    change_screentip.cpp \
    cnavdelegate.cpp \
    cnavmodel.cpp \
    cnavview.cpp \
    fixedval_widget.cpp \
    key_board.cpp \
    main.cpp \
    mylineedit.cpp \
    myprogressbar.cpp \
    offset_knife.cpp \
    plc_fun_cmd.cpp \
    plc_plc_pic.cpp \
    popupwin.cpp \
    popupwin1.cpp \
    popupwin_left.cpp \
    process_modify.cpp \
    qroundprogressbar.cpp \
    set_dgn.cpp \
    set_plc_plc.cpp \
    set_widget.cpp \
    shm.c \
    t3dashboard.cpp \
    textticker.cpp \
    wedget1.cpp \
    widget.cpp \
    widget2.cpp \
    widget2_workpic.cpp \
    widget3.cpp \
    widget3_10.cpp \
    widget3_11.cpp \
    widget3_12.cpp \
    widget3_13.cpp \
    widget3_14.cpp \
    widget3_15.cpp \
    widget3_2.cpp \
    widget3_3.cpp \
    widget3_4.cpp \
    widget3_5.cpp \
    widget3_6.cpp \
    widget3_7.cpp \
    widget3_8.cpp \
    widget3_9.cpp \
    widget4.cpp \
    widget5.cpp \
    widget5_2.cpp

HEADERS += \
    Bar.h \
    MachineFusion.h \
    MachineProcess.h \
    MachineSequence.h \
    MachineTrace.h \
    accidence.h \
    baseset.h \
    change_screentip.h \
    cnavdelegate.h \
    cnavmodel.h \
    cnavview.h \
    command.h \
    config.h \
    decode.h \
    error.h \
    fixedval_widget.h \
    global_variable.h \
    home.h \
    key_board.h \
    m3.h \
    machineStruct.h \
    mlinkdef.h \
    motion.h \
    mylineedit.h \
    myprogressbar.h \
    offset_knife.h \
    para.h \
    parse_syntax.h \
    plc.h \
    plc_fun_cmd.h \
    plc_plc_pic.h \
    popupwin.h \
    popupwin1.h \
    popupwin_left.h \
    pos.h \
    process_modify.h \
    qroundprogressbar.h \
    save.h \
    servo.h \
    set_dgn.h \
    set_plc_plc.h \
    set_widget.h \
    shm.h \
    t3dashboard.h \
    tc.h \
    tcq.h \
    textticker.h \
    tp.h \
    wedget1.h \
    widget.h \
    widget2.h \
    widget2_workpic.h \
    widget3.h \
    widget3_10.h \
    widget3_11.h \
    widget3_12.h \
    widget3_13.h \
    widget3_14.h \
    widget3_15.h \
    widget3_2.h \
    widget3_3.h \
    widget3_4.h \
    widget3_5.h \
    widget3_6.h \
    widget3_7.h \
    widget3_8.h \
    widget3_9.h \
    widget4.h \
    widget5.h \
    widget5_2.h

FORMS += \
    change_screentip.ui \
    fixedval_widget.ui \
    key_board.ui \
    myprogressbar.ui \
    offset_knife.ui \
    plc_fun_cmd.ui \
    plc_plc_pic.ui \
    popupwin.ui \
    popupwin1.ui \
    popupwin_left.ui \
    process_modify.ui \
    set_dgn.ui \
    set_plc_plc.ui \
    set_widget.ui \
    wedget1.ui \
    widget.ui \
    widget2.ui \
    widget2_workpic.ui \
    widget3.ui \
    widget3_10.ui \
    widget3_11.ui \
    widget3_12.ui \
    widget3_13.ui \
    widget3_14.ui \
    widget3_15.ui \
    widget3_2.ui \
    widget3_3.ui \
    widget3_4.ui \
    widget3_5.ui \
    widget3_6.ui \
    widget3_7.ui \
    widget3_8.ui \
    widget3_9.ui \
    widget4.ui \
    widget5.ui \
    widget5_2.ui

TRANSLATIONS += \
    BLUE_zh_CN.ts

INCLUDEPATH += $$PWD/sdk

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    image.qrc
