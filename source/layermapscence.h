#ifndef LAYERMAPSCENCE_H
#define LAYERMAPSCENCE_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <vector>
#include <math.h>

using namespace std;
//typedef vector<Item_CommandBlock*> mapRow;
//typedef vector<mapRow> blockMap;

class LayerMapScence : public QGraphicsScene
{
    Q_OBJECT
public:
    //explicit LayerMapScence(QObject *parent = 0);
    LayerMapScence():
        mCellSize(32,32){}
    static int mapHeight,mapWidth;
    void removeAllBlocks();
    //blockMap map;

protected:
    virtual void drawBackground(QPainter *painter, const QRectF &rect) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    // The size of the cells in the grid.
    const QSize mCellSize;
    // The item being dragged.
    QGraphicsItem *mDragged;
    // The distance from the top left of the item to the mouse position.
    QPointF mDragOffset;
};

#endif // LAYERMAPSCENCE_H
