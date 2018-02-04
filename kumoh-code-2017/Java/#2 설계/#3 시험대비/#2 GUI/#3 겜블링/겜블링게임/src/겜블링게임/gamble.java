package ∞◊∫Ì∏µ∞‘¿”;

import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.*;

public class gamble extends JFrame
{
	private JLabel message;
	private JPanel c;
	private JLabel x;
	private JLabel y;
	private JLabel z;

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
					gamble frame = new gamble();
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
	public gamble()
	{
		setTitle("Gamble");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 300, 200);
		message = new JLabel("∞‘¿”¿ª Ω√¿€«’¥œ¥Ÿ.");
		c = new JPanel();
		x = new JLabel("0");
		y = new JLabel("0");
		z = new JLabel("0");
		c.setLayout(null);
		setContentPane(c);
		
		message.setLocation(75, 24);
		message.setSize(141, 55);
		message.setFont(new Font("∏º¿∫ ∞ÌµÒ", Font.BOLD, 15));
		c.add(message);
		c.addKeyListener(new key(this));
		
		x.setLocation(80, 50);
		x.setSize(50, 90);
		x.setFont(new Font("∏º¿∫ ∞ÌµÒ", Font.BOLD, 30));
		c.add(x);
		
		y.setFont(new Font("∏º¿∫ ∞ÌµÒ", Font.BOLD, 30));
		y.setBounds(140, 50, 50, 90);
		c.add(y);
		
		z.setFont(new Font("∏º¿∫ ∞ÌµÒ", Font.BOLD, 30));
		z.setBounds(200, 50, 50, 90);
		c.add(z);
		
		setSize(338, 264);
		setVisible(true);
		c.requestFocus();
	}
	
	class key extends KeyAdapter
	{
		gamble main;
		key(gamble g)
		{
			main = g;
		}
		
		public void keyPressed(KeyEvent e)
		{
			int r = (int)(Math.random() * 5);
			int r1 = (int)(Math.random() * 5);
			int r2 = (int)(Math.random() * 5);
			
			if(e.getKeyChar() == '\n')
			{
				main.x.setText("" + r);
				main.y.setText("" + r1);
				main.z.setText("" + r2);
			}
			if(r == r1 && r1 == r2 && r2 == r)
			{
				main.message.setText("∏µŒ ∞∞¿∫ ºˆ ¿‘¥œ¥Ÿ.");
			}
			else
			{
				main.message.setText("æ∆Ω±±∫ø‰.");
			}
		}
	}
}
