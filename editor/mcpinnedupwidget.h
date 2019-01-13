#ifndef MCPINNEDUPWIDGET_H
#define MCPINNEDUPWIDGET_H

#include <QWidget>

// 简单封装 QWidget
// 做 mcEditorToolBoxSplitter 的辅助类
class mcPinnedUpWidget : public QWidget
{
    Q_OBJECT
public:
    explicit mcPinnedUpWidget(QWidget *parent = nullptr);

signals:
    void pinned(bool isPinned);

public slots:
    void setPinned(bool isPinned)
    {
        _isPinned=isPinned;
        emit pinned(isPinned);
    }

protected:
    bool _isPinned;
};

#endif // MCPINNEDUPWIDGET_H
