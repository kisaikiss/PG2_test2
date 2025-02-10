#pragma once
#include "Vertex.h"
#include "Matrix3x3.h"

/// <summary>
/// 画像を描画する
/// </summary>
/// <param name="localVertex">描画したいオブジェクトのローカル座標での四頂点</param>
/// <param name="worldMatrix">描画したいオブジェクトのワールド行列</param>
/// <param name="vpVpMatrix">描画したい行列をスクリーン座標へ変換するための行列</param>
/// <param name="graphCropPos">描画したい画像を切り取る位置</param>
/// <param name="widthHalf">オブジェクトの幅の半分</param>
/// <param name="heightHalf">オブジェクトの高さの半分</param>
/// <param name="graph">画像のハンドル</param>
/// <param name="direction">向いている向き(trueで右)</param>
/// <param name="color">描画するときの色(指定しなければ白)</param>
void DrawObj(const Vertex& localVertex, const Matrix3x3& worldMatrix, const Matrix3x3& vpVpMatrix,
	const Vector2Int& graphCropPos, const float& widthHalf, const float& heightHalf,
	const int& graph, bool const& direction, const unsigned int& color = 0xffffffff);

/// <summary>
/// 線分を描画
/// </summary>
/// <param name="pos1">線分の先の点1</param>
/// <param name="pos2">線分の先の点2(反対側)</param>
/// <param name="vpVpMatrix">レンダリングパイプラインを通すための行列</param>
/// <param name="color">色(設定しないなら白)</param>
void DrawLine(const Vector2& pos1, const Vector2& pos2, const Matrix3x3& vpVpMatrix, const unsigned int& color = 0xffffffff);