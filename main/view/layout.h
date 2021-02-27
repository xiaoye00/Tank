#pragma once

#include <QObject>
#include <QString>

#include "../widget/dice.h"
#include "box.h"
#include "graphics_scene.h"
#include "item_manager.h"
#include "layout_def.h"

namespace tank {
class Layout : public QObject {
    Q_OBJECT
  public:
    Layout();
    ~Layout();

    void addScene(GraphicsScene* scene) { scene_ = scene; };
    void setPaceSize(int size) { pace_size_ = size; };
    void initiation();
    auto setViewArea(int w, int h) {
        view_w_ = w;
        view_h_ = h;
    };

    auto   getViewAreaW() { return view_w_; };
    auto   getViewAreaH() { return view_h_; };
    QPoint getPlayerView();
    // Dice* dice{nullptr};

  signals:
    void signalShowDice();
    void signalUpdateItems();
    void signalUpdateView(QPoint);

  public slots:
    void slotRunTasks();
    void slotShowDice();

  private:
    GraphicsScene* scene_{nullptr};
    ItemManager*   item_manager{nullptr};
    int            pace_size_{0};
    int            view_w_{0};
    int            view_h_{0};
};
} // namespace tank