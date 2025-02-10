#pragma once
#include <stack>
#include <memory>
#include "AbstractScene.h"
#include "IOnChangedListener.h"

class Looper final : public IOnSceneChangedListener
{
public:
    Looper();
    ~Looper();
    bool Loop() const;

    /// <summary>
    /// シーン変更
    /// </summary>
    /// <param name="scene">変更するシーンのenum</param>
    /// <param name="stackClear">現在のシーンのスタックを消すか</param>
    void OnSceneChanged(const eSCENE scene, const bool stackClear) override;

    /// <summary>
   /// 現在のシーンをポップする
   /// </summary>
    void ScenePop() override;

private:
    std::stack<std::shared_ptr<AbstractScene>> sceneStack_; //シーンのスタック
};