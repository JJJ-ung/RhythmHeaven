#pragma once

namespace MotionID
{
	enum ID
	{
		MOTION_NULL = 0,
		MOTION_TOUCH,
		MOTION_PRESS,
		MOTION_SLIDE,
		MOTION_UP,
		MOTION_SCRATCHUP,
		MOTION_SCRATCHDOWN
	};
}

namespace ObjID
{
	enum ID
	{
		BUTTON_GAMEICON, BUTTON_INVENTORY, BUTTON_OPENING,
		MEDAL,
		NPC_NONREACT, NPC_REACT,
		PLAYER,
		MOUSE,
		END
	};
}

namespace SceneID
{
	enum ID
	{
		GAME_NULL, GAME_ROBOT, GAME_BIRDS, GAME_FARM, GAME_LIZARDS, GAME_FANCLUB
	};
}

namespace FrameID
{
	enum ID
	{
		NORMAL, SILVER, GOLD, PERFECT
	};
}

namespace JudgeID
{
	enum ID
	{
		NOTHING, GOOD, BAD, PERFECT, END
	};
}