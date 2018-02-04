package practice;

public class Match {

	private Player []players;
	private int turn; //�����÷��̾� ���� 1�̸� 1��° �÷��̾� 2�̸� 2��° �÷��̾�
	private int playType; // ����Ÿ�� 1.���� 2.��Ʈ��ũ
	private OmokBoard playBoard;
	private int boardSize; //0�̸� 10*10, 1�̸� 15*15, 2�� 19*19
	protected boolean checkWinningCondition(Position m) {
		int stoneNum[] = new int[8];
		playBoard.countSameColorStones(m, playBoard.getStone(m.getRow(), m.getColumn()), stoneNum);
		for(int i = 0;i<8;i++) {
			if(stoneNum[i] == 5)
			{
				return true;
			}
		}
		return false;
	}
	protected boolean checkValidity(Position m) {
		if(playBoard.getStone(m.getRow(), m.getColumn()) == StoneType.None) {
			return true;
		}
		else
		{
		return false;
		}
	}
	public Match(int r,int c) {
		playBoard = new OmokBoard(r,c);
	}
	public Match() {
		playBoard = new OmokBoard(19,19);
	}
	public int getPlayType() {
		return playType;
	}
	public void setPlayType(int n) {
		if(n == 1|| n== 2) {
		this.playType = n;
		}
		else {
			System.out.println("1�Ǵ� 2�Է�");
		}
	}
	public int getBoardSize() {
		return boardSize;
	}
	public void setBoardSize(int n) {
		if( n==0) {
			boardSize = 10;
			}
		else if( n == 1) {
			boardSize = 15;
		}
		else if(n==2) {
			boardSize = 19;
		}
		else
			System.out.println("0~2������ �����Է�");
	}
	public int getTurn() {
		return turn;
	}
	public void setTurn(int n) {
		this.turn = n;
	}
	public Player getPlayer(int n) {
		return players[n];
	}
	public Player getCurrentPlayer() {
		return players[turn];
	}
	public StoneType getCurrentColor() {
		return null;
	}
	public void showBoard() {
		playBoard.displayBoard();
	}
	
	public void registerStone(int x,int y,StoneType s) {
		playBoard.putStone(x, y, s);
	}
	public OmokBoard getBoard() {
		return playBoard;
	}
	public void setPlayer(int n, Player player) {
		this.players[n] = player;
	}
	public int getPlayerType() {
		return players[turn].getPlayerType();
	}
}
