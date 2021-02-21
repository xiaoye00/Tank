
#include "graphics_scene.h"
namespace Tank {
GraphicsScene::GraphicsScene(QObject* parent) : QGraphicsScene(parent) {
}

void GraphicsScene::setSize(int w, int h) {
    //set scene and item size
    setSceneRect((-w) / 2,
                 (-h) / 2,
                 w,
                 h);
}

void GraphicsScene::drawBackground(QPainter* painter, const QRectF& rect) {
}
}
