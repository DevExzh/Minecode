#ifndef DEFINITION_H
#define DEFINITION_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QObject>

class MinecodeType
{
public:
    enum CommandTextureType
    {
        Impulse_Normal,Impulse_Conditional,
        Chain_Normal,Chain_Conditional,
        Repeat_Normal,Repeat_Conditional
    };

    int layerWidth;
    int layerHeight;
};

class MinecodeFunction
{
public:
    static void deletePointerToNULL(QObject *obj)
    {
        delete obj;
        obj=NULL;
    }
    static void deletePointerToNULL(QObject *obj1,QObject *obj2)
    {
        delete obj1;
        delete obj2;
        obj1=NULL; obj2=NULL;
    }
    static void deletePointerToNULL(QObject *obj1,QObject *obj2,QObject *obj3)
    {
        delete obj1;
        delete obj2;
        delete obj3;
        obj1=NULL; obj2=NULL; obj3=NULL;
    }
};

class SettingPanel
{
public:
enum SettingPanelPage
{
    Welcome,General,UI,Generate,DevTool,
    CodeEditor,Console,Notice,Document,IO,Advance
};
};

#endif // DEFINITION_H
