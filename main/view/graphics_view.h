#pragma once

#include "layout.h"

#include <QGraphicsView>
#include <QScreen>
#include <QTimer>

namespace tank {
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

    Layout* getLayout() { return layout_; };

    void initiation();

  public slots:
    void slotShowDice();
    void slotDiceHide();
    void slotDiceShow();
    void slotViewCurrentPlayer(QPoint point);

  signals:
    void sendPos(int x, int y);

  protected:
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent* event) override;
    virtual void resizeEvent(QResizeEvent* event) override;

  private:
    //scene of this view
    GraphicsScene* scene_;
    //for singleton pattern
    static GraphicsView* inst_;

    Layout* layout_{nullptr};

    GraphicsView(QWidget* parent = nullptr);

    Dice* dice_{nullptr};

    QTimer* dice_timer_hide_{nullptr};
    QTimer* dice_timer_show_{nullptr};
    //screen information
    // QScreen*                screen_{nullptr};
};
} // namespace Tank