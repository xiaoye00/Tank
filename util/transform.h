#pragma once



class Transform {
  public:
    Transform();
    Transform(int w, int h);
    ~Transform();

    template <typename T>
    auto translateToSceneBox(T box) {

        auto lux = -scene_w_ / 2 + box->LUX();
        auto luy = -scene_h_ / 2 + box->LUY();
        auto rlx = -scene_w_ / 2 + box->RLX();
        auto rly = -scene_h_ / 2 + box->RLY();

        box->setLUX(lux);
        box->setLUY(luy);
        box->setRLX(rlx);
        box->setRLY(rly);

        return box;
    };

    void setSceneW(int w) { scene_w_ = w; };
    void setSceneH(int h) { scene_h_ = h; };

  private:
    int scene_w_{0};
    int scene_h_{0};
};