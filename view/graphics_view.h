#pragma once

#include <QGraphicsView>

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

  private:
    //scene of this view
    // GraphicsScene* scene_;
    //for singleton pattern
    static GraphicsView* inst_;

    GraphicsView(QWidget* parent = nullptr);
};