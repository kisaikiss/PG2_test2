#pragma once
#include "IOnChangedListener.h"

//各シーンの元となるクラス
class AbstractScene {
protected:
    IOnSceneChangedListener* implSceneChanged_;//シーンの遷移に使う
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="impl">シーン変更前のリスナー</param>
    AbstractScene(IOnSceneChangedListener* impl);
    virtual ~AbstractScene() = default;
    virtual void Update() = 0;
    virtual void Draw() const = 0;
};
