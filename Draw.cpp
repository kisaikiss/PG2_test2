#include "Draw.h"
#include "MatrixOperater.h"
#include <Novice.h>
#include <math.h>
void DrawObj(const Vertex& localVertex, const Matrix3x3& worldMatrix, const Matrix3x3& vpVpMatrix, const Vector2Int& graphCropPos,
	const float& widthHalf, const float& heightHalf, const int& graph, bool const& direction, const unsigned int& color) {
	Matrix3x3 wvpVpMatrix = Multiply(worldMatrix, vpVpMatrix);
	Vertex screenVertex{};
	screenVertex = VertexTransform(localVertex, wvpVpMatrix);
	if (direction) {
		Novice::DrawQuad(static_cast<int>(screenVertex.leftTop.x), static_cast<int>(screenVertex.leftTop.y),
			static_cast<int>(screenVertex.rightTop.x), static_cast<int>(screenVertex.rightTop.y),
			static_cast<int>(screenVertex.leftBottom.x), static_cast<int>(screenVertex.leftBottom.y),
			static_cast<int>(screenVertex.rightBottom.x), static_cast<int>(screenVertex.rightBottom.y),
			graphCropPos.x, graphCropPos.y, static_cast<int>(widthHalf * 2.f), static_cast<int>(heightHalf * 2.f), graph, color);
	} else {
		Novice::DrawQuad(static_cast<int>(screenVertex.rightTop.x), static_cast<int>(screenVertex.leftTop.y),
			static_cast<int>(screenVertex.leftTop.x), static_cast<int>(screenVertex.rightTop.y),
			static_cast<int>(screenVertex.rightBottom.x), static_cast<int>(screenVertex.leftBottom.y),
			static_cast<int>(screenVertex.leftBottom.x), static_cast<int>(screenVertex.rightBottom.y),
			graphCropPos.x, graphCropPos.y, static_cast<int>(widthHalf * 2.f), static_cast<int>(heightHalf * 2.f), graph, color);
	}
}

void DrawLine(const Vector2& pos1, const Vector2& pos2, const Matrix3x3& vpVpMatrix, const unsigned int& color) {
	Vector2 screenPos1 = Transform(pos1, vpVpMatrix);
	Vector2 screenPos2 = Transform(pos2, vpVpMatrix);
	Novice::DrawLine(static_cast<int>(screenPos1.x), static_cast<int>(screenPos1.y), static_cast<int>(screenPos2.x), static_cast<int>(screenPos2.y), color);
}
