#include "mcprojectdialogprivate.h"

mcProjectDialogPrivate::mcProjectDialogPrivate(QObject *parent) : QObject(parent)
{
    // 初始化模型索引
    modelCpp();
    modelCSharp();
    modelCss();
    modelHtml();
    modelJavaScript();
    modelPython();
}

QStandardItemModel* mcProjectDialogPrivate::modelCpp()
{
    QStandardItemModel *itemModelCpp=new QStandardItemModel;
    itemModelCpp->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/application.svg")),tr("C/C++ Solution")));
    itemModelCpp->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/application.svg")),tr("C/C++ Console")));
    itemModelCpp->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/library.svg")),tr("C/C++ Library")));
    _modelMap["C/C++"]=itemModelCpp;
    return itemModelCpp;
}

QStandardItemModel* mcProjectDialogPrivate::modelCSharp()
{
    QStandardItemModel *itemModelCSharp=new QStandardItemModel;
    itemModelCSharp->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/form.svg")),tr("C# Form")));
    itemModelCSharp->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/library.svg")),tr("C# Library")));
    _modelMap["C#"]=itemModelCSharp;
    return itemModelCSharp;
}

QStandardItemModel* mcProjectDialogPrivate::modelCss()
{
    QStandardItemModel *itemModelCss=new QStandardItemModel;
    itemModelCss->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/language-css3.svg")),tr("Cascading Style Sheets File")));
    _modelMap["CSS"]=itemModelCss;
    return itemModelCss;
}

QStandardItemModel* mcProjectDialogPrivate::modelHtml()
{
    QStandardItemModel *itemModelHtml=new QStandardItemModel;
    itemModelHtml->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/language-html5.svg")),tr("HTML File")));
    _modelMap["HTML"]=itemModelHtml;
    return itemModelHtml;
}

QStandardItemModel* mcProjectDialogPrivate::modelJavaScript()
{
    QStandardItemModel *itemModelJavaScript=new QStandardItemModel;
    itemModelJavaScript->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/language-javascript.svg")),tr("JavaScript File")));
    _modelMap["JavaScript"]=itemModelJavaScript;
    return itemModelJavaScript;
}

QStandardItemModel* mcProjectDialogPrivate::modelPython()
{
    QStandardItemModel *itemModelPython=new QStandardItemModel;
    itemModelPython->appendRow(new QStandardItem(QIcon(QStringLiteral(":/types/resources/types/language-python.svg")),tr("Python File")));
    _modelMap["Python"]=itemModelPython;
    return itemModelPython;
}

QStandardItemModel* mcProjectDialogPrivate::modelFromString(const QString &language)
{
    return _modelMap[language];
}
