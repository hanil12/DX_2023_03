#include "framework.h"
#include "Maze.h"

Maze::Maze()
{
	Vector2 offset = Vector2(400,100);

	_blocks.resize(25);
	for (int y = 0; y < _poolCountY; y++)
	{
		_blocks[y].reserve(25);
		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<MazeBlock> block = make_shared<MazeBlock>();
			block->SetPostion(offset + Vector2(18 * x, 18 * y));
			block->SetType(MazeBlock::BlockType::DISABLE);

			_blocks[y].push_back(block);
		}
	}

	CreateMaze();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto blockArr : _blocks)
	{
		for(auto block : blockArr)
			block->Update();
	}
}

void Maze::Render(HDC hdc)
{
	for (auto blockArr : _blocks)
	{
		for (auto block : blockArr)
			block->Render(hdc);
	}
}

// Maze for Programmer
void Maze::CreateMaze()
{
	// ³ëµå ¶Õ±â
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if(x % 2 == 0 || y % 2 == 0)
				continue;

			_blocks[y][x]->SetType(MazeBlock::BlockType::ABLE);
		}
	}
}
