package practice;

public class ComputerPlayer extends Player {

	ComputerPlayer(int id, String name,int order, int playType,StoneType s,double winningRate){
		super(id,name,order,playType,s,winningRate);
	}
	public Position play(OmokBoard board) {
		int weight = 0;
		int maxX = 0;
		int maxY = 0;

		for(int x = 0; x < board.getRowCount() ; x++)
		{
			for(int y = 0;y < board.getColCount() ; y++)
			{
				if(evaluatePosition(board,x,y)+measureDistance(board,x,y) > weight) // 가중치계산과 거리계산의 합이 가중치보다 큰 경우
				{
					weight = evaluatePosition(board,x,y) + measureDistance(board,x,y);
					//System.out.println(weight);
					maxX = x;
					maxY = y;
				}
			} 
		}
		Position p = new Position(maxX, maxY);
		//System.out.println(maxX+" "+maxY);
		return p;
	}
	private int getIndexMaxSameColor(int[] stoneNum)	//양쪽의 연속된 같은색 돌이 가장많은 인덱스를 찾아서 반환
	{
		int MaxSame = 0;
		int index = 0;
		for(int i = 0 ; i < 4 ; i++)
		{
			if(stoneNum[i]+stoneNum[i+4] > MaxSame)
			{
				MaxSame = stoneNum[i]+stoneNum[i+4];
				index = i;
			}
		}
		return index;
	}
	private int checkWeight(int[] stoneNum , boolean []isBlockage,int []opStoneNum,boolean []opIsBlockage)
	{			//가중치를 계산해서 반환
		int index = getIndexMaxSameColor(stoneNum);			//자신의돌색깔과 같은 연속된 돌의 갯수가 가장 큰 값을 가지는 인덱스
		int opIndex = getIndexMaxSameColor(opStoneNum);		//상대방의 돌색깔과 같은 연속된 돌의 갯수가 가장 큰 값을 가지는 인덱스
		int count = stoneNum[index]+stoneNum[index+4] + 1;	//양옆을 합치고 자신이 놓았을때의 총 연속된 갯수
		int opCount = opStoneNum[opIndex]+opStoneNum[opIndex+4] + 1;//양옆을 합치고 상대가 놓았을때의 총 연속된 갯수
		
		int weight = 0;
		if(count == 5)				//내가 돌을 놓았을 경우 5개 완성 (100)
			weight = 100;
		else if(opCount == 5)		// 상대방이 돌을 놓았을 경우에 5개 완성 (90) 
			weight = 90;
		else if(count == 4 && (isBlockage[index] == true||isBlockage[index+4] == true))
			weight = 70;			//내 돌 4개 (막힌)놓았을 경우(70)
		else if(opCount == 4 && (opIsBlockage[opIndex] == true||opIsBlockage[opIndex+4] == true))
			weight = 65;			//상대방 4개 (막힌)놓았을 경우(65) 
		else if(count == 4)
			weight = 80;			//내가 4개 (양 옆)놓았을 경우(80) 
		else if(opCount == 4)
			weight = 75;			//상대방 4개 (양 옆)놓았을 경우(75) 
		else if(count == 3 && (isBlockage[index] == true||isBlockage[index+4] == true))
			weight = 50;			//내 돌 3개 (막힌)놓았을 경우(50)
		else if(opCount == 3 && (opIsBlockage[opIndex] == true||opIsBlockage[opIndex+4] == true))
			weight = 45;			//상대방 3개 (막힌)놓았을 경우(45) 
		else if(count == 3)
			weight = 60;			//내 돌 3개 (양 옆)놓았을 경우(60) 
		else if(opCount == 3)
			weight = 55;			// 상대방 3개 (양 옆)놓았을 경우(55) 
		else if(count == 2 && (isBlockage[index] == true||isBlockage[index+4] == true))
			weight = 30;			//내 돌 2개 (막힌)놓았을 경우(30) 
		else if(opCount == 2 && (opIsBlockage[opIndex] == true||opIsBlockage[opIndex+4] == true))
			weight = 25;			//상대방 2개 (막힌)놓았을 경우(25)
		else if(count == 2)
			weight = 40;			//내 돌 2개 (양 옆)놓았을 경우(40) 
		else if(opCount == 2)
			weight = 35;			//상대방 2개 (양 옆)놓았을 경우(35) 
		else if(count == 1 && (isBlockage[index] == true||isBlockage[index+4] == true))
			weight = 10;			//내 돌 1개 (막힌)놓았을 경우(10) 
		else if(opCount == 1 && (opIsBlockage[opIndex] == true||opIsBlockage[opIndex+4] == true))
			weight = 5;				//상대방 1개 (막힌)놓았을 경우(5)
		else if(count == 1)
			weight = 20;			//내 돌 1개 (양 옆)놓았을 경우(20) 
		else if(opCount == 1)
			weight = 15;			//상대방 1개 (양 옆)놓았을 경우(15) 
		
		return weight;
	}
	private int evaluatePosition(OmokBoard board, int x, int y)
	{
		if(board.getStone(x, y) != StoneType.None)
			return 0;
		int []stoneNum = new int[8];
		int []opStoneNum = new int[8];
		boolean []isBlockage = new boolean[8];		//자신의 색깔이 마지막에 막혀있는지 안막혀있는지 확인
		boolean []opIsBlockage = new boolean[8];	//상대의 색깔이 마지막에 막혀있는지 안막혀있는지 확인
		StoneType color = StoneType.None;
		StoneType opColor = StoneType.None;
		Position p = new Position(x,y);
		if(getOrder() == 1)
		{
			color = StoneType.Black;
			opColor = StoneType.White;
		}
		else if(getOrder() == 2)
		{
			color = StoneType.White;
			opColor = StoneType.Black;
		}

		countSameColorStones(board,p, color, stoneNum ,isBlockage);  //팔방향으로 연속된 돌들의 갯수를 stoneNum에 담고 마지막에 막혀있는지를 isBlockage에 담는다.
		countSameColorStones(board,p, opColor, opStoneNum ,opIsBlockage);
		int weight = checkWeight(stoneNum, isBlockage, opStoneNum, opIsBlockage);//가중치를 계산해서 반환
		
		return weight;
	}
	public int measureDistance(OmokBoard board ,int x, int y)
	{		//거리를 계산해서 가중치를 정하여 반환
		double centerDistance = board.getRowCount() / 2;
		double rowd =  Math.abs(x - centerDistance);		//거리를 계산하기 때문에 절대값(abs)
		double cold = Math.abs(y - centerDistance);
		double distance = 0;
		if(rowd < cold)
			distance = cold;
		else
			distance = rowd;
		if(distance >= centerDistance*4/5)
			return 1;
		else if(distance >= centerDistance*3/5)
			return 2;
		else if(distance >= centerDistance*2/5)
			return 3;
		else if(distance >= centerDistance*1/5)
			return 4;
		else return 5;
	}
	public void countSameColorStones(OmokBoard board,Position p, StoneType color, int[] stoneNum, boolean []isBlockage)
	{
		//팔방향으로 연속된 돌들의 갯수를 stoneNum에 담고 마지막에 막혀있는지를 isBlockage에 담는다.
		StoneType oppenentColor = StoneType.None;	//상대방 돌 색깔
		if(color == StoneType.White)
			oppenentColor = StoneType.Black;
		else
			oppenentColor = StoneType.White;
		for(int i = 0 ; i < board.getRowCount() ; i++)
		{
			if(board.getStone(p.getRow() - i, p.getColumn()) == color)
				stoneNum[0]++;
			else if(board.getStone(p.getRow() - i, p.getColumn()) == oppenentColor)
			{
				isBlockage[0] = true;			//상대방 돌 색깔과 같으면 막혀있음
				break;
			}				
			else break;
		}
		for(int i = 0 ; i < board.getRowCount() ; i++)
		{
			if(board.getStone(p.getRow() - i, p.getColumn() +i) == color)
				stoneNum[1]++;
			else if(board.getStone(p.getRow() - i, p.getColumn()+i) == oppenentColor)
			{
				isBlockage[1] = true;
				break;
			}
			else break;
		}
		for(int i = 0 ; i < board.getRowCount() ; i++)
		{
			if(board.getStone(p.getRow(), p.getColumn() +i) == color)
				stoneNum[2]++;
			else if(board.getStone(p.getRow(), p.getColumn()+i) == oppenentColor)
			{
				isBlockage[2] = true;
				break;
			}
			else break;
		}
		for(int i = 0 ; i < board.getRowCount() ; i++)
		{
			if(board.getStone(p.getRow()+i, p.getColumn() +i) == color)
				stoneNum[3]++;
			else if(board.getStone(p.getRow() + i, p.getColumn()+i) == oppenentColor)
			{
				isBlockage[3] = true;
				break;
			}
			else break;
		}
		for(int i = 0 ; i < board.getRowCount() ; i++)
		{
			if(board.getStone(p.getRow()+i, p.getColumn()) == color)
				stoneNum[4]++;
			else if(board.getStone(p.getRow() + i, p.getColumn()) == oppenentColor)
			{
				isBlockage[4] = true;
				break;
			}
			else break;
		}
		for(int i = 0 ; i < board.getRowCount() ; i++)
		{
			if(board.getStone(p.getRow()+i, p.getColumn()-i) == color)
				stoneNum[5]++;
			else if(board.getStone(p.getRow() + i, p.getColumn() - i) == oppenentColor)
			{
				isBlockage[5] = true;
				break;
			}
			else break;
		}
		for(int i = 0 ; i < board.getRowCount() ; i++)
		{
			if(board.getStone(p.getRow(), p.getColumn()-i) == color)
				stoneNum[6]++;
			else if(board.getStone(p.getRow() , p.getColumn()- i) == oppenentColor)
			{
				isBlockage[6] = true;
				break;
			}
			else break;
		}
		for(int i = 0 ; i < board.getRowCount() ; i++)
		{
			if(board.getStone(p.getRow()-i, p.getColumn()-i) == color)
				stoneNum[7]++;
			else if(board.getStone(p.getRow() - i, p.getColumn()-i) == oppenentColor)
			{
				isBlockage[7] = true;
				break;
			}
			else break;
		}
	}
}
	
	

	

