#pragma once
class MazeBlock
{
public:
	enum class BlockType
	{
		ABLE,
		DISABLE,
		NONE
	};

	MazeBlock();
	~MazeBlock();

	void Update();
	void Render(HDC hdc);

	void SetPostion(Vector2 pos) { _rect->SetCenter(pos); }
	void SetType(MazeBlock::BlockType type) { _type = type; }

private:
	BlockType _type = BlockType::NONE;
	vector<HBRUSH> _brushes;

	shared_ptr<RectCollider> _rect;
};

