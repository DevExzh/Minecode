#include "minecodedesigner.h"
#include "ui_minecodedesigner.h"
#include "mainwindow.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

MinecodeDesigner::MinecodeDesigner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MinecodeDesigner)
{
    ui->setupUi(this);
    setCentralWidget(ui->MultiViewEditor);
    QPointer<MinecodeLayerView> layerView = new MinecodeLayerView();
    QPointer<QOpenGLWidget> openGLW=new QOpenGLWidget();
    QPointer<LayerMapScence> layerViewScence=new LayerMapScence();
    layerView->setScene(layerViewScence);
    layerView->setFrameStyle(QFrame::NoFrame);
    layerView->setContextMenuPolicy(Qt::CustomContextMenu);
    layerView->setRenderHint(QPainter::Antialiasing);//指定Render标签，抗锯齿
    layerView->setDragMode(QGraphicsView::ScrollHandDrag);//拖动模式，鼠标可拖动
    ui->MultiViewEditor->addWidget(layerView);
    ui->MultiViewEditor->addWidget(openGLW);
    QPointer<NewLayerDialog> nlyr=new NewLayerDialog();
    connect(layerView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showNewItemMenu(QPoint)));
    connect(ui->actionMenu_Layer,SIGNAL(triggered()),nlyr,SLOT(show()));

    toolSelectGroup = new QActionGroup(this);
    toolSelectGroup->addAction(ui->actionSelect_Tool);
    toolSelectGroup->addAction(ui->actionHand_Tool);
    toolSelectGroup->addAction(ui->actionZoom_Tool);
    toolSelectGroup->addAction(ui->actionRotate_Tool);
    toolSelectGroup->setExclusive(true);

    dementionGroup = new QActionGroup(this);
    dementionGroup->addAction(ui->action2DView);
    dementionGroup->addAction(ui->action3DView);

    connect(toolSelectGroup,SIGNAL(triggered(QAction*)),this,SLOT(selectToolChanged(QAction*)));
    connect(dementionGroup,SIGNAL(triggered(QAction*)),this,SLOT(dementionChanged(QAction*)));

    ui->objectViewer->setHeaderLabels(QStringList()<<tr("Object")<<tr("Type"));
    ui->cmdEditor->setHeaderLabels(QStringList()<<tr("Object")<<tr("Command"));

    setTreeWidgetStyle(ui->objectViewer);
    setTreeWidgetStyle(ui->cmdEditor);
/*
    QPolygonF myPolygon1;
    myPolygon1 << QPointF(0,10) << QPointF(20,10);
    QPolygonF myPolygon2;
    myPolygon2 << QPointF(10,0) << QPointF(10,20);
    QPixmap pixmap(20, 20);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);

    QVector<qreal> dashes;//line style--虚线
    qreal space = 2;
    dashes << 2 << space << 2 <<space;
    QPen pen(Qt::lightGray,1);
    pen.setDashPattern(dashes);
    pen.setWidth(1);

    painter.setPen(pen);
    painter.translate(0, 0);
    painter.drawPolyline(myPolygon1);
    painter.drawPolyline(myPolygon2);

    layerViewScence->setBackgroundBrush(pixmap);
    */
}

void MinecodeDesigner::setTreeWidgetStyle(QTreeWidget *wid)
{
    for(int i=0;i<wid->columnCount();i++)
    {
        wid->headerItem()->setTextAlignment(i,Qt::AlignHCenter | Qt::AlignVCenter);
        wid->headerItem()->setFont(i,QFont("方正黑体简体",9,QFont::Normal));
    }
}

MinecodeDesigner::~MinecodeDesigner()
{
    delete ui;
}

void MinecodeDesigner::UIRetranslate()
{
    this->ui->retranslateUi(this);
}

/*
void MinecodeDesigner::AddLayerViewItem(MinecodeType::CommandTextureType type)
{
    //QPointer<Item_CommandBlock> cbItem=new Item_CommandBlock();
    //cbItem->setCommandBlockType(type);
    //layerViewScence->addItem(cbItem);
}*/

