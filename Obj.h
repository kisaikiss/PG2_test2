#pragma once
#include "Matrix3x3.h"
#include "Vector2.h"
#include "Vector2Int.h"
#include "Vertex.h"
#include "ColorData.h"
#include <Novice.h>

class Obj {
public:
	Obj();
	virtual ~Obj();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>オブジェクトを破棄するときはfalse、それ以外の時はtrue</returns>
	virtual bool Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="vpVpMatrix">スクリーン座標に変換するための行列</param>
	virtual void Draw(const Matrix3x3& vpVpMatrix) const;

	virtual float GetWidthHalf() const { return widthHalf_; }
	virtual float GetHeightHalf() const { return heightHalf_; }
	virtual Vector2 GetPos() const { return pos_; }
protected:
	int graph_;
	float theta_;
	float widthHalf_;
	float heightHalf_;
	float graphWidthHalf_;
	float graphHeightHalf_;
	Vector2Int graphCropPos_;
	Vector2 pos_;
	Vector2 speed_;
	Vector2 scale_;
	Vertex vertex_; //ワールド座標での各頂点
	Vertex baseVertex_; //オブジェクトの中心座標を原点としたローカル座標上での各頂点
	Matrix3x3 worldMatrix_;		//ワールド行列
	ColorData colorData_;
	unsigned int color_;
	BlendMode blendMode_;

	/// <summary>
	/// 色の更新処理
	/// </summary>
	void UpdateColor();

	/// <summary>
	/// 描画色を設定する(0 ~ 255)
	/// </summary>
	/// <param name="red">赤</param>
	/// <param name="green">緑</param>
	/// <param name="blue">青</param>
	/// <param name="alpha">透明度</param>
	void SetColor(const int& red, const int& green, const int& blue, const int& alpha);

	/// <summary>
	/// widthHalfとheightHalfをもとにbaseVertexをセットする
	/// </summary>
	void SetBaseVertex();

	/// <summary>
	/// 画面内に居るか
	/// </summary>
	/// <returns>trueなら画面内、falseなら画面外</returns>
	bool IsInside() const;
};