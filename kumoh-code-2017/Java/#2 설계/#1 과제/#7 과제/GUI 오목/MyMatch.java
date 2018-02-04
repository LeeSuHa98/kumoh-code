package 오목;

import java.util.Scanner;

public class MyMatch extends Match
{	
	public MyMatch() {}
	public MyMatch(int rows, int cols)
	{
		super(rows, cols);
	}

	public boolean getCheckWinningCondition(Position p)
	{
		return checkWinningCondition(p);
	}
	
	public boolean getCheckValidity(Position p)
	{
		return checkValidity(p);
	}
	
	public void registerPlayers(String name1, String name2)
	{
		if(playType == 1)	// 1 : User vs User
		{
			super.insertPlayers(name1, name2);
		}
		else if(playType == 2)	// 2 : User vs AI
		{
			if(order == 1)
			{
				players[1] = new Player(1, name1, order, 100);
				players[2] = new ComputerPlayer(2, "computer", 2, 100);
			}
			else if(order == 2)
			{
				players[1] = new ComputerPlayer(1, "computer", 1, 100);
				players[2] = new Player(2, name2, order, 100);
			}
			else
			{
				System.out.println("입력 범위 초과! (1 or 2)");
			}
		}
	}
}