void MinecodeDesigner::selectToolChanged(QAction *action)
{
    if(action == ui->actionSelect_Tool)
    {
        //TO DO
    }
    else if(action == ui->actionHand_Tool)
    {
        //TO DO
    }
    else if(action == ui->actionZoom_Tool)
    {
        //TO DO
    }
    else if(action == ui->actionRotate_Tool)
    {
        //TO DO
    }
}

void MinecodeDesigner::dementionChanged(QAction *action)
{
    if(action == ui->action2DView)
    {
        ui->MultiViewEditor->setCurrentIndex(0);
    }
    else if(action == ui->action3DView)
    {
        ui->MultiViewEditor->setCurrentIndex(1);
    }
}

/*
void MinecodeDesigner::LoadedStatusChanged()
{
    ui->toolBar->setEnabled(IsLoaded);
}
*/

/*
void MinecodeDesigner::ReadProjectFile(QString project)
{

}

void MinecodeDesigner::LoadTexturePack(QString location)
{

}*/

void MinecodeDesigner::on_actionMenu_Layer_triggered()
{
}

void MinecodeDesigner::showNewItemMenu(const QPoint& pos)
{
    Q_UNUSED(pos);
    if(newItemMenu)
    {
        delete newItemMenu;
        newItemMenu=NULL;
    }
    QMenu *newItemMenu=new QMenu();
    QMenu *newItemMenu_CB=new QMenu();
    newItemMenu_CB->setTitle(tr("New Command Block"));
    newItemMenu->addMenu(newItemMenu_CB);
    QAction *newItemMenu_CB_Impulse=newItemMenu_CB->addAction(tr("Impulse Command Block"));
    QAction *newItemMenu_CB_Chain=newItemMenu_CB->addAction(tr("Chain Command Block"));
    QAction *newItemMenu_CB_Repeat=newItemMenu_CB->addAction(tr("Repeat Command Block"));
    /*QAction *newItemMenu_NewLayer=*/newItemMenu->addAction(tr("New Layer"));
    newItemMenu->addSeparator();
    /*QAction *newItemMenu_CSignal=*/newItemMenu->addAction(tr("Create Signal"));
    /*QAction *newItemMenu_CScoreboard=*/newItemMenu->addAction(tr("Create Scoreboard Object"));
    /*QAction *newItemMenu_CDelay=*/newItemMenu->addAction(tr("Create Redstone Delay"));
    newItemMenu->addSeparator();
    /*QAction *newItemMenu_Cut=*/newItemMenu->addAction(tr("Cut"));
    /*QAction *newItemMenu_Copy=*/newItemMenu->addAction(tr("Copy"));
    /*QAction *newItemMenu_Paste=*/newItemMenu->addAction(tr("Paste"));
    /*QAction *newItemMenu_Delete=*/newItemMenu->addAction(tr("Delete"));
    /*QAction *newItemMenu_SelectAll=*/newItemMenu->addAction(tr("Select All"));

    connect(newItemMenu_CB_Impulse,SIGNAL(triggered(bool)),this,SLOT(newItemMenu_CB_Impulse_DoAction()));
    connect(newItemMenu_CB_Chain,SIGNAL(triggered(bool)),this,SLOT(newItemMenu_CB_Chain_DoAction()));
    connect(newItemMenu_CB_Repeat,SIGNAL(triggered(bool)),this,SLOT(newItemMenu_CB_Repeat_DoAction()));

    newItemMenu->exec(QCursor::pos());
}

void MinecodeDesigner::newItemMenu_CB_Impulse_DoAction()
{
    //AddLayerViewItem(MinecodeType::Impulse_Normal);
}

void MinecodeDesigner::newItemMenu_CB_Chain_DoAction()
{
    //AddLayerViewItem(MinecodeType::Chain_Normal);
}

void MinecodeDesigner::newItemMenu_CB_Repeat_DoAction()
{
    //AddLayerViewItem(MinecodeType::Repeat_Normal);
}

void MinecodeDesigner::removeAll()
{
    delete ui->menubar;
    delete ui->statusbar;
}
