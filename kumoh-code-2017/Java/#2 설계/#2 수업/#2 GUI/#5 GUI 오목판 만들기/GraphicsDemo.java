import java.awt.Color;
import java.awt.Container;
import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class GraphicsDemo extends JFrame
{
	MyPanel board = new MyPanel();
	Container c;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args)
	{
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				try
				{
					GraphicsDemo frame = new GraphicsDemo();
					frame.setVisible(true);
				} catch (Exception e)
				{
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	
	void initializeComponent()
	{
		this.setSize(860, 720);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		c = getContentPane();
		c.setLayout(null);
		c.add(board);
	}
	
	public GraphicsDemo()
	{	
		super("test");
		
		initializeComponent();
	}
	
	class MyPanel extends JPanel
	{
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
		public Graphics getGraphic(){return graphic;} 
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
}
