package 오목;

import java.awt.AWTException;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Panel;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;


public class OmokGUI extends JFrame implements ActionListener
{
	MyPanel board = new MyPanel();
	JButton button1 = new JButton("Start");
	JButton button2 = new JButton("Exit");
	JLabel Playerlabel1;
	JLabel Playerlabel2;
	JLabel errorLabel;
	JTextField PlayerText1;	// 플레이어1 이름
	JTextField PlayerText2;	// 플레이어2 이름
	JRadioButton sizebtn1;	// 10x10
	JRadioButton sizebtn2;	// 15x15
	JRadioButton sizebtn3;	// 19x19
	JRadioButton radiobtn1;	// 사람 vs 사람
	JRadioButton radiobtn2;	// 사람 vs AI
	JRadioButton firstRadiobtn;	// 선공
	JRadioButton secRadiobtn;	// 후공
	Container c;
	JLabel label;
	MouseEventHandler mh = new MouseEventHandler(this);

	MyMatch game;
	Graphics graphics;

	int type = 0;				//사람대사람 : 1, 사람대컴퓨터 : 2
	boolean state = false;		//게임중인지 아닌지 여부
	int isFirst = 0;			//선공 : 1, 후공 : 2
	
	public OmokGUI()
	{
		super("오목게임");
		initializeComponent();
	}
	public void initializeComponent()
	{
		this.setSize(860, 720);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		c = getContentPane();
		c.setLayout(null);
		graphics = board.getGraphics();
		
		label = new JLabel("Game Start.");
		Playerlabel1 = new JLabel("Player1");
		Playerlabel2 = new JLabel("Player2");
		errorLabel = new JLabel("");

		PlayerText1 = new JTextField();
		PlayerText2 = new JTextField();

		sizebtn1 = new JRadioButton("BoardSize : 10x10");
		sizebtn2 = new JRadioButton("BoardSize : 15x15");
		sizebtn3 = new JRadioButton("BoardSize : 19x19");
		sizebtn1.setBounds(710, 130, 150, 30);
		sizebtn2.setBounds(710, 160, 150, 30);
		sizebtn3.setBounds(710, 190, 150, 30);
		
		radiobtn1 = new JRadioButton("User VS User");
		radiobtn2 = new JRadioButton("User VS AI");
		radiobtn1.setBounds(710, 230, 120, 30);
		radiobtn2.setBounds(710, 260, 120, 30);
		firstRadiobtn = new JRadioButton("First");
		secRadiobtn = new JRadioButton("Second");
		firstRadiobtn.setBounds(710, 410, 70, 20);
		secRadiobtn.setBounds(780, 410, 70, 20);
		firstRadiobtn.setVisible(false);
		secRadiobtn.setVisible(false);

		label.setBounds(170, 170, 300, 200);
		label.setFont(new Font("굴림", 0, 30));
		
		Playerlabel1.setBounds(720, 290, 120, 30);
		Playerlabel2.setBounds(720, 350, 120, 30);
		PlayerText1.setBounds(720, 320, 120, 25);
		PlayerText2.setBounds(720, 380, 120, 25);
		errorLabel.setBounds(700, 500, 130, 25);
		errorLabel.setForeground(Color.RED);
		Playerlabel1.enable(false);
		Playerlabel2.enable(false);
		PlayerText1.enable(false);
		PlayerText2.enable(false);

		if(state)
		{
			label.setVisible(false);
			board.setVisible(true);
		}
		else
		{
			label.setVisible(true);
			board.setVisible(false);
		}
		c.add(label);

		button1.setBounds(730, 450, 80, 30);
		button1.addActionListener(this);
		button2.setBounds(730, 500, 80, 30);
		button2.addActionListener(this);

		sizebtn1.addActionListener(this);
		sizebtn2.addActionListener(this);
		sizebtn3.addActionListener(this);
		
		radiobtn1.addActionListener(this);
		radiobtn2.addActionListener(this);
		firstRadiobtn.addActionListener(this);
		secRadiobtn.addActionListener(this);

		c.add(sizebtn1);
		c.add(sizebtn2);
		c.add(sizebtn3);
		
		c.add(radiobtn1);
		c.add(radiobtn2);
		c.add(firstRadiobtn);
		c.add(secRadiobtn);

		c.add(button1);
		c.add(button2);

		c.add(PlayerText1);
		c.add(PlayerText2);
		c.add(Playerlabel1);
		c.add(Playerlabel2);
		c.add(errorLabel);
		c.add(board);
		
		board.addMouseListener(mh);
		this.setVisible(true);
	}
	@Override
	public void actionPerformed(ActionEvent e) 
	{
		if(e.getSource() == button1)
		{
			if(radiobtn1.isSelected() == false && radiobtn2.isSelected() == false)
			{
				JOptionPane.showMessageDialog(null,"모드를 선택하세요");
				return;
			}
			else if(radiobtn2.isSelected() == true && firstRadiobtn.isSelected() == false && secRadiobtn.isSelected() == false)
			{
				JOptionPane.showMessageDialog(null,"선공/후공 선택하세요");
				return;
			}
			else if(radiobtn1.isSelected() == true)
			{
				type = 1;
			}
			else if(radiobtn2.isSelected() == true)
			{
				type = 2;
			}
			if(PlayerText1.getText().length() == 0 && PlayerText2.getText().length() == 0)
			{
				JOptionPane.showMessageDialog(null,"플레이어를 입력하세요");
				return;
			}
			
			board.resetGraphics();
			board.repaint();
			state = true;
			board.setVisible(true);
			label.setVisible(false);
			game = new MyMatch();
			game.playBoard.clear();
			game.setPlayType(type);
			
			if(type == 1)
			{
				game.turn = 1;
			}
			else if(type == 2)
			{
				game.turn = 1;
				if(firstRadiobtn.isSelected() == true)
				{
					game.order = 1;
					isFirst = 1;
				}
				else
				{
					game.order = 2;
					isFirst = 2;
				}
			}
			game.registerPlayers(PlayerText1.getText(), PlayerText2.getText());
			if(type == 2 && isFirst == 2)
			{
				mh.comPlay();
			}
		}
		else if(e.getSource() == radiobtn1)
		{
			if(radiobtn1.isSelected() == false)
			{
				Playerlabel1.enable(false);
				PlayerText1.enable(false);
				Playerlabel2.enable(false);
				PlayerText2.enable(false);
				repaint();
			}
			else
			{
				radiobtn2.setSelected(false);
				Playerlabel1.enable(true);
				Playerlabel2.enable(true);
				PlayerText1.enable(true);
				PlayerText2.enable(true);
				firstRadiobtn.setVisible(false);
				secRadiobtn.setVisible(false);
				repaint();
			}
		}
		else if(e.getSource() == radiobtn2)
		{
			if(radiobtn2.isSelected() == false)
			{
				Playerlabel1.enable(false);
				PlayerText1.enable(false);
				firstRadiobtn.setVisible(false);
				secRadiobtn.setVisible(false);
				repaint();
			}
			else
			{
				radiobtn1.setSelected(false);
				Playerlabel1.enable(true);
				PlayerText1.enable(true);
				Playerlabel2.enable(false);
				PlayerText2.enable(false);
				firstRadiobtn.setVisible(true);
				secRadiobtn.setVisible(true);
				repaint();
			}
		}
		else if(e.getSource() == button2)
		{
			JOptionPane.showMessageDialog(null,"게임을 종료합니다.");
			System.exit(1);	
		}
		else if(e.getSource() == firstRadiobtn)
		{
			secRadiobtn.setSelected(false);
			Playerlabel1.enable(true);
			PlayerText1.enable(true);
			Playerlabel2.enable(false);
			PlayerText2.enable(false);
			repaint();
		}
		else if(e.getSource() == secRadiobtn)
		{
			firstRadiobtn.setSelected(false);
			Playerlabel1.enable(false);
			PlayerText1.enable(false);
			Playerlabel2.enable(true);
			PlayerText2.enable(true);
			repaint();
		}
		else if(e.getSource() == sizebtn1)
		{
			sizebtn2.setSelected(false);
			sizebtn3.setSelected(false);
			repaint();
		}
		else if(e.getSource() == sizebtn2)
		{
			sizebtn1.setSelected(false);
			sizebtn3.setSelected(false);
			repaint();
		}
		else if(e.getSource() == sizebtn3)
		{
			sizebtn1.setSelected(false);
			sizebtn2.setSelected(false);
			repaint();
		}
	}
	public static void main(String[] args)
	{
		OmokGUI omokGUI = new OmokGUI();
	}
}

