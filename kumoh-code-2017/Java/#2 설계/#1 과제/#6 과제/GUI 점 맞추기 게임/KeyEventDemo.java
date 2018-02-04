import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.Random;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.Timer;

public class KeyEventDemo extends JFrame implements ActionListener 
{
	final int DELTABlue = 100, DELTARed = 10;
	JLabel blueLabel;
	JLabel redLabel;
	JLabel positionLabel; 
	Point bluePoint;
	Point redPoint;
	int frameWidth;
	int frameHeight;
	Random rnd = new Random();
	Timer escapeTimer = new Timer(1800, this);


	public KeyEventDemo()
	{
		super("test");
		initializeComponents();
	}
	
	private void initializeGame() 
	{
		frameWidth = this.getSize().width;
		frameHeight = this.getSize().height;
		bluePoint = new Point(rnd.nextInt(frameWidth), rnd.nextInt(frameHeight));
		redPoint = new Point(rnd.nextInt(frameWidth), rnd.nextInt(frameHeight));
		blueLabel.setLocation(bluePoint);
		redLabel.setLocation(redPoint);
		escapeTimer.start();
	}
	
	private void initializeComponents() 
	{
		Container c = getContentPane();
		c.setLayout(null);
		
		KeyEventHandler keh = new KeyEventHandler();
		this.addKeyListener(keh);
		
		blueLabel = new JLabel(" ");
		redLabel = new JLabel(" ");
		positionLabel = new JLabel();
		
		blueLabel.setOpaque(true);
		redLabel.setOpaque(true);

		blueLabel.setSize(10, 10);
		blueLabel.setBackground((Color.BLUE));
		blueLabel.setLocation(0, 0);

		redLabel.setSize(10, 10);
		redLabel.setBackground((Color.RED));
		redLabel.setLocation(0, 10);
		
		positionLabel.setLocation(200, 200);
		positionLabel.setSize(500,500);

		c.add(blueLabel);
		c.add(redLabel);
		c.add(positionLabel);
		
		setSize(600, 600);

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);     
		initializeGame();
	}

	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		KeyEventDemo app = new KeyEventDemo();
	}

	class KeyEventHandler implements KeyListener
	{
		@Override
//		public void keyPressed(KeyEvent e)
//		{
//			// TODO Auto-generated method stub
//			switch(e.getKeyCode())
//			{
//			case KeyEvent.VK_UP:
//				if ( redPoint.y == 0 ) break;
//				redPoint.y = redPoint.y-DELTARed;
//				redLabel.setLocation(redPoint);
//				break;
//			case KeyEvent.VK_DOWN:
//				if ( redPoint.y == frameHeight ) break; 
//				redPoint.y = redPoint.y + DELTARed;
//				redLabel.setLocation(redPoint); 
//				break;
//			case KeyEvent.VK_LEFT:
//				if ( redPoint.x == 0 ) break; 
//				redPoint.x = redPoint.x - DELTARed;
//				redLabel.setLocation(redPoint); 
//				break; 
//			case KeyEvent.VK_RIGHT:
//				if ( redPoint.x == frameWidth ) break;
//				redPoint.x = redPoint.x+DELTARed;
//				redLabel.setLocation(redPoint); 
//				break;
//			}
		
		public void keyPressed(KeyEvent e)
		{
			// TODO Auto-generated method stub
			switch(e.getKeyCode())
			{
			case KeyEvent.VK_UP:
				if ( bluePoint.y == 0 ) break;
				bluePoint.y = bluePoint.y - DELTABlue;
				blueLabel.setLocation(bluePoint);
				break;
			case KeyEvent.VK_DOWN:
				if ( bluePoint.y == frameHeight ) break; 
				bluePoint.y = bluePoint.y + DELTABlue;
				blueLabel.setLocation(bluePoint); 
				break;
			case KeyEvent.VK_LEFT:
				if ( bluePoint.x == 0 ) break; 
				bluePoint.x = bluePoint.x - DELTABlue;
				blueLabel.setLocation(bluePoint); 
				break; 
			case KeyEvent.VK_RIGHT:
				if ( bluePoint.x == frameWidth ) break;
				bluePoint.x = bluePoint.x + DELTABlue;
				blueLabel.setLocation(bluePoint); 
				break;
			}
			
			positionLabel.setText( "red X: " + redPoint.x + ", Y : " + redPoint.y + "" );
			
			if(isCatched())
			{
				JOptionPane.showMessageDialog(null, "잡았습니다","잡힘!" ,JOptionPane.INFORMATION_MESSAGE);
				escapeTimer.stop();
			}
		}

		@Override
		public void keyReleased(KeyEvent e)
		{
			// TODO Auto-generated method stub
			
		}

		@Override
		public void keyTyped(KeyEvent e)
		{
			// TODO Auto-generated method stub
			
		}
	}

	public boolean isCatched()
	{
		Rectangle r1 = new Rectangle(redLabel.getLocation(), redLabel.getSize());
		Rectangle r2 = new Rectangle(blueLabel.getLocation(), blueLabel.getSize());

		if (r1.intersects(r2) ) return true;
		else return false;
	}

//	public void runAwayBlueLabel()
//	{
//		int dir = rnd.nextInt(4) + 1;
//		switch(dir)
//		{
//		case 1: // 왼쪽
//			bluePoint.x -= DELTABlue;
//			if(bluePoint.x < 0) bluePoint.x = 0;
//			break;
//		case 2: // 오른쪽
//			bluePoint.x += DELTABlue;
//			int xlimit = frameWidth - blueLabel.getSize().width;
//			if(bluePoint.x > xlimit ) bluePoint.x = xlimit;
//			break;
//		case 3: // 위쪽
//			bluePoint.y -= DELTABlue;
//			if(bluePoint.y < 0) bluePoint.y = 0;
//			break;
//		case 4: // 아래
//			bluePoint.y += DELTABlue;
//			int ylimit = frameHeight - blueLabel.getSize().height;
//			if(bluePoint.x > ylimit ) bluePoint.x = ylimit;
//			break;
//		}
//		blueLabel.setLocation(bluePoint);
//	}
	
	public void runAwayRedLabel()
	{
		int dir = rnd.nextInt(4) + 1;
		switch(dir)
		{
		case 1: // 왼쪽
			redPoint.x -= DELTARed;
			if(redPoint.x < 0) redPoint.x = 0;
			break;
		case 2: // 오른쪽
			redPoint.x += DELTARed;
			int xlimit = frameWidth - redLabel.getSize().width;
			if(redPoint.x > xlimit ) redPoint.x = xlimit;
			break;
		case 3: // 위쪽
			redPoint.y -= DELTARed;
			if(redPoint.y < 0) redPoint.y = 0;
			break;
		case 4: // 아래
			redPoint.y += DELTARed;
			int ylimit = frameHeight - redLabel.getSize().height;
			if(redPoint.x > ylimit ) redPoint.x = ylimit;
			break;
		}
		redLabel.setLocation(redPoint);
	}
	@Override
	public void actionPerformed(ActionEvent arg0)
	{
		// TODO Auto-generated method stub
//		runAwayBlueLabel();
		runAwayRedLabel();
	}
}

