#pragma once

#include <QObject>
#include <QString>

#include "../widget/dice.h"
#include "graphics_scene.h"
#include "item_manager.h"
#include "layout_def.h"
namespace Tank {
class Layout : public QObject {
    Q_OBJECT
  public:
    Layout();
    ~Layout();

    void  addScene(GraphicsScene* scene) { scene_ = scene; };
    void  setPaceSize(int size) { pace_size_ = size; };
    void  initiation();
    Dice* dice{nullptr};

  signals:
    void signalShowDice();
    void signalUpdateItems();

  public slots:
    void slotRunTasks();
    void slotShowDice();

  private:
    GraphicsScene* scene_{nullptr};
    ItemManager*   item_manager{nullptr};
    int            pace_size_{0};
};
} // namespace Tank