class MyPanel extends JPanel
{
	OmokGUI frame;
	BufferedImage img;
	Graphics graphic = super.getGraphics();
	Graphics memgraphics;
	
	public void resetGraphics()
	{
		try 
		{
			img = ImageIO.read(new File("OH.png"));
			memgraphics = img.createGraphics();
			memgraphics.setColor(Color.BLACK);
			
			int interval = img.getWidth() / 22;
			for(int i = interval; i < img.getWidth(); i +=  interval)
			{
				memgraphics.drawLine(i, interval, i, img.getHeight() - interval);
			}
			for(int j = interval; j < img.getHeight(); j += interval)
			{
				memgraphics.drawLine(interval, j, img.getWidth() - interval, j);
			}
			//int interPoint =(img.getWidth() - 2*interval)/4;
			for(int i = interval * 4; i <= img.getWidth() - interval * 4; i += interval * 7)
			{
				for(int j = interval * 4; j <= img.getHeight() - interval * 4; j += interval * 7)
				{
					memgraphics.fillOval(i - 3, j - 3, 6, 6);
				}
			}
		} 
		catch (IOException e1) { e1.printStackTrace(); }
	}
	public MyPanel()
	{
		this.setLocation(30, 30);
		this.setLayout(null);
		this.setSize(660, 660);
		this.setOpaque(true);
		try 
		{
			img = ImageIO.read(new File("OH.png"));
			memgraphics = img.createGraphics();
			memgraphics.setColor(Color.BLACK);
			int interval = img.getWidth() / 22;
			for(int i = interval; i < img.getWidth(); i += interval)
			{
				memgraphics.drawLine(i, interval, i, img.getHeight() - interval);
			}
			for(int j = interval; j < img.getHeight(); j += interval)
			{
				memgraphics.drawLine(interval, j, img.getWidth() - interval, j);
			}
			//int interPoint =(img.getWidth() - 2*interval)/4;
			for(int i = interval * 4; i <= img.getWidth() - interval * 4; i += interval * 7)
			{
				for(int j = interval * 4; j <= img.getHeight() - interval * 4; j += interval * 7)
				{
					memgraphics.fillOval(i - 3, j - 3, 6, 6);
				}
			}
		} 
		catch (IOException e1) {e1.printStackTrace();}
	}
	public Graphics getGraphic(){ return graphic; } 
	public void paintComponent(Graphics graphics)
	{
		int dx1 = 0; int dy1 = 0;
		int dx2 = this.getWidth(); 
		int dy2 = this.getHeight();
		int sx1 = 0; int sy1 = 0;
		int sx2 = img.getWidth(); 
		int sy2 = img.getHeight();
		graphics.drawImage(img, dx1, dy1, dx2, dy2, sx1, sy1, sx2, sy2, null);
	}
}

