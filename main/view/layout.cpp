#include "layout.h"
#include "../widget/dice.h"

#include "config.h"
#include "db.h"
#include "item_pace.h"
#include "item_player.h"
#include "player.h"
#include "transform.h"
#include "util.h"
namespace tank {
Layout::Layout() {
    item_manager = new ItemManager;
    getRondomNumber(10);
    // dice = new Dice;
}

Layout::~Layout() {
}

void Layout::initiation() {
    auto xml_path = InstallPath();
    xml_path += "map_demo.xml";
    Config config;
    auto   path = xml_path.c_str();
    config.loadDesign(path);
    auto db                 = DB::getInstance();
    auto [scene_w, scene_h] = db->MapSize();
    scene_->setSize(scene_w, scene_h);
    auto paces = db->getPaces();
    for (auto& pace : *paces) {
        auto item = item_manager->createItemPace(pace);
        scene_->addItem(item);
    }

    auto buildings = db->getBuildings();
    for (auto& building : *buildings) {
        auto item = item_manager->createItemBuilding(building);
        scene_->addItem(item);
    }

    auto players = db->getPlayers();
    for (auto& player : *players) {
        auto size = paces->size();
        auto pos  = getRondomNumber(size - 1);
        auto pace = (*paces)[pos];
        player->setPosition(pos);
        player->setPace(pace);
        auto orient = getRondomNumber(1);
        player->setOrient(orient);
        auto item = item_manager->createItemPlayer(player);
        scene_->addItem(item);
    }

    //who first
    auto who    = getRondomNumber(1);
    auto player = db->getPlayerByID(who);
    setCurrentPlayerID(who);

    auto point = getPlayerView();

    emit signalUpdateView(point);

    // connect(dice, &Dice::signalPostDice, this, &Layout::slotRunTasks);
    // connect(this, &Layout::signalShowDice, this, &Layout::slotShowDice);
}

QPoint Layout::getPlayerView() {
    auto item_player = item_manager->getCurrentItemPlayer();
    auto player      = item_player->getPlayer();
    auto box         = player->getBox();

    QPoint point;
    //calculate left
    auto lux = box->LUX() - view_w_ / 2;

    auto scene_w = scene_->width();
    auto scene_h = scene_->height();
    //out of left threshold
    if (lux < -scene_w / 2) {
        point.setX(-scene_w / 2);
        // rect.setWidth(view_w_);
    } else {
        point.setX(lux);
    }
    // calculate right
    auto rlx = box->RLX() + view_w_ / 2;
    //out of right threshold
    if (rlx > scene_w / 2) {
        point.setX(scene_w / 2 - view_w_);
        // rect.setWidth(view_w_);
    }

    //calculate top
    auto luy = box->LUY() - view_h_ / 2;
    //out of top threshold
    if (luy < -scene_h / 2) {
        point.setY(-scene_h / 2);
        // rect.setHeight(view_h_);
    } else {
        point.setY(luy);
    }

    //calculate bottom
    auto rly = box->RLY() + view_h_ / 2;
    //out of bottom threshold
    if (rly > scene_h / 2) {
        /* code */
        point.setY(scene_h / 2 - view_h_);
        // rect.setHeight(view_h_);
    }

    return point;
}

void Layout::slotRunTasks() {
    auto item_player = item_manager->getCurrentItemPlayer();
    auto player      = item_player->getPlayer();
    auto run_steps   = player->RunSteps();
    auto db          = DB::getInstance();
    auto paces       = db->getPaces();
    if (player->Orient() == GoOrient::kGoAhead) {
        while (*run_steps) {
            (*run_steps)--;
            player->setPosition((player->Position() + 1) % db->getNumPaces());
            auto pace = (*paces)[player->Position()];
            player->setPace(pace);
            item_player->refreshItem();
        }
    } else {
        while (*run_steps) {
            (*run_steps)--;
            player->setPosition((player->Position() - 1 + db->getNumPaces()) % db->getNumPaces());
            auto pace = (*paces)[player->Position()];
            player->setPace(pace);
            item_player->refreshItem();
        }
    }

    auto pace = player->getPace();

    auto building = pace->getAssociateBuilding();

    if (building) {
        if (!building->getOwner()) {
            building->setOwner(player);
        }

        auto item_building = item_manager->getItemBuildingByBuilding(building);

        item_building->preDraw();

        item_building->update();
    }

    setCurrentPlayerID(getNextPlayerID());

    auto point = getPlayerView();

    emit signalUpdateView(point);

    emit signalShowDice();
}

void Layout::slotShowDice() {
    // dice->resetData();

    emit signalUpdateItems();
}
} // namespace tank
