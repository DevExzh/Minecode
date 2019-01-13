#ifndef EXPROVIDER_H
#define EXPROVIDER_H

#include <QObject>

// 所有 Provider 的基类，实现的 Provider 必须继承此类
// 在 Minecode Studio Release 4 时更改
class exProvider : public QObject
{
    Q_OBJECT
public:
    explicit exProvider(QObject *parent = nullptr);
    virtual QStringList search(const QString &path)=0;
    virtual int counts()=0;

private:
    virtual void initialize()=0;
};

#endif // EXPROVIDER_H
