#include "layermapscence.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

/*
LayerMapScence::LayerMapScence(QObject *parent) : QGraphicsScene(parent) : mCellSize(32,32)
{

}
*/

void LayerMapScence::drawBackground(QPainter *painter, const QRectF &rect)
{
    qreal left = int(rect.left()) - (int(rect.left()) % mCellSize.width());
    qreal top = int(rect.top()) - (int(rect.top()) % mCellSize.height());

    QVarLengthArray<QLineF, 100> lines;

    for (qreal x = left; x < rect.right(); x += mCellSize.width())
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for (qreal y = top; y < rect.bottom(); y += mCellSize.height())
        lines.append(QLineF(rect.left(), y, rect.right(), y));

    painter->drawLines(lines.data(), lines.size());
}

void LayerMapScence::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mDragged = qgraphicsitem_cast<QGraphicsItem*>(itemAt(mouseEvent->scenePos(), QTransform()));
    if (mDragged) {
        mDragOffset = mouseEvent->scenePos() - mDragged->pos();
    } else
        QGraphicsScene::mousePressEvent(mouseEvent);
}

void LayerMapScence::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mDragged) {
        // Ensure that the item's offset from the mouse cursor stays the same.
        mDragged->setPos(mouseEvent->scenePos() - mDragOffset);
    } else
        QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void LayerMapScence::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mDragged) {
        int x = floor(mouseEvent->scenePos().x() / mCellSize.width()) * mCellSize.width();
        int y = floor(mouseEvent->scenePos().y() / mCellSize.height()) * mCellSize.height();
        mDragged->setPos(x, y);
        mDragged = 0;
    } else
        QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
