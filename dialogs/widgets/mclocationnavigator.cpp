#include "mclocationnavigator.h"

mcLocationNavigator::mcLocationNavigator(QWidget *parent) :
    QWidget(parent),
    controlContainer(new QHBoxLayout)
{
    this->setLayout(controlContainer);
    controlContainer->setContentsMargins(0,0,0,0);
    controlContainer->setSpacing(0);
}

void mcLocationNavigator::addController(const QString &name)
{
    controlContainer->addWidget([=]()->mcNavigatorControlItem*{
        mcNavigatorControlItem *item=new mcNavigatorControlItem;
        item->setControlName(name);
        itemTable[name]=item;
        itemTableIndex[itemTableIndex.count()]=name;

        connect(item,&mcNavigatorControlItem::arrowMenuQuested,[=](QMenu *menu){
            emit itemMenuQuested(menu,QPoint(item->pos().x()+item->width()-item->arrowButtonSize().width()/2
                                             ,item->pos().y()+this->height()));
        });
        return item;
    }());
}

void mcLocationNavigator::setCurrentLocation(const QString &path)
{
    QString modifiedPath=path;
    if(!path.endsWith("/"))
        modifiedPath+="/";
    QStringList pathList;
    QList<int> characterList;
    for(int i=0;i<modifiedPath.length();++i)
    {
        if(modifiedPath[i]=="/")
        {
            if(characterList.count()==0)
            {
                pathList+=modifiedPath.mid(0,i).replace("/","");
            }
            else
            {
                pathList+=modifiedPath.mid(characterList[characterList.count()-1]+1,i-characterList[characterList.count()-1]).replace("/","");
            }
            characterList+=i;
        }
    }

    for(int i=0;i<characterList.count();++i)
    {
        this->addController(pathList[i]);
    }

    qDebug("Minecode Location Navigator has been set to "+path.toLocal8Bit());
}
