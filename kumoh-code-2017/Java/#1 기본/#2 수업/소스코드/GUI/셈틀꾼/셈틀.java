import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JLabel;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextField;
import java.awt.GridLayout;

public class ¼ÀÆ² extends JFrame implements ActionListener
{

	private JPanel contentPane;
	private JTextField textField;
	private JButton btnNewButton;
	private JButton btnNewButton_1;
	private JButton btnNewButton_2;
	private JButton btnNewButton_3;
	private JButton btnNewButton_4;
	private JButton btnNewButton_5;
	private JButton btnNewButton_6;
	private JButton btnNewButton_7;
	private JButton btnNewButton_8;
	private JButton btnNewButton_9;
	private JButton btnNewButton_10;
	private JButton btnNewButton_11;
	private JButton btnNewButton_12;
	private JButton btnNewButton_13;
	private JButton btnNewButton_14;
	private JButton btnNewButton_15;
	private JButton btnNewButton_16;

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
					¼ÀÆ² frame = new ¼ÀÆ²();
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
	public ¼ÀÆ²()
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 350, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		textField = new JTextField();
		textField.setBounds(12, 10, 410, 51);
		contentPane.add(textField);
		textField.setColumns(10);
		
		JPanel panel = new JPanel();
		panel.setBounds(12, 77, 246, 174);
		contentPane.add(panel);
		panel.setLayout(new GridLayout(4, 4));
		
		btnNewButton_4 = new JButton("1");
		btnNewButton_4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				
				String text = textField.getText();
				textField.setText(text + btnNewButton_1.getText());
			}
		});
		panel.add(btnNewButton_4);
		
		btnNewButton_12 = new JButton("2");
		btnNewButton_12.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				
				String text = textField.getText();
				textField.setText(text + btnNewButton_2.getText());
			}
		});
		panel.add(btnNewButton_12);
		
		btnNewButton_8 = new JButton("3");
		btnNewButton_8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				
				String text = textField.getText();
				textField.setText(text + btnNewButton_3.getText());
			}
		});
		panel.add(btnNewButton_8);
		
		btnNewButton_1 = new JButton("+");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_1);
		
		btnNewButton_2 = new JButton("4");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_2);
		
		btnNewButton_3 = new JButton("5");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_3);
		
		btnNewButton_6 = new JButton("6");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_6);
		
		btnNewButton = new JButton("-");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton);
		
		btnNewButton_9 = new JButton("7");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_9);
		
		btnNewButton_5 = new JButton("8");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_5);
		
		btnNewButton_7 = new JButton("9");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_7);
		
		btnNewButton_10 = new JButton("*");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_10);
		
		btnNewButton_11 = new JButton("C");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_11);
		
		btnNewButton_13 = new JButton("0");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_13);
		
		btnNewButton_14 = new JButton("AC");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_14);
		
		btnNewButton_15 = new JButton("/");
		btnNewButton_1.addActionListener(this);
		panel.add(btnNewButton_15);
		
		btnNewButton_16 = new JButton("=");
		btnNewButton_1.addActionListener(this);
		btnNewButton_16.setBounds(270, 77, 52, 174);
		contentPane.add(btnNewButton_16);
	}

	@Override
	public void actionPerformed(ActionEvent e)
	{
		// TODO Auto-generated method stub
		JButton button = (JButton)e.getSource();
		if(button.getText().equals("C"))
		{
			String text = textField.getText();
			textField.subText(text.substring(0, text.length()-1));
		}
		else if(button.getText().equals("AC"))
		{
			textField.setText("");
		}
		else
		{
			String text = textField.getText();
			textField.subText(text + button.getText());
		}
		String text = textField.getText();
		textField.setText(text + button);
	}
}
