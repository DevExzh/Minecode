#-------------------------------------------------
#
# Project created by QtCreator 2018-07-18T17:06:53
#
#-------------------------------------------------

QT       += core gui
CONFIG += qscintilla2_qt5 c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Minecode
TEMPLATE = app
RC_FILE = "publish.rc"
TRANSLATIONS = Language\minecode_zh-CN.ts

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    newprojectdialog.cpp \
    statisticaldatadialog.cpp \
    studioconfigdialog.cpp \
    eprocesswindow.cpp \
    minecodedesigner.cpp \
    #GraphicsItem/item_commandblock.cpp \
    minecodelayerview.cpp \
    layermapscence.cpp \
    LayerDesinger/newlayerdialog.cpp \
    #exzhopenglwidget.cpp \
    #switchpldialog.cpp \
    #MinecodeLexer/lexer_cbpp.cpp \
    Frameless/projectbuildoptiondialog.cpp \
    Frameless/findandreplacedialog.cpp \
    Inherit/exsplashscreen.cpp \
    Frameless/aboutdialog.cpp \
    InfoDialog/ssobjectdialog.cpp \
    InfoDialog/confirminstalldialog.cpp \
    ManagerDialog/pluginmanagerdialog.cpp \
    Support/nofocusdelegate.cpp \
    Inherit/autohidetabwidget.cpp \
    #Inherit/Threads/extappconfig.cpp \
    Helper/minecodestringhelper.cpp \
    InfoDialog/msgwindow.cpp \
    #GraphicsItem/item_redstone.cpp \
    #Designer/designermap.cpp

HEADERS += \
        mainwindow.h \
    newprojectdialog.h \
    statisticaldatadialog.h \
    studioconfigdialog.h \
    eprocesswindow.h \
    minecodedesigner.h \
    #GraphicsItem/item_commandblock.h \
    minecodelayerview.h \
    definition.h \
    layermapscence.h \
    LayerDesinger/newlayerdialog.h \
    #exzhopenglwidget.h \
    #switchpldialog.h \
    #MinecodeLexer/lexer_cbpp.h \
    Frameless/projectbuildoptiondialog.h \
    Frameless/findandreplacedialog.h \
    Inherit/exsplashscreen.h \
    Frameless/aboutdialog.h \
    InfoDialog/ssobjectdialog.h \
    InfoDialog/confirminstalldialog.h \
    ManagerDialog/pluginmanagerdialog.h \
    Support/nofocusdelegate.h \
    Inherit/autohidetabwidget.h \
    #Inherit/Threads/extappconfig.h \
    Helper/minecodestringhelper.h \
    InfoDialog/msgwindow.h \
    #GraphicsItem/item_redstone.h \
    #Designer/designermap.h

FORMS += \
        mainwindow.ui \
    newprojectdialog.ui \
    statisticaldatadialog.ui \
    studioconfigdialog.ui \
    eprocesswindow.ui \
    minecodedesigner.ui \
    LayerDesinger/newlayerdialog.ui \
    #switchpldialog.ui \
    Frameless/projectbuildoptiondialog.ui \
    Frameless/findandreplacedialog.ui \
    Frameless/aboutdialog.ui \
    InfoDialog/ssobjectdialog.ui \
    InfoDialog/confirminstalldialog.ui \
    ManagerDialog/pluginmanagerdialog.ui \
    InfoDialog/msgwindow.ui

RESOURCES += \
    Resources.qrc

DISTFILES +=

win32: LIBS += -L$$PWD/glut/ -lglut32
win32: LIBS += -L$$PWD/glut/ -lglut

INCLUDEPATH += $$PWD/glut
DEPENDPATH += $$PWD/glut

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lqscintilla2_qt5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lqscintilla2_qt5d
else:unix: LIBS += -L$$PWD/./ -lqscintilla2_qt5

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
