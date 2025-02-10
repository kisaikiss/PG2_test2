#pragma once
#include "eScene.h"
class IOnSceneChangedListener {
public:
    IOnSceneChangedListener() = default;
    virtual ~IOnSceneChangedListener() = default;
    /// <summary>
    /// シーンを変える
    /// </summary>
    /// <param name="scene">変えたいシーンのenum</param>
    /// <param name="stackClear">スタックをクリアするか</param>
    virtual void OnSceneChanged(const eSCENE scene, const bool stackClear) = 0;

    /// <summary>
    /// 現在のシーンをポップする
    /// </summary>
    virtual void ScenePop() = 0;
};