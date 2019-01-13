#include "mceditor.h"

mcEditor::mcEditor(QWidget *parent):
    QWidget(parent),
    _editorBase(new QsciScintilla)
{
    //行号显示区域
    _editorBase->setMarginType(1, QsciScintilla::NumberMargin);
    _editorBase->setMarginLineNumbers(1, true);
    _editorBase->setMarginWidth(1,54);
    _editorBase->setMarginSensitivity(1, true);
    //断点设置区域
    _editorBase->setMarginType(0, QsciScintilla::SymbolMargin);
    _editorBase->setMarginLineNumbers(0, false);
    _editorBase->setMarginWidth(0,10);
    _editorBase->setMarginSensitivity(0, true);    //设置是否可以显示断点
    _editorBase->setMarginsBackgroundColor(QColor("#f0f0f0"));
    _editorBase->setMarginMarkerMask(0, QsciScintilla::SC_MASK_FOLDERS);
    connect(_editorBase,&QsciScintilla::marginClicked,[=](int margin,int line,Qt::KeyboardModifiers state)
    {
        Q_UNUSED(state);
        if (margin == 0) {
            if (_editorBase->markersAtLine(line) != 0) {
                _editorBase->markerDelete(line, 0);
    //            做一些去掉断点的逻辑程序
            } else {
                _editorBase->markerAdd(line, 0);
    //            做一些增加断点的逻辑程序
            }
        }
    });
    _editorBase->markerDefine(QsciScintilla::MarkerSymbol::Circle, 0);
    _editorBase->setMarkerBackgroundColor(QColor("#f44336"), 0);
    _editorBase->setMarkerForegroundColor(QColor(Qt::transparent),0);
    //单步执行显示区域
    _editorBase->setMarginType(2, QsciScintilla::SymbolMargin);
    _editorBase->setMarginLineNumbers(2, false);
    _editorBase->setMarginWidth(2, 20);
    _editorBase->setMarginSensitivity(2, false);
    _editorBase->setMarginMarkerMask(2, 0x04);
    _editorBase->markerDefine(QsciScintilla::RightArrow, 2);
    _editorBase->setMarkerBackgroundColor(QColor("#eaf593"), 2);
    //自动折叠区域
    _editorBase->setMarginType(3, QsciScintilla::SymbolMargin);
    _editorBase->setMarginLineNumbers(3, false);
    _editorBase->setMarginWidth(3, 15);
    _editorBase->setMarginSensitivity(3, true);

    _editorBase->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CHARSET_ANSI);
    _editorBase->setScrollWidthTracking(true);
    _editorBase->setScrollWidth(1);

    QPointer<QVBoxLayout> codeEditorContainer=new QVBoxLayout;
    codeEditorContainer->addWidget(_editorBase);
    codeEditorContainer->setMargin(0);

    connect(_editorBase,&QsciScintilla::cursorPositionChanged,[=](int line,int index)
    {
        Q_UNUSED(line);
        Q_UNUSED(index);
        updateEditorStatus();
    });

    this->setLayout(codeEditorContainer);
}

void mcEditor::setLexer(QsciLexer *lexer)
{
    _editorBase->setLexer(lexer);
}

void mcEditor::setFont(const QFont &font)
{
    _editorBase->setFont(font);
}

void mcEditor::updateEditorStatus()
{
    if(_editorBase->selectedText().length()==0)
    {
        statusText=(
                    tr("Line: %1").arg((_editorBase->SendScintilla(_editorBase->SCI_LINEFROMPOSITION,_editorBase->SCI_GETCURRENTPOS))+1L)+
                    +"  "
                    +tr("Column: %1").arg(_editorBase->SendScintilla(_editorBase->SCI_GETCOLUMN,_editorBase->SendScintilla(_editorBase->SCI_GETCURRENTPOS)))+
                    +"  <font color=gray>|</font>  "
                    +tr("All: %1 Lines").arg(_editorBase->SendScintilla(_editorBase->SCI_GETLINECOUNT))
                    +"  <font color=gray>|</font>  "
                    );
    }
}
