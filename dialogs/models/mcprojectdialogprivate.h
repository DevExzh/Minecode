#ifndef MCPROJECTDIALOGPRIVATE_H
#define MCPROJECTDIALOGPRIVATE_H

#include <QObject>
#include <QStandardItemModel>
#include <QMap>

class mcProjectDialogPrivate : public QObject
{
    Q_OBJECT
public:
    explicit mcProjectDialogPrivate(QObject *parent = nullptr);

    // 各种内置支持的语言模板
    QStandardItemModel* modelCpp();
    QStandardItemModel* modelPython();
    QStandardItemModel* modelCss();
    QStandardItemModel* modelHtml();
    QStandardItemModel* modelCSharp();
    QStandardItemModel* modelJavaScript();

    // 根据名字来索引模型
    QStandardItemModel* modelFromString(const QString &language);

protected:
    QMap<QString,QStandardItemModel* > _modelMap;
};

#endif // MCPROJECTDIALOGPRIVATE_H
