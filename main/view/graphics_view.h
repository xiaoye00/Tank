#pragma once

#include "layout.h"

#include <QGraphicsView>
namespace Tank {
class GraphicsView : public QGraphicsView {
    Q_OBJECT
  public:
    ~GraphicsView(){};

    static GraphicsView* getInstance() {
        if (!inst_) {
            inst_ = new GraphicsView;
        }
        return inst_;
    }

  signals:
    void sendPos(int x, int y);

  protected:
    virtual void mouseMoveEvent(QMouseEvent* event) override;

  private:
    //scene of this view
    GraphicsScene* scene_;
    //for singleton pattern
    static GraphicsView* inst_;

    Layout* layout_;

    GraphicsView(QWidget* parent = nullptr);
};
}