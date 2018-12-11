#ifndef EPROCESSWINDOW_H
#define EPROCESSWINDOW_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QDialog>
#include <QTimer>

namespace Ui {
class EProcessWindow;
}

class EProcessWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EProcessWindow(QWidget *parent = 0);
    ~EProcessWindow();

private:
    Ui::EProcessWindow *ui;
    QTimer *marqueeClock;
    bool isLeft;

private slots:
        void SetFormStyleFromSignal(QString);
        void SetFormFontFromSignal(QFont);
        void UIRetranslate();
        void MarqueeAnimation();
};

#endif // EPROCESSWINDOW_H
