#pragma once
#include "Matrix3x3.h"
#include "Vector2.h"
#include "Vertex.h"

/// <summary>
/// 逆行列を作る
/// </summary>
/// <param name="matrix">行列</param>
/// <returns>受け取った行列の逆行列</returns>
Matrix3x3 Inverse(Matrix3x3 const& matrix);

/// <summary>
/// 受け取った2つの行列を乗算する
/// </summary>
/// <param name="matrix1">行列1</param>
/// <param name="matrix2">行列2</param>
/// <returns>乗算結果</returns>
Matrix3x3 Multiply(Matrix3x3 const& matrix1, Matrix3x3 const& matrix2);

/// <summary>
/// 正射影行列を作る
/// </summary>
/// <param name="left">左端</param>
/// <param name="top">上端</param>
/// <param name="right">右端</param>
/// <param name="bottom">下端</param>
/// <returns>正射影行列</returns>
Matrix3x3 MakeOrthographicMatrix(float const& left, float const& top, float const& right, float const& bottom);

/// <summary>
/// ビューポート行列を作る
/// </summary>
/// <param name="left">左端</param>
/// <param name="top">上端</param>
/// <param name="width">画面の横幅</param>
/// <param name="height">画面の縦幅</param>
/// <returns>ビューポート行列</returns>
Matrix3x3 MakeViewportMatrix(float const& left, float const& top, float const& width, float const& height);

/// <summary>
/// 拡縮行列を作る
/// </summary>
/// <param name="scale">拡縮率</param>
/// <returns>拡縮行列</returns>
Matrix3x3 MakeScaleMatrix(Vector2 const& scale);

/// <summary>
/// 回転行列を作る
/// </summary>
/// <param name="theta">回転角</param>
/// <returns>回転行列</returns>
Matrix3x3 MakeRotateMatrix(float const& theta);

/// <summary>
/// 移動行列を作る
/// </summary>
/// <param name="translate">移動量</param>
/// <returns>移動行列</returns>
Matrix3x3 MakeTranslateMatrix(Vector2 const& translate);

/// <summary>
/// アフィン変換する
/// </summary>
/// <param name="scale">拡縮率</param>
/// <param name="rotate">回転角</param>
/// <param name="translate">移動量</param>
/// <returns>アフィン行列</returns>
Matrix3x3 MakeAffineMatrix(Vector2 const& scale, float const& rotate, Vector2 const& translate);

/// <summary>
/// トランスフォームする
/// </summary>
/// <param name="vector">ベクトル</param>
/// <param name="matrix">行列</param>
/// <returns>トランスフォーム結果</returns>
Vector2 Transform(Vector2 const& vector, Matrix3x3 const& matrix);

/// <summary>
/// 四頂点をトランスフォームする
/// </summary>
/// <param name="vertex">四頂点</param>
/// <param name="matrix">行列</param>
/// <returns>トランスフォーム結果</returns>
Vertex VertexTransform(Vertex const& vertex, Matrix3x3 const& matrix);

static const int kRowHeight = 20;
static const int kColumnWidth = 70;

/// <summary>
/// 行列の中身をデバッグ用に描画
/// </summary>
/// <param name="x">描画位置X</param>
/// <param name="y">描画位置Y</param>
/// <param name="matrix">中身を確認したい行列</param>
void MatrixScreenPrintf(int x, int y, Matrix3x3 matrix);
