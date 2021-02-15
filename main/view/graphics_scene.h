#pragma once

#include <QGraphicsScene>

class GraphicsScene : public QGraphicsScene {
    Q_OBJECT
  public:
    explicit GraphicsScene(QObject* parent = nullptr);
    ~GraphicsScene(){};
    void setSize(int w, int h);
  protected:
    virtual void drawBackground(QPainter* painter, const QRectF& rect) override;
};