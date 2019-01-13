#ifndef MCEDITOR_H
#define MCEDITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <Qsci/qscilexer.h>
#include <Qsci/qsciscintilla.h>

class mcEditor : public QWidget
{
    Q_OBJECT
public:
    explicit mcEditor(QWidget *parent = nullptr);

signals:
    void lexerChanged();
    void statusChanged(const QString &status);

public slots:
    void setLexer(QsciLexer *lexer);
    void setFont(const QFont &font);
    void updateEditorStatus();

protected:
    QsciScintilla *_editorBase;
    QFont *_code_font;
    QString statusText;
};

#endif // MCEDITOR_H
