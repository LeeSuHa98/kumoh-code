import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SpringLayout;

public class ProgramBasic extends JFrame implements ActionListener{ 
	JButton btn1,btn2,btn3,btn4,btn5,btn6,btn7,btn8,btn9,btn10,btn11,btn12,Obtn1,Obtn2,Obtn3,Obtn4,Obtn5;
	JTextField txtDisplay;
	int operand1 = 0,operand2 = 0;
	String op;
	int result;
	public static void main(String[] args) {

		ProgramBasic app = new ProgramBasic("test");
	}
	public ProgramBasic(String s) //constructor 
	{ 
		super(s);
		initializeComponents();
	}
	private void initializeComponents() {
		Container c = getContentPane();

		setSize(500,500);
		BoxLayout layout = new BoxLayout(c, BoxLayout.Y_AXIS);
		c.setLayout(layout);
		JPanel p1 = new JPanel();
		JPanel p2 = new JPanel();
		c.add(p1);
		c.add(p2);



		p1.setLayout(new GridLayout(1, 3, 5, 5));
		txtDisplay = new JTextField(15); 
		p1.add(txtDisplay);
		p2.setLayout(new BoxLayout(p2, BoxLayout.X_AXIS));
		JPanel p3 = new JPanel();
		JPanel p4 = new JPanel();
		p2.add(p3);
		p2.add(p4);

		p3.setLayout(new GridLayout(4, 3, 5, 5));
		btn1 = new JButton("1");
		p3.add(btn1);
		btn1.addActionListener(this);
		btn2 = new JButton("2");
		btn2.addActionListener(this);
		p3.add(btn2);
		btn3 = new JButton("3");
		btn3.addActionListener(this);
		p3.add(btn3);
		btn4 = new JButton("4");
		btn4.addActionListener(this);
		p3.add(btn4);
		btn5 = new JButton("5");
		btn5.addActionListener(this);
		p3.add(btn5);
		btn6 = new JButton("6");
		btn6.addActionListener(this);
		p3.add(btn6);
		btn7 = new JButton("7");
		btn7.addActionListener(this);
		p3.add(btn7);
		btn8 = new JButton("8");
		btn8.addActionListener(this);
		p3.add(btn8);
		btn9 = new JButton("9");
		btn9.addActionListener(this);
		p3.add(btn9);
		btn10 = new JButton("C");
		btn10.addActionListener(this);
		p3.add(btn10);
		btn11 = new JButton("0");
		btn11.addActionListener(this);
		p3.add(btn11);
		btn12 = new JButton("CE");
		btn12.addActionListener(this);
		p3.add(btn12);


		p4.setLayout(new GridLayout(5, 1, 5, 5)); 
		Obtn1 = new JButton("+");
		Obtn1.addActionListener(this);
		p4.add(Obtn1);
		Obtn2 = new JButton("-");
		Obtn2.addActionListener(this);
		p4.add(Obtn2);
		Obtn3 = new JButton("*");
		Obtn3.addActionListener(this);
		p4.add(Obtn3);
		Obtn4 = new JButton("/");
		Obtn4.addActionListener(this);
		p4.add(Obtn4);
		Obtn5 = new JButton("=");
		Obtn5.addActionListener(this);
		p4.add(Obtn5);
		//p4.add(p5);


		setLocation(300, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		JButton b = (JButton) e.getSource();
		String caption,s;
		if(b == btn1 || b == btn2 || b == btn3|| b == btn4|| b == btn5|| b == btn6|| b == btn7|| b == btn8|| b == btn9|| b == btn11) {
			caption = b.getText();
			s = txtDisplay.getText();
			s = s+caption;
			txtDisplay.setText(s);
		}
		else if(b == btn10||b == btn12) {
			txtDisplay.setText("");
		}
		else if(b == Obtn1) { // +
			operand1 = Integer.parseInt(txtDisplay.getText());
			op = "+";
			txtDisplay.setText("");
		}
		else if( b == Obtn2) { // -
			operand1 = Integer.parseInt(txtDisplay.getText());
			op = "-";
			txtDisplay.setText("");

		}
		else if( b == Obtn3) { // *
			operand1 = Integer.parseInt(txtDisplay.getText());
			op = "*";
			txtDisplay.setText("");

		}
		else if(b == Obtn4) { // /
			operand1 = Integer.parseInt(txtDisplay.getText());
			op = "/";
			txtDisplay.setText("");
		}
		else if(b == Obtn5) { // =
			if(op == "+") {
				operand2 = Integer.parseInt(txtDisplay.getText());
				result = operand1+operand2;
				txtDisplay.setText(Integer.toString(result));
			}
			else if(op == "-") {
				operand2 = Integer.parseInt(txtDisplay.getText());
				result = operand1-operand2;
				txtDisplay.setText(Integer.toString(result));
			}
			else if(op == "*") {
				operand2 = Integer.parseInt(txtDisplay.getText());
				result = operand1*operand2;
				txtDisplay.setText(Integer.toString(result));
			}
			else if(op == "/") {
				operand2 = Integer.parseInt(txtDisplay.getText());
				result = operand1/operand2;
				txtDisplay.setText(Integer.toString(result));
			}
		}
	}
} 

