#-------------------------------------------------
#
# Project created by QtCreator 2018-12-22T12:02:18
#
#-------------------------------------------------

QT       += core gui

RC_FILE = "icon/release.rc"

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Minecode
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_MESSAGELOGCONTEXT

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        minecode.cpp \
    services/exfontprovider.cpp \
    services/exconfigprovider.cpp \
    dialogs/mcprojectdialog.cpp \
    dialogs/mcemptycodeeditorwidget.cpp \
    plugins/minecodeplugin.cpp \
    dialogs/models/mcprojectdialogprivate.cpp \
    dialogs/mcfiledialog.cpp \
    dialogs/delegate/nofocusdelegate.cpp \
    editor/mceditor.cpp \
    editor/mceditortoolbox.cpp \
    editor/mceditortoolboxsplitter.cpp \
    editor/mcpinnedupwidget.cpp \
    dialogs/mcbusywindow.cpp \
    dialogs/mcpreferencedialog.cpp \
    editor/infodialogs/mceditorstatisticsdialog.cpp \
    editor/build-in/mcpgeneralpage.cpp \
    editor/build-in/mcpuserinterfacepage.cpp \
    editor/build-in/mcpnetworkpage.cpp \
    editor/build-in/mcpenvironmentpage.cpp \
    editor/build-in/mcpeditorpage.cpp \
    services/exstyleprovider.cpp \
    dialogs/mcaboutdialog.cpp \
    editor/build-in/mcppagesmanagement.cpp \
    dialogs/widgets/mclocationnavigator.cpp \
    dialogs/widgets/mcnavigatorcontrolitem.cpp \
    dialogs/widgets/mcmessagelabel.cpp \
    dialogs/widgets/mcnotification.cpp \
    exglobal.cpp \
    services/mcconsole.cpp \
    services/mcconsoleparser.cpp

HEADERS += \
        minecode.h \
    services/exfontprovider.h \
    services/exconfigprovider.h \
    exglobal.h \
    dialogs/mcprojectdialog.h \
    dialogs/mcemptycodeeditorwidget.h \
    plugins/minecodeplugin.h \
    dialogs/models/mcprojectdialogprivate.h \
    dialogs/mcfiledialog.h \
    dialogs/delegate/nofocusdelegate.h \
    editor/mceditor.h \
    editor/mceditortoolbox.h \
    editor/mceditortoolboxsplitter.h \
    editor/mcpinnedupwidget.h \
    dialogs/mcbusywindow.h \
    dialogs/mcpreferencedialog.h \
    editor/infodialogs/mceditorstatisticsdialog.h \
    editor/build-in/mcpgeneralpage.h \
    editor/build-in/mcpuserinterfacepage.h \
    editor/build-in/mcpnetworkpage.h \
    editor/build-in/mcpenvironmentpage.h \
    editor/build-in/mcpeditorpage.h \
    services/exstyleprovider.h \
    services/exprovider.h \
    dialogs/mcaboutdialog.h \
    mcDialogs \
    mcGlobal \
    editor/build-in/mcppagesmanagement.h \
    dialogs/widgets/mclocationnavigator.h \
    dialogs/widgets/mcnavigatorcontrolitem.h \
    dialogs/widgets/mcmessagelabel.h \
    dialogs/widgets/mcnotification.h \
    mcDefaultStyleSheets \
    services/mcconsole.h \
    services/mcconsoleparser.h

FORMS += \
        minecode.ui \
    dialogs/mcprojectdialog.ui \
    dialogs/mcemptycodeeditorwidget.ui \
    dialogs/mcfiledialog.ui \
    dialogs/mcbusywindow.ui \
    dialogs/mcpreferencedialog.ui \
    editor/build-in/mcpgeneralpage.ui \
    editor/build-in/mcpuserinterfacepage.ui \
    editor/build-in/mcpnetworkpage.ui \
    editor/build-in/mcpenvironmentpage.ui \
    editor/build-in/mcpeditorpage.ui \
    dialogs/mcaboutdialog.ui \
    dialogs/widgets/mcnotification.ui

RESOURCES += \
    resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libraries/MinGW/ -llibpluma.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libraries/MinGW/ -llibpluma-d.dll
else:mac: LIBS += -F$$PWD/libraries/MinGW/ -framework libpluma.dll
else:unix: LIBS += -L$$PWD/libraries/MinGW/ -llibpluma.dll

INCLUDEPATH += $$PWD/libraries/MinGW
DEPENDPATH += $$PWD/libraries/MinGW

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libraries/MinGW/ -lqscintilla2_qt5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libraries/MinGW/ -lqscintilla2_qt5d
else:mac: LIBS += -F$$PWD/libraries/MinGW/ -framework qscintilla2_qt5
else:unix: LIBS += -L$$PWD/libraries/MinGW/ -lqscintilla2_qt5

INCLUDEPATH += $$PWD/libraries/MinGW
DEPENDPATH += $$PWD/libraries/MinGW