class MouseEventHandler extends MouseAdapter implements MouseMotionListener
{
	OmokGUI frame;
	public MouseEventHandler(OmokGUI frame)
	{
		this.frame = frame;
	}
	public void mouseClicked(MouseEvent e)
	{
		Point point = findPoint(e.getX(), e.getY());
		if(frame.type == 1)
		{
			play(point);
		}
		if(frame.type == 2)
		{
			int flag = play(point);

			if(flag == 1 || flag ==2)
			{
				return;
			}
			else
			{
				comPlay();
			}
		}
	}
	public Point findPoint(int x, int y)
	{
		x = x * 2 / 3;
		y = y * 2 / 3;
		int x_share = x / 20;
		int y_share = y / 20;
		int x_mod = x % 20;
		int y_mod = y % 20;

		int x_result;
		int y_result;

		if(x_mod < 10)
		{
			x_result = x_share * 20;
		}
		else
		{
			x_result = (x_share + 1) * 20;
		}
		if(y_mod < 10)
		{
			y_result = y_share * 20;
		}
		else
		{
			y_result = (y_share + 1) * 20;
		}

		Point point = new Point(x_result, y_result);

		return point;
	}
	public int play(Point point)			// 0 : 이상 무,  1 : 오류,  2 : 승리
	{
		boolean error = false;			//에러가 있으면 다시 놓게 함
		Graphics g = frame.board.memgraphics;
		if(frame.state == true && ((!(point.getX() < 20) && !(point.getY() < 20)) || (!(point.getX() > 420) && !(point.getY() < 420))))
		{
			Position p = new Position((int)point.getX() / 20, (int)point.getY() / 20);
			if(frame.game.checkValidity(p))
			{
				frame.game.playBoard.putStone(p.getRow(), p.getColumn(), frame.game.getCurrentColor());
				if(frame.game.checkWinningCondition(p))
				{
					if(frame.game.turn == 1)
					{
						g.setColor(Color.black);	
					}
					else if(frame.game.turn == 2)
					{
						g.setColor(Color.white);
					}
					g.fillOval((int)point.getX() - 9 ,(int)point.getY() - 9, 18, 18);
					frame.errorLabel.setText("");
					frame.board.repaint();
					JOptionPane.showMessageDialog(null, "[player" + frame.game.turn + "] " + frame.game.players[frame.game.turn].getName() + " 승리!!");
					frame.state = false;
					
					return 2;
				}
			}
			else 
			{
				frame.errorLabel.setText("착수 할 수 없습니다.");
				error = true;		
				return 1;
			}
			
			if(frame.game.turn == 1)
			{
				g.setColor(Color.black);	
			}
			else if(frame.game.turn == 2)
			{
				g.setColor(Color.white);	
			}
			if(!error)
			{
				frame.errorLabel.setText("");
				g.fillOval((int)point.getX() - 9 ,(int)point.getY() - 9, 18, 18);
				frame.game.turn = frame.game.turn % 2 + 1;
				frame.board.repaint();
				//frame.board.paint(frame.board.graphic);
			}
		}
		return 0;
	}
	public int comPlay()
	{
		boolean error = false;
		Graphics g = frame.board.memgraphics;

		if(frame.state == true)
		{	
			Position p = frame.game.players[frame.game.turn].play(frame.game.playBoard);
			frame.game.playBoard.putStone(p.getRow(), p.getColumn(), frame.game.getCurrentColor());
			if(frame.game.checkWinningCondition(p))
			{
				if(frame.game.turn == 1)
				{
					g.setColor(Color.black);	
				}
				else if(frame.game.turn == 2)
				{
					g.setColor(Color.white);	
				}
				g.fillOval(((int)p.getRow()) * 20 - 9, ((int)p.getColumn()) * 20 - 9, 18, 18);
				frame.board.repaint();
				JOptionPane.showMessageDialog(null, "[player" + frame.game.turn + "] " + frame.game.players[frame.game.turn].getName() + " 승리!!");
				frame.state = false;
				return 2;
				//바둑판 없애는 코드
			}
			if(frame.game.turn == 1)
			{
				g.setColor(Color.black);	
			}
			else if(frame.game.turn == 2)
			{
				g.setColor(Color.white);	
			}
			if(!error)
			{
				g.fillOval(((int)p.getRow()) * 20 - 9, ((int)p.getColumn()) * 20 - 9, 18, 18);
				frame.game.turn = frame.game.turn % 2 + 1;
				frame.board.repaint();
			}
		}
		return 0;
	}
}