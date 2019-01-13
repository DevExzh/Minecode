#ifndef NOFOCUSDELEGATE_H
#define NOFOCUSDELEGATE_H

#include <QStyledItemDelegate>

class NoFocusDelegate : public QStyledItemDelegate
{
public:
    NoFocusDelegate();
    ~NoFocusDelegate();

private:
    void paint(QPainter *painter,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

#endif // NOFOCUSDELEGATE_H
